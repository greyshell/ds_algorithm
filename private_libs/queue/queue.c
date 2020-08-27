/*
 * author: greyshell
 * description: singly linked list based implementation of queue, data_arr: int
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "queue.h"

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
     * check if the queue is empty
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
     * get the size of the queue
     * time complexity: O(1)
     * space complexity: O(1)
     */
    return q->size;
}

bool enqueue(queue *q, int data) {
    /*
     * insert an element at rear / tail
     * time complexity: O(1)
     * space complexity: O(1)
     */
    queue_node *temp_node;

    // create a new node
    temp_node = (queue_node *) malloc(sizeof(queue_node));
    if (temp_node == NULL) {
        return false;
    }

    temp_node->data = data;
    temp_node->next = NULL;

    // special case: check if the inserting node is the 1st node
    if (is_empty_queue(q) == true) {
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

bool dequeue(queue *q, int *out_data) {
    /*
     * remove an element from front / head
     * time complexity: O(1)
     * space complexity: O(1)
     */
    queue_node *temp_node;

    if (is_empty_queue(q) == true) {
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

bool peek_at_front(queue *q, int *out_data) {
    /*
     * display the element at front
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_queue(q) == true) {
        return false;
    }
    *out_data = q->front->data;
    return true;
}

bool peek_at_rear(queue *q, int *out_data) {
    /*
     * display the element at rear
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (is_empty_queue(q) == true) {
        return false;
    }
    *out_data = q->rear->data;
    return true;
}

bool delete_queue(queue *q) {
    /* remove all elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bool return_type;
    int out_data;

    while (is_empty_queue(q) == false) {
        return_type = dequeue(q, &out_data);
        if (return_type == false) {
            return false;
        }
    }
    return true;
}

void display_queue(queue *q) {
    /* display all elements
     * time complexity: O(n)
     * space complexity: O(1)
     */
    queue_node *curr_node;
    curr_node = q->front;

    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    return;
}