#!/usr/bin/env python3

# author: greyshell
# description: demo how to use heapq library

import heapq


class MaxHeapNode(object):
    def __init__(self, key):
        self.key = key

    def __lt__(self, other):
        # compare based on val
        # tweak the comparison logic to build max heap: change less_than_sign to greater_than_sign
        return self.key > other.key

    def __eq__(self, other):
        return self.key == other.key

    def __str__(self):
        return str(self.key)


def demo_max_heap():
    print(f"========================================")
    print(f"demo max heap ")
    print(f"========================================")
    # create a max heap that stores an object (key, index, name) and the key is key
    max_heap = list()

    heapq.heappush(max_heap, MaxHeapNode(17))
    heapq.heappush(max_heap, MaxHeapNode(1000))
    heapq.heappush(max_heap, MaxHeapNode(250))
    heapq.heappush(max_heap, MaxHeapNode(500))

    print(f"max value {max_heap[0]}")
    node = heapq.heappop(max_heap)
    print(f"popped item: {node.key}")
    print(f"max value {max_heap[0]}")


class HeapSatelliteNode(object):
    def __init__(self, name, age):
        # self.val = val
        self.name = name
        self.age = age

    def __lt__(self, other):
        # compare based on age
        # tweak the comparison logic to build max heap: change less_than_sign to greater_than_sign
        # key = age, so compare based on the key
        return self.age > other.age

    def __eq__(self, other):
        return self.age == other.age

    def __str__(self):
        return f"name:{self.name}, age:{self.age}"


def demo_max_satellite_heap():
    print(f"========================================")
    print(f"demo max satellite heap ")
    print(f"========================================")
    # create a max heap that stores an object (key, index, name) and the key is key
    max_heap = list()

    # compare based on the age
    heapq.heappush(max_heap, HeapSatelliteNode('asinha', 39))
    heapq.heappush(max_heap, HeapSatelliteNode('dhaval', 22))
    heapq.heappush(max_heap, HeapSatelliteNode('ravi', 23))

    print(f"max value {max_heap[0]}")
    node = heapq.heappop(max_heap)
    print(f"popped item: {node.name}")
    print(f"max value {max_heap[0]}")


def heap_sort(nums):
    heapq.heapify(nums)
    return [heapq.heappop(nums) for _ in range(0, len(nums))]


def main():

    min_heap = [12, 7, 11, 15, 35, 17]

    print(f"========================================")
    print(f"demo heap sort")
    print(f"========================================")

    print(f"before heap sort: {min_heap}")
    r = heap_sort(min_heap)
    print(f"after heap sort: {r}")

    print(f"========================================")
    print(f"demo min heap ")
    print(f"========================================")
    # build a min heap
    heapq.heapify(min_heap)  # in-place, in linear time, O(n), Heap elements can be tuples.

    # push an item
    heapq.heappush(min_heap, 25)  # O(log(n))
    heapq.heappush(min_heap, 5)  # O(log(n))
    heapq.heappush(min_heap, 10)  # O(log(n))

    # peek the min item
    data = min_heap[0]  # O(1)

    # pop an item
    data = heapq.heappop(min_heap)  # O(log(n))
    print(f"popped item: {data}")
    print(f"current heap : {min_heap}")

    # when we need to make the heap size constant, we can use heappushpop() and heapreplace()
    # time complexity: O(log(n)), improving the performance
    dummy_nums = min_heap.copy()  # copy all elements to another list
    data = -1
    popped_value = heapq.heappushpop(min_heap, data)  # 1st push then pop
    print(f"popped value: {popped_value}")

    popped_value = heapq.heapreplace(dummy_nums, data)  # 1st pop from existing min then push
    print(f"popped value: {popped_value}")

    print(f"========================================")
    print(f"demo nlargest / smallest element or element ")
    print(f"========================================")

    # k largest / smallest elements
    # best for smaller values of k
    min_heap.append(100)
    min_heap.append(200)
    min_heap.append(50)
    print(f"nums = {min_heap}")

    large = heapq.nlargest(3, min_heap)
    small = heapq.nsmallest(3, min_heap)
    print(f"3 largest values: {large}")
    print(f"3 smallest values: {small}")
    # when k==1, it is more efficient to use the built-in min() and max() functions.

    # for larger k values it is more efficient to use the sorted() function.

    # kth largest element
    k = 3
    kth_large = heapq.nlargest(k, min_heap)
    print(f"{k}th/rd/nd largest value: {kth_large[k - 1]}")  # last element of the kth_large list

    # demo max heap
    demo_max_heap()

    # demo satellite data in the max heap
    demo_max_satellite_heap()


if __name__ == '__main__':
    main()
