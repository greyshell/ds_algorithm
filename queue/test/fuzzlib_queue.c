/*
 * author: greyshell
 * description: fuzz queue
 * make -f fuzz_lib_with_afl SRC_FLD=queue/tests WRAPPER_PROG=fuzzlib_queue LIB_FLD=queue
 * LIB=queue
 * */

#include <stdio.h>
#include "stdbool.h"
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "../../liquid_oxygen/queue/queue.h"

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
}

int main(void) {
    int data, out_data = 0;
    size_t choice, queue_size;
    queue my_queue;
    int return_type;
    uint8_t number_operations;
    uint8_t operation_type;
    size_t ops_count = 11;

    // initialize the queue
    printf("create the queue \n");
    initialize_queue(&my_queue);
    number_operations = read8();
    printf("number of operations: %d \n", number_operations);

    for (int i = 0; i < number_operations; i++) {
        // choose the random operation
        operation_type = read8();
        switch (operation_type % ops_count) {
            case 0:
                // enqueue at rear
                printf("enter the element: \n");
                scanf("%d", &data);
                printf("operation: enqueue, data: %d \n", data);
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

            default:
                printf("wrong choice \n");
        }
    }

    delete_queue(&my_queue);
    return 0;

}
