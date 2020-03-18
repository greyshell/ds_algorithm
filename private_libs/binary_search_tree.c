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

tree_node *create_bst_node(int data) {
    tree_node *temp_node;
    temp_node = (tree_node *) malloc(sizeof(tree_node));

    temp_node->data = data;
    temp_node->left = NULL;
    temp_node->right = NULL;
    return temp_node;
}

void insert_bst(binary_search_tree *bst, int data) {
    tree_node *curr_node, *temp_node;

    if (bst->root == NULL) {
        temp_node = create_bst_node(data);
        bst->root = temp_node;
        return;
    }

    curr_node = bst->root;
    while (curr_node != NULL) {
        // insert into the right sub tree
        if (data > curr_node->data) {
            if (curr_node->right == NULL) {
                curr_node->right = create_bst_node(data);
                return;
            } else {
                curr_node = curr_node->right;
            }
        }
            // insert into the left sub tree
        else {
            if (curr_node->left == NULL) {
                curr_node->left = create_bst_node(data);
                return;
            } else {
                curr_node = curr_node->left;
            }
        }
    }
}

void in_order_traversal_bst_recursive(tree_node *curr_ptr) {
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