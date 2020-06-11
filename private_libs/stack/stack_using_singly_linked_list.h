/*
 * author: greyshell
 * description: stack using singly linked list, data -> int
 * */

#ifndef STACK_USING_SINGLY_LINKED_LIST_H__
#define STACK_USING_SINGLY_LINKED_LIST_H__

#include "stdbool.h"

typedef struct my_node {
    int data;
    struct my_node *next;
} linkedlist_node;

typedef struct my_stack {
    linkedlist_node *top;
} stack;

void initialize_stack(stack *);

bool is_empty_stack(stack *);

size_t get_stack_size(stack *);

bool push(stack *, int);

bool pop(stack *, int *);

bool peek(stack *, int *);

bool delete_stack(stack *);

// auxiliary operations

void display_stack(stack *);

#endif // STACK_USING_SINGLY_LINKED_LIST_H__