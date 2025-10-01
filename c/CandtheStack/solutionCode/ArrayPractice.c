/**
 * The code along demonstrates the use of arrays in C programming.
 * This program will showcase various array operations such as initialization,
 * accessing elements, and iterating through the array.
 *
 * @author Albert Lionelle
 * @date 2024-04-08
 */

#include <stdio.h>
#include <stdlib.h>

int getSum(int *numbers, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += numbers[i]; //*(numbers + i);
  }

  return sum;
}

void arraysFunctions() {
  int numbers[5] = {1, 2, 3, 4, 5};
  int sum = getSum(numbers, 5);

  printf("Sum of the elements is %d", sum);
  printf("\n");
}

void arraysLoops() {
  int numbers[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    printf("numbers[%d] = %d (%p)\n", i, numbers[i], (void *)&numbers[i]);
  }
  printf("\n");

  char names[3][20] = {"Alice", "Bob", "Charlie"};
  for (int i = 0; i < 3; i++) {
    printf("names[%d] = %s\n", i, names[i]);
  }
  printf("\n");

  int evens[100];

  for (int i = 0; i < 100; i++) {
    printf("evens[%d] = %d\n", i, evens[i]);
  }
  printf("\n");
  for (int i = 0; i < 100; i++) {
    evens[i] = i * 2;
  }
  for (int i = 0; i < 100; i++) {
    printf("evens[%d] = %d\n", i, evens[i]);
  }
  printf("\n");
}

int main() {
  arraysLoops();
  arraysFunctions();
}