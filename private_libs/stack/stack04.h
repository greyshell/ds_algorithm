/*
 * author: greyshell
 * description: stack
 * */

#ifndef STACK04_H__
#define STACK04_H__

#include <lzma.h>
#include "stdbool.h"

typedef void view_stack_func(void *);

typedef struct {
    int top;
    size_t initial_capacity;
    size_t current_capacity;
    int *data_arr;
} stack;

bool initialize_stack(stack *, size_t);

bool is_empty_stack(stack *);

size_t get_stack_size(stack *);

bool push(stack *, int);

bool pop(stack *, int *);

bool peek(stack *, int *);

bool delete_stack(stack *);

void display_stack(stack *);

#endif // STACK03_H__
