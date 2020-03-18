/*
 * author: greyshell
 * description: linked list based implementation of BST
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_search_tree.h"

void initialize_bst(binary_search_tree *bst) {
    bst->root = NULL;
}

bst_node *create_bst_node(int data) {
    bst_node *temp_node;
    temp_node = (bst_node *) malloc(sizeof(bst_node));

    temp_node->data = data;
    temp_node->left = NULL;
    temp_node->right = NULL;
    return temp_node;
}

void insert_bst(binary_search_tree *t, int data) {
    bst_node *curr_ptr, *temp_node;

    if (t->root == NULL) {
        temp_node = create_bst_node(data);
        t->root = temp_node;
        return;
    }

    curr_ptr = t->root;
    while (curr_ptr != NULL) {
        // insert into the right sub tree
        if (data > curr_ptr->data) {
            if (curr_ptr->right == NULL) {
                curr_ptr->right = create_bst_node(data);
                return;
            } else {
                curr_ptr = curr_ptr->right;
            }
        }
            // insert into the left sub tree
        else {
            if (curr_ptr->left == NULL) {
                curr_ptr->left = create_bst_node(data);
                return;
            } else {
                curr_ptr = curr_ptr->left;
            }
        }
    }
}

void in_order_traversal_bst_recursive(bst_node *curr_ptr) {
    if (curr_ptr != NULL) {
        in_order_traversal_bst_recursive(curr_ptr->left);
        printf("%d ", curr_ptr->data);
        in_order_traversal_bst_recursive(curr_ptr->right);
    }
}

void wrapper_in_order_traversal_bst(binary_search_tree *bst) {
    in_order_traversal_bst_recursive(bst->root);
    return;
}