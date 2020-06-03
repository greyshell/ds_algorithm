/*
 * author: greyshell
 * description: fuzz the singly linked list based stack implementation
 * command: make -f fuzz_lib_with_afl SRC_FLD=stack WRAPPER_PROG=fuzzlib_stack_using_singly_linked_list LIB_FLD=stack LIB=stack_using_singly_linked_list
 * */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../private_libs/stack/stack_using_singly_linked_list.h"

void readn(void *s, int n) {
    int bytes_read;
    bytes_read = read(0, s, n);
    if (bytes_read == n) {
        return;
    }
    if (bytes_read == 0 || bytes_read == -1) {
        memset(s, 0, n);
        return;
    }
    memset(&((char *) s)[bytes_read], 0, n - bytes_read);
}

uint8_t read8() {
    uint8_t i;
    readn(&i, sizeof(i));
    return i;
}

int read_int() {
    int i;
    readn(&i, sizeof(i));
    return i;
}

size_t read_size_t() {
    size_t i;
    readn(&i, sizeof(i));
    return i;
}

// create the adt
stack my_stack;

// define the stack API
size_t op_get_stack_size() {
    int stack_size;
    printf("operation: get the stack size \n");
    stack_size = get_stack_size(&my_stack);
    printf("stack size: %zu \n", stack_size);
}

int op_push() {
    int data;
    int return_type;
    data = read_int();
    printf("operation: push an element \n");
    return_type = push(&my_stack, data);
    if (return_type == 1) {
        printf("%d is successfully pushed \n", data);
    } else {
        printf("unable to push \n");
    }
}

int op_pop() {
    int out_data;
    int return_type;
    printf("operation: pop an element \n");
    return_type = pop(&my_stack, &out_data);
    if (return_type == 1) {
        printf("%d is popped \n", out_data);
    } else {
        printf("unable to pop \n");
    }
}


int op_peek() {
    int out_data;
    int return_type;
    printf("operation: peek the stack top \n");
    return_type = peek(&my_stack, &out_data);
    if (return_type == 1) {
        printf("stack top has %d \n", out_data);
    } else {
        printf("empty stack, unable to peek \n");
    }
}

void op_display_stack() {
    printf("operation: display all stack elements \n");
    display_stack(&my_stack);
}

void op_delete_stack() {
    int return_type;
    printf("operation: delete stack / pop all elements \n");
    return_type = delete_stack(&my_stack);
    if (return_type == 1) {
        printf("all stack elements are deleted \n");
        return 0;
    } else {
        printf("unable to delete all stack elements \n");
    }
}

int main(void) {
    uint8_t number_operations;
    uint8_t operation_type;
    // (total functions to fuzz - 1) -> as the switch case starts from 0
    size_t ops_count = 5;
    // initialize
    initialize_stack(&my_stack);

    // randomize the nos of operations and get the input through fuzzer
    number_operations = read8();
    printf("nos of operations: %d \n", number_operations);
    for (int i = 0; i < number_operations; i++) {
        // choose the random operation
        operation_type = read8();
        switch (operation_type % ops_count) {
            case 0:
                op_get_stack_size();
                break;
            case 1:
                op_push();
                break;
            case 2:
                op_pop();
                break;
            case 3:
                op_peek();
                break;
            case 4:
                op_display_stack();
                break;
            case 5:
                op_delete_stack();
                break;

        }
    }
    // delete the ADT
    delete_stack(&my_stack);

    return 0;
}