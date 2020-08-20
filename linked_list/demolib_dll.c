/*
 * author: greyshell
 * description: test XOR doubly linked list
 * data / key -> void pointer
 * */

#include <stdio.h>
#include "stdbool.h"
#include "../private_libs/linked_list/xor_dll.h"

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
    size_t dll_size;
    doubly_linked_list my_dll;
    bool return_type;
    view_doubly_linked_list *my_func = my_display;
    int test_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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
        } else {
            printf("node not added \n");
        }
    }

    printf("display: ");
    display_dll(&my_dll, my_func);

    int data2 = 5;
    printf("\n");
    return_type = is_found_in_dll(&my_dll, &data2, my_compare);
    printf("find element: %d \n", return_type);

    printf("deleting: %d", data2);
    delete_dll_node_if_found(&my_dll, &data2, my_compare);

    printf("\ndisplay: ");
    display_dll(&my_dll, my_func);

    return 0;
}
