//
// Created by root on 3/6/20.
//

// CC=afl-clang-fast CXX=afl-clang-fast++ cmake ..
// AFL_USE_ASAN=1 afl-gcc ../linked_list/fuzz_singly_linkedlist.c ../private_libs/node.c -o fuzz_driver

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "../private_libs/singly_linked_list.h"

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
    memset(&((char *)s)[bytes_read], 0, n - bytes_read);
}

uint8_t read8() {
    uint8_t i;
    readn(&i, sizeof(i));
    return i;
}

int readInt() {
    int i;
    readn(&i, sizeof(i));
    return i;
}

size_t readSizet() {
    size_t i;
    readn(&i, sizeof(i));
    return i;
}

singly_linked_list my_list;

void op_get_node() {
    int data;
    data = readInt();
    linkedlist_node *temp_node;
    printf("Operation: Get my_node with data: %d\n", data);
    temp_node = get_node(&my_list, data);
    if (!temp_node) return;
    printf("Node: %p has the value: %d\n", temp_node, temp_node->data);
}

void op_get_kth_node() {
    linkedlist_node *temp_node;
    size_t k;
    k = readSizet();
    printf("Operation: Get kth my_node: %zu\n", k);
    temp_node = get_kth_node(&my_list, k);
    if (!temp_node) return;
    printf("Node: %p has the value: %d\n", temp_node, temp_node->data);
}

void op_get_kth_node_from_end() {
    linkedlist_node *temp_node;
    size_t k;
    k = readSizet();
    printf("Operation: Get kth my_node from end with k: %zu\n", k);
    temp_node = get_kth_node_from_end(&my_list, k);
    if (!temp_node) return;
    printf("Node: %p has the value: %d\n", temp_node, temp_node->data);
}


void op_get_middle_node() {
    linkedlist_node *temp_node;
    printf("Operation: Get middle my_node\n");
    temp_node = get_middle_node(&my_list);
    if (!temp_node) return;
    printf("Node: %p has the value: %d\n", temp_node, temp_node->data);
}

void op_is_empty_singly_linked_list() {
    printf("Operation: Check is empty\n");
    printf("result: %d\n", is_empty_singly_linked_list(&my_list));
}

void op_count_singly_linked_list() {
    printf("Operation: Count\n");
    printf("Count: %lu\n", count_singly_linked_list(&my_list));
}

void op_display_singly_linked_list() {
    printf("Operation: Display\n");
    display_singly_linked_list(&my_list);
}

void op_reverse_display_singly_linked_list() {
    printf("Operation: Reverse Display\n");
    reverse_display_singly_linked_list(&my_list);
}


void op_insert_at_head() {
    int data;
    linkedlist_node *temp_node;
    data = readInt();
    printf("Operation: Insert at head with data: %d\n", data);
    insert_at_head(&my_list, data);
}


void op_insert_at_index() {
    int data;
    size_t index;
    linkedlist_node *temp_node;
    index = readSizet();
    data = readInt();
    printf("Operation: Insert at index %zu with data: %d\n", index, data);
    insert_at_index(&my_list, data, index);
}

void op_insert_at_tail() {
    int data;
    linkedlist_node *temp_node;
    data = readInt();
    printf("Operation: Insert at tail with data: %d\n", data);
    insert_at_tail(&my_list, data);
}

void op_delete_at_head() {
    int data;
    printf("Operation: Delete at head\n");
    data = delete_at_head(&my_list);
    printf("Deleted value: %d\n", data);
}


void op_delete_at_tail() {
    int data;
    printf("Operation: Delete at tail\n");
    data = delete_at_tail(&my_list);
    printf("Deleted value: %d\n", data);
}

void op_delete_at_index() {
    int data;
    size_t index;
    index = readSizet();
    printf("Operation: Delete at index: %zu\n",index);
    data = delete_at_index(&my_list, index);
    printf("Deleted value: %d\n", data);
}

void op_delete_kth_node_from_end() {
    int data;
    size_t index;
    index = readSizet();
    printf("Operation: Delete kth node from end: %zu\n", index);
    data = delete_kth_node_from_end(&my_list, index);
    printf("Deleted value: %d\n", data);
}

void op_delete_element() {
    int data;
    printf("Operation: Delete an element\n");
    data = readInt();
    delete_element(&my_list, data);
    printf("Deleted value: %d\n", data);
}

void op_delete_all() {
     printf("Operation: Delete all element\n");
    delete_all(&my_list);
}



int main() {
    uint8_t number_operations;
    uint8_t operation_type;
    int i;
    initialize_singly_linked_list(&my_list);

    // 1. Figure out how many operations: 255
    number_operations = read8();
    printf("Number of operations: %d\n", number_operations);
    for (i = 0; i < number_operations; i++) {
        operation_type = read8();
        switch (operation_type % 17) {
            case 0:
                op_get_node();
                break;
            case 1:
                op_get_kth_node();
                break;
            case 2:
                op_get_kth_node_from_end();
                break;
            case 3:
                op_get_middle_node();
                break;
            case 4:
                op_is_empty_singly_linked_list();
                break;
            case 5:
                op_count_singly_linked_list();
                break;
            case 6:
                op_display_singly_linked_list();
                break;
            case 7:
                op_reverse_display_singly_linked_list();
                break;
            case 8:
                op_insert_at_head();
                break;
            case 9:
                op_insert_at_tail();
                break;
            case 10:
                op_insert_at_index();
                break;
            case 11:
                op_delete_at_head();
                break;
            case 12:
                op_delete_at_tail();
                break;
            case 13:
                op_delete_at_index();
                break;
            case 14:
                op_delete_kth_node_from_end();
                break;
            case 15:
                op_delete_element();
                break;
            case 16:
                op_delete_all();
                break;
        }
    }
    delete_all(&my_list);

    return 0;
}
