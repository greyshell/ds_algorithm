/*
 * author: greyshell
 * description: dynamic array based implementation of stack
 * */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dynamic_array_stack.h"

void initialize_dynamic_array_stack(dynamic_array_stack *s) {
    /*
     * create a stack, initialize the stack top and set the capacity
     * time complexity: O(1)
     * space complexity: O(1)
     */
    s->top = -1;
    s->capacity = 1;
    s->reserved = 0;
    s->array = malloc(s->capacity * sizeof(int));
    if (s->array == NULL){
        printf("unable to allocate space !!");
    }
}

size_t stack_reserve_count_dynamic_array(dynamic_array_stack *s){
    /*
     * check the capacity of the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return s->reserved;
}

size_t stack_capacity_dynamic_array(dynamic_array_stack *s){
    /*
     * check the capacity of the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return s->capacity;
}

void double_stack(dynamic_array_stack *s){
    /*
     * double up the stack size when it becomes full
     * if the memory block cannot be resized in placed, then the old data will be copied to the new block.
     * time complexity: O(n)
     * space complexity: O(1), no additional space is used
     */
    s->capacity *= 2;
    s->array = realloc(s->array, s->capacity * sizeof(int));
    // note: too many doubling may cause memory overflow exception
    if (s->array == NULL){
        printf("unable to allocate space !!");
    }
}

void push_dynamic_array(dynamic_array_stack *s, int data){
    /*
     * add an element in the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == s->capacity - 1){
        double_stack(s);
    }
    s->array[++s->top] = data;
    s->reserved++;
}

int peek_dynamic_array(dynamic_array_stack *s){
    /*
     * peek the stack top
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == -1){
        printf("stack is empty !!");
        return INT_MIN;
    }
    return s->array[s->top];
}

void peek_all_dynamic_array(dynamic_array_stack *s){
    /*
     * display all elements from the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int top_ptr;
    top_ptr = s->top;
    if (s->top == -1){
        printf("stack is empty !!");
        return;
    }
    while (top_ptr > -1){
        printf("%d ", s->array[top_ptr--]);
    }
    printf("\n");
}

int pop_dynamic_array(dynamic_array_stack *s){
    /*
     * remove an element from the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == -1){
        printf("stack is empty, returning INT_MIN \n");
        return INT_MIN;
    }
    // to do: need to implement the shrink function for 3/4 ratio
    s->reserved--;
    return s->array[s->top--];
}

void pop_all_dynamic_array(dynamic_array_stack *s){
    /*
     * display all elements from the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int data;
    if (s->top == -1){
        printf("stack is empty \n");
        return;
    }
    while (s->top > -1){
        data = pop_dynamic_array(s);
        printf("%d is popped \n", data);
    }
}
