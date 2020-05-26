/*
 * author: greyshell
 * */

#ifndef STACK_USING_SINGLY_LINKED_LIST_H__
#define STACK_USING_SINGLY_LINKED_LIST_H__


typedef struct my_node {
    int data;
    struct my_node *next;
} linkedlist_node;


typedef struct my_stack {
    linkedlist_node *top;
} stack;


void initialize_stack(stack *);

void push(stack *, int);

int pop(stack *);

void pop_all(stack *);

int peek(stack *);

void peek_all(stack *);

#endif // STACK_USING_SINGLY_LINKED_LIST_H__