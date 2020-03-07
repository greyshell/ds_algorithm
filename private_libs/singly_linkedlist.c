/*
 * author: greyshell
 * description: implementation of singly linked list
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "singly_linkedlist.h"


void display(singly_linkedlist *head) {
    /*
     * time complexity: O(n)
     * space complexity: O(1) -> temporary pointer variables
     */
    singly_linkedlist *curr_ptr;

    // when the list has 0 element
    if (head == NULL) {
        printf("\nempty list !!");
        return;
    }
    curr_ptr = head;

    while (curr_ptr != NULL) {
        printf("%d ", curr_ptr->data);
        curr_ptr = curr_ptr->next;
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
    singly_linkedlist *curr_ptr;
    size_t count = 0;
    curr_ptr = head;

    while (curr_ptr != NULL) {
        ++count;
        curr_ptr = curr_ptr->next;
    }
    return count;
}

singly_linkedlist *get_node(singly_linkedlist *head, int data) {
    /*
     * if found then return the node_pointer else return NULL
     * time complexity: O(n), find the position
     * space complexity: O(1), for temporary pointer variable
     */
    singly_linkedlist *curr_ptr;

    curr_ptr = head;
    while (curr_ptr != NULL) {
        if (curr_ptr->data == data) {
            return curr_ptr;
        }
        curr_ptr = curr_ptr->next;
    }
    return NULL;  // covers the scenario when head is NULL / data is not found
}

singly_linkedlist *get_middle_node(singly_linkedlist *head) {
    /*
     * time complexity: O(n), scan the linked list only 1 time.
     * space complexity: O(1), temporary pointer variable
     */
    singly_linkedlist *fast_ptr, *slow_ptr;
    if (head == NULL) {
        printf("\nempty list !!");
        return NULL;
    }

    fast_ptr = slow_ptr = head;
    // when the list count >= 2
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;  // when the list count is 1 returns NULL
}

singly_linkedlist *get_kth_node_from_end(singly_linkedlist *head, size_t k) {
    /*
     * 1 traversal / pass
     * time complexity: O(n)
     * space complexity: O(1)
     */
    singly_linkedlist *first_ptr, *second_ptr;
    size_t count;
    first_ptr = second_ptr = head;

    // k = 1 means last node
    if (k < 1) {
        printf("\nk < 1");
        return NULL;
    }

    if (head == NULL) {
        printf("\nempty list !!");
        return NULL;
    }

    // move the first_ptr by k nodes so that the gap between first_ptr and second_prt is k
    count = 1;
    while (count <= k && first_ptr != NULL) {
        first_ptr = first_ptr->next;
        count++;
    }

    // when k is more than that list length
    if (--count < k) {
        printf("\nk > list length !!");
        return NULL;
    }

    while (first_ptr != NULL) {
        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next;
    }

    return second_ptr;
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
     * node: through this function you can't insert element after the last node
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

singly_linkedlist *delete_at_tail(singly_linkedlist *head) {
    /*
     * use get_kth_node_from_end() where k = 2, to get the second last node
     */
    singly_linkedlist *temp_node, *second_last_node;
    size_t k = 2;
    second_last_node = get_kth_node_from_end(head, k);
    temp_node = second_last_node->next;
    free(temp_node);
    second_last_node->next = NULL;

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
