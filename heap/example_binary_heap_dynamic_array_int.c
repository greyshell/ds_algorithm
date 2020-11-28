/*
 * author: greyshell
 * description: tests heap
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

#include "../libO2/include/binary_heap_dynamic_array_int.h"


int main(void) {
    int out_data = 0;
    size_t heap_size;
    bool return_type;
    int test_arr[] = {5, 7, 70, 3, 1};

    heap h;

    printf("create & initialize the heap \n");
    initialize_heap(&h, 1, true);
    printf("heap capacity: %zu \n", h.current_capacity);

    // test heap_sort
    heap_sort(test_arr, 5, true);

    printf("sorted array: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", test_arr[i]);
    }
    printf("\n");

    push_heap(&h, 4);
    push_heap(&h, 2);
    push_heap(&h, 3);
    printf("heap capacity: %zu \n", h.current_capacity);
    pop_heap(&h, &out_data);
    printf("heap capacity: %zu \n", h.current_capacity);
    pop_heap(&h, &out_data);
    printf("heap capacity: %zu \n", h.current_capacity);
    pop_heap(&h, &out_data);
    pop_heap(&h, &out_data);
    pop_heap(&h, &out_data);
    printf("heap capacity: %zu \n", h.current_capacity);
    pop_heap(&h, &out_data);
    pop_heap(&h, &out_data);
    printf("---- \n");

    push_heap(&h, 9);
    push_heap(&h, 7);
    push_heap(&h, 19);

    push_heap(&h, 30);
    push_heap(&h, 10);
    push_heap(&h, 20);
    peek_heap(&h, &out_data);
    printf("peek = %d \n", out_data);
    display_heap(&h);
    printf("\n");

    heap_size = get_heap_size(&h);
    printf("heap size: %zu \n", heap_size);
    printf("heap capacity: %zu \n", h.current_capacity);

    pop_heap(&h, &out_data);
    pop_heap(&h, &out_data);
    printf("removed: %d \n", out_data);

    printf("heap capacity: %zu \n", h.current_capacity);
    display_heap(&h);
    printf("\n");

    printf("heap ptr: %p \n", &h);

    size_t index = 5;
    return_type = peek_heap_by_index(&h, index, &out_data);
    if (return_type){
        printf("value at index %zu is %d", index, out_data);
    }
    else{
        printf("invalid index");
    }

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

    printf("================== \n");

//    heap h3;
//    initialize_heap(&h3, 1, false);
//    push_heap(&h3, 1);
//    push_heap(&h3, 5);
//    push_heap(&h3, 6);
//    push_heap(&h3, 9);
//    push_heap(&h3, 11);
//    push_heap(&h3, 8);
//    push_heap(&h3, 15);
//    push_heap(&h3, 17);
//    push_heap(&h3, 21);
//
//    display_heap(&h3);
//    printf("\n");
//
//    return_type = pop_heap_by_index(&h3, 1, &out_data);
//    if (return_type == false){
//        printf("unable to remove \n");
//    }
//    printf("removed = %d \n", out_data);
//
//    display_heap(&h3);
//    printf("\n");
//
//    printf("================== \n");

    heap h3;
    initialize_heap(&h3, 1, false);
    push_heap(&h3, 1);
    push_heap(&h3, 9);
    push_heap(&h3, 22);
    push_heap(&h3, 17);
    push_heap(&h3, 11);
    push_heap(&h3, 33);
    push_heap(&h3, 27);
    push_heap(&h3, 21);
    push_heap(&h3, 19);

    display_heap(&h3);
    printf("\n");

    return_type = pop_heap_by_index(&h3, 5, &out_data);
    if (return_type == false){
        printf("unable to remove \n");
    }
    printf("removed = %d \n", out_data);

    display_heap(&h3);
    printf("\n");

    return 0;
}
