/*
 * author: greyshell
 * description: singly linked list based implementation of stack, data -> int
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stack_using_singly_linked_list.h"

void initialize_stack(stack *s) {
    /*
     * create a stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    s->top = NULL;
    s->size = 0;
}

int is_empty_stack(stack *s) {
    /*
     * return 1 if the stack if empty, else return 0
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == NULL) {
        return 1;
    }
    return 0;
}

size_t get_stack_size(stack *s) {
    /*
     * return the stack size
     * time complexity: O(1)
     * space complexity: O(1)
     */

    return s->size;
}

int push(stack *s, int data) {
    /*
     * add an element into the stack
     * return 1 if push is successful, else return 0
     * time complexity: O(1)
     * space complexity: O(1)
     */
    linkedlist_node *temp_node;

    // create a new node
    temp_node = (linkedlist_node *) malloc(sizeof(linkedlist_node));
    if (temp_node == NULL){
        printf("unable to allocate space \n");
        return 0;
    }
    temp_node->data = data;

    // link the node where the stack top points
    temp_node->next = s->top;

    // update the stack top
    s->top = temp_node;
    // update the stack size
    s->size++;
    return 1;
}

int pop(stack *s, int *out_data) {
    /*
     * remove an element from the stack
     * return 1 if pop is successful, else return 0
     * time complexity: O(1)
     * space complexity: O(1)
     */
    linkedlist_node *temp_node;
    // check if the stack is empty
    if (is_empty_stack(s)) {
        printf("stack is empty \n");
        return 0;
    }

    *out_data = s->top->data;
    temp_node = s->top;
    // update the stack top
    s->top = s->top->next;
    // update the stack size
    s->size--;
    // delete the previous node
    free(temp_node);
    return 1;
}

int peek(stack *s, int *out_data) {
    /*
     * display the top element of the stack
     * return 1 if peek is successful else return 0
     * time complexity: O(1)
     * space complexity: O(1)
     */
    // check if the stack is empty
    if (is_empty_stack(s)) {
        return 0;
    }
    *out_data = s->top->data;
    return 1;
}

int delete_stack(stack *s) {
    /*
     * free up the total memory by popping out all elements
     * if all pops are successful then return 1 else return 0
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int out_data;

    while (s->top != NULL) {
        if (!pop(s, &out_data)) {
            return 0;
        }
    }
    return 1;
}

void display_stack(stack *s) {
    /*
     * display all stack elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    linkedlist_node *curr_ptr;
    curr_ptr = s->top;
    int count = s->size;

    printf("stack elements: ");
    while (count > 0) {
        printf("%d ", curr_ptr->data);
        curr_ptr = curr_ptr->next;
        count--;
    }
    printf("\n");
}