#!/usr/bin/env python3

# author: greyshell
# description: find k largest elements from a immutable max heap

from snowowl import Heap, HeapType


class Node:
    def __init__(self, value, index):
        self.value = value
        self.index = index

    def __lt__(self, other):
        return self.value < other.value

    def __eq__(self, other):
        return self.value == other.value


def get_k_largest_elements_immutable_max_heap(immutable_max_heap: Heap, k: int) -> list:
    """
    time complexity: O(k * log k)
    space complexity: O(k) -> auxiliary max heap
    """
    # create an auxiliary max heap
    auxiliary_max_heap = Heap([], heap_type=HeapType.MAX)

    # peek the min item from the immutable max heap
    # create a node obj with the value and index and push that object into auxiliary max heap
    node = Node(immutable_max_heap.peek(), 0)
    auxiliary_max_heap.insert(node)

    result = list()
    for i in range(0, k):
        node = auxiliary_max_heap.remove()
        result.append(node.value)

        index = node.index

        left_child_index = 2 * index + 1

        if left_child_index < len(immutable_max_heap):
            left_child = immutable_max_heap.__getitem__(left_child_index)
            left_node = Node(left_child, left_child_index)
            auxiliary_max_heap.insert(left_node)

        right_child_index = 2 * index + 2

        if right_child_index < len(immutable_max_heap):
            right_child = immutable_max_heap.__getitem__(right_child_index)
            right_node = Node(right_child, right_child_index)
            auxiliary_max_heap.insert(right_node)

    return result
