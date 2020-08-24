/*
 * author: greyshell
 * description: test singly linked list implementation
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "../private_libs/linked_list/sll.h"

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
    fflush(stdout);
}

bool my_compare(void *data, void *key) {
    /*
     * data_arr format: int
     */
    if (*(int *) data == *(int *) key) {
        return true;
    }
    return false;
}

int main(void) {
    int *data, *out_data = 0;
    size_t choice, list_size, index, out_key_found_index;
    bool return_type;
    singly_linked_list my_list;

    printf("creating the singly linked list \n");
    initialize_sll(&my_list);

    while (1) {
        printf("\n");
        printf("=================== \n");
        printf("menu driven program: \n");
        printf("==================== \n");

        printf("0. check if the linked list is empty \n");
        printf("1. get the size of the linked list \n");
        printf("2. display the linked list \n");
        printf("3. reverse display the linked list \n");

        printf("4. insert an element at head \n");
        printf("5. insert an element at tail \n");
        printf("6. insert an element at index \n");

        printf("7. delete an element at head \n");
        printf("8. delete an element at tail \n");
        printf("9. delete an element at index from head \n");
        printf("10. delete kth node element from tail \n");
        printf("11. delete an element if found \n");
        printf("12. delete all elements \n");

        printf("13. is_found the element \n");
        printf("14. get the element of kth node from head \n");
        printf("15. get the element of kth node from tail \n");
        printf("16. get the middle element \n");

        printf("17. quit \n");

        printf("\n\n");
        printf("enter your choice: \n");
        scanf("%zu", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("operation: is_empty sll \n");
                return_type = is_empty_sll(&my_list);
                printf("is empty: %d \n", return_type);
                break;
            case 1:
                printf("operation: get_sll_size \n");
                list_size = get_sll_size(&my_list);
                printf("list size: %zu \n", list_size);
                break;
            case 2:
                printf("operation: display_sll \n");
                printf("display: ");
                display_sll(&my_list, my_display);
                printf("\n");
                break;
            case 3:
                printf("operation: reverse_display_sll \n");
                printf("reverse display: ");
                reverse_display_sll(&my_list, my_display);
                printf("\n");
                break;
            case 4:
                printf("enter the element: \n");
                data = (int *) malloc(sizeof(int));
                scanf("%d", data);

                printf("operation: insert_sll_node_at_head, data_arr: %d \n", *data);
                return_type = insert_sll_node_at_head(&my_list, data);
                if (return_type == true) {
                    printf("inserted \n");
                } else {
                    printf("unable to insert \n");
                }
                break;
            case 5:
                printf("enter the element: \n");
                data = (int *) malloc(sizeof(int));
                scanf("%d", data);
                printf("operation: insert_sll_node_at_tail, data_arr: %d \n", *data);
                return_type = insert_sll_node_at_tail(&my_list, data);
                if (return_type == true) {
                    printf("inserted \n");
                } else {
                    printf("unable to insert \n");
                }
                break;

            case 6:
                printf("enter the element: \n");
                data = (int *) malloc(sizeof(int));
                scanf("%d", data);
                printf("enter the index (0 <= k < size): \n");
                scanf("%zu", &index);

                printf("operation: insert_sll_node_at_index, index: %zu, data_arr: %d \n", index,
                       *data);
                return_type = insert_sll_node_at_index(&my_list, data, index);
                if (return_type == true) {
                    printf("inserted \n");
                } else {
                    printf("unable to insert \n");
                }
                break;
            case 7:
                printf("operation: delete_sll_node_at_head \n");
                return_type = delete_sll_node_at_head(&my_list, (void **) &out_data);
                if (return_type == true) {
                    printf("deleted: %d \n", *(int *) out_data);
                    free(out_data);
                } else {
                    printf("unable to delete \n");
                }
                break;

            case 8:
                printf("operation: delete_sll_node_at_tail \n");
                return_type = delete_sll_node_at_tail(&my_list, (void **) &out_data);
                if (return_type == true) {
                    printf("deleted: %d \n", *(int *) out_data);
                    free(out_data);
                } else {
                    printf("unable to delete \n");
                }
                break;
            case 9:
                printf("enter the index (0 <= k < size): \n");
                scanf("%zu", &index);
                printf("operation: delete_sll_node_at_index_from_head, index: %zu \n", index);
                return_type = delete_sll_node_at_index_from_head(&my_list, index,
                                                                 (void **) &out_data);
                if (return_type == true) {
                    printf("deleted: %d \n", *(int *) out_data);
                    free(out_data);
                } else {
                    printf("unable to delete \n");
                }
                break;
            case 10:
                printf("enter the index (1 <= k <= size): \n");
                scanf("%zu", &index);
                printf("operation: delete_sll_node_at_index_from_tail, index: %zu \n", index);
                return_type = delete_sll_node_at_index_from_tail(&my_list, index, (void **)
                        &out_data);
                if (return_type == true) {
                    printf("deleted: %d \n", *(int *) out_data);
                    free(out_data);
                } else {
                    printf("unable to delete \n");
                }
                break;
            case 11:
                printf("enter the key: \n");
                data = (int *) malloc(sizeof(int));
                scanf("%d", data);
                printf("operation: delete_sll_node_if_found, key: %d \n", *(int *) data);
                return_type = delete_sll_node_if_found(&my_list, data, my_compare, (void **)
                        &out_data);
                if (return_type == true) {
                    printf("deleted: %d \n", *(int *) out_data);
                    free(data);
                    free(out_data);
                } else {
                    printf("not found, unable to delete \n");
                }
                break;
            case 12:
                printf("operation: delete_sll \n");
                return_type = delete_sll(&my_list);
                if (return_type == true) {
                    printf("deleted all \n");
                } else {
                    printf("unable to delete all \n");
                }
                break;
            case 13:
                data = (int *) malloc(sizeof(int));
                printf("enter the key : \n");
                scanf("%d", data);
                printf("operation: is_found_in_sll, key: %d \n", *(int *) data);
                return_type = is_found_in_sll(&my_list, data, my_compare, &out_key_found_index);
                if (return_type == true) {
                    printf("found at index = %zu \n", out_key_found_index);
                    free(data);
                } else {
                    printf("not found \n");
                }
                break;
            case 14:
                printf("enter the index k (0 <= k < size): \n");
                scanf("%zu", &index);
                printf("operation: get_kth_element_in_sll_from_head, k: %zu \n", index);
                return_type = get_kth_element_in_sll_from_head(&my_list, index, (void **)
                        &out_data);
                if (return_type == true) {
                    printf("kth element = %d \n", *out_data);
                } else {
                    printf("not found \n");
                }
                break;
            case 15:
                printf("enter the index (1 <= k <= size): \n");
                scanf("%zu", &index);
                printf("operation: get_kth_element_in_sll_from_tail, k: %zu \n", index);
                return_type = get_kth_element_in_sll_from_tail(&my_list, index,
                                                               (void **) &out_data);
                if (return_type == true) {
                    printf("kth element = %d \n", *out_data);
                } else {
                    printf("not found \n");
                }
                break;

            case 16:
                printf("operation: get_middle_element_in_sll \n");
                return_type = get_middle_element_in_sll(&my_list, (void **) &out_data);
                if (return_type == true) {
                    printf("middle element = %d \n", *out_data);
                } else {
                    printf("not found \n");
                }
                break;

            case 17:
                // delete the entire list and exit from the program
                printf("operation: delete_sll \n");
                delete_sll(&my_list);
                return 0;

            default:
                printf("wrong choice \n");
        }
    }

}
