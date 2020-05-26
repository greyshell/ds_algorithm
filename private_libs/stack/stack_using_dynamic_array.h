/*
 * author: greyshell
 * description: dynamic array based implementation of stack
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

void push(stack *, int);

int pop(stack *);

void pop_all(stack *);

int peek(stack *);

void peek_all(stack *);

#endif // STACK_USING_DYNAMIC_ARRAY_H__
