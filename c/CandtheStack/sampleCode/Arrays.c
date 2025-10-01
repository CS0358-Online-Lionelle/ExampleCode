/**
 * Example using simple array declaration. 
 * 
 * @author Albert Lionelle
 */
#include <stdio.h>


void printMatrix(int* matrix, int width, int height) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++){
            printf("%3d ", matrix[i * width + j]);
        }
        printf("\n");
    }
}

void matrixExample() {
    int matrix[3][3];
    int counter = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            matrix[i][j] = counter++;
        }
    }
    printMatrix((int*)matrix, 3, 3);

    int matrix2[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printMatrix((int*)matrix2, 4, 3);
}



void forLoopExample() {
    int evens[100];

    for(int i = 0; i < 100; i++) {
        evens[i] = i * 2;
    }
    for(int i = 0; i < 100; i++) {
        printf("%d ", evens[i]);
    }
    printf("\n");
}

void printArray(int* array, int size) {
    for(int i = 0; i < size; i++) { 
        printf("Value %d, pointer %p\n", array[i], (void*)&array[i]);
    } 
}

int main() {
    int points[2] = {10, 20};
    printf("Point 0: %d\n", points[0]);
    printf("Point 1: %d\n", points[1]);

    printArray(points, 2);

    int* pointers = points;
    for(int i =0; i < 2; i++) {
        printf("Points value %d, points pointer %p\n", *(pointers+i), (void*)(pointers+i));
    }

    // int points2[2];
    // points2[0] = 10;
    // points2[1] = 20;

    forLoopExample();
    matrixExample();

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // ptr now points to the first element of arr

    printArray(ptr, 5);
    printArray(arr, 5);
}