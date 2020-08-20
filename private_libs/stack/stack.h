/*
 * author: greyshell
 * description: stack
 * */

#ifndef STACK_H__
#define STACK_H__

#include <glob.h>
#include "stdbool.h"

typedef struct list {
    int data;
    struct list *next;
} stack_node;

typedef struct {
    stack_node *top;
    size_t size;
} stack;

void initialize_stack(stack *);

bool is_empty_stack(stack *);

size_t get_stack_size(stack *);

bool push(stack *, int);

bool pop(stack *, int *);

bool peek(stack *, int *);

bool delete_stack(stack *);

void display_stack(stack *);

#endif // STACK_H__