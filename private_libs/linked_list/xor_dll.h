/*
 * author: greyshell
 * description: memory efficient / XOR doubly linked list
 * data / key -> void pointer
 * */

#ifndef XOR_DLL_H__
#define XOR_DLL_H__

#include <stdint.h>
#include <lzma.h>
#include "stdbool.h"

typedef void view_doubly_linked_list(void *);

typedef bool compare_doubly_linked_list(void *, void *);

typedef struct list {
    void *data;
    size_t ptr_diff;
} xor_dll_node;


typedef struct {
    xor_dll_node *head;
    xor_dll_node *tail;
    size_t size;
} doubly_linked_list;


void initialize_dll(doubly_linked_list *);

size_t get_dll_size(doubly_linked_list *);

bool is_empty_dll(doubly_linked_list *);

bool insert_dll_node_at_head(doubly_linked_list *, void *);

bool insert_dll_node_at_tail(doubly_linked_list *, void *);

bool insert_dll_node_at_index(doubly_linked_list *, void *, size_t);

bool delete_dll_node(doubly_linked_list *, void *, compare_doubly_linked_list *);

bool delete_dll_node_at_head(doubly_linked_list *, void *);

bool delete_dll_node_at_tail(doubly_linked_list *, void *);

bool delete_dll_node_at_index(doubly_linked_list *, void *, size_t);

bool delete_dll(doubly_linked_list *);

void display_dll(doubly_linked_list *, view_doubly_linked_list *);

void reverse_display_dll(doubly_linked_list *, view_doubly_linked_list *);

bool find_element_in_dll(doubly_linked_list *, void *, compare_doubly_linked_list *);

#endif // XOR_DLL_H__
