/*
 * author: greyshell
 * description: dynamic array based implementation of stack
 * */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack_using_dynamic_array.h"

void initialize_stack(stack *s) {
    /*
     * create a stack, initialize the stack top and set the capacity
     * time complexity: O(1)
     * space complexity: O(1)
     */
    s->top = -1;
    s->capacity = 1;
    s->array = malloc(s->capacity * sizeof(int));
    if (s->array == NULL) {
        printf("unable to allocate space !!");
    }
}

void doubling_stack(stack *s) {
    /*
     * double up the stack size when it becomes full
     * if the memory block cannot be resized in placed, then the old data will be copied to the new block.
     * amortized time complexity: O(n)
     * space complexity: O(1), no additional space is used
     */
    printf("doubling up the stack size as the existing capacity: %zu \n", s->capacity);
    s->capacity *= 2;
    s->array = realloc(s->array, s->capacity * sizeof(int));
    // note: too many doubling may cause memory overflow exception
    if (s->array == NULL) {
        printf("unable to allocate space !!");
    }
}

void halving_stack(stack *s) {
    /*
     * halving stack size when half of the spaces are empty
     * amortized time complexity: O(n),
     * space complexity: O(1), no extra space is required
     */
    if (s->capacity == 1) {
        return;
    }
    printf("halving the stack size as the existing capacity: %zu \n", s->capacity);
    s->capacity /= 2;
    s->array = realloc(s->array, s->capacity * sizeof(int));
}

void push(stack *s, int data) {
    /*
     * add an element in the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == s->capacity - 1) {
        doubling_stack(s);
    }
    s->array[++s->top] = data;
}

int pop(stack *s) {
    /*
     * remove an element from the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int data;
    if (s->top == -1) {
        printf("stack is empty, returning INT_MIN \n");
        return INT_MIN;
    }
    data = s->array[s->top--];
    // check if the stack needs to be shrink
    // example: if the stack capacity: 8, occupied: 6 then after 3 pops, stack shrinks to size 4
    if ((s->top + 1) < s->capacity / 2) {
        halving_stack(s);
    }
    return data;
}

void pop_all(stack *s) {
    /*
     * display all elements from the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int data;
    if (s->top == -1) {
        printf("stack is empty \n");
        return;
    }
    while (s->top > -1) {
        data = pop(s);
        printf("%d is popped \n", data);
    }
}

int peek(stack *s) {
    /*
     * peek the stack top
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == -1) {
        printf("stack is empty !!");
        return INT_MIN;
    }
    return s->array[s->top];
}

void peek_all(stack *s) {
    /*
     * display all elements from the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int top_ptr;
    top_ptr = s->top;
    if (s->top == -1) {
        printf("stack is empty !!");
        return;
    }
    while (top_ptr > -1) {
        printf("%d ", s->array[top_ptr--]);
    }
    printf("\n");
}