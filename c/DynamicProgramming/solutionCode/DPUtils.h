#ifndef DPUTILS_H
#define DPUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Converts a clock count to seconds.
 *
 * @param clock The clock ticks to convert.
 *              This is typically the result of a call to clock().
 * @return The time in seconds.
 */
double clockToSeconds(clock_t clock) { return (double)clock / CLOCKS_PER_SEC; }

/**
 * Prints an array of integers.
 */
void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/**
 * Prints a matrix of integers.
 * The matrix is represented as a 1D array.
 */
void printMatrix(int *arr, int width, int hight) {
  for (int i = 0; i < hight; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", arr[i * width + j]);
    }
    printf("\n");
  }
}

/**
 * Takes a clock count and converts it into human-readable time.
 * If the time is greater than 1 minute, it will print in minutes and seconds.
 *
 * @param clockTicks The clock ticks to convert.
 *                   This is typically the result of a call to clock().
 */
void printTimeTaken(int clockTicks) {
  if (clockTicks > CLOCKS_PER_SEC * 60) {
    int minutes = clockTicks / (CLOCKS_PER_SEC * 60);
    int seconds = (clockTicks % (CLOCKS_PER_SEC * 60)) / CLOCKS_PER_SEC;
    printf("Time taken: %d minutes and %d seconds\n", minutes, seconds);
  } else {
    printf("Time taken: %.8f seconds\n", clockToSeconds(clockTicks));
  }
}

#endif // DPUTILS_H