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
FILE(GLOB STACK_SLL private_libs/stack/stack_sll.c)
FILE(GLOB STACK_DYN_ARR private_libs/stack/stack_dyn_arr.c)

# queue
FILE(GLOB QUEUE_SLL private_libs/queue/queue_sll.c)

# singly linked list
FILE(GLOB MySinglyLinkedList private_libs/singly_linked_list/singly_linked_list.c)

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
# --- API test ---
add_executable(testlib_singly_linked_list linked_list/testlib_singly_linked_list.c ${MySinglyLinkedList})


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
add_executable(reverse_stack stack/reverse_stack.c ${STACK_SLL})
# --- API demo ---
add_executable(demolib_stack_sll stack/demolib_stack_sll.c ${STACK_SLL})
add_executable(demolib_stack_dyn_arr stack/demolib_stack_dyn_arr.c ${STACK_DYN_ARR})
# --- API test ---
add_executable(testlib_stack_dyn_arr stack/testlib_stack_dyn_arr.c ${STACK_DYN_ARR})
add_executable(testlib_stack_sll stack/testlib_stack_sll.c ${STACK_SLL})


# queue
# --- API demo ---
add_executable(demolib_queue_sll queue/demolib_queue_sll.c ${QUEUE_SLL})
# --- API test ---
add_executable(testlib_queue_sll queue/testlib_queue_sll.c ${QUEUE_SLL})
# string
# =======
# --- API demo ---
# --- API test ---


# binary_search_tree
# --- API demo ---
# --- API test ---
