#!/usr/bin/env python3

# author: greyshell
# description: how to use queue ADT

from collections import deque as queue


def main():
    q = queue()
    # enque: adding items at rear
    q.append(9)
    q.append(5)
    q.append(3)
    q.append(1)

    # display the queue elements
    print(f"display the queue elements: {list(q)}")

    # dequeue: deleting items from front
    data = q.popleft()
    print(f"item deleted from font: {data}")
    print(f"display the queue elements: {list(q)}")

    # peek
    print(f"peek the front: {q[0]}")
    print(f"peek the rare: {q[-1]}")

    # dequeue at rear
    data = q.pop()
    print(f"item deleted from rare: {data}")


if __name__ == '__main__':
    main()
