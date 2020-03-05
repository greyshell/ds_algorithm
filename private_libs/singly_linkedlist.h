/*
 * author: greyshell
 * */

#ifndef SINGLY_LINKEDLIST_H__
#define SINGLY_LINKEDLIST_H__

typedef struct node {
    int data;
    struct node *next;
} singly_linkedlist;

void display(singly_linkedlist *);

void reverse_display(singly_linkedlist *);

void display_nth_last_node(singly_linkedlist *);

size_t count(singly_linkedlist *);

size_t search(singly_linkedlist *, int);

singly_linkedlist *get_node(singly_linkedlist *, int);

singly_linkedlist *get_middle_node(singly_linkedlist *);

singly_linkedlist *get_kth_node_from_end(singly_linkedlist *, int);

singly_linkedlist *insert_at_head(singly_linkedlist *, int);

singly_linkedlist *insert_at_tail(singly_linkedlist *, int);

singly_linkedlist *insert_at_index(singly_linkedlist *, int, size_t);

singly_linkedlist *delete_at_index(singly_linkedlist *, int, int);

singly_linkedlist *delete_at_head(singly_linkedlist *);

singly_linkedlist *delete_at_tail(singly_linkedlist *);

singly_linkedlist *delete_element(singly_linkedlist *, int);

singly_linkedlist *delete_list(singly_linkedlist *);



singly_linkedlist *reverse_list(singly_linkedlist *);

int is_palindrome(singly_linkedlist *);


singly_linkedlist *merge_two_sorted_list(singly_linkedlist *, singly_linkedlist *);

singly_linkedlist *merge_k_sorted_list(singly_linkedlist *, int);


#endif // SINGLY_LINKEDLIST_H__
