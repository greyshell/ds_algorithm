/*
 * author: greyshell
 * description: test dynamic array based implementation of stack
 * */

#include <stdio.h>
#include "../private_libs/dynamic_array_stack.h"

int main(void) {
    int data = 5;
    size_t choice;
    dynamic_array_stack my_stack;
    printf("creating a stack !! \n");
    initialize_dynamic_array_stack(&my_stack);
    printf("stack capacity: %zu \n", stack_capacity_dynamic_array(&my_stack));
    data = 1;
    printf("push 1 \n");
    push_dynamic_array(&my_stack, data);
    printf("stack capacity: %zu \n", stack_capacity_dynamic_array(&my_stack));
    data = 2;
    printf("push 2 \n");
    push_dynamic_array(&my_stack, data);
    printf("stack capacity: %zu \n", stack_capacity_dynamic_array(&my_stack));
    data = 3;
    printf("push 3 \n");
    push_dynamic_array(&my_stack, data);
    data = 4;
    printf("push 4 \n");
    push_dynamic_array(&my_stack, data);
    data = 5;
    printf("push 5 \n");
    push_dynamic_array(&my_stack, data);

    printf("stack capacity: %zu \n", stack_capacity_dynamic_array(&my_stack));
    printf("stack reserved: %zu \n", stack_reserve_count_dynamic_array(&my_stack));

    data = peek_dynamic_array(&my_stack);
    printf("peek = %d \n", data);
    peek_all_dynamic_array(&my_stack);
    pop_all_dynamic_array(&my_stack);
    printf("stack capacity: %zu \n", stack_capacity_dynamic_array(&my_stack));

    data = pop_dynamic_array(&my_stack);
    printf("popped = %d \n", data);
//    data = pop_dynamic_array(&my_stack);
//    printf("popped = %d \n", data);
//    data = pop_dynamic_array(&my_stack);
//    printf("popped = %d \n", data);
//    data = pop_dynamic_array(&my_stack);
//    printf("popped = %d \n", data);
    return 0;
}