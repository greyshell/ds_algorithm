#!/usr/bin/env python3

# author: greyshell
# description: learning min heap

import heapq


def heap_sort(nums):
    """
    property:
    =========
    - not stable
    - takes a axillary list / array -> space complexity O(n)
    - time complexity: O(log(n) + log(n)) ~ O(log(n)) for push and pop method
    :param nums: int
    :return: List[int]
    """
    h = list()
    output = []
    for num in nums:
        heapq.heappush(h, num)
    print(f"after heapify / heappush: {h} ")

    for _ in range(0, len(h)):
        output.append(heapq.heappop(h))

    # return [heapq.heappop(h) for _ in range(len(h))]  # using list comprehension
    return output


def main():
    nums = [12, 7, 11, 15, 35, 17]
    print(f"list: {nums}")

    # build the heap
    heapq.heapify(nums)  # in-place, in linear time, O(n), Heap elements can be tuples.
    print(f"after heapify process: {nums}")

    # push the value item onto the heap, maintaining the heap invariant
    data = 5
    heapq.heappush(nums, data)  # O(log(n))
    print(f"after pushing {data} element to the heap: {nums}")

    # access the smallest item without popping it
    data = nums[0]  # O(1)
    print(f"access the smallest item without popping it: {data}")

    # pop and return the smallest item from the heap, maintaining the heap invariant
    # if the heap is empty, IndexError is raised.
    data = heapq.heappop(nums)  # O(log(n))
    print(f"pop the min item from heap: {data}")
    print(f"after {data} is popped from the heap : {nums}")

    # when we need to make the heap size constant, we can use heappushpop() and heapreplace()
    # time complexity: O(log(n)), better than  2*O(log(n)) -> push + pop
    dummy_nums = nums[:]  # copy all elements to another list
    data = -1
    popped_value = heapq.heappushpop(nums, data)  # 1st push then pop
    print(f"popped value: {popped_value}")

    popped_value = heapq.heapreplace(dummy_nums, data)  # 1st pop the existing min then push
    print(f"popped value: {popped_value}")

    # heap sort
    nums.append(1)
    print(f"before heap sort: {nums}")
    r = heap_sort(nums)
    print(f"after heap sort: {r}")

    # return a list with the n largest elements from the dataset defined by iterable.
    large = heapq.nlargest(5, nums)
    small = heapq.nsmallest(5, nums)
    print(f"largest values: {large}, smallest values: {small}")
    # find kth largest value
    # best for smaller values of k,
    # For larger values, it is more efficient to use the sorted() function.
    # when k==1, it is more efficient to use the built-in min() and max() functions.
    k = 3
    kth_large = heapq.nlargest(k, nums)[k - 1]
    print(f"{k}th largest value: {kth_large}")


if __name__ == '__main__':
    main()
