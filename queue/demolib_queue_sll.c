/*
 * author: greyshell
 * description: test singly linked list based implementation of queue
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/queue/queue_sll.h"

void my_display(void *data) {
    printf("%d ", *(int *) data);
}

int main(void) {
    size_t queue_size;
    queue my_queue;
    int *out_data;
    int return_type;
    int data = 30;
    // declare a function pointer that points to my_display() function
    // typedef void my_func(void *);
    my_func *func_ptr = my_display;

    // initialize the queue
    printf("create the queue \n");
    initialize_queue(&my_queue);

    // enqueue at rear
    return_type = enqueue(&my_queue, &data);
    if (return_type == true) {
        printf("enqueue at rear: %d \n", data);
    } else {
        printf("unable to enqueue \n");
    }
    // check if the queue is empty
    return_type = is_empty_queue(&my_queue);
    printf("is empty: %d \n", return_type);

    // get queue size
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

    // display queue elements
    display_queue(&my_queue, func_ptr);
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
        printf("queue deletion successful \n");
    } else {
        printf("unable to delete queue \n");
    }

    return 0;
}
