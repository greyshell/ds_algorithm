#!/usr/bin/env python3

# author: greyshell
# description: stack using deque

from collections import deque


def main():
    """
    - deque is backed by doubly linked list
    - it that guarantees the stable O(1) push and pop
    - no parallel processing support / it handles locking and unlocking
    :return:
    """
    s = deque()
    # push: O(1), stack grows from left to right
    s.append(9)
    s.append(5)
    s.append(3)
    s.append(1)

    # display the stack elements: convert the deque into list
    print(f"display the stack elements: {s}")
    print(f"display the stack elements: {list(s)}")

    # peek, O(1)
    data = s[-1]
    print(f"peek the stack top: {data}")

    # pop: O(1), stack shrinks from right to left
    # raise IndexError => pop from an empty list
    try:
        data = s.pop()
        print(f"popped: {data}")
    except IndexError as e:
        print(f"{e}")

    print(f"display the stack elements: {list(s)}")


if __name__ == '__main__':
    main()
