//
// Created by root on 3/6/20.
//

// CC=afl-clang-fast CXX=afl-clang-fast++ cmake ..
// AFL_USE_ASAN=1 afl-gcc ../linkedList/fuzz_singly_linkedlist.c ../private_libs/node.c -o fuzz_driver

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "../private_libs/singly_linkedlist.h"

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
    memset(&s[bytes_read], 0, n - bytes_read);
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

node *head = NULL;

void op_display() {
    printf("Operation: Display\n");
    display_singly_linked_list(head);
}

void op_reverse_display() {
    printf("Operation: Reverse Display\n");
    reverse_display(head);
}

void op_count() {
    printf("Operation: Count\n");
    printf("Count: %lu\n", count(head));
}

void op_get_node() {
    int data;
    data = readInt();
    printf("Operation: Get my_node with data: %d\n", data);
    head = get_node(head, data);
    if (!head) return;
    printf("Node; %p has the value: %d\n", head, head->data);
}

void op_get_middle_node() {
    printf("Operation: Get middle my_node\n");
    head = get_middle_node(head);
    if (!head) return;
    printf("Node; %p has the value: %d\n", head, head->data);
}

void op_get_kth_node_from_end() {
    size_t k;
    k = readSizet();
    printf("Operation: Get kth my_node from end with k: %zu\n", k);
    head = get_kth_node_from_end(head, k);
    if (!head) return;
    printf("Node; %p has the value: %d\n", head, head->data);
}

void op_insert_at_head() {
    int data;
    data = readInt();
    printf("Operation: Insert at head with data: %d\n", data);
    head = insert_at_head(head, data);
    if (!head) return;
    printf("Node; %p has the value: %d\n", head, head->data);
}

void op_insert_at_tail() {
    int data;
    data = readInt();
    printf("Operation: Insert at tail with data: %d\n", data);
    head = insert_at_tail(head, data);
    if (!head) return;
    printf("Node; %p has the value: %d\n", head, head->data);
}

void op_insert_at_index() {
    int data;
    size_t index;
    index = readSizet();
    data = readInt();
    printf("Operation: Insert at index %zu with data: %d\n", index, data);
    head = insert_at_index(head, data, index);
    if (!head) return;
    printf("Node; %p has the value: %d\n", head, head->data);
}

int main() {
    uint8_t number_operations;
    uint8_t operation_type;
    int i;

    // 1. Figure out how many operations: 255
    number_operations = read8();
    printf("Number of operations: %d\n", number_operations);
    for (i = 0; i < number_operations; i++) {
        operation_type = read8();
        switch (operation_type % 9) {
            case 0:
                op_display();
                break;
            case 1:
                op_reverse_display();
                break;
            case 2:
                op_count();
                break;
            case 3:
                op_get_node();
                break;
            case 4:
                op_get_middle_node();
                break;
            case 5:
                op_get_kth_node_from_end();
                break;
            case 6:
                op_insert_at_head();
                break;
            case 7:
                op_insert_at_tail();
                break;
            case 8:
                op_insert_at_index();
                break;
        }
    }
    delete_list(head);

    return 0;
}