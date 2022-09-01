#include <stdio.h>
#include <time.h>
#include <math.h>
#include "test.h"

static clock_t start_time;
static unsigned int num_tests;

void start_tests() {
  start_time = clock();
  num_tests = 0;
  printf("Starting tests");
}

void end_tests() {
  double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
  printf("\n%d tests passed in %4.5f seconds\n", num_tests, elapsed_time);
}

/**
*facciamo il test della funzione presa da parametro
*/
void test(void (*test_fun)()) {
  num_tests += 1;
  printf(".");
  test_fun();
}
