/*
 * author: greyshell
 * description: implementation of singly linked list
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sll.h"

void initialize_sll(singly_linked_list *list) {
    /*
     * initialize the list
     * time complexity: O(1)
     * space complexity: O(1)
     */
    list->head = NULL;
}

size_t get_sll_size(singly_linked_list *list) {
    /*
     * get the size of the list
     * time complexity: O(1)
     * space complexity: O(1)
     */
    sll_node *curr_ptr;
    size_t count = 0;
    curr_ptr = list->head;

    while (curr_ptr != NULL) {
        count++;
        curr_ptr = curr_ptr->next;
    }
    return count;
}

bool is_empty_sll(singly_linked_list *list) {
    /*
     * check if the list is empty
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (list->head == NULL) {
        return true;
    }
    return false;
}

void display_sll(singly_linked_list *list, view_singly_linked_list *func_ptr) {
    /*
     * display list elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    sll_node *curr_ptr;
    curr_ptr = list->head;

    while (curr_ptr != NULL) {
        func_ptr(curr_ptr->data);
        curr_ptr = curr_ptr->next;
    }
}

static void _rev_dsp_sll(sll_node *curr_ptr, view_singly_linked_list *func_ptr) {
    /*
     * helper function that displays the list elements in reverse order
     * time complexity: O(n)
     * space complexity: O(n) -> for call stack
     */
    if (curr_ptr == NULL) {
        return;
    }
    _rev_dsp_sll(curr_ptr->next, func_ptr);
    func_ptr(curr_ptr->data);
}

void reverse_display_sll(singly_linked_list *list, view_singly_linked_list *func_ptr) {
    /*
     * reverse display list elements
     * time complexity: O(n)
     * space complexity: O(n)
     */
    if (list->head == NULL) {
        return;
    }
    _rev_dsp_sll(list->head, func_ptr);
}

bool insert_sll_node_at_head(singly_linked_list *list, void *data) {
    /*
     * insert node at head
     * time complexity: O(1)
     * space complexity: O(1)
     */

    sll_node *temp_node;

    // create a new node
    temp_node = (sll_node *) malloc(sizeof(sll_node));

    if (temp_node == NULL) {
        return false;
    }
    temp_node->data = data;

    // link the node where head points to
    temp_node->next = list->head;

    // update the head
    list->head = temp_node;

    return true;
}

bool insert_sll_node_at_tail(singly_linked_list *list, void *data) {
    /*
     * insert node at tail
     * time complexity: O(1)
     * space complexity: O(1)
     */

    sll_node *temp_node, *curr_ptr;

    // create a new node
    temp_node = (sll_node *) malloc(sizeof(sll_node));

    if (temp_node == NULL) {
        return false;
    }
    temp_node->data = data;
    temp_node->next = NULL;

    // when the list is empty then head and tail both are same
    if (list->head == NULL) {
        // update the head
        list->head = temp_node;
    } else {
        // when the singly_linked_list is non empty, traverse the singly_linked_list till the end
        curr_ptr = list->head;
        while (curr_ptr->next != NULL) {
            curr_ptr = curr_ptr->next;
        }
        // at this point curr_ptr points to the last node and curr_ptr->next point to NULL
        // link the new node after the last node
        curr_ptr->next = temp_node;
    }
    return true;
}

bool insert_sll_node_at_index(singly_linked_list *list, void *data, size_t index) {
    /*
     * insert node at a given index
     * time complexity: O(1)
     * space complexity: O(1)
     */
    sll_node *temp_node, *curr_ptr;
    size_t position;
    bool flag = false;

    // special case: when the given index is 0, singly_linked_list can be empty
    if (index == 0) {
        return insert_sll_node_at_head(list, data);
    }
        // case: when the given index is greater than 1
    else {
        curr_ptr = list->head;
        position = 1;
        // while traversing the singly_linked_list, when we checks for the given index with
        // singly_linked_list pos the curr_ptr pointer should point to previous my_node, so that
        // the new my_node can be inserted between (k-1)th and kth my_node.
        while (curr_ptr != NULL) {
            if (position == index && curr_ptr->next != NULL) {
                // create the my_node
                temp_node = (sll_node *) malloc(sizeof(sll_node));
                temp_node->data = data;
                // curr_ptr points to the previous node and we need to insert the temp node after this
                // my_node link the new my_node with the next my_node address where the curr_ptr points
                temp_node->next = curr_ptr->next;
                // update the curr_ptr with the new my_node address
                curr_ptr->next = temp_node;  // connect the new my_node with the present my_node
                flag = true;
            }
            position++;
            curr_ptr = curr_ptr->next;
        }

        // iterate the entire singly_linked_list but the given index not found
        if (flag == false) {
            return false;
        }
    }
    return true;
}

