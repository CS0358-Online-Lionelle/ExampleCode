/**
 * Test code to test the NeuVector functions. 
 * 
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include <locale.h>
 
 #include "NeuVector.h"

void add_elements(NeuVector* vector, int start, int end) {
    for (int i = start; i < end; i++) {
        append_vector_element(vector, i);
    }
}


void test_add_elements() {
    NeuVector* vector = create_vector(5); // Create a vector with initial capacity of 5
    printf("Adding elements 0 to 9...\n");
    add_elements(vector, 0, 10);
    const char *actual = vector_to_string(vector);
    if(strcmp(actual, "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]") == 0) {
        printf("Test passed: Elements added correctly.\n");
    } else {
        printf("Test failed: Elements not added correctly. %s\n", actual);
    }
    free((char *) actual); // Free the string representation
    free_vector(vector); // Free the vector
}

void test_remove_elements() {
    NeuVector* vector = create_vector(5); // Create a vector with initial capacity of 5
    printf("Adding elements 0 to 9...\n");
    add_elements(vector, 0, 10);
    printf("Removing elements...\n");
    int removed_element = remove_vector_element(vector, 3);
    if (removed_element == 3 && vector->size == 9) {
        printf("Test passed: Element removed correctly.\n");
    } else {
        printf("Test failed: Element not removed correctly.\n");
    }
    free_vector(vector); // Free the vector
}

void test_pop_elements() {
    NeuVector* vector = create_vector(5); // Create a vector with initial capacity of 5
    printf("Adding elements 0 to 9...\n");
    add_elements(vector, 0, 10);
    printf("Popping element...\n");
    int popped_element = pop_vector_element(vector);
    if (popped_element == 9 && vector->size == 9) {
        printf("Test passed: Element popped correctly.\n");
    } else {
        printf("Test failed: Element not popped correctly.\n");
    }
    free_vector(vector); // Free the vector
}

void test_insert_elements() {
    NeuVector* vector = create_vector(5); // Create a vector with initial capacity of 5
    printf("Adding elements 0 to 9...\n");
    add_elements(vector, 0, 10);
    printf("Inserting element at index 3...\n");
    insert_vector_element(vector, 3, 99);
    if (vector->data[3] == 99 && vector->size == 11) {
        printf("Test passed: Element inserted correctly.\n");
    } else {
        printf("Test failed: Element not inserted correctly.\n");
    }
    free_vector(vector); // Free the vector
}

void test_push_elements() {
    NeuVector* vector = create_vector(5); // Create a vector with initial capacity of 5
    printf("Adding elements 0 to 9...\n");
    add_elements(vector, 0, 10);
    printf("Pushing element...\n");
    int pushed_element = 100;
    append_vector_element(vector, pushed_element);
    if (vector->data[vector->size - 1] == pushed_element && vector->size == 11) {
        printf("Test passed: Element pushed correctly.\n");
    } else {
        printf("Test failed: Element not pushed correctly.\n");
    }
    free_vector(vector); // Free the vector
}

void speed_test_add(int num_elements) {
    NeuVector* vector = create_vector(5); // Create a vector with initial capacity of 5
 
    printf("Speed test: Adding %'d elements...\n", num_elements);
    // add clock to measure time taken
    clock_t start_time = clock(); // Start the timer
    for (int i = 0; i < num_elements; i++) {
        append_vector_element(vector, i);
    }
    clock_t end_time = clock(); // End the timer
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate time taken
    printf("Time taken to add %d elements: %.8f seconds\n", num_elements, time_taken);
    printf("Vector size after adding: %'ld\n", vector->size); // Print the size of the vector
    printf("Vector capacity after adding: %'ld\n", vector->capacity); // Print the capacity of the vector
    free_vector(vector); // Free the vector
}

int main(int argc, char* argv[]) {
    if(argc > 1) {
        if (setlocale(LC_NUMERIC, "C.utf8") == NULL) {
            printf("Failed to set default locale\n");
        }
        int num_elements = atoi(argv[1]); // Convert argument to integer
        speed_test_add(num_elements); // Run speed test with specified number of elements
        return EXIT_SUCCESS; // Exit after speed test
    } // else run other tests
    
    /*
    test_add_elements(); // Test adding elements
    test_insert_elements(); // Test inserting elements
    
    test_remove_elements(); // Test removing elements
    test_pop_elements(); // Test popping elements
    test_push_elements(); // Test pushing elements
    */
    return EXIT_SUCCESS;
    
}