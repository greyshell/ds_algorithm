/*
 * author: greyshell
 * description: example stack
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../libO2/include/stack_singly_linkedlist_int.h"

int main(void) {
    int out_data = 0;
    bool return_type;
    stack s;

    // initialize the stack
    initialize_stack(&s);

    // check if the stack is empty
    return_type = is_empty_stack(&s);
    printf("is empty stack: %d \n", return_type);

    // push an element
    return_type = push(&s, 7);
    if (return_type) {
        printf("element pushed \n");
    } else {
        printf("pushed failed \n");
    }

    // peek the stack top
    return_type = peek(&s, &out_data);
    if (return_type) {
        printf("element peeked: %d \n", out_data);
    } else {
        printf("peek failed \n");
    }

    // display stack elements
    printf("stack elements: \n");
    display_stack(&s);
    printf("\n");

    // pop an element
    return_type = pop(&s, &out_data);
    if (return_type) {
        printf("element popped: %d \n", out_data);
    } else {
        printf("pop failed \n");
    }

    // get the stack size
    return_type = get_stack_size(&s);
    printf("stack size: %d \n", return_type);

    // delete the stack
    delete_stack(&s);

    return 0;
}
