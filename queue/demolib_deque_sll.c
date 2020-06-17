/*
 * author: greyshell
 * description: test singly linked list based implementation of deque
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/queue/deque_sll.h"

int main(void) {
    size_t queue_size;
    deque my_deque;
    int *out_data_addr;
    int return_type;
    int data[] = {30, 40, 50, 70, 90};

    // initialize the queue
    printf("creating the queue \n");
    initialize_deque(&my_deque);

    for (int i = 0; i < 5; i++) {
        // enqueue at rear
        return_type = enqueue_at_rear(&my_deque, &data[i]);  // pass the addr of the element
        if (return_type == true) {
            printf("enque at rear: %d \n", data[i]);
        } else {
            printf("unable to enque \n");
        }
    }

    // check if the deque is empty
    return_type = is_empty_deque(&my_deque);
    printf("is empty: %d \n", return_type);

    // get queue size
    queue_size = get_deque_size(&my_deque);
    printf("queue size: %zu \n", queue_size);

    // peek at rear
    return_type = peek_at_rear(&my_deque, (void **) &out_data_addr);
    if (return_type == true) {
        printf("peek rear : %d \n", *out_data_addr);
    } else {
        printf("unable to peek \n");
    }

    // peek at front
    return_type = peek_at_front(&my_deque, (void **) &out_data_addr);
    if (return_type == true) {
        printf("peek front : %d \n", *out_data_addr);
    } else {
        printf("unable to peek \n");
    }

    for (int i = 0; i < 5; i++) {
        // dequeue at front
        return_type = dequeue_from_front(&my_deque, (void **) &out_data_addr);
        if (return_type == true) {
            printf("deque from front : %d \n", *out_data_addr);
        } else {
            printf("unable to deque \n");
        }
    }

    // check if the deque is empty
    return_type = is_empty_deque(&my_deque);
    printf("is empty: %d \n", return_type);

    // get queue size
    queue_size = get_deque_size(&my_deque);
    printf("queue size: %zu \n", queue_size);

    return 0;
}
