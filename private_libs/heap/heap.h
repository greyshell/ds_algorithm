/*
 * author: greyshell
 * description: max heap
 * */

#ifndef HEAP_H__
#define HEAP_H__

#include <lzma.h>
#include "stdbool.h"

typedef struct {
    bool type;  // non zero -> max heap
    size_t size;
    size_t initial_capacity;
    size_t current_capacity;
    int *data_arr;
} heap;

bool initialize_heap(heap *h, size_t, bool);

bool is_empty_heap(heap *h);

bool get_heap_size(heap *, size_t *);

bool insert_heap(heap *, int);

bool remove_heap(heap *, int *);

bool peek_heap(heap *, int *);

bool delete_heap(heap *);

void display_heap(heap *);

#endif // HEAP_H__
