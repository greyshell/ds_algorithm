# purpose: add .c files
cmake_minimum_required(VERSION 3.14)
project(ds_algorithm C)

set(CMAKE_C_STANDARD 99)

# Include all library code
# FILE(GLOB MyCSources private_libs/*.c)
# ========================
# include all source files
# =========================
# foo lib
FILE(GLOB MyFoo private_libs/foo/foo.c)
# stack
FILE(GLOB MyStack01 private_libs/stack/stack_using_singly_linked_list.c)
FILE(GLOB MyStack02 private_libs/stack/stack_using_dynamic_array.c)
# queue
# queue
# singly linked list
FILE(GLOB MySinglyLinkedList private_libs/singly_linked_list/singly_linked_list.c)
# double linked list
# circular linked list
# unrolled linked list
# skip list
# binary search tree
FILE(GLOB MyBST private_libs/binary_search_tree/binary_search_tree.c)
# sorting
FILE(GLOB MySorting private_libs/sorting/sorting.c)
# hashtable



# backtracking
# ============


# bit_manipulation
# ================

# binary search tree
# ==================
add_executable(testlib_binary_search_tree binary_search_tree/testlib_binary_search_tree.c ${MyBST})

# dynamic programming
# ====================
add_executable(find_fib dynamic_programming/find_fib.c)


# graph
# =====


# hashing
# =========


# heap
# =========


# linked_list
# ===========
add_executable(testlib_singly_linked_list linked_list/testlib_singly_linked_list.c ${MySinglyLinkedList})

# private_libs
# ============


# queue
# ======


# recursion
# =========

# basic
# ==========
add_executable(testlib_foo basic/testlib_foo.c ${MyFoo})
add_executable(test basic/test.c)
add_executable(quine basic/quine.c)
add_executable(concept basic/variable_size.c)
add_executable(example_variadic_function basic/variadic_function.c)

# searching
# =========


# sorting
# =======
add_executable(testlib_sort sorting/testlib_sorting.c ${MySorting})

# stack
# ======
add_executable(testlib_stack_using_singly_linked_list stack/testlib_stack_using_singly_linked_list.c ${MyStack01})
add_executable(testlib_stack_using_dynamic_array stack/testlib_stack_using_dynamic_array.c ${MyStack02})

# string
# =======



# binary_search_tree
# =====
