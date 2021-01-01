#!/usr/bin/env python3

# author: greyshell
# description: find the median from data stream
# reference: https://leetcode.com/problems/find-median-from-data-stream/

import heapq


class MaxHeapNode(object):
    def __init__(self, key):
        self.key = key

    def __lt__(self, other):
        # tweak the comparison logic, so that when heapq use this it builds the max heap
        return self.key > other.key


class MedianFinder:
    def __init__(self):
        """
        store lower nums in a max heap
        store higher nums in a min heap
        """
        self.max_heap = list()
        self.min_heap = list()
        self.max_heap_length = 0
        self.min_heap_length = 0
        self.median = None

    def _heap_rebalance(self):
        #  when any heap of the two heaps has 2 extra elements then
        #  pop the element from that heap and push into other one
        if self.max_heap_length - self.min_heap_length == 2:
            node = heapq.heappop(self.max_heap)
            self.max_heap_length -= 1

            heapq.heappush(self.min_heap, node.key)
            self.min_heap_length += 1

        elif self.min_heap_length - self.max_heap_length == 2:
            num = heapq.heappop(self.min_heap)
            self.min_heap_length -= 1

            heapq.heappush(self.max_heap, MaxHeapNode(num))
            self.max_heap_length += 1

    def _update_median(self):
        # when the two heap lengths are same
        if self.max_heap_length == self.min_heap_length:
            self.median = (self.max_heap[0].key + self.min_heap[0]) / 2
            return

        # when any heap has 1 extra element
        if self.max_heap_length > self.min_heap_length:
            self.median = self.max_heap[0].key
        else:
            self.median = self.min_heap[0]

    def add_num(self, num: int) -> None:
        """
        time complexity: O(log n)
        space complexity: O(1)
        """
        # when the max_heap is empty or the number is less than max number of max heap
        if self.max_heap_length == 0 or \
                num < self.max_heap[0].key:
            heapq.heappush(self.max_heap, MaxHeapNode(num))
            self.max_heap_length += 1
        else:
            heapq.heappush(self.min_heap, num)
            self.min_heap_length += 1

        self._heap_rebalance()
        self._update_median()

    def get_median(self) -> float:
        """
        time complexity: O(1)
        space complexity: O(1)
        """
        return self.median


def main():
    # create the object
    s = MedianFinder()
    # add 1 and get the median
    s.add_num(-1)
    median = s.get_median()
    print(f"median: {median}")

    # add 2 and get the median
    s.add_num(-2)
    median = s.get_median()
    print(f"median: {median}")

    # add 3 and get the median
    s.add_num(-3)
    median = s.get_median()
    print(f"median: {median}")


if __name__ == '__main__':
    main()
