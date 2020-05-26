# Description

`stack_using_dynamic_array.h`:
- `repeated doubling / halving` technique is used to grow / shrink the stack size.
- `amortized` time complexity of `push()` and `pop()` -> `O(1)`.

`stack_using_singly_linked_list.h`
- it is a singly linked list based implementation.
- compare with `static` array based implementation, extra space is required for storing the references.

**How to use:**

```
// file name: test_stack.c
#include "../private_libs/stack_using_singly_linked_list.h"

int main(void){
    stack s;
    initialize_stack(&s);
    push(s, 5);
    int data = peek(s);
    int data = pop(s)

    return 0;
}
```

add the following lines to `CMakeLists.txt`.

```
FILE(GLOB MyStack01 private_libs/stack/stack_using_singly_linked_list.c)
add_executable(test_stack stack/test_stack.c ${MyStack01})
```

**Detailed APIs**

Sl No | APIs                             | Time Complexity | Space Complexity | Notes
------|----------------------------------|-----------------|------------------|----------------------------------------------------------------------------------
1     | `void initialize_stack(stack *)` | O(1)            | O(1)             | create the stack and initialize the stack top
2     | `void push(stack *, int)`        | O(1)            | O(1)             | add an element into the stack
3     | `int pop(stack *)`               | O(1)            | O(1)             | delete an element from the stack, if the stack is empty then it returns `INT_MIN`
4     | `void pop_all(stack *)`          | O(n)            | O(1)             | delete all elements from the stack
5     | `int peek(stack *)`              | O(1)            | O(1)             | display the stack top, if the stack is empty then it returns `INT_MIN`
6     | `void peek_all(stack *)`         | O(n)            | O(1)             | display all elements from the stack
