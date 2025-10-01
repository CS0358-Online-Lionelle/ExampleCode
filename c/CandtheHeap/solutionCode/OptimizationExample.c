/**
 * Solution file for Code Along Optimization Example. 
 * 
 * This code is based off the code provided in:
 * https://diveintosystems.org/book/C12-CodeOpt/basic.html
 * 
 * 
 * @author Albert Lionelle
 * @date 2025.04.10
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool isPrime(int x) {
    if (x <= 1) return false;
    int max = sqrt(x)+1; // remove the calculation from the loop
    for (int i = 2; i < max; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int *getPrimes(int size) {
    int *arr = (int *)malloc(sizeof(int) * size);
    int count = 0;
    for (int i = 2; count < size; i++) {
        if (isPrime(i)) {
            arr[count] = i;
            count++;
        }
    }
    return arr;
}

void runTest(int size, bool print) {
    int *arr = getPrimes(size);
    if (print) {
        printArray(arr, size);
    }
    free(arr);
}

int timeFunction(void (*func)(int, bool), int arg, bool print) {
    clock_t start = clock();
    func(arg, print);
    clock_t end = clock();
    return (int)(end - start);
}

void printClockTimeInSeconds(int timeTaken) {
    if (timeTaken > CLOCKS_PER_SEC * 60) {
        int minutes = timeTaken / (CLOCKS_PER_SEC * 60);
        int seconds = (timeTaken % (CLOCKS_PER_SEC * 60)) / CLOCKS_PER_SEC;
        printf("Time taken: %d minutes and %d seconds\n", minutes, seconds);
    } else {
        printf("Time taken: %.2f seconds\n", (double)timeTaken / CLOCKS_PER_SEC);
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }
    int size = atoi(argv[1]);
    bool print = true;
    if (size < 0) {
        printf("Size must be a positive integer.\n");
        return 1;
    }
    if (size > 1000) {
        print = false;
    }
    // Example of timing a function
    int timeTaken = timeFunction(runTest, size, print);
    
    printClockTimeInSeconds(timeTaken);


    return 0;
}