/*
 * author: greyshell
 * description: dynamic array based implementation of heap
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "heap.h"

static void _swap_heap_nodes(heap *h, size_t i, size_t j) {
    /*
     * helper function: _swap_heap_nodes values between two nodes
     * time complexity: O(1)
     * space complexity: O(1)
     */
    int temp = h->data_arr[i];
    h->data_arr[i] = h->data_arr[j];;
    h->data_arr[j] = temp;
}

static size_t _get_left_child_index(size_t parent_index) {
    /*
     * helper function: get the left child index
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return 2 * parent_index + 1;
}

static size_t _get_right_child_index(size_t parent_index) {
    /*
     * helper function: get the right child
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return 2 * parent_index + 2;
}

static size_t _get_parent_index(size_t child_index) {
    /*
     * helper function: get the parent index
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return (child_index - 1) / 2;
}

static bool _has_left_child(heap *h, size_t index) {
    /*
     * helper function: check if the current node has any left child
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (_get_left_child_index(index) < h->size) {
        return true;
    }
    return false;
}

static bool _has_right_child(heap *h, size_t index) {
    /*
     * helper function: check if the current node has any right child
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (_get_right_child_index(index) < h->size) {
        return true;
    }
    return false;
}

static bool _has_parent(size_t index) {
    /*
     * helper function: check if the current node has any parent
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (index != 0 && _get_parent_index(index) >= 0) {
        return true;
    }
    return false;
}

static size_t _left_child(heap *h, size_t index) {
    /*
     * helper function: get the left child of a node
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return h->data_arr[_get_left_child_index(index)];
}

static size_t _right_child(heap *h, size_t index) {
    /*
     * helper function: get the right child of a node
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return h->data_arr[_get_right_child_index(index)];
}

static size_t _parent(heap *h, size_t index) {
    /*
     * helper function: get the parent of a node
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return h->data_arr[_get_parent_index(index)];
}

static bool _doubling_heap(heap *h) {
    /*
     * double up the size when it becomes full
     * note: when realloc() is unable to resized, then it creates a new memory block and
     * copy all the old data_arr into it.
     * note: too many doubling may cause memory overflow exception
     * time complexity: O(n) -> worst case
     * space complexity: O(1)
     */
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
     * bottom up heapify / bubbling up
     * time complexity: O(logN)
     * space complexity: O(1)
     */
    size_t p_index, index = n;

    if (h->type == true) {
        // max heap logic
        while (_has_parent(index) && h->data_arr[index] > _parent(h, index)) {
            p_index = _get_parent_index(index);
            _swap_heap_nodes(h, p_index, index);
            index = _get_parent_index(index);
        }
    } else {
        // min heap logic
        while (_has_parent(index) && h->data_arr[index] < _parent(h, index)) {
            p_index = _get_parent_index(index);
            _swap_heap_nodes(h, p_index, index);
            index = _get_parent_index(index);
        }
    }
}

void heapify_down(heap *h, size_t index) {
    /*
     * top down heapify / bubbling down
     * time complexity: O(logN)
     * space complexity: O(1)
     */
    if (h->type == true) {
        // max heap logic
        while (_has_left_child(h, index)) {
            size_t greater_child_index = _get_left_child_index(index);

            if (_has_right_child(h, index) && _right_child(h, index) > _left_child(h, index)) {
                greater_child_index = _get_right_child_index(index);
            }

            if (h->data_arr[index] > h->data_arr[greater_child_index]) {
                break;
            } else {
                _swap_heap_nodes(h, index, greater_child_index);
            }
            // move to the node we just swapped down
            index = greater_child_index;
        }
    } else {
        // min heap logic
        while (_has_left_child(h, index)) {
            size_t smaller_child_index = _get_left_child_index(index);

            if (_has_right_child(h, index) && _right_child(h, index) < _left_child(h, index)) {
                smaller_child_index = _get_right_child_index(index);
            }

            if (h->data_arr[index] < h->data_arr[smaller_child_index]) {
                break;
            } else {
                _swap_heap_nodes(h, index, smaller_child_index);
            }
            // move to the node we just swapped down
            index = smaller_child_index;
        }
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
    h->type = type; // non zero value means max heap
    h->initial_capacity = capacity;
    h->current_capacity = capacity;
    h->size = 0;
    return true;
}

bool get_heap_size(heap *h, size_t *out_data) {
    /*
     * get the heap size
     * time complexity: O(1)
     * space complexity: O(1)
     */
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
     * time complexity: O(log(n))
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
    /*
     * peek the high priority element
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_heap(h) == true) {
        return false;
    }
    *out_data = h->data_arr[0];
    return true;
}

bool remove_heap(heap *h, int *out_data) {
    /*
     * remove an element from the heap
     * time complexity: O(log(n))
     * space complexity: O(1)
     */
    if (is_empty_heap(h) == true) {
        return false;
    }
    *out_data = h->data_arr[0];
    h->data_arr[0] = h->data_arr[h->size - 1];
    h->size--;
    heapify_down(h, 0);
    return true;
}

void display_heap(heap *h) {
    /*
     * display heap elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    if (h != NULL) {
        size_t counter;
        for (counter = 0; counter < h->size; counter++) {
            printf("%d ", h->data_arr[counter]);
        }
    }
}

bool delete_heap(heap *h) {
    /*
     * delete the heap
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (h != NULL) {
        free(h->data_arr);
        h = NULL;
        return true;
    }
    return false;
}

bool build_heap(heap *h, int *arr, size_t n) {
    /*
     * heapify an array, bottom up approach
     * start from bottom and check if that node and its children maintains the heap property
     * time complexity: O(n)
     * space complexity: O(1)
     */
    size_t i;
    if (h == NULL) {
        return false;
    }

    h->initial_capacity = n;
    for (i = 0; i < n; i++) {
        h->data_arr[i] = arr[i];
    }

    h->size = n;
    // 1/2 elements are leaf nodes and those always satisfy the heap property, so discard those
    // start from the last level left most element to root
    // scanning from right to left, bottom to top
    for (i = (n - 1) / 2; i >= 0; i--) {
        heapify_down(h, i);
        // without this condition i gets the higher value due to unsigned in nature
        // check if the node is root
        if (i == 0) {
            break;
        }
    }
    return true;
}
