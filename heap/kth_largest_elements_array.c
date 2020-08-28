/*
 * author: greyshell
 * description: find kth max elements in an array
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/heap/heap.h"

void k_largest_elements_02(int *arr, int n, int k) {
    /*
     * time complexity: O(n + k*log(n))
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
     * time complexity: O(n*log(k)), O(log(k) -> 1 hence it will be O(n)
     * space complexity: O(k)
     */
    heap h;
    size_t heap_size;
    int data;

    // create a min heap of size k
    initialize_heap(&h, k, false);

    for (int i = 0; i < n; i++) {
        push_heap(&h, arr[i]);
        get_heap_size(&h, &heap_size);
        // check if the heap overflows
        if (heap_size == k + 1) {
            pop_heap(&h, &data);
        }
    }

    display_heap(&h);
    printf("\n");
    delete_heap(&h);
}

int main(void) {
    int arr[] = {10, 2, 30, 50, 1, 70};
    int n = 6, k = 3;
    k_largest_elements(arr, n, k);
    k_largest_elements_02(arr, n, k);
    return 0;
}