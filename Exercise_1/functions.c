#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include "functions.h"
#include "unity.h"

//variabile che calcolerà il tempo che ci mette il programma ad ordinare
static clock_t start_time;
/*convete in intero il valore*/
int* new_int(int value) {
  int* result = (int*)malloc(sizeof(int));
  *result = value;
  return result;
}
/*converte in float il valore*/
float* new_float(float value) {
  float* result = (float*) malloc(sizeof(float));
  *result = value;
  return result;
}
/*converte in string il valore*/
char* new_string(char* value) {
  char* result = (char*) malloc(strlen(value)*sizeof(char));
  strcpy(result, value);
  return result;
}
/*creiamo un array che tratterà il field degli interi, memorizziamo il contenuto di field2
separandolo dagli altri con la strtok avendo come token la virgola. Questo dopo aver controllato
se il file non è vuoto*/
void bin_ins_int(FILE * fp, char* filename, int k){
	char * id, *field1, *field2, *field3;
	int ** array_i;
	int * tmp;
	fp = fopen(filename,"r");
	if(fp != NULL){
		char buffer[100];
		//forse solo k al posto di max_lines, anche nel for a line 48
		array_i = malloc(MAX_LINES * sizeof(int*));
		/*array = malloc(MAX_LINES * sizeof(char*));
		array_d = malloc(MAX_LINES * sizeof(float*));*/
		int i=0;
		printf("### READING INTEGERS FROM FILE ###\n");
		/*Using fgets to hold into buffer from file*/
		for(i=0; i < MAX_LINES; i++){
			//?
			if(fgets(buffer, 100, fp)==NULL) break;
			id = strtok(buffer,",");
			field1 = strtok(NULL, ",");
      			field2 = strtok(NULL, ",");
      			field3 = strtok(NULL, ",");
			array_i[i] = new_int(atoi(field2));
			//array_d[i] = new_float(atof(field3));
			//array[i] = new_string(field1);
			}
	}
	/*chiudiamo il file ed iniziamo a conteggiare quanto tempo ci mette il programma ad elaborare utilizzando
	la clock()*/
	printf("File closed.\n");
	fclose(fp);
	sleep(1);
	start_time = clock();
	//nel metodo sottostante rendiamo l'array_i di tipo generico,k-1 perchè partiamo da indice 0
	//e chiamiamo anche il metodo compare_int_ptr
	insertion_sort((void**) array_i, k-1, compare_int_ptr);
	double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    	printf("\ntest on int array passed in %4.5f seconds\n", elapsed_time);
  //qui ci assicuriamo che l'array sia in ordine
	for(int i=0; i < k-1; i++){
		assert(*array_i[i] <= *array_i[i+1]);
	
	}
	//printf("size of int %d\n",sizeof() );
	for(int i=0; i < k; i++){
		free(array_i[i]);
	}

	free(array_i);
	//free(array);
	//free(array_d);
	array_i = NULL;
}


