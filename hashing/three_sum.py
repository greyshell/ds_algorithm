#!/usr/bin/env python3

# author: greyshell

def three_sum(arr: list, target: int) -> bool:
    """
    time: O(n^3)
    space: O(1)
    """
    for i in range(0, len(arr)):
        for j in range(i + 1, len(arr)):
            for k in range(j + 1, len(arr)):
                if arr[i] + arr[j] + arr[k] == target:
                    return True

    return False
