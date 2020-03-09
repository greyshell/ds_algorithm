/*
 * author: greyshell
 * description: test my singly linked list implementation
 * */

#include <stdio.h>
#include "../private_libs/singly_linkedlist.h"

int main(void) {
    int data;
    size_t index, choice;
    node *temp_node;
    singly_linked_list my_list;
    printf("\ninitializing the singly linked list: ");
    initialize_singly_linked_list(&my_list);

    while (1) {
        printf("\n\n===================");
        printf("\nmenu driven program:");
        printf("\n====================");
        printf("\n0. get the node pointer if found the element");
        printf("\n1. get the node pointer of given a kth node");
        printf("\n2. get the node pointer of a given kth node from the end");
        printf("\n3. get the middle node");

        printf("\n4. check if the singly linked list is empty");
        printf("\n5. get the total count of singly linked list elements");
        printf("\n6. display the singly linked list");
        printf("\n7. reverse display the singly_linked_list");

        printf("\n8. insert an element at head");
        printf("\n9. insert an element at tail");
        printf("\n10. insert an element at index");

        printf("\n11. delete an element at head");
        printf("\n12. delete an element at tail");
        printf("\n13. delete an element at index");
        printf("\n14. delete kth node from the end");
        printf("\n15. delete an element if found");
        printf("\n16. delete all elements");

        printf("\n17. quit");

        printf("\n\ndisplay list:");
        printf("\n=============\n");
        display_singly_linked_list(&my_list);

        printf("\n\nenter your choice: ");
        scanf("%zu", &choice);

        switch (choice) {
            case 0:
                printf("\nenter the element to be searched: ");
                scanf("%d", &data);
                temp_node = get_node(&my_list, data);
                if (temp_node != NULL){
                    printf("\nelement = %d found at %p",data, temp_node);
                }
                break;
            case 1:
                printf("\nenter k: ");
                scanf("%zu", &index);
                temp_node = get_kth_node(&my_list, index);
                if (temp_node != NULL){
                    printf("\nelement = %d found at %zu",temp_node->data, index);
                }
                break;
            case 2:
                printf("\nenter k:");
                scanf("%zu", &index);
                temp_node = get_kth_node_from_end(&my_list, index);
                if (temp_node != NULL){
                    printf("\nelement = %d found at %zu index from the last",temp_node->data, index);
                }
                break;
            case 3:
                temp_node = get_middle_node(&my_list);
                if (temp_node != NULL){
                    printf("\nelement = %d found at middle",temp_node->data);
                }
                break;
            case 4:
                printf("\nlist is_empty = %d", is_empty(&my_list));
                break;
            case 5:
                printf("\nlist count = %zu", count(&my_list));
                break;

            case 6:
                display_singly_linked_list(&my_list);
                break;
            case 7:
               reverse_display_singly_linked_list(&my_list);
                break;

            case 8:
                printf("\nenter the element to be inserted: ");
                scanf("%d", &data);
                insert_at_head(&my_list, data);
                break;
            case 9:
                printf("\nenter the element to be inserted: ");
                scanf("%d", &data);
                insert_at_tail(&my_list, data);
                break;
            case 10:
                printf("\nenter the element to be inserted: ");
                scanf("%d", &data);
                printf("\nenter the index / k: ");
                scanf("%zu", &index);
                insert_at_index(&my_list, data, index);
                break;

            case 11:
                data = delete_at_head(&my_list);
                printf("\nelement = %d is deleted", data);
                break;
            case 12:
                data = delete_at_tail(&my_list);
                printf("\nelement = %d is deleted", data);
                break;
            case 13:
                printf("\nenter the index / k: ");
                scanf("%zu", &index);
                data = delete_at_index(&my_list, index);
                printf("\nelement = %d is deleted", data);
                break;
            case 14:
                printf("\nenter the index / k: ");
                scanf("%zu", &index);
                data = delete_kth_node_from_end(&my_list, index);
                printf("\nelement = %d is deleted", data);
                break;
            case 15:
                printf("\nenter the data to be deleted: ");
                scanf("%d", &data);
                delete_element(&my_list, data);
                break;

            case 16:
                delete_all(&my_list);
                break;

            case 17:
                return 0;
            default:
                printf("\nwrong choice");
        }
    }

}