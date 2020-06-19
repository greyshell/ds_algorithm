# Description

`queue_sll.h`:
- a `singly linked list` based implementation where the data is a `void` pointer.

**API Details**:

Sl No | Methods                                  | Time | Space
------|-------------------------------------------|------|------
1     | `void initialize_queue(queue *)`          | O(1) | O(1)
2     | `void initialize_queue(queue *)`          | O(1) | O(1)
3     | `bool is_empty_queue(queue *)`            | O(1) | O(1)
4     | `size_t get_queue_size(queue *)`          | O(1) | O(1)
5     | `bool enqueue(queue *, void *)`           | O(1) | O(1)
6     | `bool dequeue(queue *, void **)`          | O(1) | O(1)
7     | `bool peek_at_front(queue *, void **)`    | O(1) | O(1)
8     | `bool peek_at_rear(queue *, void **)`     | O(1) | O(1)
9     | `bool delete_queue(queue *)`              | O(1) | O(1)
10    | `void display_queue(queue *, view_queue *)` | O(n) | O(1)

Example: `cat ../stack/demolib_queue_sll.c`
