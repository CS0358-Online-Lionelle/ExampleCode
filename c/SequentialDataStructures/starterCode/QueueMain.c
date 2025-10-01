/**
 * Sample Test file for the Queue implementation.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "NeuQueue.h"

void test_enqueue_dequeue() {
    NeuQueue* queue = create_queue(5); // Create a queue with initial capacity of 5
    printf("Enqueueing elements 0 to 4...\n");
    for (int i = 0; i < 5; i++) {
        enqueue(queue, i);
    }
    print_queue(queue); // Print the queue contents
    const char *actual = queue_to_string(queue);
    if(strcmp(actual, "[0, 1, 2, 3, 4]") == 0) {
        printf("Test passed: Elements enqueued correctly.\n");
    } else {
        printf("Test failed: Elements not enqueued correctly. %s\n", actual);
    }
    free((char *) actual); // Free the string representation

    printf("Dequeuing elements...\n");
    for (int i = 0; i < 3; i++) {
        int value = dequeue(queue);
        printf("Dequeued: %d\n", value);
    }
    actual = queue_to_string(queue);
    print_queue(queue); // Print the queue contents after dequeueing
    if(strcmp(actual, "[3, 4]") == 0) {
        printf("Test passed: Elements dequeued correctly.\n");
    } else {
        printf("Test failed: Elements not dequeued correctly. %s\n", actual);
    }
    free((char *) actual); // Free the string representation 
    
    // enqueue more elements to check wrap around
    printf("Enqueueing elements 5 to 6...\n");
    for (int i = 5; i < 7; i++) {
        enqueue(queue, i);
    }
    actual = queue_to_string(queue);
    print_queue(queue); // Print the queue contents after enqueueing more elements
    if(strcmp(actual, "[3, 4, 5, 6]") == 0) {
        printf("Test passed: Elements enqueued correctly after wrap around.\n");
    } else {
        printf("Test failed: Elements not enqueued correctly after wrap around. %s\n", actual);
    }
    free((char *) actual); // Free the string representation

    // now test actual memory locations, underscores are used when there is nothing in that location
    printf("Showing memory locations...\n");
    print_queue_memory(queue); // Print the memory locations of the queue elements



    free_queue(queue); // Free the queue
}

int main(int argc, char* argv[]) {
    // Check if the user provided a number of elements as a command line argument
    test_enqueue_dequeue(); // Run the test function

    return EXIT_SUCCESS; // Exit successfully
}