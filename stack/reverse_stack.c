/*
 * author: greyshell
 * description: reverse the stack without using any auxiliary stack
 * */

#include <stdio.h>
#include "../private_libs/stack/stack_sll.h"

void my_display(void *data) {
    /*
     * display elements: datatype -> int
     */
    printf("%d ", *(int *) data);
}

void insert_at_bottom(stack *s, void *data) {
    /*
     * start inserting elements from bottom
     * time complexity: O(n)
     */
    void *out_data;
    if (is_empty_stack(s)) {
        push(s, data);
        return;
    }
    pop(s, &out_data);
    insert_at_bottom(s, data);
    push(s, out_data);
}

void reverse_stack(stack *s) {
    /*
     * reverse all stack elements
     * time complexity: O(n^2), reverse_stack() depends on insert_at_bottom()
     * space complexity: O(n), at the max n elements can be present in the call stack
     */
    void *out_data;
    if (is_empty_stack(s)){
        return;
    }
    pop(s, &out_data);
    reverse_stack(s);
    insert_at_bottom(s, out_data);
}

int main(void) {
    int data[] = {10, 20, 30, 40, 50};
    stack my_stack;

    // initialize the stack
    initialize_stack(&my_stack);

    for (int i = 0; i < 5; i++) {
        push(&my_stack, &data[i]);
    }

    // display the stack
    view_stack_func *my_func_ptr = my_display;
    printf("display: ");
    display_stack(&my_stack, my_func_ptr);
    printf("\n");

    // reverse the stack
    reverse_stack(&my_stack);
    printf("display: ");
    display_stack(&my_stack, my_func_ptr);
    printf("\n");

    return 0;
}
