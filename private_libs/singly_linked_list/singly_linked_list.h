/*
 * author: greyshell
 * */

#ifndef SINGLY_LINKEDLIST_H__
#define SINGLY_LINKEDLIST_H__

#include <stdint.h>
#include "stdbool.h"


typedef struct my_node {
    int data;
    struct my_node *next;
} linkedlist_node;


typedef struct my_singly_linked_list {
    linkedlist_node *head;
} singly_linked_list;


void initialize_singly_linked_list(singly_linked_list *list);

linkedlist_node *get_node(singly_linked_list *, int);

linkedlist_node *get_kth_node(singly_linked_list *, size_t);

linkedlist_node *get_kth_node_from_end(singly_linked_list *, size_t);

linkedlist_node *get_middle_node(singly_linked_list *);

bool is_empty_singly_linked_list(singly_linked_list *);

size_t count_singly_linked_list(singly_linked_list *);

void display_singly_linked_list(singly_linked_list *);

void reverse_display(linkedlist_node *);

void reverse_display_singly_linked_list(singly_linked_list *);

void insert_at_head(singly_linked_list *, int);

void insert_at_tail(singly_linked_list *, int);

void insert_at_index(singly_linked_list *, int, size_t);

int delete_at_head(singly_linked_list *);

int delete_at_tail(singly_linked_list *);

int delete_at_index(singly_linked_list *, size_t);

int delete_kth_node_from_end(singly_linked_list *, size_t);

void delete_element(singly_linked_list *, int);

void delete_all(singly_linked_list *);

/*
 * TO DO:
 * void *reverse_singly_linked_list(singly_linked_list *);
 * bool is_palindrome_singly_linked_list(singly_linked_list *);
 * void insertion_sort_single_linked_list(singly_linked_list *);
 * void *merge_two_sorted_singly_linked_list(singly_linked_list *, singly_linked_list *, singly_linked_list *);
 *
 * */

#endif // SINGLY_LINKEDLIST_H__