/*creiamo un array che tratterà il field dei float, memorizziamo il contenuto di field2
separandolo dagli altri con la strtok avendo come token la virgola. Questo dopo aver controllato
se il file non è vuoto*/
void bin_ins_float(FILE * fp, char* filename, int k){
	char * id, *field1, *field2, *field3;
//	char ** array;
//	int ** array_i;
	float ** array_d;
	int * tmp;
	fp = fopen(filename,"r");
	if(fp == NULL)
		perror("Error occured while opening the FILE.\n");
	else{
		char buffer[100];
		//proviamo MAX_LINES al posto di k
		array_d = malloc(MAX_LINES * sizeof(float*));
		
		int field_count = 0;
		int i=0;
		printf("### READING FLOAT FROM FILE ###\n");
		
		while(fgets(buffer, 100, fp) && i < k){
			id = strtok(buffer,",");
			field1 = strtok(NULL, ",");
      			field2 = strtok(NULL, ",");
      			field3 = strtok(NULL, ",");
			array_d[i] = new_float(atof(field3));
			i++;
		}
		printf("File closed.\n");
		fclose(fp);
		sleep(1);
		start_time = clock();
		insertion_sort((void**) array_d, k-1, compare_float_ptr);
		double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    		printf("\ntest on float array passed in %4.5f seconds\n", elapsed_time);
		for(int i=0; i < k-1; i++){
			assert(*array_d[i] <= *array_d[i+1]);
			
	  }
	
		for(int i=0; i < k; i++){
			free(array_d[i]);
		}
		
		free(array_d);
		array_d = NULL;
	}
}
/*creiamo un array che tratterà il field delle strings, memorizziamo il contenuto di field2
separandolo dagli altri con la strtok avendo come token la virgola. Questo dopo aver controllato
se il file non è vuoto*/
void bin_ins_string(FILE * fp, char* filename, int k){
	char * id, *field1, *field2, *field3;
	char ** array;
//	int ** array_i;
//	float ** array_d;
	int * tmp;
	fp = fopen(filename,"r");
	if(fp == NULL)
		perror("Error occured while opening the FILE.\n");
	else{
		char buffer[100];
		array = malloc(MAX_LINES * sizeof(char*));
		int field_count = 0;
		int i=0;
		printf("### READING STRING FROM FILE ###\n");
		/*Using fgets to hold into buffer from file*/
		while(fgets(buffer, 100, fp) && i < k){
			id = strtok(buffer,",");
			field1 = strtok(NULL, ",");
      			field2 = strtok(NULL, ",");
      			field3 = strtok(NULL, ",");
			array[i] = new_string(field1);
			i++;
		}
		printf("File closed.\n");
		fclose(fp);
		sleep(1);
		start_time = clock();
		insertion_sort((void**) array, k-1, compare_string_ptr);
		double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    		printf("\ntest on string array passed in %4.5f seconds\n", elapsed_time);
		for(int i=0; i < k-1; i++){
			assert(*array[i] <= *array[i+1]);
	  }
	
		for(int i=0; i < k; i++){
			free(array[i]);
		}
		
		free(array);
		array = NULL;
	}
}
/*qui creiamo un array che ordinerà da un certo k in poi con l'ordinatore mergesort*/
void merge_int(FILE* fp, char* filename, int k){
	char * id, *field1, *field2, *field3;
//	char ** array;
	int ** array_i;
//	float ** array_d;
	int * tmp;
	fp = fopen(filename,"r");
	if(fp == NULL)
		perror("Error occured while opening the FILE.\n");
	else{
		
		char buffer[100];
		array_i = malloc(MAX_LINES * sizeof(int*));
		
		int field_count = 0;
		int i=0;
		printf("### READING INTEGERS FROM FILE ###\n");
		
		while(fgets(buffer, 100, fp) && i < MAX_LINES){
			id = strtok(buffer,",");
			field1 = strtok(NULL, ",");
      			field2 = strtok(NULL, ",");
      			field3 = strtok(NULL, ",");
			array_i[i] = new_int(atoi(field2));
			i++;
		}
		printf("File closed.\n");
		fclose(fp);

		sleep(1);
		start_time = clock();
		//gli passiamo l'array cast a void
		merge_sort((void**) array_i, MAX_LINES-k+1, compare_int_ptr);
		double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    		printf("\ntest on int array passed in %4.5f seconds\n", elapsed_time);
		
		for(int i=0; i < MAX_LINES; i++){
			free(array_i[i]);
		}
		free(array_i);
		//free(array);
		//free(array_d);
		array_i = NULL;
	     }
		//merge_sort((void**)array_i, k, compare_int_ptr);
}

/* ordiniamo  i float in mergesort*/
void merge_float(FILE* fp, char* filename, int k){
	char * id, *field1, *field2, *field3;
	char ** array;
	int ** array_i;
	float ** array_d;
	int * tmp;
	fp = fopen(filename,"r");
	if(fp == NULL)
		perror("Error occured while opening the FILE.\n");
	else{
		/*Create buffer of 1024 chars*/
		char buffer[100];
		array_d = malloc(MAX_LINES * sizeof(float*));
		/* row_counter && field_counter*/
		int field_count = 0;
		int i=0;
		printf("### READING FLOAT FROM FILE ###\n");
		/*Using fgets to hold into buffer from file*/
		while(fgets(buffer, 100, fp) && i < MAX_LINES){
			id = strtok(buffer,",");
			field1 = strtok(NULL, ",");
      			field2 = strtok(NULL, ",");
      			field3 = strtok(NULL, ",");
			array_d[i] = new_float(atof(field3));
			i++;
		}
		printf("File closed.\n");
		fclose(fp);
		sleep(1);
		start_time = clock();
		//gli passiamo l'array cast a void
		merge_sort((void**) array_d, MAX_LINES-k+1, compare_float_ptr);
		double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    		printf("\ntest on float array passed in %4.5f seconds\n", elapsed_time);
		
		for(int i=0; i < MAX_LINES; i++){
			free(array_d[i]);
		}
		free(array_d);
		array_d = NULL;
	     }
		//merge_sort((void**)array_i, k, compare_int_ptr);
}
/*ordiniamo le stringhe in mergefloat*/
void merge_string(FILE* fp, char* filename, int k){
	char * id, *field1, *field2, *field3;
	char ** array;
	int ** array_i;
	float ** array_d;
	int * tmp;
	fp = fopen(filename,"r");
	if(fp == NULL)
		perror("Error occured while opening the FILE.\n");
	else{
		/*Create buffer of 1024 chars*/
		char buffer[100];
		array = malloc(MAX_LINES * sizeof(char*));
		/* row_counter && field_counter*/
		int field_count = 0;
		int i=0;
		printf("### READING STRINGS FROM FILE ###\n");
		/*Using fgets to hold into buffer from file*/
		while(fgets(buffer, 100, fp) && i < MAX_LINES){
			id = strtok(buffer,",");
			field1 = strtok(NULL, ",");
      			field2 = strtok(NULL, ",");
      			field3 = strtok(NULL, ",");
			array[i] = new_string(field1);
			i++;
		}
		printf("File closed.\n");
		fclose(fp);
		sleep(1);
		start_time = clock();
		//gli passiamo l'array cast a void
		merge_sort((void**) array, MAX_LINES-k+1, compare_string_ptr);
		double elapsed_time = (clock() - start_time)/(double)CLOCKS_PER_SEC;
    		printf("\ntest on string array passed in %4.5f seconds\n", elapsed_time);
		
		for(int i=0; i < MAX_LINES; i++){
			free(array[i]);
		}
		free(array);
		array = NULL;
	     }
		//merge_sort((void**)array_i, k, compare_int_ptr);
}

