#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LINES 20000000

typedef int (*CompFunction)(void*, void*);

struct Record{
	int id;
	char * field1;
	int field2;
	double field3;
}record;

struct Record records[MAX_LINES];

FILE * fp;
char * filename;
int p;
int r;


void bin_ins_int(FILE * fp, char* filename, int k);
void bin_ins_float(FILE * fp, char* filename, int k);
void bin_ins_string(FILE * fp, char* filename, int k);
void insertionsort_fullarray_int(char* filename, int k);
void insertionsort_fullarray_float(char* filename, int k);
void insertionsort_fullarray_string(char* filename, int k);
void mergesort_fullarray_int(char* filename, int k);
void mergesort_fullarray_float(char* filename, int k);
void mergesort_fullarray_string(char* filename, int k);
/* For test suite on mergesort only */
void merge_int(FILE* fp, char* filename, int k);
void merge_float(FILE* fp, char* filename, int k);
void merge_string(FILE* fp, char* filename, int k);
/* Other prototype functions */
//void Print(void** array_i, void** array, void** array_f);
//void Ordinamento(void** array_i, void** array,void** array_d);
int* new_int(int value);
float* new_float(float value);
char* new_string(char* value);
//void insertion_sort(void** array, int size, CompFunction compare);
void merge_sort(void** array, int size, CompFunction compare);
void merge(void** array, int first, int middle, int last, CompFunction compare);
void msort(void** array, int first, int last, CompFunction compare);
void swap(void** e1, void** e2);
int compare_int_ptr(void* ptr1, void* ptr2);
int compare_string_ptr(void* ptr1, void* ptr2);
int compare_float_ptr(void* ptr1, void* ptr2);
void insertion_sort(void** array, int size, CompFunction compare);
int binary_search(void** array, void* item, int low, int high, CompFunction compare);
void insert(void** array, int pos, CompFunction compare);
