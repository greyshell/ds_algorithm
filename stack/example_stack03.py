#!/usr/bin/env python3

# author: greyshell
# description: stack using queue.LifoQueue

from queue import LifoQueue


def main():
    """
    - used for parallel computing / multi producer and consumer scenarios
    - locking and un-locking needs to be implemented manually
    :return:
    """
    s = LifoQueue()
    # push: O(1)
    s.put(9)
    s.put(2)

    # check if the stack is empty
    print(f"{s.empty()}")

    # not found any method for peek and display stack elements

    # pop: O(1)
    data = s.get_nowait()
    data = s.get_nowait()

    try:
        data = s.get_nowait()  # not wait for producer to add the element if the stack is empty
        print(f"popped: {data}")
    except Exception as e:
        print(f"{e}")

    exit(0)

    data = s.get()  # popped out the last stack element
    data = s.get()  # waits for ever as the stack is empty, producer needs to add an element
    print(f"popped: {data}")


if __name__ == '__main__':
    main()
