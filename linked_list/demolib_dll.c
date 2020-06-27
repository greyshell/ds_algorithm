/*
 * author: greyshell
 * description: test XOR doubly linked list
 * data / key -> void pointer
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/linked_list/doubly_linked_list.h"

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
    // printf("%p \n", (int *) data);
    //printf("\n");
}

bool my_data_compare(void *data, void *key) {
    /*
     * data format: int
     */
    if (*(int *) data == *(int *) key) {
        return true;
    }
    return false;
}

int main(void) {
    size_t dll_size;
    doubly_linked_list my_dll;
    int *out_data;
    bool return_type;
    int data = 30;
    view_doubly_linked_list *my_func = my_display;
    int test_data[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // initialize the dll
    printf("create the dll \n");
    initialize_dll(&my_dll);

    dll_size = get_dll_size(&my_dll);
    printf("dll size: %zu \n", dll_size);

    return_type = is_empty_dll(&my_dll);
    printf("is empty: %d \n", return_type);

    for (int i = 0; i < 10; i++) {
        return_type = insert_dll_node_at_head(&my_dll, &test_data[i]);
        if (return_type == true) {
            printf("node added: %d \n", test_data[i]);
            //printf("node addr added: %p \n", &test_data[i]);
        } else {
            printf("node not added \n");
        }
    }


    printf("display: ");
    display_dll(&my_dll, my_func);

    int d = 9;
    compare_data_func_dll *f = my_data_compare;

    void *p = NULL, *c = NULL;
    printf("\n");
    return_type = _get_dll_prev_curr_node(&my_dll, &d, f, p, c);
    printf("return: %d", return_type);

    return 0;
}
