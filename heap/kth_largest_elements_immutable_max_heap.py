#!/usr/bin/env python3

# author: greyshell
# description: find k largest elements from a immutable max heap

from typing import List
import heapq


class MaxHeapNode(object):
    def __init__(self, key, index):
        self.key = key
        self.index = index

    def __lt__(self, other):
        # tweak the comparison logic, so that when heapq use this it builds the max heap
        return self.key > other.key

    def __eq__(self, other):
        return self.key == other.key


class Solution:
    @staticmethod
    def k_largest_elements_immutable_max_heap(immutable_max_heap: List[int], k: int) -> List:
        """
        time complexity: O(k * log k)
        space complexity: O(k) -> auxiliary max heap
        """
        # output list
        out = list()
        # immutable_max_heap length
        immutable_max_heap_length = len(immutable_max_heap)

        # create an auxiliary max heap of size k
        auxiliary_max_heap = list()

        # peek the min item from the immutable max heap
        num = immutable_max_heap[0]

        # push that object into auxiliary max heap
        heapq.heappush(auxiliary_max_heap, MaxHeapNode(num, 0))

        for i in range(0, k):
            node = heapq.heappop(auxiliary_max_heap)
            # add the node.key into the out list
            out.append(node.key)
            index = node.index

            left_child_index = 2 * index + 1
            if left_child_index < immutable_max_heap_length:
                left_child = immutable_max_heap[left_child_index]
                heapq.heappush(auxiliary_max_heap, MaxHeapNode(left_child, left_child_index))

            right_child_index = 2 * index + 2
            if right_child_index < immutable_max_heap_length:
                right_child = immutable_max_heap[right_child_index]
                heapq.heappush(auxiliary_max_heap, MaxHeapNode(right_child, right_child_index))

        return out


def main():
    max_heap = [7, 17, 16, 2, 3, 15, 14]
    # make sure that we pass a max heap
    heapq._heapify_max(max_heap)
    print(f"immutable max heap = {max_heap}")

    s = Solution()
    print(f"solution:")
    out = s.k_largest_elements_immutable_max_heap(max_heap, k=5)
    print(out)


if __name__ == '__main__':
    main()
