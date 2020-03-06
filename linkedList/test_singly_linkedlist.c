/*
 * author: greyshell
 * description: test the singly linked list implementation
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/singly_linkedlist.h"

int main(void) {
    singly_linkedlist *list_head = NULL, *temp_node;
    int choice, data;
    size_t index, list_count;

    while (1) {
        printf("\n\n===================");
        printf("\nmenu driven program:");
        printf("\n====================");
        printf("\n1. display the list");
        printf("\n2. reverse display the list");
        printf("\n3. display the total count");
        printf("\n4. get the node pointer if found the element");
        printf("\n5. get the node pointer of the middle(ceil) of the list");
        printf("\n6. get the kth node pointer from the end of the list");

        printf("\n7. create a new empty list");
        printf("\n8. insert an element at head");
        printf("\n9. insert an element at tail");
        printf("\n10. insert an element at index");

        printf("\n11. delete an element at index");
        printf("\n12. delete an element at head");
        printf("\n13. delete an element at tail");
        printf("\n14. delete an element if found");
        printf("\n15. delete the entire the list");

        printf("\n513. reverse the list");
        printf("\n514. check if the list is palindrome");

        printf("\n10. quit\n");

        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(list_head);
                break;

            case 2:
                reverse_display(list_head);
                break;

            case 3:
                list_count = count(list_head);
                printf("\ntotal count = %lu", list_count);
                break;

            case 4:
                printf("\nenter the element to be searched: ");
                scanf("%d", &data);
                temp_node = get_node(list_head, data);
                if (temp_node != NULL)
                    printf("\nnode: %p has the value: %d ", temp_node, temp_node->data);
                else
                    printf("\nvalue not found !!");
                break;

            case 5:
                temp_node = get_middle_node(list_head);
                if (temp_node != NULL)
                    printf("\nmiddle node: %p has the value: %d ", temp_node, temp_node->data);
                else
                    printf("\nlist items are less than 2");
                break;

            case 6:
                printf("\nenter k: ");
                scanf("%zu", &index);
                temp_node = get_kth_node_from_end(list_head, index);
                if (temp_node != NULL)
                    printf("\nk= %zu node: %p has the value: %d ", index, temp_node, temp_node->data);
                else
                    printf("\nk is not valid");
                break;

            case 7:
                // call the function to delete the old list
                list_head = NULL;  // resetting HEAD
                break;

            case 8:
                printf("\nenter the element to be inserted at head: ");
                scanf("%d", &data);
                list_head = insert_at_head(list_head, data);
                break;

            case 9:
                printf("\nenter the element to be inserted at tail: ");
                scanf("%d", &data);
                list_head = insert_at_tail(list_head, data);
                break;

            case 10:
                printf("\n[*] note: index range: 0 <= index <= 18446744073709551615");
                /*
                 * 1844674407370955166 and onwards => 18446744073709551615
                 *  -1 => 18446744073709551615
                 *  -2 => 18446744073709551614
                 *  -18446744073709551614 => 2
                 *  -18446744073709551615 => 1
                 *  -18446744073709551616 and onwards => 18446744073709551615
                 */
                printf("\nenter the index at where to insert: ");
                scanf("%zu", &index);
                printf("\nenter the element to be inserted at index = %zu ", index);
                scanf("%d", &data);
                list_head = insert_at_index(list_head, data, index);
                break;


            case 100:
                return 0;

            default:
                printf("\nwrong choice");
        }
    }

}