/*
  compara due elementi castizzandoli ad int, dando un risultato "boolean"
*/
int compare_int_ptr(void* ptr1, void* ptr2){
  int i1 =  *(int*)ptr1;
  int i2 =  *(int*)ptr2;
  if(i1 < i2) {
    return -1;
  }

  if(i1==i2) {
    return 0;
  }

  return 1;
}

/*compara due stringhe sfruttando il metodo strcmp fornito da libreria
*/
int compare_string_ptr(void* ptr1, void* ptr2){
  return strcmp((char*)ptr1, (char*)ptr2);
}


/*compara due elementi castizzandoli a float e dando un risultato "boolean"
*/
int compare_float_ptr(void* ptr1, void* ptr2){
  float i1 =  *(float*)ptr1;
  float i2 =  *(float*)ptr2;
  if(i1<i2) {
    return -1;
  }

  if(i1==i2) {
    return 0;
  }

  return 1;
}


void swap(void** e1, void** e2){
  void* tmp = *e1;
  *e1 = *e2;
  *e2 = tmp;
}

/* abbiamo utilizzato il metodo compare perchè compariamo tipi void, quindi non potevamo 
utilizzare operatori binari classici, il binary search è più efficiente del semplice insertion
ci troviamo gli indici di low, high e mid, compariamo con l'elemento per capire se rispetto ad item
è ordinato  l'array
*/
int binary_search(void** a, void* item, int low, int high, CompFunction compare){
    if(high <= low)
        return (compare(item,a[low]) > 0) ? low + 1 : low;
        
    int mid = (low + high) / 2;
 
    if(compare(item,a[mid]) == 0)
        return mid + 1;
 
    if(compare(item,a[mid]) > 0){
        return binary_search(a, item,mid + 1, high, compare);
    }
    return binary_search(a, item, low, mid - 1, compare);
}
/* insertion_sort method
essendo un tipo di ordiamento binary insertion, chiamiamo il metodo binary search */
void insertion_sort(void** array, int size, CompFunction compare) {
	void* key;
	int i,loc;
  	for(i=1; i < size+1; i++){
    		key = array[i];
    		int j = i - 1;
    		loc = binary_search(array,key,0,i, compare);

        	while(j >= loc)
		{
			array[j + 1] = array[j];
            		j--;	
		}
		array[j+1] = key;
  	}
}


void merge(void** array, int first, int middle, int last, CompFunction compare){
  int dim = last - first + 1;
  int i, j, p;
  void** new_array;
  new_array = malloc(dim*sizeof(void*));
  i = first;
  j = middle + 1;
  p = 0;
  /*se l'elemento i è minore dell'elemento in posizione j, allora mettiamo 
  dentro new array l'elemento in posizione i, altrimenti quello in posizione j*/
  while (i <= middle && j <= last) {
    if (compare(array[i], array[j]) < 0) new_array[p++] = array[i++];
    else new_array[p++] = array[j++];
  }
  while (i <= middle) new_array[p++] = array[i++];
  while (j <= last) new_array[p++] = array[j++];
  for (int h=0; h<dim; h++) {
    swap (&array[first+h], (void**)&new_array[h]);
  }
  free(new_array);
} 

void msort(void** array, int first, int last, CompFunction compare){
  if (first < last) {
  	/*troviamo il punto medio dell'array*/
    int middle = (first + last) / 2;
    /*chiamiamo il metodo per la prima metà*/
    msort(array, first, middle, compare);
    /*chiamiamo il metodo per la seconda metà*/
    msort(array, middle+1, last, compare);
    /*uniamo le due metà ordinate*/
    merge(array, first, middle, last, compare);
  }
}

void merge_sort(void** array, int size, CompFunction compare) {
  msort(array, 0, size-1, compare);
}

void Print(void** array_i, void** array, void** array_f){
	printf("NOW IT CONTAINS...\n");
	int i = 0;
	printf("|\t ID \t|\t STRING \t|\t INTEGER \t|\t FLOAT \t\t|\n");
	while( i < MAX_LINES){
		printf("|\t %d \t|\t %s \t|\t %d \t|\t %f \t\t|\n", i, (char*)array[i], *((int*)array_i[i]), *((float*)array_f[i]));
		i++;	
	}
	printf("-----------------------------------------------------\n");
}

