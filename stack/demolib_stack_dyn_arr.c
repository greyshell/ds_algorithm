/*
 * author: greyshell
 * description: test dynamic array based implementation of stack, datatype -> int
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/stack/stack_dyn_arr.h"

int main(void) {
    size_t stack_size;
    stack my_stack;
    int out_data = 0;
    bool return_type;

    // initialize the stack
    return_type = initialize_stack(&my_stack);
    if (return_type == true) {
        printf("stack is created and initialized \n");
    } else {
        printf("unable to create the stack \n");
    }

    // push
    return_type = push(&my_stack, 30);
    if (return_type == true) {
        printf("pushed: %d \n", 30);
    } else {
        printf("unable to push \n");
    }

    // display stack
    display_stack(&my_stack);

    // peek
    return_type = peek(&my_stack, &out_data);
    if (return_type == true) {
        printf("stack top: %d \n", out_data);
    } else {
        printf("empty stack, unable to peek \n");
    }

    // pop
    return_type = pop(&my_stack, &out_data);
    if (return_type == true) {
        printf("popped: %d \n", out_data);
    } else {
        printf("unable to pop \n");
    }

    // check if the stack is empty
    return_type = is_empty_stack(&my_stack);
    printf("is empty: %d \n", return_type);

    // get stack size
    stack_size = get_stack_size(&my_stack);
    printf("stack size: %zu \n", stack_size);

    // delete stack
    return_type = delete_stack(&my_stack);
    if (return_type == true) {
        printf("deleted all elements from the stack \n");
    } else {
        printf("unable to delete all stack elements \n");
    }

    return 0;
}
