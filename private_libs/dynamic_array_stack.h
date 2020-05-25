/*
 * author: greyshell
 * */

#ifndef DYNAMIC_ARRAY_STACK_H__
#define DYNAMIC_ARRAY_STACK_H__


#include <stdint.h>

typedef struct my_stack {
    int top;
    size_t capacity;
    size_t reserved;
    int *array;
} dynamic_array_stack;

void initialize_dynamic_array_stack(dynamic_array_stack *);

size_t stack_reserve_count_dynamic_array(dynamic_array_stack *s);

size_t stack_capacity_dynamic_array(dynamic_array_stack *);

void push_dynamic_array(dynamic_array_stack *, int);

int pop_dynamic_array(dynamic_array_stack *);

void pop_all_dynamic_array(dynamic_array_stack *);

int peek_dynamic_array(dynamic_array_stack *);

void peek_all_dynamic_array(dynamic_array_stack *);

#endif // DYNAMIC_ARRAY_STACK_H__
