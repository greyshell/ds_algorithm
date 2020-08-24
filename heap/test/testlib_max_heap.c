/*
 * author: greyshell
 * description: test singly linked list based implementation of queue
 * */

#include <stdio.h>
#include "stdbool.h"

#include "../../private_libs/heap/heap.h"


int main(void) {
    int data, capacity = 7, out_data = 0;
    bool max_heap = true;
    size_t choice, heap_size;
    heap h;
    bool return_type;

    // initialize the queue
    printf("create the heap \n");
    initialize_heap(&h, capacity, max_heap);

    insert_heap(&h, 50);
    insert_heap(&h, 40);
    insert_heap(&h, 200);
    insert_heap(&h, 60);
    insert_heap(&h, 30);
    insert_heap(&h, 70);
    insert_heap(&h, 100);
    peek_heap(&h, &out_data);
    printf("peek = %d \n", out_data);
    display_heap(&h);
    printf("\n");

    get_heap_size(&h, &heap_size);
    printf("heap size: %zu \n", heap_size);

    remove_heap(&h, &out_data);
    printf("removed: %d \n", out_data);
    display_heap(&h);
    printf("\n");

    delete_heap(&h);

    return 0;
}
