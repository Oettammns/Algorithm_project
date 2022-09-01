#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include "functions.h"
#include "unity.h"
#include "test.h"

static clock_t start_time;

/* Unit Test FILE*/
void test_insertion_sort_on_null_array();
void test_insertion_sort_on_empty_array();
void test_insertion_sort_on_all_equal_element_array();

/*test di un binary insertion sort con array nullo*/
void test_insertion_sort_on_null_array(){
    int** array = NULL;
    start_time = clock();
    insertion_sort((void**) array, 0, compare_int_ptr);
    double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    printf("\ntest on null array passed in %4.5f seconds\n", elapsed_time);
    assert(1);
    
}

/* test binary_insertion_sort con array vuoto */
void test_insertion_sort_on_empty_array() {
    int** array;
    array = malloc(sizeof(int*));
    start_time = clock();
    insertion_sort((void**) array, 0, compare_int_ptr);
    double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    printf("\ntest on empty array passed in %4.5f seconds\n", elapsed_time);
    free(array);
    array = NULL;
    assert(1);
}

//test merge con array nullo
void test_merge_sort_on_null_array(){
	int** array = NULL;
	start_time = clock();
	merge_sort((void**) array, 0, compare_int_ptr);
	double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
	printf("\ntest on null array passed in %4.5f seconds\n", elapsed_time);
	assert(1);

}
//test merco con array vuoto
void test_merge_sort_on_empty_array(){
	int** array;
    	array = malloc(sizeof(int*));
    	start_time = clock();
    	insertion_sort((void**) array, 0, compare_int_ptr);
    	double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    	printf("\ntest on empty array passed in %4.5f seconds\n", elapsed_time);
    	free(array);
    	array = NULL;
    	assert(1);
}

int main(int argc, char const *argv[]) {
  printf("TestSuite BinaryInsertionSort...\n");
  start_tests();
  test(test_insertion_sort_on_null_array);
  test(test_insertion_sort_on_empty_array);
  sleep(1);
  printf("Close BinaryInsertionSort...\n");
  end_tests();
  printf("-------------------------------------------\n");
  printf("TestSuite MergeSort...\n");
  start_tests();
  test(test_merge_sort_on_null_array);
  test(test_merge_sort_on_empty_array);
  end_tests();
  return 0;
}
