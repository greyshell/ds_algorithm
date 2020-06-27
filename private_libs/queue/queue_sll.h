/*
 * author: greyshell
 * description: singly linked list based implementation of queue
 * data / key -> void pointer
 * */

#ifndef QUEUE_SLL_H__
#define QUEUE_SLL_H__

#include "stdbool.h"

typedef void view_queue_func(void *);

typedef struct list {
    void *data;
    struct list *next;
} queue_node;

typedef struct {
    queue_node *front;
    queue_node *rear;
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
