/*
 * author: greyshell
 * description: reverse the stack without using any auxiliary stack
 * */

#include <stdio.h>
#include "../private_libs/stack/stack_using_singly_linked_list.h"

void insert_at_bottom(stack *s, int data){
    /*
     * start inserting elements from bottom
     */
    int popped_value;
    if (is_empty_stack(s)){
        push(s, data);
        return;
    }
    pop(s, &popped_value);
    insert_at_bottom(s, data);
    push(s, popped_value);
}

void reverse_stack(stack *s) {
    /*
     * reverse all stack elements
     * time complexity: O(n^2)
     * space complexity: O(n), at the max n element can be present in the call stack
     */
    int popped_value;
    if (is_empty_stack(s)){
        return;
    }
    pop(s, &popped_value);
    reverse_stack(s);
    insert_at_bottom(s, popped_value);
}

int main(void) {
    stack my_stack;

    // initialize the stack
    initialize_stack(&my_stack);

    // push elements
    push(&my_stack, 10);
    push(&my_stack, 20);
    push(&my_stack, 30);
    push(&my_stack, 40);
    push(&my_stack, 50);

    // display the stack
    display_stack(&my_stack);

    // reverse the stack
    reverse_stack(&my_stack);

    // display the stack
    display_stack(&my_stack);

    // delete the stack
    delete_stack(&my_stack);
    return 0;
}
