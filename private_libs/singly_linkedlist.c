/*
 * author: greyshell
 * description: implementation of singly linked list
 * */

#include <stdio.h>
#include <stdlib.h>
#include "singly_linkedlist.h"


void display(singly_linkedlist *head) {
    /*
     * time complexity: O(n)
     * space complexity: O(1) -> temporary pointer variables
     */
    singly_linkedlist *ptr;
    if (head == NULL) {
        printf("\nempty list !!");
        return;
    }
    ptr = head;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void reverse_display(singly_linkedlist *head) {
    /*
     * time complexity: O(n)
     * space complexity: O(n) -> maximum depth of the call stack
     */
    if (head == NULL) {
        return;
    }
    reverse_display(head->next);
    printf("%d ", head->data);
    return;
}

size_t count(singly_linkedlist *head) {
    /*
     * time complexity: O(n)
     * space complexity: O(1) -> temporary pointer variables
     */
    singly_linkedlist *ptr;
    size_t count = 0;
    ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

size_t search(singly_linkedlist *head, int data) {
    /*
     * if found then return the index else return -1
     * time complexity: O(n), find the position
     * space complexity: O(1), for temporary pointer variable
     */
    singly_linkedlist *ptr;
    size_t index = 0;

    ptr = head;
    while (ptr != NULL) {
        if (ptr->data == data) {
            return index;
        }
        ptr = ptr->next;
        index++;
    }
    return -1;
}

singly_linkedlist *get_node(singly_linkedlist *head, int data) {
    /*
     * if found then return the pointer else return NULL
     * time complexity: O(n), find the position
     * space complexity: O(1), for temporary pointer variable
     */
    singly_linkedlist *ptr = NULL;
    size_t index = 0;

    ptr = head;
    while (ptr != NULL) {
        if (ptr->data == data) {
            return ptr;
        }
        ptr = ptr->next;
        index++;
    }
    return NULL;
}

singly_linkedlist *get_middle_node(singly_linkedlist *head) {
    /*
     * time complexity: O(n), scan the linked list only 1 time.
     * space complexity: O(1), temporary pointer variable
     */
    singly_linkedlist *fast_ptr, *slow_ptr;
    if (head == NULL) {
        printf("\nlist is empty");
        return NULL;
    }

    fast_ptr = slow_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
}

singly_linkedlist *get_kth_node_from_end(singly_linkedlist *head, int k){
    /*
     * pass the list only 1 time
     * time complexity: O(n)
     * space complexity: O(1)
     */
    singly_linkedlist *first_ptr, *second_ptr;
    size_t count = 0;

    if (head == NULL) {
        printf("\nlist is empty");
        return NULL;
    }

    first_ptr = second_ptr = head;
    // move the fast ptr by k so that the gap between  and second is k nodes apart

    while (first_ptr != NULL) {
        count++;
        if(k){

        }
        first_ptr = first_ptr->next;

    }

    return NULL;
}

singly_linkedlist *insert_at_head(singly_linkedlist *head, int data) {
    /*
     * time complexity: O(1)
     * space complexity: O(1)
     */
    singly_linkedlist *temp_node;
    // create a new node
    temp_node = (singly_linkedlist *) malloc(sizeof(singly_linkedlist));
    temp_node->data = data;
    // link the node where head points to this new node
    temp_node->next = head;
    // update the head
    head = temp_node;
    return head;
}

singly_linkedlist *insert_at_tail(singly_linkedlist *head, int data) {
    /*
     * time complexity: O(n), find the last element and insert at the end
     * space complexity: O(1), for creating the temporary pointer variable
     */
    singly_linkedlist *ptr, *temp_node;
    // create a new node
    temp_node = (singly_linkedlist *) malloc(sizeof(singly_linkedlist));
    temp_node->data = data;
    temp_node->next = NULL;

    // when the list is empty then head element and tail both are same
    if (head == NULL) {
        // update the head
        head = temp_node;
        return head;
    }
    // when the list is non empty, traverse the list till the end node
    ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    // at this point ptr points to the last node and ptr->next point to NULL
    // link the new node with the last node
    ptr->next = temp_node;

    return head;
}

singly_linkedlist *insert_at_index(singly_linkedlist *head, int data, size_t position) {
    /*
     * time complexity: O(n) -> for finding the position
     * space complexity: O(1) -> for temporary pointer variable
     */
    singly_linkedlist *temp_node, *ptr;
    size_t index = 0;

    // case: when the given position is negative
    if (position < 0) {
        printf("\nindex can't be negative, unable to insert");
        return head;
    }
        // special case: when the given position is 0, list can be empty
    else if (position == 0) {
        return insert_at_head(head, data);
    }
        // case: when the given position is greater than 1
    else {
        ptr = head;
        index = 1;
        /*
         * while traversing the list, when we checks for the given position with list index,
         * the ptr pointer should point to previous node, so that the new node can be inserted
         * between (k-1)th and kth node.
         */

        while (ptr != NULL) {
            if (index == position && ptr->next != NULL) {
                // create the node
                temp_node = (singly_linkedlist *) malloc(sizeof(singly_linkedlist));

                temp_node->data = data;
                // ptr points to the previous node and the we need to insert the node after this
                // node link the new node with the next node address where the ptr points
                temp_node->next = ptr->next;
                // update the ptr with the new node address
                ptr->next = temp_node;  // connect the new node with the present node
                return head;
            }
            index++;
            ptr = ptr->next;
        }
        // iterate the entire list but the given position not found
        printf("\nunable to create the node, given index not found !!");
        return head;
    }

}

singly_linkedlist *delete_at_head(singly_linkedlist *head) {
    /*
     * time complexity: Θ(1)
     * space complexity: O(1), for temporary pointer variable
     */
    singly_linkedlist *temp_node;

    if (head == NULL) {
        printf("\nlist is empty");
        return head;
    }
    // copy the present head to temp
    temp_node = head;
    // update the head with next node
    head = head->next;
    // free the temp node
    free(temp_node);
    return head;
}

singly_linkedlist *delete_at_tail(singly_linkedlist *head){
    /*
     * use get_nth_node_from_end where k = 0
     */
    return NULL;
}

singly_linkedlist *delete(singly_linkedlist *head, int data) {
    /*
     * time complexity: Θ(n)
     * space complexity: O(1), temporary pointer variable
     */
    singly_linkedlist *temp_node, *ptr;

    if (head == NULL) {
        printf("list is empty\n");
        return head;
    }
    // deletion of first node
    if (head->data == data) {
        return delete_at_head(head);
    }
    // deletion in between or at the end
    ptr = head;
    while (ptr->next != NULL) {
        if (ptr->next->data == data) {
            temp_node = ptr->next;
            ptr->next = temp_node->next;
            free(temp_node);
            return head;
        }
        ptr = ptr->next;
    }

    printf("\nelement %d not found\n", data);
    return head;
}

singly_linkedlist *delete_list(singly_linkedlist *head) {
    /*
     * time complexity: Θ(n), for scanning the list of size n
     * space complexity: O(1), temporary pointer variable
     */
    singly_linkedlist *temp_node, *ptr;

    if (head == NULL) {
        printf("list is empty");
        return head;
    }
    ptr = head;
    while (ptr != NULL) {
        temp_node = ptr;
        ptr = ptr->next;
        head = ptr;
        free(temp_node);
    }
    return head;
}
