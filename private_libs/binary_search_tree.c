/*
 * author: greyshell
 * description: linked list based implementation of BST
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_search_tree.h"

void initialize_bst(binary_search_tree *bst) {
    /*
     * time complexity: O(1)
     * space complexity: O(1)
     */
    bst->root = NULL;
}

bst_node *create_bst_node(int data) {
    /*
     * time complexity: O(1)
     * space complexity: O(1)
     */
    bst_node *temp_node;
    temp_node = (bst_node *) malloc(sizeof(bst_node));

    temp_node->data = data;
    temp_node->left = NULL;
    temp_node->right = NULL;
    return temp_node;
}

bst_node *find_parent_node_position(bst_node *t, int data) {
    bst_node *curr_ptr, *prev_ptr = NULL;

    curr_ptr = t;
    while (curr_ptr != NULL) {
        prev_ptr = curr_ptr;
        if (data == curr_ptr->data) {
            // data is already present in the BST
            return NULL;
        } else if (data < curr_ptr->data) {
            curr_ptr = curr_ptr->left;
        } else {
            curr_ptr = curr_ptr->right;
        }
    }
    return prev_ptr;
}

void insert_bst(binary_search_tree *t, int data) {
    /*
     * time complexity: depends on the height of the tree
     * - best case: O(log(n)) -> balanced tree
     * - worst case: O(n) -> left / right skewed tree
     *
     * space complexity: O(1)
     */
    bst_node *parent_node, *temp_node;

    // case 0: the tree is empty, insert into root
    if (t->root == NULL) {
        temp_node = create_bst_node(data);
        t->root = temp_node;
        return;
    }

    parent_node = find_parent_node_position(t->root, data);
    if (parent_node == NULL) {
        // case: data is already present in the BST
        printf("\nunable to insert, data is already present in BST");
    } else {
        temp_node = create_bst_node(data);
        if (data < parent_node->data) {
            parent_node->left = temp_node;
        } else {
            parent_node->right = temp_node;
        }

    }
    /* // old implementation
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
    */
}

void in_order_traversal_bst_recursive(bst_node *curr_ptr) {
    /*
     * time complexity: TBD
     * space complexity: O(height of the BST) -> call stack
     * - best case: O(log(n)) -> balanced tree
     * - worst case: O(n) -> left / right skewed tree
     */
    if (curr_ptr != NULL) {
        in_order_traversal_bst_recursive(curr_ptr->left);
        printf("%d ", curr_ptr->data);
        in_order_traversal_bst_recursive(curr_ptr->right);
    }
}

void pre_order_traversal_bst_recursive(bst_node *curr_ptr) {
    /*
     * time complexity: TBD
     * space complexity: O(height of the BST) -> call stack
     * - best case: O(log(n)) -> balanced tree
     * - worst case: O(n) -> left / right skewed tree
     */
    if (curr_ptr != NULL) {
        printf("%d ", curr_ptr->data);
        in_order_traversal_bst_recursive(curr_ptr->left);
        in_order_traversal_bst_recursive(curr_ptr->right);
    }
}

void post_order_traversal_bst_recursive(bst_node *curr_ptr) {
    /*
     * time complexity: TBD
     * space complexity: O(height of the BST) -> call stack
     * - best case: O(log(n)) -> balanced tree
     * - worst case: O(n) -> left / right skewed tree
     */
    if (curr_ptr != NULL) {
        in_order_traversal_bst_recursive(curr_ptr->left);
        in_order_traversal_bst_recursive(curr_ptr->right);
        printf("%d ", curr_ptr->data);
    }
}

void all_ordered_traversals_bst_recursive(binary_search_tree *bst) {
    /*
     * time complexity | space complexity: depends on the following functions
     *  - in_order_traversal_bst_recursive()
     *  - pre_order_traversal_bst_recursive()
     *  - post_order_traversal_bst_recursive()
     */
    printf("\nin-order traversal / sorted order: ");
    in_order_traversal_bst_recursive(bst->root);
    printf("\npre-order traversal: ");
    pre_order_traversal_bst_recursive(bst->root);
    printf("\npost-order traversal: ");
    post_order_traversal_bst_recursive(bst->root);
    return;
}

bool is_empty_bst(binary_search_tree *bst) {
    /*
     * time complexity: O(1)
     * space complexity: O(1)
     */
    if (bst->root == NULL) {
        return true;
    }
    return false;
}

bst_node *search_node_bst(binary_search_tree *bst, int data) {
    /*
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *curr_ptr;
    // case: root is NULL
    if (bst->root == NULL) {
        return NULL;
    }

    curr_ptr = bst->root;
    while (curr_ptr != NULL) {
        if (data == curr_ptr->data) {
            return curr_ptr;
        } else if (data < curr_ptr->data) {
            curr_ptr = curr_ptr->left;
        } else {
            curr_ptr = curr_ptr->right;
        }
    }
    // case 0: when root is NULL while loop will not execute
    // case 1: when the while loop execution finishes and curr_ptr reaches to the NULL -> element not found
    return NULL;
}

bst_node *get_min_element_node_bst(binary_search_tree *bst) {
    /*
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *curr_ptr;
    // case: root is NULL
    if (bst->root == NULL) {
        return NULL;
    }

    curr_ptr = bst->root;
    // iterate the loop by checking with the left node address
    // due to this, when the curr_ptr->left reaches to NULL, curr_ptr points to the leaf node
    while (curr_ptr->left != NULL) {
        curr_ptr = curr_ptr->left;
    }
    return curr_ptr;
}

bst_node *get_max_element_node_bst(binary_search_tree *bst) {
    /*
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *curr_ptr;
    // case: root is NULL
    if (bst->root == NULL) {
        return NULL;
    }

    curr_ptr = bst->root;
    // iterate the loop by checking with the right node address
    // due to this, when the curr_ptr->right reaches to NULL, curr_ptr points to the leaf node
    while (curr_ptr->right != NULL) {
        curr_ptr = curr_ptr->right;
    }
    return curr_ptr;
}

void delete_bst(binary_search_tree *bst, int data) {
    printf("\nTBD");
}