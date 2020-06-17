/*
 * author: greyshell
 * description: singly linked list based implementation of deque
 * data / key: void pointer
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "deque_sll.h"

void initialize_deque(deque *q) {
    /*
     * create the deque
     * time complexity: O(1)
     * space complexity: O(1)
     */
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool is_empty_deque(deque *q) {
    /*
     * return true if the deque if empty, else return false
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (q->front == NULL) {
        return true;
    }
    return false;
}

size_t get_deque_size(deque *q) {
    /*
     * return the deque size
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return q->size;
}

bool enqueue_at_rear(deque *q, void *data) {
    /*
     * add an element into the deque
     * if insertion is successful then return true else return false
     * time complexity: O(1)
     * space complexity: O(1)
     */
    linkedlist_node *temp_node;

    // create a new node
    temp_node = (linkedlist_node *) malloc(sizeof(linkedlist_node));
    if (temp_node == NULL) {
        return false;
    }
    // insert an address as data to the queue
    temp_node->data = data;
    temp_node->next = NULL;

    // special case: check if the inserting node is the 1st node
    if (is_empty_deque(q)) {
        q->rear = temp_node;
        q->front = temp_node;
        q->size++;
    } else {
        // link the previous node
        q->rear->next = temp_node;
        // update the rear to the present node
        q->rear = temp_node;
        q->size++;
    }
    return true;
}

bool dequeue_from_front(deque *q, void **out_data) {
    /*
     * remove an element from the deque
     * if removal is successful then return true else return false
     * time complexity: O(1)
     * space complexity: O(1)
     */
    linkedlist_node *temp_node;

    if (is_empty_deque(q)) {
        return false;
    }

    temp_node = q->front;
    // spacial case: when queue has 1 element
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    *out_data = temp_node->data;
    free(temp_node);
    q->size--;
    return true;
}

bool peek_at_front(deque *q, void **out_data) {
    /*
     * display the element at front
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_deque(q)) {
        return false;
    }
    *out_data = q->front->data;
    return true;
}

bool peek_at_rear(deque *q, void **out_data) {
    /*
     * display the element at rear
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_deque(q)) {
        return false;
    }
    *out_data = q->rear->data;
    return true;
}

