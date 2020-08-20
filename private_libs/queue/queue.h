/*
 * author: greyshell
 * description: queue
 * */

#ifndef QUEUE_H__
#define QUEUE_H__

#include <lzma.h>
#include "stdbool.h"

typedef struct list {
    int data;
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

bool enqueue(queue *, int);

bool dequeue(queue *, int *);

bool peek_at_front(queue *, int *);

bool peek_at_rear(queue *, int *);

bool delete_queue(queue *);

void display_queue(queue *);

#endif // QUEUE_H__
