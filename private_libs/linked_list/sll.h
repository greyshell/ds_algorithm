/*
 * author: greyshell
 * */

#ifndef SLL_H__
#define SLL_H__

#include <stdint.h>
#include <lzma.h>
#include "stdbool.h"

typedef void view_singly_linked_list(void *);

typedef bool compare_singly_linked_list(void *, void *);

typedef struct list {
    void *data;
    struct list *next;
} sll_node;


typedef struct {
    sll_node *head;
} singly_linked_list;


void initialize_sll(singly_linked_list *);

size_t get_sll_size(singly_linked_list *);

bool is_empty_sll(singly_linked_list *);

bool insert_sll_node_at_head(singly_linked_list *, void *);

bool insert_sll_node_at_tail(singly_linked_list *, void *);

bool insert_sll_node_at_index(singly_linked_list *, void *, size_t);

bool delete_sll_node_at_head(singly_linked_list *, void **);

bool delete_sll_node_at_tail(singly_linked_list *, void **);

bool delete_sll_node_at_index_from_head(singly_linked_list *, size_t, void **);

bool delete_sll_node_at_index_from_tail(singly_linked_list *, size_t, void **);

bool delete_sll_node_if_found(singly_linked_list *, void *, compare_singly_linked_list *, void **);

bool delete_sll(singly_linked_list *);

void display_sll(singly_linked_list *, view_singly_linked_list *);

void reverse_display_sll(singly_linked_list *, view_singly_linked_list *);

bool is_found_in_sll(singly_linked_list *, void *, compare_singly_linked_list *, size_t *);

bool get_kth_element_in_sll_from_head(singly_linked_list *, size_t, void **);

bool get_kth_element_in_sll_from_tail(singly_linked_list *, size_t, void **);

bool get_middle_element_in_sll(singly_linked_list *, void **);

#endif // SLL_H__
