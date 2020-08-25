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

# heap
FILE(GLOB MaxHeap private_libs/heap/heap.c)

# stack
FILE(GLOB Stack private_libs/stack/stack.c)
FILE(GLOB Stack02 private_libs/stack/stack02.c)
FILE(GLOB Stack03 private_libs/stack/stack03.c)
FILE(GLOB Stack04 private_libs/stack/stack04.c)

# queue
FILE(GLOB Queue private_libs/queue/queue.c)
FILE(GLOB Queue02 private_libs/queue/queue02.c)

# linked list
FILE(GLOB SinglyLinkedList private_libs/linked_list/sll.c)
FILE(GLOB DoublyLinkedList private_libs/linked_list/xor_dll.c)
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
add_executable(testlib_sll linked_list/testlib_sll.c ${SinglyLinkedList})

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
# --- API test ---
add_executable(testlib_stack stack/test/testlib_stack.c ${Stack})
add_executable(testlib_stack02 stack/test/testlib_stack02.c ${Stack02})
add_executable(testlib_stack03 stack/test/testlib_stack03.c ${Stack03})
add_executable(testlib_stack04 stack/test/testlib_stack04.c ${Stack04})
# ------ code ------
add_executable(reverse_stack stack/reverse_stack.c ${Stack})


# queue
# ======
# --- API test ---
add_executable(testlib_queue queue/test/testlib_queue.c ${Queue})
add_executable(testlib_queue02 queue/test/testlib_queue02.c ${Queue02})
# ------ code ------


# heap
# ======
# --- API test ---
add_executable(testlib_heap heap/test/testlib_heap.c ${MaxHeap})
# ------ code ------

# string
# =======
# --- API demo ---
# --- API test ---


# binary_search_tree
# --- API demo ---
# --- API test ---


# hash
add_executable(test_hash hashing/test_hash.c ${HASHTABLE})