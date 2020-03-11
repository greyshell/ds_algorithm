#!/usr/bin/env python3

# author: greyshell
# description: continuous median

"""
write a class that can support the following two functions
1. continuous insertion of numbers
2. the instant O(1) time retrieval of the median of the numbers that have been inserted so far.

reference: https://leetcode.com/problems/find-median-from-data-stream/
"""

import heapq


class MedianFinder:
    def __init__(self):
        """
        initialize your data structure here.
        """
        # create an empty max heap for the left / lower half of the list
        # pop() gives the max element of the left half in O(1) time
        self.lower_max_heap = list()
        heapq._heapify_max(self.lower_max_heap)

        # create an empty min heap for the right half of the list
        # pop() gives the min element of the right half in O(1) time
        self.upper_min_heap = list()
        heapq.heapify(self.upper_min_heap)
        # means in O(1 + 1) time, we can get the two middle elements of a sorted array
        # median means the middle element of a sorted array.
        # if the array length is even, then median is the average of the two middle elements
        self.median = None

    def add_num(self, num: int) -> None:
        """
        time complexity: O(log(n)), assuming len() method takes O(1) time
        space complexity: O(1)
        """
        # start insertion by putting the first number into the lower half
        # means if there is no number in the lower half OR if the number is less than the lower_max_heap.peek()
        if len(self.lower_max_heap) == 0 or num < self.lower_max_heap[0]:
            heapq.heappush(self.lower_max_heap, num)
        else:
            heapq.heappush(self.upper_min_heap, num)

        # heap rebalancing:
        # our main goal is to distribute the elements into two heaps equally
        # means the whenever length difference of two heaps reaches to 2 we need to rebalance
        # we no need to do anything when both upper and lower has equal elements
        # if the lower half has 2 more extra element then pop 1 element out and push into upper half
        if len(self.lower_max_heap) - len(self.upper_min_heap) == 2:
            n = heapq.heappop(self.lower_max_heap)
            heapq.heappush(self.upper_min_heap, n)
        # if the upper half has 2 more extra element then pop 1 element out and push into lower half
        elif len(self.upper_min_heap) - len(self.lower_max_heap) == 2:
            n = heapq.heappop(self.upper_min_heap)
            heapq.heappush(self.lower_max_heap, n)

        # update the median:
        # if the two heaps have the same length then we need to find the average
        if len(self.lower_max_heap) == len(self.upper_min_heap):
            self.median = (self.lower_max_heap[0] + self.upper_min_heap[0]) / 2
        # when the lower half has an extra element
        elif len(self.lower_max_heap) > len(self.upper_min_heap):
            self.median = self.lower_max_heap[0]
        # when the upper half has an extra element
        else:
            self.median = self.upper_min_heap[0]

    def get_median(self) -> float:
        """
        time complexity: O(1)
        space complexity: O(1)
        """
        return self.median


def main():
    # create the object
    obj = MedianFinder()
    # add 1 and get the median
    obj.add_num(1)
    median = obj.get_median()
    print(f"median: {median}")

    # add 2 and get the median
    obj.add_num(2)
    median = obj.get_median()
    print(f"median: {median}")

    # add 3 and get the median
    obj.add_num(3)
    median = obj.get_median()
    print(f"median: {median}")


if __name__ == '__main__':
    main()
