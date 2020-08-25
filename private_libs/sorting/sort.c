/*
 * author: greyshell
 * description: implementation of sorting algorithms
 * */


#include <stdio.h>
#include <stdlib.h>
#include <z3.h>
#include "sort.h"
#include "../heap/heap.h"

static void _swap(int *a, int *b) {
    /*
     * time complexity: O(1) | space complexity: O(1)
     */
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

static int _find_max(int *arr, int n) {
    /*
     * time complexity: O(1) | space complexity: O(1)
     */
    int max = *(arr + 0);  // pointer notation 
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

static int _find_min(int *arr, int n) {
    /*
     * time complexity: O(1) | space complexity: O(1)
     */
    int min = arr[0];  // array notation
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void display_array(int *arr, size_t n) {
    /*
     * time complexity: O(n) | space complexity: O(1)
     */
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void counting_sort(int *arr, int *output_arr, size_t n) {
    /*
     * property:
     * =========
     * - takes the advantage of special properties of keys
     * - perform the sorting by key indexing / using keys as indices
     * - another name: key-indexed counting sort
     * - present implementation supports the negative integers and use the dynamic array to build
     * the auxiliary array
     * - stable sorting algorithm, preserves the relative ordering of keys.
     * - this is not in-place sorting algorithm. however, an another variant uses
     * in-place sort to avoid the auxiliary array in the cost of compromising the stability factor.
     *
     * time complexity:
     * ================
     * - O(n) -> provided the range of the distinct key values is within a constant
     * factor of the file / input size.
     *
     * space complexity:
     * =================
     * - a auxiliary array -> O(k) and the output array -> O(n) is required
     *
     */
    int max = _find_max(arr, n); // O(n)
    int min = _find_min(arr, n); // O(n)
    size_t range = max - min + 1;

    if (arr == NULL || output_arr == NULL) {
        return;
    }

    // dynamically generates the auxiliary array using calloc(), default value is set to 0
    int *auxiliary_array = (int *) calloc(range, sizeof(int));

    // pick each key from the array and go to particular index of auxiliary array and track the total count_singly_linked_list
    for (int i = 0; i < n; i++) {
        auxiliary_array[arr[i] - min]++;
    }

    // prepare the cumulative sum
    for (int i = 1; i <= range; i++) {
        auxiliary_array[i] = auxiliary_array[i] + auxiliary_array[i - 1];
    }

    // calculate each key's last index
    for (int i = 0; i <= range; i++) {
        auxiliary_array[i] = auxiliary_array[i] - 1;
    }

    // start from picking up the last element
    // then place that element into it's last index of the output array
    for (int i = n - 1; i >= 0; i--) {
        output_arr[auxiliary_array[arr[i] - min]] = arr[i];
        auxiliary_array[arr[i] - min]--;
    }

}

void cocktail_sort(int *arr, size_t n) {
    /*
     * property:
     * =========
     * - bidirectional bubble sort / cocktail shaker sort / shuttle sort
     * - the algorithm extends the bubble sort by operating in two directions.
     * - time and space complexity is same as bubble sort
     * - it is just a minor performance improvement => cocktail sort < 2 * bubble sort
     */
    int is_swapped = 0;
    int left_index = 0;
    int right_index = n - 1;

    if (arr == NULL) {
        return;
    }

    while (1) {
        is_swapped = 0;
        // objective: push the smaller element to the left most
        for (int i = right_index; i > left_index; i--) {
            // if the right element is smaller than the left element then perform _swap_heap_nodes
            if (arr[i] < arr[i - 1]) {
                _swap(&arr[i], &arr[i - 1]);
                is_swapped = 1;
            }
        }
        // improvement: if the array is sorted then we don't need to perform another iteration
        if (is_swapped == 0) {
            // no _swap_heap_nodes occurs inside the inner loop which means now the array is sorted
            break;
        }
        // resent the is_swapped flag
        is_swapped = 0;
        // left index has already the min value so increment the pointer
        left_index++;
        // objective: push the highest element to the right most
        for (int i = left_index; i < right_index; i++) {
            if (arr[i] > arr[i + 1]) {
                _swap(&arr[i], &arr[i + 1]);
                is_swapped = 1;
            }
        }

        if (is_swapped == 0) {
            // no _swap_heap_nodes occurs inside the inner loop which means now the array is sorted
            break;
        }

        right_index--;
    }
}

void bubble_sort(int *arr, size_t n) {
    /*
     * property:
     * =========
     * - compare adjacent elements and place the small element at the left.
     * - after 1st pass of the outer loop, the smallest element bubbles up at the 0th index.
     * - every passes of outer loop, builds up a small sorted array of small elements
     * from left to right.
     * - at any point of time if the program crashes then also we can get a sorted sub-array
     * where all elements are placed in their actual positions.
     * - in order to find kth smallest element, we need kth pass of the outer loop -> O(k*n)
     * - effective on array data_arr structure not linked list
     * - used for internal sorting: uses the main memory exclusively
     * - stable: preserves the relative order of the duplicate items / keys,
     *      - interchange only occurs when the right_element < left_element
     *      - due to that, for duplicate keys, interchange does not happen
     * - where cost (in terms of time complexity) of moving data_arr / swaps dominates
     * the cost of making comparisons
     * there bubble sort is not a good choice.
     * - cocktail sort is a variation of bubble sort. minor performance improvement through
     * bi-directional sort,
     * means bubbling up the smallest and the largest element in single pass.
     * although the all time complexities are same, but insertion sort takes less swaps
     * comparing to bubble sort.
     * - bubble is not use anywhere in real life.
     *
     *  time complexity:
     *  ================
     *  - worst case / tight upper bound: when the input array is reversely sorted -> o(n^2)
     *      - 1st pass -> n comparisons and at most n swaps
     *      - 2nd pass -> n - 1 comparisons and at most n - 1 swaps
     *      - total comparisons =  n + (n -1) + (n-2) + .. 1 -> n*(n-1)/2 -> n^2
     *      - total swaps = n^2
     *  - best case / tight lower bound: when the input array is already sorted -> Ω(n)
     *      - total comparisons = (n-1)
     *      - total swaps = 0
     *      - adaptive: algorithm takes the advantage of 'existing order of input' to
     *      reduce the running time.
     *  - average case: considering the random distribution of elements -> o(n^2)
     *      - total comparisons = n^2
     *      - total swaps = n^2
     *  - not an optimal algorithm as best and worst case time complexities are different
     *
     * space complexity:
     * =================
     *  - in-place / in-memory sorting: no auxiliary space is required
     *  - non recursive: call stack max depth -> none
     *  - takes constant time -> Θ(1): best and worst case space complexities are same.
     */
    int i, j;
    bool is_swapped;

    if (arr == NULL) {
        return;
    }

    for (i = 0; i < n; i++) {
        is_swapped = false;
        // after the 1st pass of the outer loop, the smallest element bubbles up in the 0th index
        // inner loop is used to compare the adjacent elements
        for (j = n - 1; j > i; j--) {
            // if the right element is smaller than the left element then perform _swap_heap_nodes
            if (arr[j] < arr[j - 1]) {
                _swap(&arr[j], &arr[j - 1]);
                is_swapped = true;
            }
        }
        // improvement: if the array is sorted then we don't need to perform another iteration
        if (is_swapped == false) {
            // no _swap_heap_nodes occurs inside the inner loop which means now the array is sorted
            break;
        }
    }
}

void heap_sort(int *arr, size_t n, bool sort_type) {
    /*
     * use auxiliary data structure: max heap -> sort type: asc
     * in-place sorting
     * time complexity: O(n*log(n))
     * space complexity: O(1)
     */
    size_t i;
    heap h;

    if (arr == NULL) {
        return;
    }

    // initialize the heap
    h.type = sort_type;
    // assign the existing array for in-place sorting
    h.data_arr = arr;

    h.initial_capacity = n;
    h.current_capacity = n;
    h.size = 0;

    // build the heap: O(log(n))
    build_heap(&h, arr, n);

    for (i = n - 1; i > 0; i--) {
        _swap(&arr[0], &arr[i]);
        h.size--;
        heapify_down(&h, 0);
    }
}