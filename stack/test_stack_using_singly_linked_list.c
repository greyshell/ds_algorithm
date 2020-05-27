/*
 * author: greyshell
 * description: test singly linked list based implementation of stack
 * */

#include <stdio.h>
#include "../private_libs/stack/stack_using_singly_linked_list.h"

int main(void) {
    int data;
    size_t choice;
    stack my_stack;
    printf("creating a stack !!");
    initialize_stack(&my_stack);

    while (1) {
        printf("\n\n");
        printf("=================== \n");
        printf("menu driven program: \n");
        printf("==================== \n");
        printf("0. push an element \n");
        printf("1. pop an element \n");
        printf("2. pop all elements \n");
        printf("3. peek the stack top \n");
        printf("4. display all stack elements \n");
        printf("5. delete the stack and quit \n");

        printf("\n");
        printf("current DS state: \n");
        printf("================= \n");
        peek_all(&my_stack);

        printf("\n\n");
        printf("enter your choice: \n");
        printf("================== \n");
        scanf("%zu", &choice);
        printf("\n");


        switch (choice) {
            case 0:
                printf("enter the element to be pushed: \n");
                scanf("%d", &data);
                push(&my_stack, data);
                break;
            case 1:
                data = pop(&my_stack);
                printf("element = %d is deleted \n", data);
                break;
            case 2:
                pop_all(&my_stack);
                break;
            case 3:
                data = peek(&my_stack);
                printf("stack top has %d \n", data);
                break;
            case 4:
                peek_all(&my_stack);
                break;

            case 5:
                // quit from the program
                delete_stack(&my_stack);
                return 0;

            default:
                printf("wrong choice \n");
        }
    }

}
