#!/usr/bin/env python3

# author: greyshell

from snowowl import Heap, HeapType


def get_k_largest_elements_array(array: list, k: int) -> list:
    """
    time complexity: O(n*log(k))
    space complexity: O(k)
    """
    min_heap = Heap([])

    for num in array:
        min_heap.insert(num)
        if len(min_heap) > k:
            _ = min_heap.remove()

    return [n for n in min_heap]


def get_k_largest_elements_array_alternate(array: list, k: int) -> list:
    """
     * time complexity: O(n + k*log(n))
     * space complexity: O(1)
    """
    max_heap = Heap(array, heap_type=HeapType.MAX)  # O(n)
    return [max_heap.remove() for _ in range(0, k)]
