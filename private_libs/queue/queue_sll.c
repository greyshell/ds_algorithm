/*
 * author: greyshell
 * description: singly linked list based implementation of queue
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "queue_sll.h"

void initialize_queue(queue *q) {
    /*
     * create the queue
     * time complexity: O(1)
     * space complexity: O(1)
     */
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool is_empty_queue(queue *q) {
    /*
     * return true if the queue if empty, else return false
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (q->front == NULL) {
        return true;
    }
    return false;
}

size_t get_queue_size(queue *q) {
    /*
     * return the queue size
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return q->size;
}

bool enqueue(queue *q, void *data) {
    /*
     * insert an element at the rear
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

    temp_node->data = data;
    temp_node->next = NULL;

    // special case: check if the inserting node is the 1st node
    if (is_empty_queue(q)) {
        q->rear = temp_node;
        q->front = temp_node;
    } else {
        // link the last added node pointed by rear
        q->rear->next = temp_node;
        // update the rear to the present node
        q->rear = temp_node;
    }
    q->size++;
    return true;
}

bool dequeue(queue *q, void **out_data) {
    /*
     * remove an element from front
     * if removal is successful then return true else return false
     * time complexity: O(1)
     * space complexity: O(1)
     */
    linkedlist_node *temp_node;

    if (is_empty_queue(q)) {
        return false;
    }

    temp_node = q->front;
    // spacial case: when queue has only 1 element that we are trying to delete
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

bool peek_at_front(queue *q, void **out_data) {
    /*
     * display the element at front
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_queue(q)) {
        return false;
    }
    *out_data = q->front->data;
    return true;
}

bool peek_at_rear(queue *q, void **out_data) {
    /*
     * display the element at rear
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_queue(q)) {
        return false;
    }
    *out_data = q->rear->data;
    return true;
}

bool delete_queue(queue *q) {
    /* remove all elements and empty the queue
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bool return_type;
    void *out_data;

    while (is_empty_queue(q) != true) {
        return_type = dequeue(q, &out_data);
        if (return_type == false) {
            return false;
        }
    }
    return true;
}

void display_queue(queue *q, view_queue_func *func_ptr) {
    /* display all queue elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    linkedlist_node *curr_ptr;

    if (is_empty_queue(q)) {
        return;
    }
    curr_ptr = q->front;

    while (curr_ptr != NULL) {
        func_ptr(curr_ptr->data);
        curr_ptr = curr_ptr->next;
    }
    return;
}