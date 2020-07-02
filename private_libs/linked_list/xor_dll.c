/*
 * author: greyshell
 * description: memory efficient / XOR doubly linked list
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "xor_dll.h"

void initialize_dll(doubly_linked_list *l) {
    /*
     * create the doubly linked list
     * time complexity: O(1)
     * space complexity: O(1)
     */
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

size_t get_dll_size(doubly_linked_list *l) {
    /*
     * get the size of the list
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return l->size;
}

bool is_empty_dll(doubly_linked_list *l) {
    /*
     * check if the list is empty
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (l->head == NULL) {
        return true;
    }
    return false;
}

bool insert_dll_node_at_head(doubly_linked_list *l, void *data) {
    /*
     * insert an element at head
     * time complexity: O(1)
     * space complexity: O(1)
     */
    xor_dll_node *temp_node;
    xor_dll_node *next_node = l->head;

    // create a new node
    temp_node = (xor_dll_node *) malloc(sizeof(xor_dll_node));
    if (temp_node == NULL) {
        return false;
    }
    temp_node->data = data;
    temp_node->ptr_diff = (size_t) next_node;
    if (!is_empty_dll(l)) {
        // update the tail when adding the 1st element
        l->head->ptr_diff ^= (size_t) temp_node;
        l->tail = temp_node;
    }
    l->head = temp_node;
    l->size++;
    return true;
}

void display_dll(doubly_linked_list *l, view_doubly_linked_list *func_ptr) {
    /*
     * display elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    xor_dll_node *curr_node = l->head;
    xor_dll_node *prev_node = NULL;
    xor_dll_node *next_node;
    while (curr_node != NULL) {
        func_ptr(curr_node->data);
        // calculate the next node
        next_node = (xor_dll_node *) ((size_t) prev_node ^ (size_t) (curr_node->ptr_diff));
        // set the prev node
        prev_node = curr_node;
        // update the curr node
        curr_node = next_node;
    }
}

static bool _get_dll_prev_curr_node(doubly_linked_list *l, void *key, compare_doubly_linked_list
*func_ptr, xor_dll_node **prev_node, xor_dll_node **curr_node) {
    /*
     * get the curr and prev node when the key is found
     * time complexity: O(n)
     * space complexity: O(1)
     */
    xor_dll_node *next_node;
    *curr_node = l->head;
    *prev_node = NULL;

    while (*curr_node != NULL) {
        if (func_ptr((*curr_node)->data, key)) {
            return true;
        }
        // update the curr_ptr to next node
        next_node = (xor_dll_node *) ((size_t) *prev_node ^ (size_t) ((*curr_node)->ptr_diff));
        *prev_node = *curr_node;
        *curr_node = next_node;
    }

    return false;
}

bool find_element_in_dll(doubly_linked_list *l, void *key, compare_doubly_linked_list *func) {
    /*
     * find an element in doubly linked list
     * time complexity: O(n)
     * space complexity: O(1)
     */
    void *prev_node, *curr_node;
    return _get_dll_prev_curr_node(l, key, func, (xor_dll_node **) &prev_node,
                                   (xor_dll_node **) &curr_node);
}


bool delete_dll_node(doubly_linked_list *l, void *key, compare_doubly_linked_list *func) {
    /*
     * delete an element if found
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bool return_type;
    xor_dll_node *prev_node, *curr_node, *prev_prev_node, *next_node, *nex_next_node;

    return_type = _get_dll_prev_curr_node(l, key, func, (xor_dll_node **) &prev_node,
                                          (xor_dll_node **) &curr_node);
    if (return_type == false) {
        return false;
    }

    next_node = (xor_dll_node *) ((size_t) prev_node ^ (size_t) curr_node->ptr_diff);

    if (prev_node != NULL) {
        prev_prev_node = (xor_dll_node *) ((size_t) prev_node->ptr_diff ^ (size_t) curr_node);
        prev_node->ptr_diff = ((size_t) prev_prev_node ^ (size_t) next_node);
    } else {
        l->head = next_node;
    }
    if (next_node != NULL) {
        nex_next_node = (xor_dll_node *) (next_node->ptr_diff ^ (size_t) curr_node);
        next_node->ptr_diff = ((size_t) prev_node ^ (size_t) nex_next_node);
    }

    if (l->tail == curr_node) {
        l->tail = prev_node;
    }

    free(curr_node);
    l->size--;
    return true;

}

bool delete_dll(doubly_linked_list *l) {
    /*
     * delete xor doubly linked list
     * time complexity: O(n)
     * space complexity: O(1)
     */
    xor_dll_node *curr_node = l->head;
    xor_dll_node *prev_node = NULL;
    xor_dll_node *next_node;

    while (curr_node != NULL) {
        // calculate the next node
        next_node = (xor_dll_node *) ((size_t) prev_node ^ (size_t) (curr_node->ptr_diff));
        // set the prev node
        prev_node = curr_node;
        // update the curr node
        curr_node = next_node;
    }
    return 1;
}