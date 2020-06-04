# Description

static array elements are stored on the `system stack memory` and dynamic array elements are
 stored on the `heap memory`. so any static array based implementation runs faster than dynamic
  array based implementation.

`stack_using_dynamic_array.h`:
- `repeated doubling / halving` technique is used to grow / shrink the stack size.
- `amortized` time complexity of `push()` and `pop()` -> `O(1)`.
- initial array size = 1

`stack_using_singly_linked_list.h`:
- it is `singly linked list` based implementation.
- compare with `static` array based implementation, extra space is required for storing the references.

**Detailed APIs**

Sl No | APIs                             | Time Complexity | Space Complexity | Notes
------|----------------------------------|-----------------|------------------|------------------------------------------------------------------------------------------------------------------------------
1     | `void initialize_stack(stack *)` | O(1)            | O(1)             | create the stack and initialize the stack top
2     | `bool push(stack *, int)`        | O(1)            | O(1)             | add an element into the stack, if push is successful, then return true else return false
3     | `bool pop(stack *, int *)`       | O(1)            | O(1)             | remove an element from the stack, if pop is successful then return true else return false
4     | `bool peek(stack *, int *)`      | O(1)            | O(1)             | display the top element, if peek is successful then return true, else return false
5     | `void display_stack(stack *)`    | O(n)            | O(1)             | display all stack elements
6     | `bool is_empty_stack(stack *)`   | O(1)            | O(1)             | if the stack is empty then return true, else return false
7     | `size_t get_stack_size(stack *)` | O(n)            | O(1)             | get the stack size, for dynamic array based implementation time complexity: O(1)
8     | `bool delete_stack(stack *)`     | O(1)            | O(1)             | delete the stack by popping out all elements, if all elements are popped out successfully then return true, else return false

**How to use**: `../stack/demo_stack_api.c`

```
# `Clion support`: add the following lines into `CMakeLists.txt`.
FILE(GLOB MyStack01 private_libs/stack/stack_using_singly_linked_list.c)
add_executable(demolib_stack_using_singly_linked_list stack/demo_stack_api.c ${MyStack01})
```