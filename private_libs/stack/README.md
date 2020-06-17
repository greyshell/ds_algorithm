# Description

static array elements are stored on the `system stack memory` and dynamic array elements are
 stored on the `heap memory`. so any static array based implementation runs faster than dynamic
  array based implementation.

`stack_dyn_arr.h`:
- dynamic array based implementation (datatype -> `int`)
- `repeated doubling / halving` technique is used to grow / shrink the stack size.
- `amortized` time complexity of `push()` and `pop()` -> `O(1)`.
- initial array size = 1

**API Details**:

Sl No | APIs                             | Time Complexity | Space Complexity | Notes
------|----------------------------------|-----------------|------------------|------------------------------------------------------------------------------------------------------------------------------
1     | `bool initialize_stack(stack *)` | O(1)            | O(1)             | create the stack and initialize the stack top, if successful then return true else false
2     | `bool push(stack *, int)`        | O(1)            | O(1)             | add an element into the stack, if push is successful, then return true else return false
3     | `bool pop(stack *, int *)`       | O(1)            | O(1)             | remove an element from the stack, if pop is successful then return true else return false
4     | `bool peek(stack *, int *)`      | O(1)            | O(1)             | display the top element, if peek is successful then return true, else return false
5     | `bool is_empty_stack(stack *)`   | O(1)            | O(1)             | if the stack is empty then return true, else return false
6     | `size_t get_stack_size(stack *)` | O(1)            | O(1)             | get the stack size
7     | `bool delete_stack(stack *)`     | O(1)            | O(1)             | delete the stack by popping out all elements, if all elements are popped out successfully then return true, else return false
8     | `void display_stack(stack *)`    | O(n)            | O(1)             | display all stack
 elements

**Example**: `cat ../stack/demolib_stack_dyn_arr.c`

`stack_sll.h`:
- it is `singly linked list` based implementation (datatype -> `void data`).
- compare with `static` array based implementation, extra space is required for storing the references.