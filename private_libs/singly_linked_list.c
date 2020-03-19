/*
 * author: greyshell
 * description: implementation of singly linked list
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "singly_linked_list.h"

void initialize_singly_linked_list(singly_linked_list *list) {
    /*
     * time complexity: O(1)
     * space complexity: O(1)
     */
    list->head = NULL;
}

bst_node *get_node(singly_linked_list *list, int data) {
    /*
     * if found then return the node_pointer else return NULL
     * time complexity: O(n), find the position
     * space complexity: O(1), for temporary pointer variable
     */
    bst_node *curr_ptr;

    curr_ptr = list->head;
    while (curr_ptr != NULL) {
        if (curr_ptr->data == data) {
            return curr_ptr;
        }
        curr_ptr = curr_ptr->next;
    }
    return NULL;  // covers the scenario when head is NULL / data is not found
}

bst_node *get_kth_node(singly_linked_list *list, size_t k) {
    /*
     * 1 traversal / pass
     * assuming list index starts from 0
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bst_node *curr_ptr = list->head;
    size_t count;

    if (list->head == NULL) {
        printf("\nsingly_linked_list is empty ");
        return NULL;
    }

    // move the curr_ptr by k nodes
    count = 1;
    while (count <= k && curr_ptr != NULL) {
        curr_ptr = curr_ptr->next;
        count++;
    }

    return curr_ptr;
}

bst_node *get_kth_node_from_end(singly_linked_list *list, size_t k) {
    /*
     * 1 traversal / pass
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bst_node *first_ptr, *second_ptr;
    size_t count;
    first_ptr = second_ptr = list->head;

    // k = 1 means last node
    if (k < 1) {
        printf("\nk < 1, invalid k");
        return NULL;
    }

    if (list->head == NULL) {
        printf("\nsingly_linked_list is empty ");
        return NULL;
    }

    // move the first_ptr by k nodes so that the gap between first_ptr and second_prt is k
    count = 1;
    while (count <= k && first_ptr != NULL) {
        first_ptr = first_ptr->next;
        count++;
    }

    // when k is more than that singly_linked_list length
    if (--count < k) {
        printf("\nk > singly_linked_list length !!");
        return NULL;
    }

    while (first_ptr != NULL) {
        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next;
    }

    return second_ptr;
}

bst_node *get_middle_node(singly_linked_list *list) {
    /*
     * time complexity: O(n), scan the linked singly_linked_list only 1 time.
     * space complexity: O(1), temporary pointer variable
     */
    bst_node *fast_ptr, *slow_ptr;

    if (list->head == NULL) {
        printf("\nsingly_linked_list is empty");
        return NULL;
    }

    fast_ptr = slow_ptr = list->head;
    // when the singly_linked_list count_singly_linked_list >= 2
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;  // if the singly_linked_list count_singly_linked_list is 1 the it returns NULL
}

bool is_empty_singly_linked_list(singly_linked_list *list) {
    if (list->head == NULL) {
        return true;
    }
    return false;
}

size_t count_singly_linked_list(singly_linked_list *list) {
    /*
     * time complexity: O(n)
     * space complexity: O(1) -> temporary pointer variables
     */
    bst_node *curr_ptr;
    size_t count = 0;
    curr_ptr = list->head;

    while (curr_ptr != NULL) {
        ++count;
        curr_ptr = curr_ptr->next;
    }
    return count;
}

void display_singly_linked_list(singly_linked_list *list) {
    /*
     * time complexity: O(n)
     * space complexity: O(1) -> temporary pointer variables
     */
    bst_node *curr_ptr;

    if (list->head == NULL) {
        printf("\nsingly_linked_list is empty !!");
        return;
    }

    curr_ptr = list->head;
    while (curr_ptr != NULL) {
        printf("%d ", curr_ptr->data);
        curr_ptr = curr_ptr->next;
    }
}

void reverse_display(bst_node *head) {
    /*
     * time complexity: O(n)
     * space complexity: O(n) -> maximum depth of the call stack
     */
    if (head == NULL) {
        return;
    }
    reverse_display(head->next);
    printf("%d ", head->data);
}

void wrapper_reverse_display_singly_linked_list(singly_linked_list *list) {
    /*
     * time complexity: O(n)
     * space complexity: O(n) -> maximum depth of the call stack
     */
    if (list->head == NULL) {
        return;
    }
    reverse_display(list->head->next);
}

void insert_at_head(singly_linked_list *list, int data) {
    /*
     * time complexity: O(1)
     * space complexity: O(1)
     */
    bst_node *temp_node;

    // create a new node
    temp_node = (bst_node *) malloc(sizeof(bst_node));
    temp_node->data = data;

    // link the node where head points to
    temp_node->next = list->head;

    // update the head
    list->head = temp_node;
}

void insert_at_tail(singly_linked_list *list, int data) {
    /*
     * time complexity: O(n), find the last element and insert at the end
     * space complexity: O(1), for creating the temporary pointer variable
     */
    bst_node *curr_ptr, *temp_node;

    // create a new node
    temp_node = (bst_node *) malloc(sizeof(bst_node));
    temp_node->data = data;
    temp_node->next = NULL;

    // when the singly_linked_list is empty then head and tail both are same
    if (list->head == NULL) {
        // update the head
        list->head = temp_node;
        return;
    }
    // when the singly_linked_list is non empty, traverse the singly_linked_list till the end
    curr_ptr = list->head;
    while (curr_ptr->next != NULL) {
        curr_ptr = curr_ptr->next;
    }
    // at this point curr_ptr points to the last node and curr_ptr->next point to NULL
    // link the new node after the last node
    curr_ptr->next = temp_node;
}

