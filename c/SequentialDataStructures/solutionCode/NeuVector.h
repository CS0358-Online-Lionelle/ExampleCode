#ifndef NEU_VECTOR_H
#define NEU_VECTOR_H

#include <stdlib.h>

#define SCALE_FACTOR 2 // Factor by which to increase capacity when needed

typedef struct {
    int *data; // Pointer to the array of integers
    size_t size; // Number of elements in the vector
    size_t capacity; // Capacity of the vector (size of allocated memory)
} NeuVector; // using NewVector, to prevent confusion with system libraries

NeuVector* create_vector(size_t initial_capacity);
void free_vector(NeuVector* vector);
int get_vector_size(NeuVector* vector);
int get_vector_capacity(NeuVector* vector);
int get_vector_element(NeuVector* vector, size_t index);
void set_vector_element(NeuVector* vector, size_t index, int value);
void insert_vector_element(NeuVector* vector, size_t index, int value);
void append_vector_element(NeuVector* vector, int value);
int pop_vector_element(NeuVector* vector);
int remove_vector_element(NeuVector* vector, size_t index);
int contains_element(NeuVector* vector, int value);
void print_vector(NeuVector* vector);
const char* vector_to_string(NeuVector* vector);



#endif // NEU_VECTOR_H