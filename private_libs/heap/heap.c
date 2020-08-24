/*
 * author: greyshell
 * description: dynamic array based implementation of heap
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "heap.h"

static void swap(heap *h, size_t i, size_t j) {
    int temp = h->data_arr[i];
    h->data_arr[i] = h->data_arr[j];;
    h->data_arr[j] = temp;
}

static size_t get_left_child_index(size_t parent_index) {
    return 2 * parent_index + 1;
}

static size_t get_right_child_index(size_t parent_index) {
    return 2 * parent_index + 2;
}

static size_t get_parent_index(size_t child_index) {
    return (child_index - 1) / 2;
}

static bool has_left_child(heap *h, size_t index) {
    if (get_left_child_index(index) < h->size) {
        return true;
    }
    return false;
}

static bool has_right_child(heap *h, size_t index) {
    if (get_right_child_index(index) < h->size) {
        return true;
    }
    return false;
}

static bool has_parent(size_t index) {
    if (index != 0 && get_parent_index(index) >= 0) {
        return true;
    }
    return false;
}

static size_t left_child(heap *h, size_t index) {
    return h->data_arr[get_left_child_index(index)];
}

static size_t right_child(heap *h, size_t index) {
    return h->data_arr[get_right_child_index(index)];
}

static size_t parent(heap *h, size_t index) {
    return h->data_arr[get_parent_index(index)];
}

static bool _doubling_heap(heap *h) {
    /*
     * double up the size when it becomes full
     * note: when realloc() is unable to resized, then it creates a new memory block and
     * copy all the old data_arr into it.
     * time complexity: O(n) -> worst case
     * space complexity: O(1)
     */
    // note: too many doubling may cause memory overflow exception
    h->data_arr = realloc(h->data_arr, (h->current_capacity * 2) * sizeof(int));
    if (h->data_arr == NULL) {
        return false;
    }
    h->current_capacity *= 2;
    return true;
}

static bool _halving_heap(heap *h) {
    /*
     * halving the size when half of the spaces are empty
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (h->current_capacity == h->initial_capacity) {
        return false;
    }

    h->data_arr = realloc(h->data_arr, (h->current_capacity / 2) * sizeof(int));
    if (h->data_arr == NULL) {
        return false;
    }
    h->current_capacity /= 2;
    return true;
}

static void _heapify_up(heap *h, size_t n) {
    /*
     * bottom up heapify
     */
    size_t p_index, index = n;

    // max heap logic: >
    while (has_parent(index) && h->data_arr[index] > parent(h, index)) {
        p_index = get_parent_index(index);
        swap(h, p_index, index);
        index = get_parent_index(index);
    }

}

static void _heapify_down(heap *h) {
    /*
     * top down heapify
     */
    size_t index = 0;
    while (has_right_child(h, index)) {
        size_t greater_child_index = get_right_child_index(index);

        if (has_left_child(h, index) && left_child(h, index) > right_child(h, index)) {
            greater_child_index = get_left_child_index(index);
        }

        if (h->data_arr[index] > h->data_arr[greater_child_index]) {
            break;
        } else {
            swap(h, index, greater_child_index);
        }
        // move to the node we just swapped down
        index = greater_child_index;
    }
}

bool initialize_heap(heap *h, size_t capacity, bool type) {
    /*
     * create and initialize the heap
     * time complexity: O(1)
     * space complexity: O(1)
     */
    h->data_arr = malloc(capacity * sizeof(int));
    if (h->data_arr == NULL) {
        return false;
    }
    h->type = type;
    h->initial_capacity = capacity;
    h->current_capacity = capacity;
    h->size = 0;
    return true;
}

bool get_heap_size(heap *h, size_t *out_data) {
    if (is_empty_heap(h)) {
        return false;
    }
    *out_data = h->size;
    return true;
}


bool is_empty_heap(heap *h) {
    /*
     * check if the heap is empty
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (h->size == 0) {
        return true;
    }
    return false;
}

bool insert_heap(heap *h, int data) {
    /*
     * insert an element in the heap
     * time complexity: O(1)
     * space complexity: O(1)
     */
    bool return_type;

    if (h->size == h->current_capacity) {
        return_type = _doubling_heap(h);
        if (return_type == false) {
            return false;
        }
    }
    // place the data at the last
    // from conceptual heap structure point of view: at the bottom far right
    h->data_arr[h->size] = data;
    h->size++;
    // restore the heap structure by bubbling up the element
    _heapify_up(h, (h->size - 1));

    return true;
}

bool peek_heap(heap *h, int *out_data) {
    if (is_empty_heap(h) == true) {
        return false;
    }
    *out_data = h->data_arr[0];
    return true;
}

bool remove_heap(heap *h, int *out_data) {
    if (is_empty_heap(h) == true) {
        return false;
    }
    *out_data = h->data_arr[0];
    h->data_arr[0] = h->data_arr[h->size - 1];
    h->size--;
    _heapify_down(h);
    return true;
}

void display_heap(heap *h) {
    size_t counter;
    for (counter = 0; counter < h->size; counter++) {
        printf("%d ", h->data_arr[counter]);
    }
}

bool delete_heap(heap *h) {
    /*
     *
     */
    // how to determine that the initialization function has been called before
    if (h->data_arr == NULL) {
        return false;
    }
    free(h->data_arr);
    return true;
}