/**
 * This sample code is used on the slides HeapMemory, 
 * providing examples to explain memory usage. 
 * 
 * @author Albert Lionelle
 * @date 2025.04.09
 */

#include <stdio.h>
#include <stdlib.h>

int* newArray(int size) {
    //int arr_stack[size]; 
    int *arr_heap = (int *) malloc(sizeof(int) * 5);
    for(int i = 0; i < size; i++) {
        arr_heap[i] = (i+1) * 2;
    }
    return arr_heap;
}

void buildPrint(int index) {
    int *arr = newArray(5);
    printf("arr[%d] = %d\n", index, arr[index]);
    free(arr);
}

int main(){
    int index = 0;
    buildPrint(index);
    return 0;
}


