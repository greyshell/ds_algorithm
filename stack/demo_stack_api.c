/*
 * author: greyshell
 * description: test singly linked list based implementation of stack, data -> int
 * */

#include <stdio.h>
#include "../private_libs/stack/stack_using_singly_linked_list.h"

int main(void) {
    size_t stack_size;
    stack my_stack;
    int out_data = 0;
    int return_type;

    // initialize the stack
    printf("creating the stack \n");
    initialize_stack(&my_stack);

    // push
    return_type = push(&my_stack, 30);
    if (return_type == 1) {
        printf("pushed: %d \n", 30);
    } else {
        printf("unable to push \n");
    }

    // display stack
    display_stack(&my_stack);

    // peek
    return_type = peek(&my_stack, &out_data);
    if (return_type == 1) {
        printf("stack top: %d \n", out_data);
    } else {
        printf("empty stack, unable to peek \n");
    }

    // pop
    return_type = pop(&my_stack, &out_data);
    if (return_type == 1) {
        printf("popped: %d \n", out_data);
    } else {
        printf("unable to pop \n");
    }

    // get stack size
    stack_size = get_stack_size(&my_stack);
    printf("stack size: %zu \n", stack_size);

    // delete stack
    return_type = delete_stack(&my_stack);
    if (return_type == 1) {
        printf("deleting the stack \n");
    } else {
        printf("unable to delete all stack elements \n");
    }

    return 0;
}
