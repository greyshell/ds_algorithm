/*
 * author: greyshell
 * description: test singly linked list implementation
 * */

#include <stdio.h>
#include "../private_libs/singly_linked_list/singly_linked_list.h"

int main(void) {
    int data;
    size_t index, choice;
    linkedlist_node *temp_node;
    singly_linked_list my_list;
    printf("creating a singly linked list !! ");
    initialize_singly_linked_list(&my_list);

    while (1) {
        printf("\n");
        printf("=================== \n");
        printf("menu driven program: \n");
        printf("==================== \n");
        printf("0. get the node pointer if found the element \n");
        printf("1. get the node pointer of given a kth node \n");
        printf("2. get the node pointer of a given kth node from the end \n");
        printf("3. get the middle node \n");

        printf("4. check if the singly linked list is empty \n");
        printf("5. get the total count_singly_linked_list of singly linked list elements \n");
        printf("6. display the singly linked list \n");
        printf("7. reverse display the singly_linked_list \n");

        printf("8. insert an element at head \n");
        printf("9. insert an element at tail \n");
        printf("10. insert an element at index \n");

        printf("11. delete an element at head \n");
        printf("12. delete an element at tail \n");
        printf("13. delete an element at index \n");
        printf("14. delete kth node from the end \n");
        printf("15. delete an element if found \n");
        printf("16. delete all elements \n");

        printf("17. quit \n");

        printf("\n\n");
        printf("display present state: \n");
        printf("====================== \n");
        display_singly_linked_list(&my_list);

        printf("\n\n");
        printf("enter your choice: \n");
        scanf("%zu", &choice);
        printf("\n");


        switch (choice) {
            case 0:
                printf("enter the element to be searched: \n");
                scanf("%d", &data);
                temp_node = get_node(&my_list, data);
                if (temp_node != NULL) {
                    // takeaway: 11.8: for printing cast the pointer to void * and use format %p````
                    printf("element = %d found at %p \n", data, (void *) temp_node);
                }
                break;
            case 1:
                printf("enter k: \n");
                scanf("%zu", &index);
                temp_node = get_kth_node(&my_list, index);
                if (temp_node != NULL) {
                    printf("element = %d found at %zu \n", temp_node->data, index);
                }
                break;
            case 2:
                printf("enter k: \n");
                scanf("%zu", &index);
                temp_node = get_kth_node_from_end(&my_list, index);
                if (temp_node != NULL) {
                    printf("element = %d found at %zu index from the last \n", temp_node->data, index);
                }
                break;
            case 3:
                temp_node = get_middle_node(&my_list);
                if (temp_node != NULL) {
                    printf("element = %d found at middle \n", temp_node->data);
                }
                break;
            case 4:
                printf("list is_empty_singly_linked_list = %d \n", is_empty_singly_linked_list(&my_list));
                break;
            case 5:
                printf("list count_singly_linked_list = %zu \n", count_singly_linked_list(&my_list));
                break;

            case 6:
                display_singly_linked_list(&my_list);
                break;
            case 7:
                reverse_display_singly_linked_list(&my_list);
                break;

            case 8:
                printf("enter the element to be inserted: \n");
                scanf("%d", &data);
                insert_at_head(&my_list, data);
                break;
            case 9:
                printf("enter the element to be inserted: \n");
                scanf("%d", &data);
                insert_at_tail(&my_list, data);
                break;
            case 10:
                printf("enter the element to be inserted: \n");
                scanf("%d", &data);
                printf("enter the index / k (k >= 0): \n");
                scanf("%zu", &index);
                insert_at_index(&my_list, data, index);
                break;

            case 11:
                data = delete_at_head(&my_list);
                printf("element = %d is deleted \n", data);
                break;
            case 12:
                data = delete_at_tail(&my_list);
                printf("element = %d is deleted \n", data);
                break;
            case 13:
                printf("enter the index / k (k >= 0): \n");
                scanf("%zu", &index);
                data = delete_at_index(&my_list, index);
                printf("element = %d is deleted \n", data);
                break;
            case 14:
                printf("enter the index / k (k >= 1): \n");
                scanf("%zu", &index);
                data = delete_kth_node_from_end(&my_list, index);
                printf("element = %d is deleted \n", data);
                break;
            case 15:
                printf("enter the data to be deleted: \n");
                scanf("%d", &data);
                delete_element(&my_list, data);
                break;

            case 16:
                delete_all(&my_list);
                break;

            case 17:
                // quite from the program
                return 0;

            default:
                printf("wrong choice \n");
        }
    }

}
