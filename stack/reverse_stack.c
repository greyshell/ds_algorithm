/*
 * author: greyshell
 * description: reverse the stack without using any auxiliary stack
 * */

#include <stdio.h>
#include "../private_libs/stack/stack_dyn_arr.h"

void insert_at_bottom(stack *s, int data){
    /*
     * start inserting elements from bottom
     * time complexity: O(n)
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
     * time complexity: O(n^2), reverse_stack() depends on insert_at_bottom()
     * space complexity: O(n), at the max n elements can be present in the call stack
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
    push(&my_stack, 50);  // top element

    // display the stack
    display_stack(&my_stack);  // 50 40 30 20 10

    // reverse the stack
    reverse_stack(&my_stack);

    // display the stack
    display_stack(&my_stack);  // output: 10 20 30 40 50

    // delete the stack
    delete_stack(&my_stack);
    return 0;
}
