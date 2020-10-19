# !/usr/bin/env python3

# author: greyshell
# description: stack using list


def main():
    """
    - python list is backed by dynamic array, so occasionally it needs to be resized when item
    is added / removed
    - it does not guarantee the stable O(1) push and pop
    - however, it provides the amortize time complexity is O(1) when the item is added / remove at
    the end of list
    - adding / removing from front / middle is much slower and it takes O(n) time as shifting of
    existing elements
    are required
    - no parallel processing support / it handles locking and unlocking
    :return:
    """
    s = list()
    # push: O(1), stack grows from left to right
    s.append(9)
    s.append(5)
    s.append(3)
    s.append(2)

    # display the stack elements
    print(f"display the stack elements: {s}")

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
