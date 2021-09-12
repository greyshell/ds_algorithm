#!/usr/bin/env python3

# author: greyshell

def three_sum(arr: list, target: int) -> bool:
    """
    time: O(n^3)
    space: O(n)
    """
    for i in range(0, len(arr)):
        for j in range(i + 1, len(arr)):
            for k in range(j + 1, len(arr)):
                if arr[i] + arr[j] + arr[k] == target:
                    return True

    return False


def three_sum_alternate(arr: list, target: int) -> bool:
    """
    time: O(n^2)
    space: O(n)
    """
    lookup = dict()
    for i in range(0, len(arr)):
        for j in range(i + 1, len(arr)):
            s = arr[i] + arr[j]
            lookup[s] = [i, j]

    for i in range(0, len(arr)):
        complement = target - arr[i]
        if complement in lookup:
            if i not in lookup.get(complement):
                # all three indexes -> [i, lookup.get(complement)]
                return True

    return False