bool delete_sll_node_at_head(singly_linked_list *list, void **out_data) {
    /*
     * delete node at head
     * time complexity: O(1)
     * space complexity: O(1)
     */
    sll_node *temp_node;

    if (list->head == NULL) {
        return false;
    }
    // copy the present head to temp
    temp_node = list->head;
    *out_data = temp_node->data;

    // update the head with next node
    list->head = list->head->next;
    // free the temp node
    free(temp_node);
    return true;
}

static bool _get_kth_sll_node_from_tail(singly_linked_list *list, size_t k, sll_node **out_node) {
    /*
     * helper function that returns the kth node from tail of the list, where 1 <= k <= size
     * time complexity: O(n)
     * space complexity: O(1)
     */
    sll_node *first_ptr, *second_ptr;
    size_t count, linked_list_size;
    first_ptr = second_ptr = list->head;

    linked_list_size = get_sll_size(list);

    if (list->head == NULL) {
        return false;
    }

    // check for invalid k
    if (k < 1 || k > linked_list_size) {
        return false;
    }

    if (linked_list_size == 1) {
        *out_node = list->head;
        return true;
    }
    // move the first_ptr by k nodes
    // so that the distance between first_ptr and second_prt is k
    count = 0;
    while (count < k) {
        first_ptr = first_ptr->next;
        count++;
    }

    while (first_ptr != NULL) {
        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next;
    }

    *out_node = second_ptr;
    return true;
}

bool get_kth_element_in_sll_from_tail(singly_linked_list *list, size_t k, void **out_data) {
    /*
     * get the kth element from tail
     * time complexity: O(n)
     * space complexity: O(1)
     */
    sll_node *out_node;
    bool return_type;

    return_type = _get_kth_sll_node_from_tail(list, k, &out_node);
    if (return_type == false) {
        return false;
    }
    *out_data = out_node->data;
    return true;
}

static bool _get_kth_sll_node_from_head(singly_linked_list *list, size_t k, sll_node **out_node) {
    /*
     * helper function that returns the kth node from head the list, where 0 <= k < size
     * time complexity: O(n)
     * space complexity: O(1)
     */
    sll_node *curr_ptr;
    size_t count, linked_list_size;


    linked_list_size = get_sll_size(list);

    if (list->head == NULL) {
        return false;
    }

    // check for invalid k
    if (k < 0 || k > linked_list_size - 1) {
        return false;
    }

    count = 0;
    curr_ptr = list->head;
    while (count < k) {
        curr_ptr = curr_ptr->next;
        count++;
    }

    *out_node = curr_ptr;
    return true;
}

bool get_kth_element_in_sll_from_head(singly_linked_list *list, size_t k, void **out_data) {
    /*
     * get the kth element from head
     * time complexity: O(n)
     * space complexity: O(1)
     */
    sll_node *out_node;
    bool return_type;

    return_type = _get_kth_sll_node_from_head(list, k, &out_node);
    if (return_type == false) {
        return false;
    }
    *out_data = out_node->data;
    return true;
}


