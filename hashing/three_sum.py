#!/usr/bin/env python3

# author: greyshell

def three_sum(arr: list, target: int) -> bool:
    """
    time: O(n^2)
    space: O(n)
    """
    lookup = set()
    for i in range(0, len(arr)):
        for j in range(i + 1, len(arr)):
            lookup.add(arr[i] + arr[j])

    for i in range(0, len(arr)):
        num = arr[i]
        if (target - num) in lookup:
            return True

    return False
