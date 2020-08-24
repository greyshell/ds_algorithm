/*
 * author: greyshell
 * description: stack
 * */

#ifndef STACK03_H__
#define STACK03_H__

#include "stdbool.h"

typedef void view_stack_func(void *);

typedef struct {
    int top;
    size_t initial_capacity;
    size_t current_capacity;
    void **data_arr;
} stack;

bool initialize_stack(stack *, size_t);

bool is_empty_stack(stack *);

size_t get_stack_size(stack *);

bool push(stack *, void *);

bool pop(stack *, void **);

bool peek(stack *, void **);

bool delete_stack(stack *);

void display_stack(stack *, view_stack_func *);

#endif // STACK03_H__
