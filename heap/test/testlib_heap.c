/*
 * author: greyshell
 * description: test heap
 * */

#include <stdio.h>
#include "stdbool.h"

#include "../../private_libs/heap/heap.h"


int main(void) {
    int data, initial_capacity = 7, out_data = 0;
    size_t choice, heap_size;
    heap h;
    bool return_type;

    // initialize the queue
    printf("create the heap \n");
    initialize_heap(&h, initial_capacity, true);

    insert_heap(&h, 4);
    insert_heap(&h, 2);
    insert_heap(&h, 3);
    insert_heap(&h, 9);
    insert_heap(&h, 7);
    insert_heap(&h, 9);
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

    printf("\ntest: build heap \n");

    int a[7] = {10, 20, 30, 40, 150, 70, 160};
    heap h1;
    // display the array
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // initialize_heap(&h1, 3, true);
    build_heap(&h1, true, a, 7);
    display_heap(&h1);
    printf("\n");
    peek_heap(&h1, &out_data);
    printf("peek = %d \n", out_data);
    delete_heap(&h1);

    // display the array: heap structure deleted
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
