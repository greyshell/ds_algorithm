/*
 * author: greyshell
 * description: tests stack
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../../liquid_oxygen/stack/stack.h"

int main(void) {
    int data;
    size_t choice, stack_size;
    stack my_stack;
    int out_data = 0;
    int return_type;

    printf("creating the stack ");
    initialize_stack(&my_stack);

    while (1) {
        printf("\n\n");
        printf("=================== \n");
        printf("menu driven program: \n");
        printf("==================== \n");
        printf("0. push an element \n");
        printf("1. pop an element \n");
        printf("2. peek the top element \n");
        printf("3. get the stack size \n");
        printf("4. display all elements \n");
        printf("5. delete the entire stack and quit from the program \n");


        printf("\n\n");
        printf("enter your choice: \n");
        printf("================== \n");
        scanf("%zu", &choice);
        printf("\n");


        switch (choice) {
            case 0: // push
                printf("enter the element to be pushed: \n");
                scanf("%d", &data);
                printf("operation: push, data_arr: %d \n", data);
                return_type = push(&my_stack, data);
                if (return_type == true) {
                    printf("%d is successfully pushed \n", data);
                } else {
                    printf("unable to push \n");
                }
                break;

            case 1: // pop
                printf("operation: pop \n");
                return_type = pop(&my_stack, &out_data);
                if (return_type == true) {
                    printf("%d is popped \n", out_data);
                } else {
                    printf("unable to pop \n");
                }
                break;

            case 2: // peek
                printf("operation: peek \n");
                return_type = peek(&my_stack, &out_data);
                if (return_type == true) {
                    printf("stack top element: %d \n", out_data);
                } else {
                    printf("empty stack, unable to peek \n");
                }
                break;

            case 3: // get stack size
                printf("operation: get stack size \n");
                stack_size = get_stack_size(&my_stack);
                printf("stack size: %zu", stack_size);
                break;


            case 4: // display all elements
                printf("operation: display \n");
                display_stack(&my_stack);
                break;

            case 5:
                // quit from the program
                printf("operation: delete stack \n");
                return_type = delete_stack(&my_stack);
                if (return_type == true) {
                    printf("all stack elements are deleted \n");
                    return 0;
                } else {
                    printf("unable to delete all stack elements \n");
                }
                break;

            default:
                printf("wrong choice \n");
        }
    }

}