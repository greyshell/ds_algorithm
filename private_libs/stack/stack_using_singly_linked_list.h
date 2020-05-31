/*
 * author: greyshell
 * description: stack using singly linked list, data -> int
 * */

#ifndef STACK_USING_SINGLY_LINKED_LIST_H__
#define STACK_USING_SINGLY_LINKED_LIST_H__

typedef struct my_node {
    int data;
    struct my_node *next;
} linkedlist_node;

typedef struct my_stack {
    linkedlist_node *top;
    size_t size;
} stack;

void initialize_stack(stack *);

int is_empty_stack(stack *);

size_t get_stack_size(stack *);

int push(stack *, int);

int pop(stack *, int *);

int peek(stack *, int *);

int delete_stack(stack *);

void display_stack(stack *);

#endif // STACK_USING_SINGLY_LINKED_LIST_H__