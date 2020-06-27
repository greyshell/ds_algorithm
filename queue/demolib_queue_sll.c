/*
 * author: greyshell
 * description: test singly linked list based implementation of queue
 * data / key -> void pointer
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/queue/queue_sll.h"

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
}

int main(void) {
    size_t queue_size;
    queue my_queue;
    int *out_data;
    bool return_type;
    int data = 30;

    // initialize the queue
    printf("create the queue \n");
    initialize_queue(&my_queue);

    // note: make sure that you insert an address
    // enqueue at rear
    return_type = enqueue(&my_queue, &data);
    if (return_type == true) {
        printf("enqueued at rear: %d \n", data);
    } else {
        printf("unable to enqueue \n");
    }

    // check if the queue is empty
    return_type = is_empty_queue(&my_queue);
    printf("is empty: %d \n", return_type);

    // get the queue size
    queue_size = get_queue_size(&my_queue);
    printf("queue size: %zu \n", queue_size);

    // peek at rear
    return_type = peek_at_rear(&my_queue, (void **) &out_data);
    if (return_type == true) {
        printf("peek at rear : %d \n", *out_data);
    } else {
        printf("unable to peek \n");
    }

    // peek at front
    return_type = peek_at_front(&my_queue, (void **) &out_data);
    if (return_type == true) {
        printf("peek at front : %d \n", *out_data);
    } else {
        printf("unable to peek \n");
    }

    // display the queue
    printf("display: ");
    display_queue(&my_queue, my_display);
    printf("\n");

    // dequeue from front
    return_type = dequeue(&my_queue, (void **) &out_data);
    if (return_type == true) {
        printf("dequeue from front : %d \n", *out_data);
    } else {
        printf("unable to dequeue \n");
    }

    // delete the queue
    return_type = delete_queue(&my_queue);
    if (return_type == true) {
        printf("deleted the queue \n");
    } else {
        printf("unable to delete \n");
    }

    return 0;
}
