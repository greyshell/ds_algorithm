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


# dynamic programming
# ====================
add_executable(find_fib dynamic_programming/find_fib.c ${MyCSources})


# graph
# =====


# hashing
# =========


# heap
# =========


# linkedList
# ===========
add_executable(test_singly_linkedlist linkedList/test_singly_linkedlist.c ${MyCSources})
# add_executable(fuzz_singly_linkedlist linkedList/fuzz_singly_linkedlist.c ${MyCSources})

# private_libs
# ============


# queue
# ======


# recursion
# =========

# build_concept
# ==========
add_executable(quine build_concept/quine.c ${MyCSources})
add_executable(test_foo build_concept/test_foo.c ${MyCSources})
add_executable(concept build_concept/concept.c ${MyCSources})

# searching
# =========


# sorting
# =======
add_executable(test_sort sorting/test_sort.c ${MyCSources})

# stack
# ======



# string
# =======



# tree
# =====
