#!/usr/bin/env python3

# author: greyshell
# description: queue

from collections import deque


def main():
    queue = deque()
    # adding into the queue at rare
    queue.append(9)
    queue.append(5)
    queue.append(3)
    queue.append(1)
    # display the queue elements
    print(f"display the queue elements: {list(queue)}")

    # deleting element from the queue at front
    data = queue.popleft()
    print(f"item deleted from font: {data}")
    print(f"display the queue elements: {list(queue)}")

    # peek -> O(1)
    print(f"peek the front: {queue[0]}")
    print(f"peek the rare: {queue[-1]}")

    # deleting an element from the queue at rare
    data = queue.pop()
    print(f"item deleted from rare: {data}")


if __name__ == '__main__':
    main()
