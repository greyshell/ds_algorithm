/*
 * author: greyshell
 * description: test my linked list based BST implementation
 * */

#include <stdio.h>
#include "../private_libs/binary_search_tree.h"

int main(void) {
    int data;
    size_t index, choice;
    tree_node *temp_node;
    binary_search_tree my_bst;
    printf("\ninitializing the BST: ");
    initialize_bst(&my_bst);

    while (1) {
        printf("\n\n===================");
        printf("\nmenu driven program:");
        printf("\n====================");
        printf("\n0. insert an element in BST");
        printf("\n1. search an element in BST");
        printf("\n2. insert an element at root in BST");
        printf("\n3. delete an element from BST");

        printf("\n4. check if the BST is empty");
        printf("\n5. get the height of the root node of BST");
        printf("\n6. display the in_order_traversal / sorted order");
        printf("\n7. display the pre_order_traversal");
        printf("\n8. display the post_order_traversal");
        printf("\n17. exit");

        printf("\n\nenter your choice: ");
        scanf("%zu", &choice);

        switch (choice) {
            case 0:
                printf("\nenter the element to be inserted: ");
                scanf("%d", &data);
                insert_bst(&my_bst, data);
                break;

            case 1:
                printf("\nenter the element to be searched: ");
                scanf("%d", &data);
                break;

            case 6:
                wrapper_in_order_traversal_bst(&my_bst);
                break;

            case 17:
                return 0;

                default:
                printf("\nwrong choice");
        }
    }

}