# purpose: add .c files
cmake_minimum_required(VERSION 3.14)
project(ds_algorithm C)

set(CMAKE_C_STANDARD 99)

# Include all library code
# FILE(GLOB MyCSources private_libs/*.c)
# ==========================================================================================
# include all source files
# ===========================================================================================
# foo lib
FILE(GLOB MyFoo private_libs/foo/foo.c)

# stack
FILE(GLOB StackSLL private_libs/stack/stack_sll.c)
FILE(GLOB StackDynArr private_libs/stack/stack_dyn_arr.c)

# queue
FILE(GLOB QueueSLL private_libs/queue/queue_sll.c)

# linked list
FILE(GLOB SinglyLinkedList private_libs/singly_linked_list/singly_linked_list.c)
FILE(GLOB DoublyLinkedList private_libs/linked_list/doubly_linked_list.c)
# double linked list
# circular linked list
# unrolled linked list
# skip list
# binary search tree
# rb tree
# avl tree
# 2-3 tree
FILE(GLOB MyBST private_libs/binary_search_tree/binary_search_tree.c)
# sorting
FILE(GLOB MySorting private_libs/sorting/sorting.c)
# hashtable
FILE(GLOB HASHTABLE private_libs/hash_table/hash.c)
# ============================================================================================

# backtracking
# ============


# bit_manipulation
# ================

# binary search tree
# ==================
# --- API demo ---
# --- API test ---
add_executable(testlib_binary_search_tree binary_search_tree/testlib_binary_search_tree.c ${MyBST})

# dynamic programming
# ====================
add_executable(find_fib dynamic_programming/find_fib.c)


# graph
# =====
# --- API demo ---
# --- API test ---


# hashing
# =========
# --- API demo ---
# --- API test ---


# heap
# =========
# --- API demo ---
# --- API test ---


# linked_list
# ===========
# --- API demo ---
add_executable(demolib_dll linked_list/demolib_dll.c ${DoublyLinkedList})
# --- API test ---
add_executable(testlib_singly_linked_list linked_list/testlib_singly_linked_list.c ${SinglyLinkedList})


# queue
# ======
# --- API demo ---
# --- API test ---

# recursion
# =========

# basic
# ======
add_executable(testlib_foo basic/testlib_foo.c ${MyFoo})
add_executable(test basic/test.c)
add_executable(play basic/play.c)
add_executable(quine basic/quine.c)
add_executable(concept basic/variable_size.c)
add_executable(example_variadic_function basic/variadic_function.c)

# searching
# =========
# --- API demo ---
# --- API test ---

# sorting
# =======
add_executable(trouble_sort sorting/trouble_sort.c ${MySorting})
# --- API demo ---
# --- API test ---
add_executable(testlib_sort sorting/testlib_sorting.c ${MySorting})

# stack
# ======
add_executable(reverse_stack stack/reverse_stack.c ${StackSLL})
# --- API demo ---
add_executable(demolib_stack_sll stack/demolib_stack_sll.c ${StackSLL})
add_executable(demolib_stack_dyn_arr stack/demolib_stack_dyn_arr.c ${StackDynArr})
# --- API test ---
add_executable(testlib_stack_dyn_arr stack/testlib_stack_dyn_arr.c ${StackDynArr})
add_executable(testlib_stack_sll stack/testlib_stack_sll.c ${StackSLL})


# queue
# --- API demo ---
add_executable(demolib_queue_sll queue/demolib_queue_sll.c ${QueueSLL})
# --- API test ---
add_executable(testlib_queue_sll queue/testlib_queue_sll.c ${QueueSLL})
# string
# =======
# --- API demo ---
# --- API test ---


# binary_search_tree
# --- API demo ---
# --- API test ---


# hash
add_executable(test_hash hashing/test_hash.c ${HASHTABLE})