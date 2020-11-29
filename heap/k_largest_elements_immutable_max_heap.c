/*
 * author: greyshell
 * description: find kth largest elements in a immutable max heap
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../libO2/include/binary_heap_dynamic_array_int.h"


void kth_largest_elements_immutable_max_heap(heap *h_immutable, int n, int k, int *out_arr) {
    /*
     * time complexity:
     * space complexity:
     */
    heap h;
    int out_data;
    size_t top_idx;

    // create a max heap
    initialize_heap(&h, k, true);

    // Put top element in heap
    push_heap(&h, 0);

    for (int i = 0;i<k;i++) {
        pop_heap(&h, (int *)&top_idx);
        peek_heap_by_index(&h, top_idx, &out_arr[i]);

        size_t left_child = get_heap_node_left_child_index(top_idx);
        size_t right_child = get_heap_node_right_child_index(top_idx);
        push_heap(&h, left_child);
        push_heap(&h, right_child);
    }


    delete_heap(&h);
}

/* 17 7 16 2 3 15 14 <- h_immutable

 Init: 17

 1'st: 16 7 [17]

 2'nd: 15 7 14 [17, 16]

 3rd: 14 7 [17, 16, 15]

 4th: 7 [17, 16, 15, 14]

*/


int main(void) {
    // test the solution
    int test_arr[] = {7, 17, 16, 2, 3, 15, 14};
    int n = 7;
    int k = 4;
    int out_arr[4] = {0};
    heap h;

    build_heap(&h, true, test_arr, 7);
    display_heap(&h);


    kth_largest_elements_immutable_max_heap(&h, n, k, out_arr);

    // expected output: 17, 16, 15, 14
//    for (int i = 0; i < k; i++){
//        printf("%d ", out_arr[i]);
//    }
//    printf("\n");

    return 0;
}