void insert_at_index(singly_linked_list *list, int data, size_t index) {
    /*
     * time complexity: O(n), find the last element and insert at the end
     * space complexity: O(1), for creating the temporary pointer variable
     */
    bst_node *temp_node, *curr_ptr;
    size_t pos = 0;

    // special case: when the given index is 0, singly_linked_list can be empty
    if (index == 0) {
        return insert_at_head(list, data);
    }
        // case: when the given index is greater than 1
    else {
        curr_ptr = list->head;
        pos = 1;
        /*
         * while traversing the singly_linked_list, when we checks for the given index with singly_linked_list pos,
         * the curr_ptr pointer should point to previous my_node, so that the new my_node can be inserted
         * between (k-1)th and kth my_node.
         */

        while (curr_ptr != NULL) {
            if (pos == index && curr_ptr->next != NULL) {
                // create the my_node
                temp_node = (bst_node *) malloc(sizeof(bst_node));
                temp_node->data = data;
                // curr_ptr points to the previous node and we need to insert the temp node after this
                // my_node link the new my_node with the next my_node address where the curr_ptr points
                temp_node->next = curr_ptr->next;
                // update the curr_ptr with the new my_node address
                curr_ptr->next = temp_node;  // connect the new my_node with the present my_node
            }
            pos++;
            curr_ptr = curr_ptr->next;
        }
        // iterate the entire singly_linked_list but the given index not found
        printf("\nunable to create the node, given index is not found !!");
    }
}

int delete_at_head(singly_linked_list *list) {
    /*
     * time complexity: O(1)
     * space complexity: O(1), for temporary pointer variable
     */
    bst_node *temp_node;
    int data;

    if (list->head == NULL) {
        printf("\nsingly_linked_list is empty, returning INT_MIN");
        return INT_MIN;
    }
    // copy the present head to temp
    temp_node = list->head;
    data = temp_node->data;

    // update the head with next node
    list->head = list->head->next;
    // free the temp node
    free(temp_node);
    return data;
}

int delete_at_tail(singly_linked_list *list) {
    /*
     * note: use get_kth_node_from_end() function, k = 2 means second node from last
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bst_node *temp_node, *second_last_node;
    int data;
    const size_t k = 2;

    second_last_node = get_kth_node_from_end(list, k);
    if (second_last_node == NULL) {
        printf("\nnode not found");
        return INT_MIN;
    }
    temp_node = second_last_node->next;
    data = temp_node->data;
    second_last_node->next = NULL;
    free(temp_node);

    return data;
}

int delete_at_index(singly_linked_list *list, size_t index) {
    /*
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bst_node *temp_node, *prev_node;
    int data;

    if (index == 0) {
        data = delete_at_head(list);
        return data;
    }

    prev_node = get_kth_node(list, index - 1);
    if (prev_node == NULL) {
        printf("\nnode not found, returning INT_MIN");
        return INT_MIN;
    }
    temp_node = prev_node->next;
    data = temp_node->data;
    prev_node->next = temp_node->next;
    free(temp_node);

    return data;
}

int delete_kth_node_from_end(singly_linked_list *list, size_t k){
    /*
     * time complexity:
     * space complexity:
     */
    bst_node *prev_node, *temp_node;
    int data;
    prev_node = get_kth_node_from_end(list, k + 1);
    if (prev_node == NULL){
        printf("\n node not found, returning INT_MIN");
        return INT_MIN;
    }

    if (prev_node == list->head){
        data = delete_at_head(list);
        return data;
    }

    temp_node = prev_node->next;
    data = temp_node->data;
    prev_node->next = temp_node->next;
    free(temp_node);

    return data;

}

void delete_element(singly_linked_list *list, int data) {
    bst_node *temp_node, *curr_ptr, *prev_ptr;

    if (list->head == NULL) {
        printf("\nsingly_linked_list is empty, returning INT_MIN as index");
        return;
    }
    // if the data is present in first node / head
    if (list->head->data == data) {
        delete_at_head(list);
        return;
    }
    // if the data is present in second node to last
    curr_ptr = prev_ptr = list->head;

    while (curr_ptr != NULL) {
        if (curr_ptr->data == data) {
            temp_node = curr_ptr;
            prev_ptr->next = temp_node->next;
            free(temp_node);
            return;
        }
        prev_ptr = curr_ptr;
        curr_ptr = curr_ptr->next;
    }

    printf("\nelement = %d not found", data);
    return;
}

void delete_all(singly_linked_list *list) {
    /*
     * time complexity: O(n)
     * space complexity: O(1), temporary pointer variable
     */
    bst_node *temp_node, *curr_ptr;

    if (list->head == NULL) {
        printf("singly_linked_list is empty");
        return;
    }

    curr_ptr = list->head;
    while (curr_ptr != NULL) {
        temp_node = curr_ptr;
        curr_ptr = curr_ptr->next;
        list->head = curr_ptr;
        free(temp_node);
    }
    list->head = NULL;
}

