#!/usr/bin/env python3

# author: greyshell
# description: stack

from collections import deque


def main():
    # deque is a double ended queue
    stack = deque()
    # push(), stack grows at the right
    stack.append(9)
    stack.append(5)
    stack.append(3)
    stack.append(1)
    # display the stack elements
    print(f"display the stack elements: {list(stack)}")

    # pop()
    data = stack.pop()
    print(f"popped: {data}")
    print(f"display the stack elements: {list(stack)}")

    # peek -> O(1)
    print(f"peek the stack top: {stack[-1]}")


if __name__ == '__main__':
    main()
