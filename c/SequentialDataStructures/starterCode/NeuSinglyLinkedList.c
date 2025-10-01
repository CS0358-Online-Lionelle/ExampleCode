/**
 * Starter code for Code Along: Singly Linked List
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "NeuSinglyLinkedList.h"

/**
 * Function to create a new node
 *
 * @param value The value to store in the node.
 * @return A pointer to the newly created node, or NULL if memory allocation
 * fails.
 */
Node *__sll_create_node(int value) {
  return NULL; // TODO: Implement this function
}

/**
 * Function to free a node
 *
 * @param node A pointer to the node to be freed.
 */
void __sll_free_node(Node *node) {
  // TODO: Implement this function
}

/**
 * Creates a new singly linked list.
 *
 * @return A pointer to the newly created list, or NULL if memory allocation
 * fails.
 */
NeuSLL *sll_create() {
  // TODO: Implement this function
  return NULL;
}

/**
 * Frees the memory allocated for the singly linked list.
 *
 * @param list A pointer to the list to be freed.
 */
void sll_free(NeuSLL *list) {
  // TODO: Implement this function
}

/**
 * Gets the node at the specified index in the singly linked list.
 *
 * @param list A pointer to the list.
 * @param index The index of the node to retrieve.
 * @return A pointer to the node at the specified index, or NULL if the index is
 * out of bounds.
 */
Node *__sll_get_node(NeuSLL *list, size_t index) {
  // TODO: Implement this function
  return NULL;
}

/**
 * Gets the element at the specified index in the singly linked list.
 *
 * @param list A pointer to the list.
 * @param index The index of the element to retrieve.
 * @return The value of the element at the specified index, or -1 if the index
 * is out of bounds.
 */
int get_sll_element(NeuSLL *list, size_t index) {
  // TODO: Implement this function
  return -1;
}

/**
 * Inserts an element at the specified index in the singly linked list.
 *
 * @param list A pointer to the list.
 * @param index The index at which to insert the element.
 * @param value The value to insert.
 */
void insert_sll_element(NeuSLL *list, size_t index, int value) {
  // TODO: Implement this function
}

/**
 * Checks if the singly linked list is empty.
 *
 * @param list A pointer to the list.
 * @return true if the list is empty, false otherwise.
 */
bool is_sll_empty(NeuSLL *list) {
  // TODO: Implement this function
  return true;
}

/**
 * Removes the element at the specified index in the singly linked list.
 *
 * @param list A pointer to the list.
 * @param index The index of the element to remove.
 * @return The value of the removed element, or -1 if the index is out of bounds.
 */
int remove_sll_element(NeuSLL *list, size_t index) {
  // TODO: Implement this function
  return -1;
}

/**
 * Gets the size of the singly linked list.
 *
 * @param list A pointer to the list.
 * @return The number of elements in the list.
 */
size_t get_sll_size(NeuSLL *list) {
  // TODO: Implement this function
  return 0;
}

/**
 * Pops the last element from the singly linked list.
 *
 * @param list A pointer to the list.
 * @return The value of the popped element, or -1 if the list is empty.
 */
int sll_pop(NeuSLL *list) {
  // TODO: Implement this function
  return -1;
}

/**
 * Pushes an element to the front of the singly linked list.
 *
 * @param list A pointer to the list.
 * @param value The value to push.
 */
void sll_push(NeuSLL *list, int value) {
  // TODO: Implement this function
}

/**
 * Sets the element at the specified index in the singly linked list.
 *
 * @param list A pointer to the list.
 * @param index The index of the element to set.
 * @param value The value to set at the specified index.
 */
void set_sll_element(NeuSLL *list, size_t index, int value) {
  // TODO: Implement this function
}

/**
 * Prints the elements of the singly linked list to the standard output.
 *
 * @param list A pointer to the list.
 */
void print_sll(NeuSLL *list) {
  if (list == NULL || list->head == NULL) {
    printf("[]\n");
    return;
  }

  printf("[");
  Node *current = list->head;
  while (current != NULL) {
    printf("%d", current->data);
    if (current->next != NULL) {
      printf(", ");
    }
    current = current->next;
  }
  printf("]\n");
}

/**
 * Converts the singly linked list to a string representation.
 *
 * @param list A pointer to the list.
 * @return A string representation of the list, or NULL if memory allocation
 * fails.
 */
const char *sll_to_string(NeuSLL *list) {
  if (list == NULL || list->head == NULL) {
    return strdup("[]");
  }

  size_t buffer_size = 64; // Initial buffer size
  char *buffer = (char *)malloc(buffer_size * sizeof(char));
  if (buffer == NULL) {
    return NULL; // Memory allocation failed
  }

  strcpy(buffer, "["); // Start the string with an opening bracket

  Node *current = list->head;
  while (current != NULL) {
    char temp[16]; // Temporary buffer to hold the string representation of the
                   // current node's data
    sprintf(temp, "%d", current->data); // Convert the integer to a string
    strcat(buffer,
           temp); // Append the string representation of the current node's data

    if (current->next != NULL) {
      strcat(buffer,
             ", "); // Append a comma and space if there are more elements
    }

    // Check if the buffer needs to be resized
    if (strlen(buffer) + 16 >= buffer_size) {
      buffer_size *= 2;
      buffer = (char *)realloc(buffer, buffer_size * sizeof(char));
      if (buffer == NULL) {
        return NULL; // Memory allocation failed
      }
    }

    current = current->next;
  }

  strcat(buffer, "]"); // Close the string with a closing bracket
  return buffer;
}