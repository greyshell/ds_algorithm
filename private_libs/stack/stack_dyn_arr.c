/*
 * author: greyshell
 * description: dynamic array based implementation of stack, datatype -> int
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "stack_dyn_arr.h"

#define INITIAL_CAPACITY 1

bool initialize_stack(stack *s) {
    /*
     * create a stack, initialize the stack top and set the capacity
     * time complexity: O(1)
     * space complexity: O(1)
     */
    s->top = -1;
    s->capacity = INITIAL_CAPACITY;
    s->array = malloc(s->capacity * sizeof(int));
    if (s->array == NULL) {
        return false;
    }
    return true;
}

bool is_empty_stack(stack *s) {
    /*
     * check if the stack is empty, if empty then returns true
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == -1) {
        return true;
    }
    return false;
}

size_t get_stack_size(stack *s) {
    /*
     * return the stack size
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return s->top + 1;
}

bool doubling_stack(stack *s) {
    /*
     * double up the stack size when it becomes full
     * if the operation is successful then return true else return false
     * if the memory block cannot be resized in placed, then the old data will be copied to the new block.
     * amortized time complexity: O(n)
     * space complexity: O(1), no additional space is used
     */
    // printf("before the push() total elements added: %d \n", s->top + 1);
    // printf("but current array size: %zu \n",s->capacity);
    // note: too many doubling may cause memory overflow exception
    s->array = realloc(s->array, (s->capacity * 2) * sizeof(int));
    if (s->array == NULL) {
        return false;
    }
    // reallocation successful hence update the capacity
    s->capacity *= 2;
    // printf("resizing the array, new array size: %zu \n", s->capacity);
    return true;
}

bool halving_stack(stack *s) {
    /*
     * halving stack size when half of the spaces are empty
     * if the operation is successful then return true else return false
     * amortized time complexity: O(n),
     * space complexity: O(1), no extra space is required
     */
    if (s->capacity == INITIAL_CAPACITY) {
        return false;
    }
    // printf("after the pop(), total elements will be : %d \n", s->top + 1);
    // printf("but current array size: %zu \n", s->capacity);
    s->array = realloc(s->array, (s->capacity / 2) * sizeof(int));
    if (s->array == NULL) {
        return false;
    }
    // reallocation successful hence update the capacity
    s->capacity /= 2;
    // printf("resizing the array, new array size: %zu \n", s->capacity);
    return true;
}

bool push(stack *s, int data) {
    /*
     * add an element in the stack
     * if doubling operation is successful when requested then return true, else false
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == s->capacity - 1) {
        if (!doubling_stack(s)) {
            return false;
        }
    }
    s->array[++s->top] = data;
    return true;
}

bool pop(stack *s, int *out_data) {
    /*
     * remove an element from the stack
     * if halving operation is successful when requested then return true, else false
     * return type indicates the state of the halving operation when requested
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_stack(s)) {
        return false;
    }

    *out_data = s->array[s->top--];
    // check if the stack size needs to be reduced
    // example: if the stack capacity: 8, occupied: 6 then after 3 pops, stack shrinks to size 4
    if ((s->top + 1) < s->capacity / 2) {
        if (!halving_stack(s)) {
            return false;
        }
    }
    return true;
}

bool peek(stack *s, int *out_data) {
    /*
     * peek the stack top, if stack is empty then return false, else true
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == -1) {
        return false;
    }

    *out_data = s->array[s->top];
    return true;
}

bool delete_stack(stack *s) {
    /*
     * free up the memory space while deleting the entire stack
     * if able to free up the space successfully then return true else return false
     * time complexity: O(1)
     * space complexity: O(1)
     */
    // check if s is not NULL
    if (s != NULL) {
        // free up the entire dynamic array
        free(s->array);
        return true;
    }
    return false;
}

void display_stack(stack *s) {
    /*
     * display all elements from the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int top_ptr;
    top_ptr = s->top;
    if (is_empty_stack(s)) {
        printf("stack is empty \n");
        return;
    }
    while (top_ptr > -1) {
        printf("%d ", s->array[top_ptr--]);
    }
    printf("\n");
}