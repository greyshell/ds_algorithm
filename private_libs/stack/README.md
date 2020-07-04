# Description

## `stack_dyn_arr.h`
- dynamic array based implementation where the data is a `void` pointer.
- `repeated doubling / halving` technique is used to grow and shrink the stack size.
- `amortized` time complexity of `push()` and `pop()` is `O(1)`.
- initial array_size can be set via `initialize_stack()` method.

**API Details**:

Sl No | Methods                                          | Time | Space
------|--------------------------------------------------|------|------
1     | `bool initialize_stack(stack *, size_t)`         | O(1) | O(1)
2     | `bool push(stack *, void *)`                     | O(1) | O(1)
3     | `bool pop(stack *, void **)`                     | O(1) | O(1)
4     | `bool peek(stack *, void **)`                    | O(1) | O(1)
5     | `bool is_empty_stack(stack *)`                   | O(1) | O(1)
6     | `size_t get_stack_size(stack *)`                 | O(1) | O(1)
7     | `bool delete_stack(stack *)`                     | O(1) | O(1)
8     | `void display_stack(stack *, view_stack_func *)` | O(n) | O(1)

## `stack_sll.h`
- it is `singly linked list` based implementation where the data is a `void` pointer.
- all ADT methods are same as `stack_dyn_arr.h` **except** - `bool initialize_stack(stack *)` 
- compare with `static` array based implementation, extra space is required for storing the references.

