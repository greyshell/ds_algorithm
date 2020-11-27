/*
 * author: greyshell
 * description: tests singly linked list based implementation of queue
 * */

#include <stdio.h>
#include "stdbool.h"

#include "../libO2/include/queue_singly_linkedlist_int.h"


int main(void) {
    int data, out_data = 0;
    size_t choice, queue_size;
    queue my_queue;
    int return_type;

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
                scanf("%d", &data);
                printf("operation: enqueue, data_arr: %d \n", data);
                return_type = enqueue(&my_queue, data);
                if (return_type == true) {
                    printf("enqueued at rear \n");
                } else {
                    printf("unable to enqueue \n");
                }
                break;

            case 1:
                // dequeue from front
                printf("operation: dequeue \n");
                return_type = dequeue(&my_queue, &out_data);
                if (return_type == true) {
                    printf("dequeue from front : %d \n", out_data);
                } else {
                    printf("unable to dequeue \n");
                }
                break;

            case 2:
                // peek at rear
                printf("operation: peek_at_rear \n");
                return_type = peek_at_rear(&my_queue, &out_data);
                if (return_type == true) {
                    printf("peek at rear : %d \n", out_data);
                } else {
                    printf("unable to peek \n");
                }
                break;

            case 3:
                // peek at front
                printf("operation: peek_at_front \n");
                return_type = peek_at_front(&my_queue, &out_data);
                if (return_type == true) {
                    printf("peek at front : %d \n", out_data);
                } else {
                    printf("unable to peek \n");
                }
                break;

            case 4:
                // get the queue size
                printf("operation: get_queue_size \n");
                queue_size = get_queue_size(&my_queue);
                printf("queue size: %zu \n", queue_size);
                break;

            case 5:
                // check if the queue is empty
                printf("operation: is_empty_queue \n");
                return_type = is_empty_queue(&my_queue);
                printf("is empty: %d \n", return_type);
                break;

            case 6:
                // display the queue
                printf("operation: display_queue \n");
                printf("display: ");
                display_queue(&my_queue);
                printf("\n");
                break;

            case 7:
                // delete the queue
                printf("operation: delete_queue \n");
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
