/*
 * author: greyshell
 * description: singly linked list based implementation of stack
 * */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack_using_singly_linked_list.h"

void initialize_stack(stack *s) {
    /*
     * create a stack and initialize the stack top
     * time complexity: O(1)
     * space complexity: O(1)
     */
    s->top = NULL;
}


void push(stack *s, int data){
    /*
     * insert an element into the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    linkedlist_node *temp_node;

    // create a new node
    temp_node = (linkedlist_node *) malloc(sizeof(linkedlist_node));
    temp_node->data = data;

    // link the node where the stack top points
    temp_node->next = s->top;

    // update the stack top
    s->top = temp_node;
    }

int pop(stack *s){
    /*
     * remove an element from the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int data;
    linkedlist_node *temp_node;
    // check if the stack is empty
    if (s->top == NULL){
        printf("stack is empty, returning INT_MIN \n");
        return INT_MIN;
    }

    temp_node = s->top;
    s->top = temp_node->next;
    data = temp_node->data;

    free(temp_node);
    return data;
}

void pop_all(stack *s){
    /*
     * remove all elements from the stack / empty the stack
     * time complexity: O(n)
     * space complexity: O(1)
     */
    int data;
    if (s->top == NULL){
        printf("stack is empty \n");
        return;
    }
    while (s->top != NULL){
        data = pop(s);
        printf("%d is popped \n", data);
    }
}

int peek(stack *s){
    /*
     * display the stack top element
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int data;
    linkedlist_node *temp_node;
    // check if the stack is empty
    if (s->top == NULL){
        printf("stack is empty, returning INT_MIN \n");
        return INT_MIN;
    }
    return s->top->data;
}

void peek_all(stack *s){
    /*
     * display all elements from the stack
     * time complexity: O(n)
     * space complexity: O(1)
     */
    int data;
    linkedlist_node *curr_ptr;
    // check if the stack is empty
    if (s->top == NULL){
        printf("stack is empty \n");
        return;
    }
    curr_ptr = s->top;
    while (curr_ptr != NULL){
        printf("%d ", curr_ptr->data);
        curr_ptr = curr_ptr->next;
    }
    printf("\n");
}