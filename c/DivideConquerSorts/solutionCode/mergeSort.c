/**
 * Solution to merge sort code along.
 *
 *
 * @author Albert Lionelle
 * @date 2025-04-21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SortUtils.h"

// global to track swaps
long int _ms_opCount = 0; // global to track swaps for merge sort

int _DEBUG = 0; // debug flag

/** Pseudo Code
 *
```
Algorithm MergeSort(A)
    Input: List A of 𝑛 elements
    Output: Mutates sorted array (A) ascending order
    Initialize:
        left = 0
        right = length(A)-1
    MergeSort(A, left, right)


def MergeSort(A, left, right):
    if left < right:
        mid = left + (right-left) // 2
        MergeSort(A, left, mid)
        MergeSort(A, mid+1, right)
        Merge(A, left, mid, right)

def Merge(A, left, mid, right):
    n1 = mid – left + 1
    n2 = right - mid
    L = [0..n1], R = [0..n2]
    # copy data to tmp arrays
    for i = 0 to n1:
        L[i] = A[left + i]
    for j = 0 to n2:
        R[j] = A[mid + 1 + j]
    # merge tmp back into A
    i = 0, j = 0, k = left
    while i < n1 and j < n2:
        if L[i] <= R[j]
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
                j = j + 1
                k = k + 1
    # copy remaining L[]
    while i < n1:
        A[k] = L[i]
        i = i + 1
        k = k + 1
    # copy remaining R[]
    while j < n2:
        A[k] = R[j]
        j = j + 1
        k = k + 1
```
 *
 */

void merge(int *arr, int left, int mid, int right, int *swapMemory) {

  int n1 = mid - left + 1; // size of left subarray
  int n2 = right - mid;    // size of right subarray

  if (_DEBUG) {
    printf("L: ");
    printArray(arr + left, n1); // print the array before sorting
    printf("R: ");
    printArray(arr + mid + 1, n2); // print the array before sorting
  }
  // use pointers to use swapMemory as temporary arrays
  int *L = swapMemory;      // left subarray
  int *R = swapMemory + n1; // right subarray
  // copy data to temp arrays L[] and R[]
  memcpy(L, arr + left, sizeof(int) * n1);
  memcpy(R, arr + mid + 1, sizeof(int) * n2);

  // for (int i = 0; i < n1; i++) {
  //     L[i] = arr[left + i]; // copy left subarray
  // }
  // for (int j = 0; j < n2; j++) {
  //     R[j] = arr[mid + 1 + j]; // copy right subarray
  // }

  // merge the temp arrays back into arr[left..right]
  int i = 0;    // initial index of first subarray
  int j = 0;    // initial index of second subarray
  int k = left; // initial index of merged subarray
  while (i < n1 && j < n2) {
    _ms_opCount++; // operation count
    if (L[i] <= R[j]) {
      arr[k] = L[i]; // copy from left subarray
      i++;
    } else {
      arr[k] = R[j]; // copy from right subarray
      j++;
    }
    k++;
  }
  // copy the remaining elements of L[], if there are any
  while (i < n1) {
    arr[k] = L[i]; // copy remaining left subarray
    i++;
    k++;
    _ms_opCount++; // operation count
  }
  // copy the remaining elements of R[], if there are any
  while (j < n2) {
    arr[k] = R[j]; // copy remaining right subarray
    j++;
    k++;
    _ms_opCount++; // operation count
  }
}

void mergeSort(int *arr, int left, int right, int *swapMemory) {
  if (left < right) {
    int mid = left + (right - left) / 2;              // find the middle point
    mergeSort(arr, left, mid, swapMemory);      // sort first half
    mergeSort(arr, mid + 1, right, swapMemory); // sort second half
    merge(arr, left, mid, right, swapMemory);   // merge the sorted halves
  }
}

void runMergeSort(int *arr, int size) {
  int swapMemory[size];
  mergeSort(arr,  0, size - 1, swapMemory); // call the merge sort function
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  if (argc < 2) {
    printf("Usage: %s <size>\n", argv[0]);
    return 1;
  }
  if (argc > 2) {
    _DEBUG = atoi(argv[2]); // set debug flag
  }
  int size = atoi(argv[1]);
  int arr[size];

  initializeRandomArray(arr, size); // initialize the array with random values

  if (size < 20) {
    printf("Before sorting:\n");
    printArray(arr, size); // print the array before sorting
  }
  int clockcounter =
      timeFunction(runMergeSort, arr, size); // call the merge sort function

  if (size < 20) {
    printf("After sorting:\n");
    printArray(arr, size); // print the array after sorting
  }

  printf("Number of operations: %ld\n",
         _ms_opCount);          // print the number of operations
  printTimeTaken(clockcounter); // print the time taken to sort the array

  return 0;
}
