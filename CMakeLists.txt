# purpose: add .c files
cmake_minimum_required(VERSION 3.14)
project(ds_algorithm C)

set(CMAKE_C_STANDARD 99)

# Include all library code
# ==========================================================================================
# include all source files
# ===========================================================================================
FILE(GLOB stack_singly_linklist_int libO2/src/stack_singly_linkedlist_int.c)
FILE(GLOB queue_singly_linklist_int libO2/src/queue_singly_linkedlist_int.c)
FILE(GLOB binary_heap_dynamic_array_int libO2/src/binary_heap_dynamic_array_int.c)
FILE(GLOB sort libO2/src/sort_int.c)

# ==========================================================================================
# include the executables
# ===========================================================================================

# core_concepts
add_executable(bracket_resolver core_concepts/bracket_resolver.c)
add_executable(play core_concepts/play.c)
add_executable(quine core_concepts/quine.c)
add_executable(concept core_concepts/variable_size.c)
add_executable(example_variadic_function core_concepts/variadic_function.c)

# stack
add_executable(example_stack_singly_linklist_int libO2/examples/example_stack_singly_linkedlist_int.c ${stack_singly_linklist_int})
add_executable(example_stack_singly_linklist_int_02 libO2/examples/example_stack_singly_linkedlist_int_02.c ${stack_singly_linklist_int})
add_executable(reverse_stack stack/reverse_stack.c ${stack_singly_linklist_int})

# queue
add_executable(example_queue_singly_linklist_int
        libO2/examples/example_queue_singly_linkedlist_int.c
        ${queue_singly_linklist_int})

# heap
add_executable(example_binary_heap_dynamic_array_int libO2/examples/example_binary_heap_dynamic_array_int.c
        ${binary_heap_dynamic_array_int})
add_executable(k_largest_elements heap/k_largest_elements_array.c
        ${binary_heap_dynamic_array_int})

# sorting
add_executable(example_sort_int libO2/examples/example_sort_int.c ${sort})