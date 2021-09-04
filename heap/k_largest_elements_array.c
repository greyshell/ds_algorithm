/*
 * author: greyshell
 * description: find k largest elements in an array without sorting
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../libO2/include/binary_heap_dynamic_array_int.h"

void k_largest_elements_02(int *arr, int n, int k, int *out_arr) {
    /*
     * time complexity: O(n + k*log(n))
     * space complexity: O(1)
     */
    heap h;
    int data;

    // create a max heap of size n
    build_heap(&h, true, arr, n);  // O(n)

    for (int i = k - 1; i >= 0; i--) {
        pop_heap(&h, &data);  // O(k*log(n))
        out_arr[i] = data;
    }

    delete_heap(&h);
}

void k_largest_elements(int *test_arr, int n, int k, int *out_arr) {
    /*
     * time complexity: O(n*log(k))
     * space complexity: O(k)
     */
    heap h;
    size_t heap_size;
    int out_data;

    // create a min heap, initial capacity = k
    // heap implementation is backed by dynamic array so we can insert any nos of elements
    initialize_heap(&h, k, false);

    for (int i = 0; i < n; i++) {
        push_heap(&h, test_arr[i]);
        heap_size = get_heap_size(&h);
        // if the heap size exceeds k, pop an item to maintain the size = k
        if (heap_size > k) {
            pop_heap(&h, &out_data);
        }
    }
    // copy the heap elements in the out_arr
    for (int i = 0; i < k; i++){
        pop_heap(&h, &out_data);
        out_arr[i] = out_data;
    }
    delete_heap(&h);
}
