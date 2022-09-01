#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"
#include "unity.h"

static clock_t clock_time;

int main(int argc, char** argv){
	//prende da cli il file che vogliamo ordinare e il k
	char* file = argv[1];
	int k = atoi(argv[2]);

	/*esegue i test, per ogni campo, binary e mergesort
	chiamando le funzioni di testing */
	printf("Executing BinaryInsertionSort on Int field...");
	insertionsort_fullarray_int(file, k);
	printf("Executing MergeSort on Int field...");
	mergesort_fullarray_int(file, k);

	
	printf("Executing BinaryInsertionSort on String field...");
	insertionsort_fullarray_string(file, k);
	printf("Executing MergeSort on String field...");
	mergesort_fullarray_string(file, k);
	
	printf("Executing BinaryInsertionSort on Float field...");
	insertionsort_fullarray_float(file, k);
	printf("Executing MergeSort on float field...");
	mergesort_fullarray_float(file, k);
	return 0;
}

/*chiamiamo i metodi,presenti nella libreria function.h, per ogni tipo da ordinare
passiamo come parametro fp che è il file csv, f che sarà il nome del file csv, k è l'indice che fa switch da
binary a merge sort*/
void insertionsort_fullarray_int(char * f, int k){
	bin_ins_int(fp, f, k);
}


void insertionsort_fullarray_float(char * f, int k){
	bin_ins_float(fp, f, k);
}

void insertionsort_fullarray_string(char * f, int k){
	bin_ins_string(fp, f, k);
}

void mergesort_fullarray_string(char * f, int k){
	merge_string(fp, f, k);
}

void mergesort_fullarray_int(char * f, int k){
	merge_int(fp, f, k);
}

void mergesort_fullarray_float(char * f, int k){
	merge_float(fp, f, k);
}
