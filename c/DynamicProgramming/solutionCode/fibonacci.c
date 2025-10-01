/**
 * Solution to code along for fibonacci sequence using memoization.
 *
 *
 * @author Albert Lionelle
 * @date   2025-04-23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#include "DPUtils.h"

enum { FIBO_RECURSIVE = 2, FIBO_MEMOIZATION = 1, FIBO_BOTH = FIBO_RECURSIVE | FIBO_MEMOIZATION };

uint64_t fibonacci_recursive(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

uint64_t fibonacci_memoization(int n, uint64_t *memo) {
  if (n <= 1) {
    memo[n] = n; // Store the base case in memo array
  }
  if (memo[n] != 0 || n == 0) {
    return memo[n];
  }
  memo[n] =
      fibonacci_memoization(n - 1, memo) + fibonacci_memoization(n - 2, memo);
  return memo[n];
}

int time_fibonacci_recursive(int n) {
  clock_t start = clock();
  uint64_t result = fibonacci_recursive(n);
  clock_t end = clock();
  printf("Fibonacci(%d) = %ld\n", n, result);
  return (int)(end - start);
}

int time_fibonacci_memoization(int n) {
  uint64_t *memo = (uint64_t *)malloc((n + 1) * sizeof(uint64_t));
  memset(memo, 0, (n + 1) * sizeof(int)); // Initialize memo array to 0
  clock_t start = clock();
  uint64_t result = fibonacci_memoization(n, memo);
  clock_t end = clock();
  printf("Fibonacci(%d) = %ld\n", n, result);
  free(memo); // Free the allocated memory for memo array
  return (int)(end - start);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <n>\n", argv[0]);
    return 1;
  }
  int n = atoi(argv[1]);
  if (n < 0) {
    printf("Error: n must be a non-negative integer.\n");
    return 1;
  }

  int fibType = FIBO_BOTH; // Default to both methods
  if (argc > 2) {
    fibType = atoi(argv[2]);
    if (fibType < FIBO_MEMOIZATION || fibType > FIBO_BOTH) {
      printf("Error: Invalid Fibonacci type. Use 1 for memoization, 2 for "
             "recursive, or 3 for both.\n");
      return 1;
    }
  }

  if ((fibType & FIBO_RECURSIVE) == FIBO_RECURSIVE) {
    int time_recursive = time_fibonacci_recursive(n);
    printf("Time taken for Fibonacci Recursive: ");
    printTimeTaken(time_recursive);
  }
  if ((fibType & FIBO_MEMOIZATION) == FIBO_MEMOIZATION) {
    int time_memoization = time_fibonacci_memoization(n);

    printf("Time taken for Fibonacci Memoization: ");
    printTimeTaken(time_memoization);
  }
  return 0;
}