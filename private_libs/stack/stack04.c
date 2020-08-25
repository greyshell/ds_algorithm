/*
 * author: greyshell
 * description: dynamic array based implementation of stack, data_arr: int
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "stack04.h"

bool initialize_stack(stack *s, size_t capacity) {
    /*
     * create the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    s->top = -1;
    s->initial_capacity = capacity;
    s->data_arr = malloc(s->initial_capacity * sizeof(int));
    if (s->data_arr == NULL) {
        return false;
    }
    s->current_capacity = s->initial_capacity;
    return true;
}

bool is_empty_stack(stack *s) {
    /*
     * check if the queue is empty
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
     * get the size of the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return s->top + 1;
}

static bool _doubling_stack(stack *s) {
    /*
     * double up the stack size when it becomes full
     * note: when realloc() is unable to resized, then it creates a new memory block and
     * copy all the old data_arr into it.
     * time complexity: O(n) -> worst case
     * space complexity: O(1)
     */
    // note: too many doubling may cause memory overflow exception
    s->data_arr = realloc(s->data_arr, (s->current_capacity * 2) * sizeof(int));
    if (s->data_arr == NULL) {
        return false;
    }
    s->current_capacity *= 2;
    return true;
}

static bool _halving_stack(stack *s) {
    /*
     * halving the size when half of the spaces are empty
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->current_capacity == s->initial_capacity) {
        return false;
    }

    s->data_arr = realloc(s->data_arr, (s->current_capacity / 2) * sizeof(int));
    if (s->data_arr == NULL) {
        return false;
    }
    s->current_capacity /= 2;
    return true;
}

bool push(stack *s, int data) {
    /*
     * insert an element at top
     * amortized time complexity: O(1)
     * space complexity: O(1)
     */
    bool return_type;

    if ((s->top + 1) == s->current_capacity) {
        return_type = _doubling_stack(s);
        if (return_type == false) {
            return false;
        }
    }
    s->data_arr[++s->top] = data;
    return true;
}

bool pop(stack *s, int *out_data) {
    /*
     * remove an element from top
     * if halving operation is successful when requested then return true, else false
     * return type indicates the state of the halving operation when requested
     * amortized time complexity: O(1)
     * space complexity: O(1)
     */
    bool return_type;

    if (is_empty_stack(s)) {
        return false;
    }

    *out_data = s->data_arr[s->top--];
    // example: if the stack capacity: 8, occupied: 6, after 3 POPs, new stack size: 4
    if ((s->top + 1) < s->current_capacity / 2) {
        return_type = _halving_stack(s);
        if (return_type == false) {
            return false;
        }
    }
    return true;
}

bool peek(stack *s, int *out_data) {
    /*
     * display the element at top
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s->top == -1) {
        return false;
    }

    *out_data = s->data_arr[s->top];
    return true;
}

bool delete_stack(stack *s) {
    /*
     * delete the stack
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (s != NULL) {
        // free up the dynamic array
        free(s->data_arr);
        s = NULL;
        return true;
    }
    return false;
}

void display_stack(stack *s) {
    /*
     * display all stack elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    size_t top_ptr = s->top;
    // due to size_t top_ptr can't decrement below 0
    while ((top_ptr + 1) > 0) {
        printf("%d ", s->data_arr[top_ptr]);
        top_ptr--;
    }
}