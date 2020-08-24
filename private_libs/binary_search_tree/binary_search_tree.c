/*
 * author: greyshell
 * description: linked list based implementation of BST
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_search_tree.h"

void initialize_bst(binary_search_tree *t) {
    /*
     * time complexity: O(1)
     * space complexity: O(1)
     */
    t->root = NULL;
}

bst_node *create_new_node_bst(int data) {
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

bst_node *search_node_bst(binary_search_tree *t, int data) {
    /*
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *curr_ptr;

    curr_ptr = t->root;
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

bst_node *search_parent_node_bst(binary_search_tree *t, int data) {
    /*
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *curr_ptr, *prev_ptr;

    prev_ptr = NULL;
    curr_ptr = t->root;
    while (curr_ptr != NULL) {
        if (data == curr_ptr->data) {
            return prev_ptr;
        }
        prev_ptr = curr_ptr;
        if (data < curr_ptr->data) {
            curr_ptr = curr_ptr->left;
        } else {
            curr_ptr = curr_ptr->right;
        }
    }
    // case 0: when root is NULL while loop will not execute
    // case 1: when the while loop execution finishes and curr_ptr reaches to the NULL -> element not found
    return NULL;
}

bst_node *get_parent_node_bst(bst_node *curr_ptr, int data) {
    /*
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *prev_ptr;

    prev_ptr = NULL;
    while (curr_ptr != NULL) {
        if (data == curr_ptr->data) {
            return prev_ptr;
        }
        prev_ptr = curr_ptr;
        if (data < curr_ptr->data) {
            curr_ptr = curr_ptr->left;
        } else {
            curr_ptr = curr_ptr->right;
        }
    }
    // case 0: when root is NULL while loop will not execute
    // case 1: when the while loop execution finishes and curr_ptr reaches to the NULL -> element not found
    return NULL;
}

bst_node *get_parent_node(binary_search_tree *t, int data) {
    /*
     * helper function for insert()
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *curr_ptr, *prev_ptr = NULL;

    curr_ptr = t->root;
    while (curr_ptr != NULL) {
        prev_ptr = curr_ptr;
        if (data == curr_ptr->data) {
            // data_arr is already present in the BST
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
        temp_node = create_new_node_bst(data);
        t->root = temp_node;
        return;
    }

    parent_node = get_parent_node(t, data);
    if (parent_node == NULL) {
        // case: data_arr is already present in the BST
        printf("\nunable to insert, data_arr is already present in BST");
        return;
    }

    temp_node = create_new_node_bst(data);

    if (data < parent_node->data) {
        parent_node->left = temp_node;
    } else {
        parent_node->right = temp_node;
    }
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

void all_ordered_traversals_bst_recursive(binary_search_tree *t) {
    /*
     * time complexity | space complexity: depends on the following functions
     *  - in_order_traversal_bst_recursive()
     *  - pre_order_traversal_bst_recursive()
     *  - post_order_traversal_bst_recursive()
     */
    printf("\nin-order traversal / sorted order: ");
    in_order_traversal_bst_recursive(t->root);
    printf("\npre-order traversal: ");
    pre_order_traversal_bst_recursive(t->root);
    printf("\npost-order traversal: ");
    post_order_traversal_bst_recursive(t->root);
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

bst_node *get_min_node_bst(binary_search_tree *t) {
    /*
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *curr_ptr;
    // case: root is NULL
    if (t->root == NULL) {
        return NULL;
    }

    return get_node_in_order_successor(t->root);;
}

bst_node *get_node_in_order_successor(bst_node *curr_ptr){
    /*
    * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
    * space complexity: O(1)
    */
    // iterate the loop by checking with the left node address
    // due to this, when the curr_ptr->left reaches to NULL, curr_ptr points to the leaf node
    while (curr_ptr->left != NULL) {
        curr_ptr = curr_ptr->left;
    }
    return curr_ptr;
}

bst_node *get_max_node_bst(binary_search_tree *t) {
    /*
     * time complexity: O(height of the BST), best case = O(log(n) for balanced tree, worst case = O(n) for skewed tree
     * space complexity: O(1)
     */
    bst_node *curr_ptr;
    // case: root is NULL
    if (t->root == NULL) {
        return NULL;
    }

    curr_ptr = t->root;
    // iterate the loop by checking with the right node address
    // due to this, when the curr_ptr->right reaches to NULL, curr_ptr points to the leaf node
    while (curr_ptr->right != NULL) {
        curr_ptr = curr_ptr->right;
    }
    return curr_ptr;
}


void delete_bst(binary_search_tree *t, int data) {
    /*
     * hibbard deletion
     */
    bst_node *curr_node, *parent_node, *temp_node, *in_order_successor, *parent_of_in_order_successor;
    parent_node = search_parent_node_bst(t, data);
    curr_node = search_node_bst(t, data);

    if (curr_node->left == NULL && curr_node->right == NULL){
        // case 1: the current node is leaf node
        if (data > parent_node->data){
            parent_node->right = NULL;
        }
        else{
            parent_node->left = NULL;
        }

        free(curr_node);
    }
    // case 2: node has only right child
    else if (curr_node->left == NULL && curr_node->right != NULL){
        if (data > parent_node->data){
            parent_node->right = curr_node->right;
        }
        else{
            parent_node->left = curr_node->right;
        }
        free(curr_node);
    }
    // case 2: node has only left child
    else if (curr_node->left != NULL && curr_node->right == NULL){
        if (data > parent_node->data){
            parent_node->right = curr_node->left;
        }
        else{
            parent_node->left = curr_node->left;
        }
        free(curr_node);
    }
    // node has two children
    else{
        // default: find in-order successor / min of the right sub tree
        in_order_successor = get_node_in_order_successor(curr_node->right);
        // swap the keys
        curr_node->data = in_order_successor->data;
        // parent_of_in_order_successor = get_parent_node_bst()
        // in_order_successor->right;
    }

}