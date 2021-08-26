#!/usr/bin/env python3

# author: greyshell
# description: demo how to use PriorityQue

from queue import PriorityQueue


class MyHeap(PriorityQueue):

    def __init__(self):
        super(MyHeap, self).__init__()

    def __lt__(self, other):
        # compare based on weight
        return self.key > other.key


def main():
    min_heap = PriorityQueue()
    # push an item
    min_heap.put(2, 'code')
    min_heap.put(1, 'eat')
    min_heap.put(0, 'bat')

    # peek
    print(min_heap)
    # pop the min item
    print(min_heap.get())


if __name__ == '__main__':
    main()
