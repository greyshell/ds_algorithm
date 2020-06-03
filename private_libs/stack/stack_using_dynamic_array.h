/*
 * author: greyshell
 * description: dynamic array based implementation of stack, data -> int
 * */

#ifndef STACK_USING_DYNAMIC_ARRAY_H__
#define STACK_USING_DYNAMIC_ARRAY_H__


#include <stdint.h>

typedef struct my_stack {
    int top;
    size_t capacity;
    int *array;
} stack;

void initialize_stack(stack *);

int is_empty_stack(stack *);

size_t get_stack_size(stack *);

int push(stack *, int);

int pop(stack *, int *);

int peek(stack *, int *);

int delete_stack(stack *);

void display_stack(stack *);

#endif // STACK_USING_DYNAMIC_ARRAY_H__
