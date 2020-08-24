/*
 * author: greyshell
 * description: reverse the stack without using any auxiliary stack
 * */

#include <stdio.h>
#include "../private_libs/stack/stack.h"

void _insert_at_bottom(stack *s, int data) {
    /*
     * time complexity: O(n)
     */
    int out_data;
    if (is_empty_stack(s)) {
        push(s, data);
        return;
    }
    pop(s, &out_data);
    _insert_at_bottom(s, data);
    push(s, out_data);
}

void reverse_stack(stack *s) {
    /*
     * reverse all stack elements
     * time complexity: O(n^2), reverse_stack() depends on insert_at_bottom()
     * space complexity: O(n), at the max n elements can be present in the call stack
     */
    int out_data;
    if (is_empty_stack(s)) {
        return;
    }
    pop(s, &out_data);
    reverse_stack(s);
    // start inserting element from bottom
    _insert_at_bottom(s, out_data);
}

int main(void) {
    // test data_arr
    int data[] = {10, 20, 30, 40, 50};
    stack s;

    // initialize the stack
    initialize_stack(&s);

    for (int i = 0; i < 5; i++) {
        push(&s, data[i]);
    }

    // display the stack
    printf("display(top -> last element): ");
    display_stack(&s);
    printf("\n");

    // reverse the stack
    reverse_stack(&s);
    printf("display: ");
    display_stack(&s);
    printf("\n");

    return 0;
}
