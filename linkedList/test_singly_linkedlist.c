/*
 * author: greyshell
 * description: test the singly linked list implementation
 * */

#include <stdio.h>
#include "../private_libs/singly_linkedlist.h"

int main(void) {
    singly_linkedlist *list_head = NULL;
    int choice, data;
    size_t position, list_count;

    while (1) {
        printf("\n\n===================");
        printf("\nmenu driven program:");
        printf("\n====================");
        printf("\n1. display the list");
        printf("\n2. reverse display the list");
        printf("\n3. display nth last node");
        printf("\n4. display the total count");

        printf("\n5. insert an element at head");
        printf("\n6. insert an element at tail");
        printf("\n7. insert an element at index");

        printf("\n8. delete an element at index");
        printf("\n9. delete an element at head");
        printf("\n10. delete an element at tail");
        printf("\n11. delete an element if found");
        printf("\n12. delete the entire the list");

        printf("\n13. reverse the list");
        printf("\n14. check if the list is palindrome");

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
            case 4:
                list_count = count(list_head);
                printf("\ntotal count = %lu", list_count);
                break;
            case 5:
                printf("\nenter the element to be inserted at head: ");
                scanf("%d", &data);
                list_head = insert_at_head(list_head, data);
                break;
            case 6:
                printf("\nenter the element to be inserted at tail: ");
                scanf("%d", &data);
                list_head = insert_at_tail(list_head, data);
                break;
            case 7:
                printf("\n[*] note: position range: 0 <= position <= 18446744073709551615");
                /*
                 * 1844674407370955166 and onwards => 18446744073709551615
                 *  -1 => 18446744073709551615
                 *  -2 => 18446744073709551614
                 *  -18446744073709551614 => 2
                 *  -18446744073709551615 => 1
                 *  -18446744073709551616 and onwards => 18446744073709551615
                 */
                printf("\n");
                printf("\nenter the position at where to insert: ");
                scanf("%zu", &position);
                printf("\nenter the element to be inserted at the %zu th position: ", position);
                scanf("%d", &data);
                list_head = insert_at_index(list_head, data, position);
                break;
            case 10:
                return 0;
            default:
                printf("\nwrong choice");
        }
    }

}