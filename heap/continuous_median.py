#!/usr/bin/env python3

# author: greyshell
# description: find the median from data stream
# reference: https://leetcode.com/problems/find-median-from-data-stream/

from snowowl.heap import Heap, HeapType


class MedianFinder:
    def __init__(self):
        # store lower nums in a max heap
        self._max_heap = Heap(list(), heap_type=HeapType.MAX)
        # store higher nums in a min heap
        self._min_heap = Heap(list())

    def add_num(self, num: int) -> None:
        """
        time complexity: O(log n)
        space complexity: O(1)
        """
        # when the _max_heap is empty or the number is less than max number of max heap
        if len(self._max_heap) == 0 or num < self._max_heap.peek():
            self._max_heap.insert(num)
        else:
            self._min_heap.insert(num)

        #  when any heap of the two heaps has 2 extra elements then rebalance the heaps
        if len(self._max_heap) - len(self._min_heap) == 2:
            item = self._max_heap.remove()
            self._min_heap.insert(item)

        elif len(self._min_heap) - len(self._max_heap) == 2:
            item = self._min_heap.remove()
            self._max_heap.insert(item)

    def get_median(self) -> float:
        """
        time complexity: O(1)
        space complexity: O(1)
        """
        if len(self._max_heap) == len(self._min_heap):
            return (self._max_heap.peek() + self._min_heap.peek()) / 2

        # when any heap has 1 extra element
        if len(self._max_heap) > len(self._min_heap):
            return self._max_heap.peek()

        return self._min_heap.peek()
