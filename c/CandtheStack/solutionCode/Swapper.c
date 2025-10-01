/**
 * This file demonstrates the use of pointers to swap values in C.
 * 
 * @author Albert Lionelle
 * @date 2024-04-08
 */

#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    printf("Values: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("Swapped values: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}