/**
 * Demo Template for the Live Demo
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SortUtils.h"

// global to track swaps
long int _ms_opCount = 0; // global to track swaps for merge sort
long int _qs_opCount = 0;

int * _swapMemory;

int _DEBUG = 0; // debug flag

void merge(int *arr, int left, int mid, int right, int *swapMemory) {

}

void mergeSort(int *arr, int left, int right, int *swapMemory) {
 
}

void runMergeSort(int *arr, int size) {
  
}

int partition(int *arr, int left, int right) {
 
}

void quickSort(int *arr, int left, int right) {
  
}

void runQuickSort(int *arr, int size) {
  
}

void runSorts(int *mArr, int *qArr, int size) {
  _ms_opCount = 0; // reset the operation count for the next iteration
  _qs_opCount = 0; // reset the operation count for the next iteration

  double mTimeTaken = clockToSeconds(timeFunction(runMergeSort, mArr, size));

  double qTimeTaken = clockToSeconds(timeFunction(runQuickSort, qArr, size));

  printf("%d,%.8f,%.8f,,%d,%ld,%ld\n", size, mTimeTaken, qTimeTaken, size,
         _ms_opCount, _qs_opCount);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL)); // see randomize function in SortUtils.h
  if (argc < 2) {
    printf("Usage: %s <size>\n", argv[0]);
    return 1;
  }
  int size = atoi(argv[1])+1;
  int step = 1;
  if (argc > 2) { // step count
    step = atoi(argv[2]);
  }
  size = size + (size % step); // make sure size is a multiple of step
  int arrayInit = 0;
  if (argc > 3) { // array type (sorted, reversed, random)
    arrayInit = atoi(argv[3]);
  }
  if(argc > 4) { // debug flag
    _DEBUG = atoi(argv[4]);
  }

  int *arr_merge = malloc(sizeof(int) * size); // allocate memory for the array
  int *arr_quick = malloc(sizeof(int) * size); // allocate memory for the array
  _swapMemory = malloc(sizeof(int) * size); // allocate memory for the array
  if (arr_merge == NULL || arr_quick == NULL || _swapMemory == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  printf("Size,MergeSort,QuickSort,spacer,size,MS_OpCount,QS_OpCount\n");
  for (int i = 1; i < size; i = i + step) {
    if (arrayInit == 1) {
      initializeSortedArray(arr_merge, i); // build a sorted array
    } else if (arrayInit == 2) {
      initializeReverseSortedArray(arr_merge,
                                   i); // build a reverse sorted array
    } else {
      initializeRandomArray(arr_merge, i); // build a random array
    }

    //memcpy(arr_quick, arr_merge, sizeof(int) * i); // copy
    for(int j = 0 ; j < i; j++){
      arr_quick[j] = arr_merge[j]; // copy the array
    }
    if (_DEBUG) {
      printf("Before sorting:\n");
      printArray(arr_merge, i); // print the array before sorting
    }
    if (_DEBUG) {
      printf("Before sorting:\n");
      printArray(arr_quick, i); // print the array before sorting
    }

    runSorts(arr_merge, arr_quick, i);
  }

  free(arr_merge);   // free the memory allocated for the array
  free(arr_quick);  // free the memory allocated for the array
  free(_swapMemory); // free the memory allocated for the array
  return 0;
}
