# purpose: add .c files
cmake_minimum_required(VERSION 3.14)
project(ds_algorithm C)

set(CMAKE_C_STANDARD 99)

# Include all library code
FILE(GLOB MyCSources private_libs/*.c)

# backtracking
# ============


# bit_manupulation
# ================

# binary search tree
# ==================
add_executable(test_binary_search_tree binary_search_tree/test_binary_search_tree.c ${MyCSources})

# dynamic programming
# ====================
add_executable(find_fib dynamic_programming/find_fib.c ${MyCSources})


# graph
# =====


# hashing
# =========


# heap
# =========


# linked_list
# ===========
add_executable(test_singly_linkedlist linked_list/test_singly_linked_list.c ${MyCSources})
# add_executable(fuzz_singly_linkedlist linked_list/fuzz_singly_linkedlist.c ${MyCSources})

# private_libs
# ============


# queue
# ======


# recursion
# =========

# basic
# ==========
add_executable(test basic/test.c ${MyCSources})
add_executable(quine basic/quine.c ${MyCSources})
add_executable(test_foo basic/test_foo.c ${MyCSources})
add_executable(concept basic/variable_size.c ${MyCSources})
add_executable(example_variatic_function basic/variadic_function.c ${MyCSources})

# searching
# =========


# sorting
# =======
add_executable(test_sort sorting/test_sort.c ${MyCSources})

# stack
# ======



# string
# =======



# binary_search_tree
# =====
