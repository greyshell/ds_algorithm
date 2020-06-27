/*
 * author: greyshell
 * description: singly linked list based implementation of stack
 * data / key -> void pointer
 * */

#ifndef STACK_SLL_H__
#define STACK_SLL_H__

#include "stdbool.h"

typedef void view_stack_func(void *);

typedef struct list {
    void *data;
    struct list *next;
} stack_node;

typedef struct {
    stack_node *top;
    size_t size;
} stack;

void initialize_stack(stack *);

bool is_empty_stack(stack *);

size_t get_stack_size(stack *);

bool push(stack *, void *);

bool pop(stack *, void **);

bool peek(stack *, void **);

bool delete_stack(stack *);

void display_stack(stack *, view_stack_func *);

#endif // STACK_SLL_H__