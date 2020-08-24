
  # Description

  ## `sll.h`
  - `singly linked list` implementation where the data_arr is a `void` pointer.

  **API Details**:

Sl No | Methods                                                                                              | Time | Space
------|------------------------------------------------------------------------------------------------------|------|------
1     | `void initialize_sll(singly_linked_list *)`                                                          | O(1) | O(1)
2     | `size_t get_sll_size(singly_linked_list *)`                                                          | O(1) | O(1)
3     | `bool is_empty_sll(singly_linked_list *)`                                                            | O(1) | O(1)
4     | `bool insert_sll_node_at_head(singly_linked_list *, void *)`                                         | O(1) | O(1)
5     | `bool insert_sll_node_at_tail(singly_linked_list *, void *)`                                         | O(n) | O(1)
6     | `bool insert_sll_node_at_index(singly_linked_list *, void *, size_t)`                                | O(n) | O(1)
7     | `bool delete_sll_node_at_head(singly_linked_list *, void **)`                                        | O(1) | O(1)
8     | `bool delete_sll_node_at_tail(singly_linked_list *, void **)`                                        | O(n) | O(1)
9     | `bool delete_sll_node_at_index_from_head(singly_linked_list *, size_t, void **)`                     | O(n) | O(1)
10    | `bool delete_sll_node_at_index_from_tail(singly_linked_list *, size_t, void **)`                     | O(n) | O(1)
11    | `bool delete_sll_node_if_found(singly_linked_list *, void *, compare_singly_linked_list *, void **)` | O(n) | O(1)
12    | `bool delete_sll(singly_linked_list *)`                                                              | O(n) | O(1)
13    | `void display_sll(singly_linked_list *, view_singly_linked_list *)`                                  | O(n) | O(1)
14    | `void reverse_display_sll(singly_linked_list *, view_singly_linked_list *)`                          | O(n) | O(n)
15    | `bool is_found_in_sll(singly_linked_list *, void *, compare_singly_linked_list *, size_t *)`         | O(n) | O(1)
16    | `bool get_kth_element_in_sll_from_head(singly_linked_list *, size_t, void **)`                       | O(n) | O(1)
17    | `bool get_kth_element_in_sll_from_tail(singly_linked_list *, size_t, void **)`                       | O(n) | O(1)
18    | `bool get_middle_element_in_sll(singly_linked_list *, void **)`                                      | O(n) | O(1)