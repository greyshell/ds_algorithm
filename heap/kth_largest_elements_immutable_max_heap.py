#!/usr/bin/env python3

# author: greyshell
# description: find k largest elements from a immutable max heap

from typing import List
import heapq


class MaxHeapObj(object):
    def __init__(self, val, index):
        self.val = val
        self.index = index

    def __lt__(self, other):
        # overwrite the 'greater than operator' to act as max heap
        return self.val > other.val

    def __eq__(self, other):
        return self.val == other.val

    def __str__(self): return str(self.val)


class Solution:
    @staticmethod
    def k_largest_elements_immutable_max_heap(immutable_max_heap: List[int], k: int) -> List:
        """
        time complexity: O(k * log k)
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

        # push that object the auxiliary max heap
        heapq.heappush(auxiliary_max_heap, MaxHeapObj(num, 0))

        for i in range(0, k):
            heap_obj = heapq.heappop(auxiliary_max_heap)
            out.append(heap_obj.val)
            index = heap_obj.index

            left_child_index = 2 * index + 1
            if left_child_index < immutable_max_heap_length:
                left_child = immutable_max_heap[left_child_index]
                heapq.heappush(auxiliary_max_heap, MaxHeapObj(left_child, left_child_index))

            right_child_index = 2 * index + 2
            if right_child_index < immutable_max_heap_length:
                right_child = immutable_max_heap[right_child_index]
                heapq.heappush(auxiliary_max_heap, MaxHeapObj(right_child, right_child_index))

        return out


def main():
    max_heap = [7, 17, 16, 2, 3, 15, 14]
    # to make sure the we pass the max heap
    heapq._heapify_max(max_heap)

    s = Solution()
    out = s.k_largest_elements_immutable_max_heap(max_heap, k=5)
    print(out)


if __name__ == '__main__':
    main()