bool delete_sll_node_at_index_from_head(singly_linked_list *list, size_t index, void **out_data) {
    /*
     * delete element at a given index
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bool return_type;
    sll_node *temp_node, *prev_node;
    sll_node *out_node;

    if (index == 0) {
        return_type = delete_sll_node_at_head(list, out_data);
        if (return_type == false) {
            return false;
        } else {
            return true;
        }

    }
    return_type = _get_kth_sll_node_from_head(list, index - 1, &out_node);
    if (return_type == false) {
        return false;
    }
    prev_node = out_node;

    temp_node = prev_node->next;
    *out_data = temp_node->data;
    prev_node->next = temp_node->next;
    free(temp_node);

    return true;
}

bool delete_sll_node_at_tail(singly_linked_list *list, void **out_data) {
    /*
     * delete from tail
     * note: use get_kth_node_from_end() function, k = 2 means second node from last
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bool return_type;
    sll_node *last_node, *second_last_node;
    size_t linked_list_size;
    const size_t k = 2;

    linked_list_size = get_sll_size(list);
    if (linked_list_size == 1) {
        *out_data = list->head->data;
        free(list->head);
        list->head = NULL;
        return true;
    }
    return_type = _get_kth_sll_node_from_tail(list, k, &second_last_node);

    if (return_type == false) {
        return false;
    }

    last_node = second_last_node->next;
    *out_data = last_node->data;
    second_last_node->next = NULL;
    free(last_node);

    return true;
}

bool delete_sll_node_at_index_from_tail(singly_linked_list *list, size_t index, void **out_data) {
    /*
     * delete element at given index from tail
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bool return_type;
    sll_node *temp_node, *prev_node;
    sll_node *out_node;
    size_t linked_list_size;

    linked_list_size = get_sll_size(list);

    // case: remove head node
    if (index == linked_list_size) {
        return_type = delete_sll_node_at_head(list, out_data);
        if (return_type == false) {
            return false;
        }
        return true;
    }

    return_type = _get_kth_sll_node_from_tail(list, index + 1, &out_node);
    if (return_type == false) {
        return false;
    }

    prev_node = out_node;

    if (prev_node == NULL) {
        return_type = delete_sll_node_at_head(list, out_data);
        if (return_type == false) {
            return false;
        }
        return true;
    }

    temp_node = prev_node->next;
    *out_data = temp_node->data;
    prev_node->next = temp_node->next;
    free(temp_node);

    return true;
}

bool delete_sll(singly_linked_list *list) {
    /*
     * delete the entire list
     * time complexity: O(n)
     * space complexity: O(1), temporary pointer variable
     */
    sll_node *temp_node, *curr_ptr;

    if (list->head == NULL) {
        return false;
    }

    curr_ptr = list->head;
    while (curr_ptr != NULL) {
        temp_node = curr_ptr;
        curr_ptr = curr_ptr->next;
        list->head = curr_ptr;
        free(temp_node);
    }
    // at this point there will be only 1 element in the list
    free(list->head);
    list->head = NULL;
    return true;
}

static bool _get_sll_prev_curr_node(singly_linked_list *list, void *key,
                                    size_t *out_found_key_index, compare_singly_linked_list
                                    *func_ptr, sll_node **prev_node, sll_node **curr_node) {
    /*
     * helper function to get the curr and prev node when the key is found
     * time complexity: O(n)
     * space complexity: O(1)
     */
    *curr_node = list->head;
    *prev_node = NULL;
    *out_found_key_index = 0;

    while (*curr_node != NULL) {
        if (func_ptr((*curr_node)->data, key)) {
            return true;
        }
        // update the curr_ptr to next node
        *prev_node = *curr_node;
        *curr_node = (*curr_node)->next;
        *out_found_key_index = *out_found_key_index + 1;
    }
    return false;
}

bool is_found_in_sll(singly_linked_list *list, void *key, compare_singly_linked_list *func_ptr,
                     size_t *out_found_key_index) {
    /*
     * find an element in the list and return the index
     * time complexity: O(n)
     * space complexity: O(1)
     */
    void *prev_node, *curr_node;
    return _get_sll_prev_curr_node(list, key, out_found_key_index, func_ptr, (sll_node **)
            &prev_node, (sll_node **) &curr_node);
}

bool delete_sll_node_if_found(singly_linked_list *list, void *key, compare_singly_linked_list
*func_ptr, void **out_data) {
    /*
     * delete the element if found
     * time complexity: O(n)
     * space complexity: O(1)
     */
    size_t out_found_index;
    bool return_type;

    return_type = is_found_in_sll(list, key, func_ptr, &out_found_index);
    if (return_type == false) {
        return false;
    }

    return_type = delete_sll_node_at_index_from_head(list, out_found_index, out_data);
    if (return_type == false) {
        return false;
    }

    return true;
}

bool get_middle_element_in_sll(singly_linked_list *list, void **out_data) {
    /*
     * scan the linked singly_linked_list only 1 time to find the middle
     * time complexity: O(n)
     * space complexity: O(1)
 */
    sll_node *fast_ptr, *slow_ptr;

    if (list->head == NULL) {
        return false;
    }

    fast_ptr = slow_ptr = list->head;
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    *out_data = slow_ptr->data;

    return true;
}