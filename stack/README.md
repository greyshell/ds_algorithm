# Description

`stack.h` is used for the singly linked list based `stack` implementation.
- `disadvantage`: extra space is required for storing the references.

**How to use:**

```
#include "../private_libs/stack.h"

int main(void){
    stack s;
    // set the stack top NULL
    initialize_stack(&s);
    // basic operations
    push(s, 5);
    int data = peek(s);
    int data = pop(s)

    return 0;
}
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

---

`dyn_array_stack.h` - is used for dynamic array based `stack` implementation.
- `repeated doubling` technique (grow and shrink) is used to improve the `amortized` time complexity(i.e. `O(1)`) for `push()` and `pop()` operations.