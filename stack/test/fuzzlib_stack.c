/*
 * author: greyshell
 * description: fuzz the stack through AFL
 * */

// make -f fuzz_lib_with_afl SRC_FLD=stack/test WRAPPER_PROG=fuzzlib_stack LIB_FLD=stack LIB=stack

#include <stdio.h>
#include "stdbool.h"
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../../private_libs/stack/stack.h"

// helper functions for fuzzing
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

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
    fflush(stdout);
}

bool my_compare(void *data, void *key) {
    /*
     * data format: int
     */
    if (*(int *) data == *(int *) key) {
        return true;
    }
    return false;
}

int main(void) {
    //
    int data, out_data = 0;
    size_t choice, stack_size;
    bool return_type;
    stack my_stack;
    uint8_t number_operations;
    uint8_t operation_type;

    size_t ops_count = 5;
    // initialize
    initialize_stack(&my_stack);

    // randomize the nos of operations and get the input through fuzzer
    number_operations = read8();
    printf("number of operations: %d \n", number_operations);

    for (int i = 0; i < number_operations; i++) {
        // choose the random operation
        operation_type = read8();
        switch (operation_type % ops_count) {
            case 0:
                data = read_int();
                printf("operation: push, data: %d \n", data);
                return_type = push(&my_stack, data);
                if (return_type == true) {
                    printf("pushed \n");
                } else {
                    printf("unable to push \n");
                }
                break;
            case 1:
                printf("operation: pop \n");
                return_type = pop(&my_stack, &out_data);
                if (return_type == true) {
                    printf("stack top has %d \n", out_data);
                } else {
                    printf("unable to pop \n");
                }
                break;
            case 2:
                printf("operation: peek \n");
                return_type = peek(&my_stack, &out_data);
                if (return_type == true) {
                    printf("peek at top: %d \n", out_data);
                } else {
                    printf("unable to peek \n");
                }
                break;
            case 3:
                printf("operation: get_stack_size \n");
                stack_size = get_stack_size(&my_stack);
                printf("stack size: %zu \n", stack_size);
                break;
            case 4:
                printf("operation: is_empty_stack \n");
                return_type = is_empty_stack(&my_stack);
                printf("is empty: %d \n", return_type);
                break;
            case 5:
                printf("operation: display_stack \n");
                display_stack(&my_stack);
                printf("\n");
                break;

            default:
                printf("wrong choice \n");

        }
    }
    // delete the ADT
    delete_stack(&my_stack);

    return 0;
}