/**
 * Test File for the Singly Linked List (SLL) implementation.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "NeuSinglyLinkedList.h"

int _debug = 0;

void test_push(int num_elements) {
  NeuSLL *list = sll_create();
  clock_t start_time = clock();
  for (int i = 0; i < num_elements; i++) {
    sll_push(list, i);
  }
  clock_t end_time = clock();
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Time taken to push %d elements: %.6f seconds\n", num_elements,
         elapsed_time);

  if (_debug) {
    printf("List after push: ");
    print_sll(list);
  }
  sll_free(list);
}

void test_pop(int num_elements) {
  NeuSLL *list = sll_create();
  for (int i = 0; i < num_elements; i++) {
    sll_push(list, i);
  }
  if (_debug) {
    printf("List before pop: ");
    print_sll(list);
  }
  clock_t start_time = clock();
  for (int i = 0; i < num_elements - 3;
       i++) { // popping all but 3 elements to make sure we can see the list
    sll_pop(list);
  }
  clock_t end_time = clock();
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Time taken to pop %d elements: %.6f seconds\n", num_elements,
         elapsed_time);

  if (_debug) {
    printf("List after pop: ");
    print_sll(list);
  }
  sll_free(list);
}

void test_add_to_end(int num_elements) {
  NeuSLL *list = sll_create();
  for (int i = 0; i < num_elements; i++) {
    sll_push(list, i);
  }
  if (_debug) {
    printf("List before insert: ");
    print_sll(list);
  }
  clock_t start_time = clock();
  for (int i = 0; i < num_elements; i++) {
    insert_sll_element(list, list->size, i);
  }
  clock_t end_time = clock();
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Time taken to insert %d elements: %.6f seconds\n", num_elements,
         elapsed_time);

  if (_debug) {
    printf("List after insert: ");
    print_sll(list);
  }
  sll_free(list);
}

void test_remove_from_end(int num_elements) {
  NeuSLL *list = sll_create();
  for (int i = 0; i < num_elements; i++) {
    sll_push(list, i);
  }
  if (_debug) {
    printf("List before remove: ");
    print_sll(list);
  }
  clock_t start_time = clock();
  for (int i = 0; i < num_elements - 3;
       i++) { // removing all but 3 elements to make sure we can see the list
    remove_sll_element(list, list->size - 1);
  }
  clock_t end_time = clock();
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Time taken to remove %d elements: %.6f seconds\n", num_elements,
         elapsed_time);

  if (_debug) {
    printf("List after remove: ");
    print_sll(list);
  }
  sll_free(list);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <number of elements>\n", argv[0]);
    return EXIT_FAILURE;
  }
  int num_elements = atoi(argv[1]);
  if (argc > 2) {
    _debug = atoi(argv[2]);
  }

  test_push(num_elements);
  test_pop(num_elements);
  test_add_to_end(num_elements);
  test_remove_from_end(num_elements);
}