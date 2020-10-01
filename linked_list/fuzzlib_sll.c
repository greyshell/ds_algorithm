/*
 * author: greyshell
 * description: fuzz the singly linked list implementation through AFL
 * make -f fuzz_lib_with_afl SRC_FLD=linked_list WRAPPER_PROG=fuzzlib_sll LIB_FLD=linked_list LIB=sll
 * */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "../liquid_oxygen/linked_list/sll.h"


// helper functions
void readn(void *s, int n) {
    int bytes_read;
    bytes_read = read(0, s, n);
    if (bytes_read == n) {
        return;
    }
    if (bytes_read == 0 || bytes_read == -1) {
        memset(s, 0, n);
        return;
    }
    memset(&((char *) s)[bytes_read], 0, n - bytes_read);
}

uint8_t read8() {
    uint8_t i;
    readn(&i, sizeof(i));
    return i;
}

int read_int() {
    int i;
    readn(&i, sizeof(i));
    return i;
}

size_t read_size_t() {
    size_t i;
    readn(&i, sizeof(i));
    return i;
}

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
    fflush(stdout);
}

bool my_compare(void *data, void *key) {
    /*
     * data format: int
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

    uint8_t number_operations;
    uint8_t operation_type;
    size_t ops_count = 11;

    // initialize
    initialize_sll(&my_list);

    // randomize the number of operations and get the input through fuzzer
    number_operations = read8();
    printf("number of operations: %d \n", number_operations);

    for (int i = 0; i < number_operations; i++) {
        // choose the random operation
        operation_type = read8();
        switch (operation_type % ops_count) {
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
                data = (int *) malloc(sizeof(int));
                *data = read_int();
                printf("operation: insert_sll_node_at_head, data: %d \n", *data);
                insert_sll_node_at_head(&my_list, data);
                break;
            case 5:
                data = (int *) malloc(sizeof(int));
                *data = read_int();
                printf("operation: insert_sll_node_at_tail, data: %d \n", *data);
                return_type = insert_sll_node_at_head(&my_list, data);
                if (return_type == true) {
                    printf("inserted \n");
                } else {
                    printf("unable to insert \n");
                }
                break;
            case 6:
                data = (int *) malloc(sizeof(int));
                *data = read_int();
                index = read_int();
                printf("operation: insert_sll_node_at_index, index: %zu, data: %d \n", index,
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
                index = read_int();
                index = index %
                        (int) (get_sll_size(&my_list) + 5); // add 5 out of the range indexes
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
                index = read_int();
                index = index % (int) (get_sll_size(&my_list) + 5);
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
                *data = read_int();
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
            default:
                printf("wrong choice \n");
        }
    }

    delete_sll(&my_list);

    return 0;
}
