#ifndef NEU_QUEUE_H
#define NEU_QUEUE_H

// Standard includes
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>

// circular queue implementation
typedef struct {
    int* data; // Pointer to the array of elements in the queue
    size_t front; // Index of the front element in the queue
    size_t end;  // Index of the rear element in the queue
    size_t size;  // Number of elements in the queue
    size_t capacity; // Capacity of the queue (size of allocated memory)
} NeuQueue;


NeuQueue* create_queue(size_t initial_capacity); // Function to create a new queue with the specified initial capacity
void free_queue(NeuQueue* queue); // Function to free the memory allocated for the queue
int get_queue_size(NeuQueue* queue); // Function to get the current size of the queue
int get_queue_capacity(NeuQueue* queue); // Function to get the current capacity of the queue
int peek_queue(NeuQueue* queue); // Function to get the front element of the queue without removing it
int dequeue(NeuQueue* queue); // Function to remove and return the front element of the queue
bool enqueue(NeuQueue* queue, int value); // Function to add an element to the end of the queue
bool is_queue_empty(NeuQueue* queue); // Function to check if the queue is empty
bool is_queue_full(NeuQueue* queue); // Function to check if the queue is full
void print_queue(NeuQueue* queue); // Function to print the elements of the queue
void print_queue_memory(NeuQueue *queue); // Function to print the memory locations of the queue elements
const char* queue_to_string(NeuQueue* queue); // Function to convert the queue to a string representation


#endif // NEU_QUEUE_H