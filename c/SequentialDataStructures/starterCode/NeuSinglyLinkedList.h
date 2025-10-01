#ifndef NEU_SINGLY_LINKED_LIST_H
#define NEU_SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    size_t size;
} NeuSLL;

NeuSLL *sll_create();
void sll_free(NeuSLL *list);

void sll_push(NeuSLL *list, int value);
int sll_pop(NeuSLL *list);
int get_sll_element(NeuSLL *list, size_t index);
void set_sll_element(NeuSLL *list, size_t index, int value);
void insert_sll_element(NeuSLL *list, size_t index, int value);
int remove_sll_element(NeuSLL *list, size_t index);
size_t get_sll_size(NeuSLL *list);
bool is_sll_empty(NeuSLL *list);
void print_sll(NeuSLL *list);
const char *sll_to_string(NeuSLL *list);





#endif // NEU_SINGLY_LINKED_LIST_H