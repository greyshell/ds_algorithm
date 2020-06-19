/*
 * author: greyshell
 * description: dynamic array based implementation of stack
 * data / key -> void pointer
 * */

#ifndef STACK_DYN_ARR_H__
#define STACK_DYN_ARR_H__

#include "stdbool.h"

typedef void view_stack(void *);

typedef struct my_stack {
    int top;
    size_t initial_capacity;
    size_t current_capacity;
    void **array;
} stack;

bool initialize_stack(stack *, size_t);

bool is_empty_stack(stack *);

size_t get_stack_size(stack *);

bool push(stack *, void *);

bool pop(stack *, void **);

bool peek(stack *, void **);

bool delete_stack(stack *);

void display_stack(stack *, view_stack *);

#endif // STACK_DYN_ARR_H__
