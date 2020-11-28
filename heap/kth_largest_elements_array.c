/*
 * author: greyshell
 * description: find kth largest elements in an array without sorting
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../libO2/include/binary_heap_dynamic_array_int.h"

void kth_largest_elements_array_02(int *arr, int n, int k, int *out_arr) {
    /*
     * time complexity: O(n + k*log(n)), works faster when k <= n/2
     * space complexity: O(1)
     */
    heap h;
    int data;

    // create a max heap of size n
    build_heap(&h, true, arr, n);

    for (int i = k - 1; i >= 0; i--) {
        pop_heap(&h, &data);
        out_arr[i] = data;
    }

    delete_heap(&h);
}

void kth_largest_elements_array(int *test_arr, int n, int k, int *out_arr) {
    /*
     * time complexity: O(n*log(k)), works faster when k > n/2
     * space complexity: O(k)
     * works better when k > n/2
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

/* ========== disable main =============

int main(void) {
    // test the solution
    int test_arr[] = {10, 20, 30, 50, 90, 70, 80, 40};
    int n = 8;
    int k = 3;
    int out_arr[3] = {0};
    int out_arr2[3] ={0};

    kth_largest_elements_array(test_arr, n, k, out_arr);
    // print the out_arr
    for (int i = 0; i < k; i++){
        printf("%d ", out_arr[i]);
    }
    printf("\n");

    kth_largest_elements_array_02(test_arr, n, k, out_arr2);
    // print the out_arr
    for (int i = 0; i < k; i++){
        printf("%d ", out_arr2[i]);
    }
    printf("\n");

    return 0;
}

*/