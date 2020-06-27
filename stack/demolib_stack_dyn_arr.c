/*
 * author: greyshell
 * description: test dynamic array based implementation of stack
 * data / key -> void pointer
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/stack/stack_dyn_arr.h"

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
}

int main(void) {
    size_t stack_size;
    stack my_stack;
    int *out_data;
    bool return_type;
    int data = 30;

    // initialize the stack
    printf("create the stack \n");
    initialize_stack(&my_stack, 1);

    // note: make sure that you insert an address
    // push at top
    return_type = push(&my_stack, &data);
    if (return_type == true) {
        printf("pushed: %d \n", data);
    } else {
        printf("unable to push \n");
    }

    // check if the stack is empty
    return_type = is_empty_stack(&my_stack);
    printf("is empty: %d \n", return_type);

    // get the stack size
    stack_size = get_stack_size(&my_stack);
    printf("stack size: %zu \n", stack_size);

    // peek at top
    return_type = peek(&my_stack, (void **) &out_data);
    if (return_type == true) {
        printf("peek at top: %d \n", *out_data);
    } else {
        printf("unable to peek \n");
    }

    // display the stack
    printf("display: ");
    display_stack(&my_stack, my_display);
    printf("\n");

    // pop from top
    return_type = pop(&my_stack, (void **) &out_data);
    if (return_type == true) {
        printf("popped: %d \n", *out_data);
    } else {
        printf("unable to pop \n");
    }

    // delete the stack
    return_type = delete_stack(&my_stack);
    if (return_type == true) {
        printf("deleted the stack \n");
    } else {
        printf("unable to delete \n");
    }

    return 0;
}
