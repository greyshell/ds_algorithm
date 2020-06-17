/*
 * author: greyshell
 * description: singly linked list implementation of queue
 * data: void pointer / an address that points to void
 * */

#ifndef QUEUE_SLL_H__
#define QUEUE_SLL_H__

#include "stdbool.h"

typedef void view_queue_func(void *);

typedef struct my_node {
    void *data;
    struct my_node *next;
} linkedlist_node;

typedef struct my_queue {
    linkedlist_node *front;
    linkedlist_node *rear;
    size_t size;
} queue;

void initialize_queue(queue *);

bool is_empty_queue(queue *);

size_t get_queue_size(queue *);

bool enqueue(queue *, void *);

bool dequeue(queue *, void **);

bool peek_at_front(queue *, void **);

bool peek_at_rear(queue *, void **);

bool delete_queue(queue *);

void display_queue(queue *, view_queue_func *);

#endif // QUEUE_SLL_H__