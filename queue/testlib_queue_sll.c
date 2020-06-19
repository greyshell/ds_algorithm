/*
 * author: greyshell
 * description: test singly linked list based implementation of queue
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

#include "../private_libs/queue/queue_sll.h"

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
}

int main(void) {
    int *data;
    size_t choice, queue_size;
    queue my_queue;
    int *out_data;
    int return_type;
    view_queue *my_func = my_display;

    // initialize the queue
    printf("create the queue \n");
    initialize_queue(&my_queue);

    while (1) {
        printf("\n\n");
        printf("=================== \n");
        printf("menu driven program: \n");
        printf("==================== \n");
        printf("0. enqueue \n");
        printf("1. dequeue \n");
        printf("2. peek at rear \n");
        printf("3. peek at front \n");
        printf("4. get the queue size \n");
        printf("5. check if the queue is empty \n");
        printf("6. display the queue \n");
        printf("7. delete the queue and quit \n");


        printf("\n\n");
        printf("enter your choice: \n");
        printf("================== \n");
        scanf("%zu", &choice);
        printf("\n");


        switch (choice) {
            case 0:
                // enqueue at rear
                printf("enter the element: \n");
                data = (int *) malloc(sizeof(int));
                if (data == NULL) {
                    return false;
                }
                scanf("%d", data);
                return_type = enqueue(&my_queue, (void *) data);  // pass the an address
                if (return_type == true) {
                    printf("enqueue at rear: %d \n", *data);
                } else {
                    printf("unable to enqueue \n");
                }
                break;

            case 1:
                // dequeue from front
                return_type = dequeue(&my_queue, (void **) &out_data);
                if (return_type == true) {
                    printf("dequeue from front : %d \n", *(int *) out_data);
                } else {
                    printf("unable to dequeue \n");
                }
                break;

            case 2:
                // peek at rear
                return_type = peek_at_rear(&my_queue, (void **) &out_data);
                if (return_type == true) {
                    printf("peek at rear : %d \n", *(int *) out_data);
                } else {
                    printf("unable to peek \n");
                }
                break;

            case 3:
                // peek at front
                return_type = peek_at_front(&my_queue, (void **) &out_data);
                if (return_type == true) {
                    printf("peek at front : %d \n", *(int *) out_data);
                } else {
                    printf("unable to peek \n");
                }
                break;

            case 4:
                // get the queue size
                queue_size = get_queue_size(&my_queue);
                printf("queue size: %zu \n", queue_size);
                break;

            case 5:
                // check if the queue is empty
                return_type = is_empty_queue(&my_queue);
                printf("is empty: %d \n", return_type);
                break;

            case 6:
                // display the queue
                printf("display: ");
                display_queue(&my_queue, my_func);
                printf("\n");
                break;

            case 7:
                // delete the queue
                return_type = delete_queue(&my_queue);
                if (return_type == true) {
                    printf("deleted the queue \n");
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
