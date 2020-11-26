/*
 * author: greyshell
 * description: find kth max elements in an array without sorting
 *  - best comparison based sorting would take O(n*log(n)) time
 *  - if the items are integers, then non-comparison based sorting (counting sort) would take O(n)
 *  time
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../libO2/include/binary_heap_dynamic_array_int.h"

void k_largest_elements_02(int *arr, int n, int k) {
    /*
     * time complexity: O(n + k*log(n)), works faster when k <= n/2
     * space complexity: O(1)
     */
    heap h;
    int data;

    // create a max heap of size n
    build_heap(&h, true, arr, n);

    for (int i = 0; i < k; i++) {
        pop_heap(&h, &data);
        printf("%d ", data);
    }
    printf("\n");

    delete_heap(&h);
}

void k_largest_elements(int *arr, int n, int k) {
    /*
     * time complexity: O(n*log(k)), works faster when k > n/2
     * space complexity: O(k)
     * works better when k > n/2
     */
    heap h;
    size_t heap_size;
    int data;

    // create a min heap, initial capacity = k
    // heap implementation is backed by dynamic array so we can insert any nos of elements
    initialize_heap(&h, k, false);

    for (int i = 0; i < n; i++) {
        push_heap(&h, arr[i]);
        get_heap_size(&h, &heap_size);
        // if the heap size exceeds k, pop an item to maintain the size = k
        if (heap_size > k) {
            pop_heap(&h, &data);
        }
    }

    display_heap(&h);
    printf("\n");
    delete_heap(&h);
}

int main(void) {
    int arr[] = {10, 2, 30, 50, 200, 70};
    int n = 6, k = 4;
    k_largest_elements(arr, n, k);
    k_largest_elements_02(arr, n, k);
    return 0;
}