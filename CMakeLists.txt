# purpose: add .c files
cmake_minimum_required(VERSION 3.14)
project(ds_algorithm C)

set(CMAKE_C_STANDARD 99)

# Include all library code
# FILE(GLOB MyCSources liquid_oxygen/*.c)
# ==========================================================================================
# include all source files
# ===========================================================================================

# stack_singly_linklist_int lib
FILE(GLOB stack_singly_linklist_int libO2/src/stack_singly_linkedlist_int.c)


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
add_executable(demo_stack_singly_linklist_int libO2/sample/demo_stack_singly_linkedlist_int.c
        ${stack_singly_linklist_int})
add_executable(reverse_stack stack/reverse_stack.c ${stack_singly_linklist_int})


# foo lib
# FILE(GLOB MyFoo liquid_oxygen/src/foo/foo.c)

# heap
# FILE(GLOB Heap liquid_oxygen/src/heap/heap.c)

# stack
# FILE(GLOB stack_sll_int liquid_oxygen/src/stack/stack_sll_int.c)
# FILE(GLOB Stack02 liquid_oxygen/stack/stack02.c)
# FILE(GLOB Stack03 liquid_oxygen/stack/stack03.c)
# FILE(GLOB Stack04 liquid_oxygen/stack/stack04.c)

# queue
#FILE(GLOB Queue liquid_oxygen/src/queue/queue.c)
#FILE(GLOB Queue02 liquid_oxygen/src/queue/queue02.c)
#
## linked list
#FILE(GLOB SinglyLinkedList liquid_oxygen/src/linked_list/sll.c)
#FILE(GLOB DoublyLinkedList liquid_oxygen/src/linked_list/xor_dll.c)
## double linked list
## circular linked list
## unrolled linked list
## skip list
## binary search tree
## rb tree
#FILE(GLOB RBT liquid_oxygen/src/rbt/rbt.c)
## avl tree
## 2-3 tree
#FILE(GLOB MyBST liquid_oxygen/src/binary_search_tree/binary_search_tree.c)
## sorting
#FILE(GLOB Sorting liquid_oxygen/src/sorting/sort.c)
## hashtable
#FILE(GLOB HASHTABLE liquid_oxygen/src/hash_table/hash.c)
## ============================================================================================
#
## backtracking
## ============
#
#
## bit_manipulation
## ================
#
## binary search tree
## ==================
## --- API demo ---
## --- API tests ---
#add_executable(testlib_binary_search_tree binary_search_tree/testlib_binary_search_tree.c ${MyBST})
#
## dynamic programming
## ====================
#add_executable(find_fib dp/find_fib.c)
#
#
## graph
## =====
## --- API demo ---
## --- API tests ---
#
#
## hashing
## =========
## --- API demo ---
## --- API tests ---
#
#
## heap
## =========
## --- API demo ---
## --- API tests ---
#
#
## linked_list
## ===========
## --- API demo ---
#add_executable(demolib_dll linked_list/demolib_dll.c ${DoublyLinkedList})
## --- API tests ---
#add_executable(testlib_sll linked_list/testlib_sll.c ${SinglyLinkedList})
#
## queue
## ======
## --- API demo ---
## --- API tests ---
#
## recursion
## =========
#
## basic
## ======
#add_executable(testlib_foo basic/testlib_foo.c ${MyFoo})
#add_executable(tests basic/tests.c)
#add_executable(play basic/play.c)
#add_executable(prob01_nayan basic/prob01_nayan.c)
#add_executable(quine basic/quine.c)
#add_executable(concept basic/variable_size.c)
#add_executable(example_variadic_function basic/variadic_function.c)
#
## searching
## =========
## --- API demo ---
## --- API tests ---
#
## sorting
## =======
## --- API tests ---
#add_executable(testlib_sort sorting/tests/testlib_sort.c ${Sorting} ${Heap})
## ------ code ------
#add_executable(trouble_sort sorting/trouble_sort.c ${Sorting})
#
#
## stack
## ======
## --- API tests ---
# add_executable(testlib_stack_sll_int liquid_oxygen/tests/testlib_stack_sll_int.c ${stack_sll_int})
#add_executable(testlib_stack02 stack/tests/testlib_stack02.c ${Stack02})
#add_executable(testlib_stack03 stack/tests/testlib_stack03.c ${Stack03})
#add_executable(testlib_stack04 stack/tests/testlib_stack04.c ${Stack04})
## ------ code ------
#add_executable(reverse_stack stack/reverse_stack.c ${Stack})
#
#
## queue
## ======
## --- API tests ---
#add_executable(testlib_queue queue/tests/testlib_queue.c ${Queue})
#add_executable(testlib_queue02 queue/tests/testlib_queue02.c ${Queue02})
## ------ code ------
#
#
## heap
## ======
## --- API tests ---
#add_executable(testlib_heap heap/tests/testlib_heap.c ${Heap})
## ------ code ------
#add_executable(kth_largest_elements_array heap/kth_largest_elements_array.c ${Heap})
#
#
## rbt
## ======
## --- API tests ---
#add_executable(testlib_rbt rbt/tests/testlib_rbt.c ${RBT} ${Queue})
## ------ code ------
#
#
## string
## =======
## --- API demo ---
## --- API tests ---
#
#
## binary_search_tree
## --- API demo ---
## --- API tests ---
#
#
## hash
#add_executable(test_hash hashing/test_hash.c ${HASHTABLE})