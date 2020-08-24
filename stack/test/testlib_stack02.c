/*
 * author: greyshell
 * description: test stack02
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "../../private_libs/stack/stack02.h"

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
}

int main(void) {
    int *data, *out_data = 0;
    size_t choice, stack_size;
    bool return_type;
    stack my_stack;

    // initialize the stack
    printf("creating the stack ");
    initialize_stack(&my_stack);

    while (1) {
        printf("\n\n");
        printf("=================== \n");
        printf("menu driven program: \n");
        printf("==================== \n");
        printf("0. push \n");
        printf("1. pop \n");
        printf("2. peek \n");
        printf("3. get the stack size \n");
        printf("4. check if the stack is empty \n");
        printf("5. display the stack \n");
        printf("6. delete the stack and quit \n");


        printf("\n\n");
        printf("enter your choice: \n");
        printf("================== \n");
        scanf("%zu", &choice);
        printf("\n");


        switch (choice) {
            case 0:
                // push at top
                printf("enter the element: \n");
                data = (int *) malloc(sizeof(int));
                scanf("%d", data);
                printf("operation: push, data_arr: %d \n", *data);
                return_type = push(&my_stack, data);
                if (return_type == true) {
                    printf("pushed \n");
                } else {
                    printf("unable to push \n");
                }
                break;
            case 1:
                // pop from top
                printf("operation: pop \n");
                return_type = pop(&my_stack, (void **) &out_data);
                if (return_type == true) {
                    printf("popped: %d \n", *(int *) out_data);
                    free(out_data);
                } else {
                    printf("unable to pop \n");
                }
                break;

            case 2:
                // peek at top
                printf("operation: peek \n");
                return_type = peek(&my_stack, (void **) &out_data);
                if (return_type == true) {
                    printf("peek at top: %d \n", *out_data);
                } else {
                    printf("unable to peek \n");
                }
                break;

            case 3:
                // get the stack size
                printf("operation: get_stack_size \n");
                stack_size = get_stack_size(&my_stack);
                printf("stack size: %zu \n", stack_size);
                break;

            case 4:
                // check if the stack is empty
                printf("operation: is_empty_stack \n");
                return_type = is_empty_stack(&my_stack);
                printf("is empty: %d \n", return_type);
                break;

            case 5:
                printf("operation: display_stack \n");
                display_stack(&my_stack, my_display);
                printf("\n");
                break;

            case 6:
                // delete the stack
                printf("operation: delete_stack \n");
                return_type = delete_stack(&my_stack);
                if (return_type == true) {
                    printf("deleted the stack \n");
                    return 0;
                } else {
                    printf("unable to delete \n");
                }
                break;

            default:
                printf("wrong choice \n");
        }
    }

}
