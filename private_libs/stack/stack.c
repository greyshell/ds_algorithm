/*
 * author: greyshell
 * description: singly linked list based implementation of stack, data_arr: int
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "stack.h"

void initialize_stack(stack *s) {
    /*
     * create a stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    s->top = NULL;
    s->size = 0;
}

bool is_empty_stack(stack *s) {
    /*
     * return 1 if the stack if empty, else return 0
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == NULL) {
        return true;
    }
    return false;
}

size_t get_stack_size(stack *s) {
    /*
     * get the size of the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return s->size;
}

bool push(stack *s, int data) {
    /*
     * insert an int data_arr at top
     * time complexity: O(1)
     * space complexity: O(1)
     */
    stack_node *temp_node;

    // create a new node
    temp_node = (stack_node *) malloc(sizeof(stack_node));
    if (temp_node == NULL) {
        return false;
    }
    temp_node->data = data;
    // link the node where the stack top points
    temp_node->next = s->top;
    // update the stack top
    s->top = temp_node;
    s->size++;
    return true;
}

bool pop(stack *s, int *out_data) {
    /*
     * remove an int data_arr from top
     * time complexity: O(1)
     * space complexity: O(1)
     */
    stack_node *temp_node;
    // check if the stack is empty
    if (is_empty_stack(s)) {
        printf("stack is empty \n");
        return false;
    }

    *out_data = s->top->data;
    temp_node = s->top;
    // update the stack top
    s->top = s->top->next;
    // delete the previous node
    free(temp_node);
    s->size--;
    return true;
}

bool peek(stack *s, int *out_data) {
    /*
     * display the element at top
     * time complexity: O(1)
     * space complexity: O(1)
     */
    // check if the stack is empty
    if (is_empty_stack(s)) {
        return false;
    }
    *out_data = s->top->data;
    return true;
}

bool delete_stack(stack *s) {
    /*
     * delete the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    bool return_type;
    int out_data;

    while (s->top != NULL) {
        return_type = pop(s, &out_data);
        if (return_type == false) {
            return false;
        }
    }
    return true;
}

void display_stack(stack *s) {
    /*
     * display all stack elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    stack_node *curr_node;
    curr_node = s->top;

    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
}