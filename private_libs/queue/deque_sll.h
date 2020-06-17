/*
 * author: greyshell
 * description: singly linked list implementation of deque
 * data: void pointer / an address that points to void
 * */

#ifndef DEQUE_SLL_H__
#define DEQUE_SLL_H__

#include "stdbool.h"

typedef struct my_node {
    void *data;
    struct my_node *next;
} linkedlist_node;

typedef struct my_queue {
    linkedlist_node *front;
    linkedlist_node *rear;
    size_t size;
} deque;

void initialize_deque(deque *);

bool is_empty_deque(deque *);

size_t get_deque_size(deque *);

bool enqueue_at_rear(deque *, void *);

bool dequeue_from_front(deque *, void **);

bool enque_at_front(deque *, void *);

bool deque_from_rear(deque *, void **);

bool peek_at_front(deque *, void **);

bool peek_at_rear(deque *, void **);

bool delete_queue(deque *);

#endif // DEQUE_SLL_H__
