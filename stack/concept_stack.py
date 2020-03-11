#!/usr/bin/env python3

# author: greyshell
# description: learning stack


def main():
    # create stack using list
    stack = list()
    # push()
    stack.insert(len(stack), 9)
    stack.insert(len(stack), 8)
    stack.insert(len(stack), 7)
    stack.insert(len(stack), 6)
    # pop()
    data = stack.pop()
    print(f"item popped: {data}")
    print(f"stack: {stack}")


if __name__ == '__main__':
    main()
