/**
 * Solution code for Code Along: Vector
 * 
 * @author Albert Lionelle
 * @date 2025_05_04
 **/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "NeuVector.h"

/**
 * Creates a new vector with the specified initial capacity.
 * 
 * @param initial_capacity The initial capacity of the vector.
 * @return A pointer to the newly created vector, or NULL if memory allocation fails.
 */
NeuVector* create_vector(size_t initial_capacity) {
    NeuVector* vector = (NeuVector*)malloc(sizeof(NeuVector));
    if (vector == NULL) {
        return NULL; // Memory allocation failed
    }
    vector->data = (int*)malloc(initial_capacity * sizeof(int));
    if (vector->data == NULL) {
        free(vector); // Free the vector structure if data allocation fails
        return NULL; // Memory allocation failed
    }
    vector->size = 0; // Initialize size to 0
    vector->capacity = initial_capacity; // Set the initial capacity
    return vector; // Return the newly created vector
}

/**
 * Frees the memory allocated for the vector.
 * 
 * @param vector A pointer to the vector to be freed.
 */
void free_vector(NeuVector* vector) {
    if (vector != NULL) {
        free(vector->data); // Free the data array
        free(vector); // Free the vector structure
    }
}


/**
 * Resizes the vector to the specified new capacity.
 * 
 * @param vector A pointer to the vector to be resized.
 * @param new_capacity The new capacity of the vector.
 */
void __neu_vector_resize(NeuVector* vector, size_t new_capacity) {
    if (new_capacity > vector->capacity) {
        int* new_data = (int*)realloc(vector->data, new_capacity * sizeof(int));
        if (new_data != NULL) {
            vector->data = new_data; // Update the data pointer
            vector->capacity = new_capacity; // Update the capacity
        } else {
            // Handle memory allocation failure
            fprintf(stderr, "Memory allocation failed during resize.\n");
        }
    }
}

/**
 * Appends an element to the end of the vector.
 * 
 * @param vector A pointer to the vector.
 * @param value The value to append.
 * @return 0 if successful, or -1 if memory allocation fails.
 */
void append_vector_element(NeuVector* vector, int value) {
    insert_vector_element(vector, vector->size, value); // Insert at the end
}

/**
 * Finds the first occurrence of a value in the vector.
 * 
 * @param vector A pointer to the vector.
 * @param value The value to find.
 * @return The index of the first occurrence of the value, or -1 if the value is not found.
 */
int contains_element(NeuVector* vector, int value) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (vector->data[i] == value) {
            return i; // Return the index of the first occurrence
        }
    }
    return -1; // not found
}

/**
 * Gets the current capacity of the vector.
 * 
 * @param vector A pointer to the vector.
 * @return The capacity of the vector.
 */
int get_vector_capacity(NeuVector* vector) {
    return vector->capacity; // Return the capacity of the vector
}

/**
 * Gets the element at the specified index in the vector.
 * 
 * @param vector A pointer to the vector.
 * @param index The index of the element to retrieve.
 * @return The value of the element at the specified index.
 */
int get_vector_element(NeuVector* vector, size_t index) {
    if (vector == NULL || vector->size == 0 || vector->data == NULL) {
        fprintf(stderr, "Vector is empty.\n");
        errno = ENODATA;
        return -1; // Vector is empty
    }
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds.\n");
        errno = ERANGE;
        return -1; // Index is out of bounds
    }
    errno = 0; // Clear errno before accessing the vector
    return vector->data[index]; // Return the element at the specified index
}

/**
 * Gets the current size of the vector.
 * 
 * @param vector A pointer to the vector.
 * @return The number of elements in the vector.
 */
int get_vector_size(NeuVector* vector) {
    return vector->size; // Return the size of the vector
}

/**
 * Inserts an element at the specified index in the vector.
 * 
 * @param vector A pointer to the vector.
 * @param index The index at which to insert the element.
 * @param value The value to insert.
 */
void insert_vector_element(NeuVector* vector, size_t index, int value) {
    if (index > vector->size) {
        fprintf(stderr, "Index out of bounds.\n");
        return; // Index is out of bounds
    }
    if (vector->size == vector->capacity) {
        __neu_vector_resize(vector, vector->capacity * SCALE_FACTOR); // Double the capacity if full
    }
    for (size_t i = vector->size; i > index; --i) {
        vector->data[i] = vector->data[i - 1]; // Shift elements to the right
    }
    vector->data[index] = value; // Insert the new element
    vector->size++; // Increase the size of the vector
}

/**
 * Removes and returns the last element of the vector.
 * 
 * @param vector A pointer to the vector.
 * @return The value of the removed element, or -1 if the vector is empty.
 */
int pop_vector_element(NeuVector* vector) {
    return remove_vector_element(vector, vector->size - 1); // Remove the last element
}

/**
 * Prints the elements of the vector to the standard output.
 * 
 * @param vector A pointer to the vector.
 */
void print_vector(NeuVector* vector) {
    printf("Vector: [");
    for(int i = 0; i < vector->size; i++) {
        printf("%d", vector->data[i]);
        if (i < vector->size - 1) {
            printf(", "); // only print comma if not the last element
        }
    }
    printf("]\n");

}

/**
 * Removes the element at the specified index in the vector.
 * 
 * @param vector A pointer to the vector.
 * @param index The index of the element to remove.
 * @return the element removed at index 
 */
int remove_vector_element(NeuVector* vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds.\n");
        errno = ERANGE;
        return -1; // Index is out of bounds
    }
    errno = 0; // Clear errno before accessing the vector
    int data = vector->data[index]; // Store the value to be removed
    for (size_t i = index; i < vector->size - 1; ++i) {
        vector->data[i] = vector->data[i + 1]; // Shift elements to the left
    }
    vector->size--; // Decrease the size of the vector
    return data;
}

/**
 * Sets the element at the specified index in the vector.
 * 
 * @param vector A pointer to the vector.
 * @param index The index of the element to set.
 * @param value The value to set at the specified index.
 */
void set_vector_element(NeuVector* vector, size_t index, int value) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds.\n");
        errno = ERANGE;
        return; // Index is out of bounds
    }
    errno = 0; // Clear errno before accessing the vector
    vector->data[index] = value; // Set the element at the specified index
}


/**
 * Converts the vector to a string representation.
 * 
 * @param vector A pointer to the vector.
 * @return A string representation of the vector.
 */
const char* vector_to_string(NeuVector* vector) {
    if (vector == NULL || vector->size == 0 || vector->data == NULL) {
        return "[]"; // Return empty string if vector is empty
    }
    size_t buffer_size = 3 + (vector->size - 1) * 4; // Estimate buffer size
    char* buffer = (char*)malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        return NULL; // Memory allocation failed
    }
    buffer[0] = '[';
    size_t offset = 1;
    for (size_t i = 0; i < vector->size; ++i) {
        offset += snprintf(buffer + offset, buffer_size - offset, "%d", vector->data[i]);
        if (i < vector->size - 1) {
            offset += snprintf(buffer + offset, buffer_size - offset, ", "); // Add comma and space
        }
        if(offset >= buffer_size) {
            // resize the buffer if needed
            buffer_size *= SCALE_FACTOR;
            buffer = (char*)realloc(buffer, buffer_size * sizeof(char));
            if (buffer == NULL) {
                return NULL; // Memory allocation failed
            }
        }
    }
    buffer[offset] = ']'; // Close the string representation
    buffer[offset + 1] = '\0'; // Null-terminate the string
    return buffer; // Return the string representation of the vector
}