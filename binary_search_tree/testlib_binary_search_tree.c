/*
 * author: greyshell
 * description: test my linked list based BST implementation
 * */

#include <stdio.h>
#include "../private_libs/binary_search_tree/binary_search_tree.h"

int main(void) {
    int data;
    size_t index, choice;
    bst_node *temp_node;
    binary_search_tree my_bst;
    printf("\ninitializing the BST: ");
    initialize_bst(&my_bst);

    while (1) {
        printf("\n\n===================");
        printf("\nmenu driven program:");
        printf("\n====================");
        printf("\n0. insert an element in BST");
        printf("\n1. search an element in BST");
        printf("\n2. get a parent node of a element");
        printf("\n3. delete an element from BST");
        printf("\n4. check if the BST is empty");
        printf("\n5. get the height of the root node of BST");
        printf("\n6. display the in_order, pre_order an post_order traversals using recursive method");
        printf("\n7. insert node at root");
        printf("\n8. display the in_order_traversal using iterative method");
        printf("\n9. get the max element in BST");
        printf("\n10. get the min element in BST");
        printf("\n11. get total nodes in BST");
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
                temp_node = search_node_bst(&my_bst, data);
                if (temp_node != NULL){
                    printf("\nelement = %d found at %p", temp_node->data, (void *) temp_node);
                }
                else{
                    printf("\ndata not found");
                }
                break;

            case 2:
                // get the parent node of an element
                printf("\nenter the element to be searched: ");
                scanf("%d", &data);
                temp_node = search_parent_node_bst(&my_bst, data);
                if (temp_node != NULL){
                    printf("\n parent element = %d found at %p", temp_node->data, (void *) temp_node);
                }
                else{
                    printf("\nparent node not found");
                }
                break;
            case 3:
                // delete an element
                break;
            case 4:
                printf("\nis_empty: %d", is_empty_bst(&my_bst));
                break;
            case 5:
                // get the height of the root node
                break;
            case 6:
                all_ordered_traversals_bst_recursive(&my_bst);
                break;
            case 7:
                // insert node at root
                break;
            case 8:
               // display in order traversal iterative method
                break;
            case 9:
                // max element
                temp_node = get_max_node_bst(&my_bst);
                printf("\nmax element = %d found at %p", temp_node->data, (void *) temp_node);
                break;
            case 10:
               // min element
                temp_node = get_min_node_bst(&my_bst);
                printf("\nmin element = %d found at %p", temp_node->data, (void *) temp_node);
                break;
            case 11:
                // size total nodes
                break;

            case 17:
                return 0;

                default:
                printf("\nwrong choice");
        }
    }

}