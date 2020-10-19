#!/usr/bin/env python3

# author: greyshell
# description: continuous median

"""
295. Find Median from Data Stream
Median is the middle value in an ordered integer list.
If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.

reference: https://leetcode.com/problems/find-median-from-data-stream/
"""

import heapq


class MedianFinder:
    def __init__(self):
        """
        solve using heapq library:
        to store lower nums of the list use one list -> convert that into a MAX heap
        to store upper nums of the list use another list -> convert that into a MIN heap
        """
        self.lower_max_heap = list()
        self.upper_min_heap = list()
        self.median = None

    def add_num(self, num: int) -> None:
        """
        time complexity: O(log(n)) -> assuming len() method takes O(1) time for list
        space complexity: O(1)
        """
        # case 1: when the lower list is empty then insert into the lower_max_heap
        # case 2: when num is less than the MAX element
        # if the number is less than the lower_max_heap.peek() then insert into the lower_max_heap
        if len(self.lower_max_heap) == 0 or num < self.lower_max_heap[0]:
            # create an max heap for the left / lower half of the list
            self.lower_max_heap.append(num)
            heapq._heapify_max(self.lower_max_heap)
        else:
            # create an min heap for the right/ upper half of the list
            self.upper_min_heap.append(num)
            heapq.heapify(self.upper_min_heap)

        # rebalance both heaps to distribute the elements equally between two
        # means the whenever length difference of two heaps reaches to 2 we need to rebalance

        # case 0: if len(self.lower_max_heap) == len(self.upper_min_heap) -> balanced state, do nothing
        # case 1: if the lower has 2 extra elements then pop out the MAX element from lower and push that to the upper
        if len(self.lower_max_heap) - len(self.upper_min_heap) == 2:
            n = heapq._heappop_max(self.lower_max_heap)
            self.upper_min_heap.append(n)
            heapq.heapify(self.upper_min_heap)
        # case 2: if the upper has 2 extra elements then pop out the MIN element from lower and push that to the lower
        elif len(self.upper_min_heap) - len(self.lower_max_heap) == 2:
            n = heapq.heappop(self.upper_min_heap)
            self.lower_max_heap.append(n)
            heapq._heapify_max(self.lower_max_heap)

        # update the median:
        # case 0: when the two heap lengths are same then take the average of two nums
        if len(self.lower_max_heap) == len(self.upper_min_heap):
            self.median = (self.lower_max_heap[0] + self.upper_min_heap[0]) / 2
        # case 1: when the lower has 1 extra element
        elif len(self.lower_max_heap) > len(self.upper_min_heap):
            self.median = self.lower_max_heap[0]
        # case 2: when the upper has 1 extra element
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
    obj.add_num(-1)
    median = obj.get_median()
    print(f"median: {median}")

    # add 2 and get the median
    obj.add_num(-2)
    median = obj.get_median()
    print(f"median: {median}")

    # add 3 and get the median
    obj.add_num(-3)
    median = obj.get_median()
    print(f"median: {median}")


if __name__ == '__main__':
    main()
