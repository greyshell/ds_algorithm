/*
 * author: greyshell
 * description: stack using singly linked list, datatype -> void pointer
 * */

#ifndef STACK_SLL_H__
#define STACK_SLL_H__

#include "stdbool.h"

typedef struct my_node {
    void *data;
    struct my_node *next;
} linkedlist_node;

typedef struct my_stack {
    linkedlist_node *top;
    size_t size;
} stack;

void initialize_stack(stack *);

bool is_empty_stack(stack *);

size_t get_stack_size(stack *);

bool push(stack *, void *);

bool pop(stack *, void **);

bool peek(stack *, void **);

bool delete_stack(stack *);

void display_stack(stack *);

#endif // STACK_SLL_H__