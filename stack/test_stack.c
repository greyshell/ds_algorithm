/*
 * author: greyshell
 * description: test my singly linked list implementation
 * */

#include <stdio.h>
#include <limits.h>
#include "../private_libs/stack.h"

int main(void) {
    int data;
    size_t choice;
    linkedlist_node *temp_node;
    stack my_stack;
    printf("creating a stack !!");
    initialize_stack(&my_stack);

    while (1) {
        printf("\n");
        printf("=================== \n");
        printf("menu driven program: \n");
        printf("==================== \n");
        printf("0. push an element \n");
        printf("1. pop an element \n");
        printf("2. pop all elements \n");
        printf("3. peek the stack top \n");
        printf("4. display all stack elements \n");

        printf("5. quit \n");

        printf("\n");
        printf("display present state: \n");
        printf("====================== \n");
        peek_all(&my_stack);

        printf("\n\n");
        printf("enter your choice: \n");
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
                if (data != INT_MIN){
                    printf("element = %d is deleted \n", data);
                }
                break;
            case 2:
                pop_all(&my_stack);
                break;
            case 3:
                data = peek(&my_stack);
                if (data != INT_MIN){
                    printf("stack top element is %d \n", data);
                }
                break;
            case 4:
                peek_all(&my_stack);
                break;

            case 5:
                // quite from the program
                return 0;

            default:
                printf("wrong choice \n");
        }
    }

}
