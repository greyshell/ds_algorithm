/*
 * author: greyshell
 * */

#ifndef BINARY_SEARCH_TREE_H__
#define BINARY_SEARCH_TREE_H__

#include <stddef.h>
#include "stdbool.h"


typedef struct sll_node {
    int data;
    struct sll_node *left;
    struct sll_node *right;
} bst_node;


typedef struct my_binary_search_tree {
    bst_node *root;
} binary_search_tree;

// main operations:
void initialize_bst(binary_search_tree *);

void insert_bst(binary_search_tree *, int);

void delete_bst(binary_search_tree *, int);

int find_minimum_bst(binary_search_tree *);
int find_maximum_bst(binary_search_tree *);

// auxiliary operations:
// karumanchi page 126, using stack
void in_order_traversal_bst(binary_search_tree *);

void all_ordered_traversals_bst_recursive(binary_search_tree *);

bool is_empty_bst(binary_search_tree *);

bst_node *search_node_bst(binary_search_tree *, int);

bst_node *search_parent_node_bst(binary_search_tree *, int);

bst_node *get_min_node_bst(binary_search_tree *t);

bst_node *get_max_node_bst(binary_search_tree *t);

bst_node *get_node_in_order_predecessor_bst(bst_node *);

bst_node *get_node_in_order_successor(bst_node *);


/*

node *get_node_in_order_predecessor_bst(binary_search_tree *);

node *get_node_in_order_successor(binary_search_tree *);

// bst *generate_bst_from_pre_order(int *);

// int find_lowest_common_ancestor(binary_search_tree *, bst *, bst *);
// same as finding the shortest path between two nodes

// count the nos of bst possible with n nodes

// check if a given binary tree is bst or not

// convert a given bst to circular linked list

// construct a balanced bst with given a sorted doubly linked list
// construct a bst from a sorted array
// construct a bst from a sorted singly linked list

// find kth smallest element in the bst

*/

#endif // BINARY_SEARCH_TREE_H__
