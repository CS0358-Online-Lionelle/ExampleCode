/**
 * Solution for Code Along Bubble Sort
 *
 * @author Albert Lionelle
 * @date 2025-04-18
 */

#include <stdio.h>
#include <stdlib.h>

#include "SortUtils.h"

// global to track swaps
long int _bs_opCount = 0;
long int _is_opCount = 0; // global to track swaps for insertion sort
long int _ss_opCount = 0; // global to track swaps for selection sort

// function to swap two elements in an array

void bubbleSort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    _bs_opCount++;
    int swapped = 0; // flag to check if any swaps were made
    for (int j = 0; j < size - i - 1; j++) {
      _bs_opCount++;
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        _bs_opCount++;
        swapped = 1;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

// function to perform insertion sort on an array
void insertionSort(int *arr, int size) {

}

// function to perform selection sort on an array
void selectionSort(int *arr, int size) {
}

void runSorts(int *bArr, int *iArr, int *sArr, int size) {
  _bs_opCount = 0; // reset the operation count for the next iteration
  _is_opCount = 0; // reset the operation count for the next iteration
  _ss_opCount = 0; // reset the operation count for the next iteration

  double bTimeTaken = clockToSeconds(timeFunction(bubbleSort, bArr, size));

  double iTimeTaken = clockToSeconds(timeFunction(insertionSort, iArr, size));

  double sTimeTaken = clockToSeconds(timeFunction(selectionSort, sArr, size));

  printf("%d,%.8f,%.8f,%.8f,,%d,%ld,%ld,%ld\n", size, bTimeTaken, iTimeTaken,
         sTimeTaken, size, _bs_opCount, _is_opCount, _ss_opCount);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL)); // see randomize function in SortUtils.h
  if (argc < 2) {
    printf("Usage: %s <size>\n", argv[0]);
    return 1;
  }
  int size = atoi(argv[1]);
  int step = 1;
  if (argc > 2) {
    step = atoi(argv[2]);
  }
  int arrayInit = 0;
  if (argc > 3) {
    arrayInit = atoi(argv[3]);
  }

  int arr_bubble[size];
  int arr_insertion[size];
  int arr_selection[size];

  printf("Size,BubbleSort,InsertionSort,SelectionSort,spacer,size,BS_OpCount,IS_OpCount,SS_"
         "OpCount\n");
  for (int i = 1; i < size; i = i + step) {
    if (arrayInit == 1) {
      initializeSortedArray(arr_bubble, i);    // build a sorted array
      initializeSortedArray(arr_insertion, i); // build a sorted array
      initializeSortedArray(arr_selection, i); // build a sorted array
    } else if (arrayInit == 2) {
      initializeReverseSortedArray(arr_bubble,
                                   i); // build a reverse sorted array
      initializeReverseSortedArray(arr_insertion,
                                   i); // build a reverse sorted array
      initializeReverseSortedArray(arr_selection,
                                   i); // build a reverse sorted array
    } else {
      initializeRandomArray(arr_bubble, i);    // build a random array
      initializeRandomArray(arr_insertion, i); // build a random array
      initializeRandomArray(arr_selection, i); // build a random array
    }

    runSorts(arr_bubble, arr_insertion, arr_selection, i);
  }

  return 0;
}
