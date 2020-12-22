#!/usr/bin/env python3

# author: greyshell
# description: find k largest elements from a immutable max heap

from typing import List
import heapq


class Solution:
    @staticmethod
    def k_largest_elements_immutable_max_heap(immutable_max_heap: List[int], k: int) -> List:
        """
        time complexity: O(k * n) -> due to build heap function
            - if max-heap push api exists then it will become O(k * log n)
        space complexity: O(k) -> auxiliary max heap
        """
        # output list
        out = []
        # immutable_max_heap length
        immutable_max_heap_length = len(immutable_max_heap)

        # create an auxiliary max heap of size k
        auxiliary_max_heap = []

        # peek the min item from the immutable max heap
        num = immutable_max_heap[0]

        # heap elements could be tuples in which the first element is the priority and defines the sort order
        # push that node (num, index) -> tuple into the auxiliary max heap

        # there no API for max heap push
        auxiliary_max_heap.append((num, 0))
        heapq._heapify_max(auxiliary_max_heap)

        for i in range(0, k):
            node = heapq._heappop_max(auxiliary_max_heap)
            out.append(node[0])
            index = node[1]

            left_child_index = 2 * index + 1
            if left_child_index < immutable_max_heap_length:
                left_child = immutable_max_heap[left_child_index]
                auxiliary_max_heap.append((left_child, left_child_index))
                heapq._heapify_max(auxiliary_max_heap)

            right_child_index = 2 * index + 2
            if right_child_index < immutable_max_heap_length:
                right_child = immutable_max_heap[right_child_index]
                auxiliary_max_heap.append((right_child, right_child_index))
                heapq._heapify_max(auxiliary_max_heap)

        return out


def main():
    max_heap = [7, 17, 16, 2, 3, 15, 14]
    # build the max heap
    heapq._heapify_max(max_heap)
    print(f"after max heapify process: {max_heap}")
    s = Solution()
    out = s.k_largest_elements_immutable_max_heap(max_heap, k=3)
    print(out)


if __name__ == '__main__':
    main()
