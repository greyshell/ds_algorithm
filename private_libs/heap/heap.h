/*
 * author: greyshell
 * description: heap
 * */

#ifndef HEAP_H__
#define HEAP_H__

#include <lzma.h>
#include "stdbool.h"

typedef struct {
    bool type;  // true: max_heap, false: min_heap
    size_t size;
    size_t initial_capacity;
    size_t current_capacity;
    int *data_arr;
    bool is_called_build_heap;  // used to attach an existing array during build_heap()
} heap;

bool initialize_heap(heap *h, size_t, bool);

bool is_empty_heap(heap *h);

bool get_heap_size(heap *, size_t *);

bool push_heap(heap *h, int data);

bool pop_heap(heap *h, int *out_data);

bool peek_heap(heap *, int *);

bool delete_heap(heap *);

void display_heap(heap *);

bool build_heap(heap *, bool, int *, size_t);

// exposing heapify_down() for heap_sort() defined in sorting/sort.c
void heapify_down(heap *, size_t);

#endif // HEAP_H__
