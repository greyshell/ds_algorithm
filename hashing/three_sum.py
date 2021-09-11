#!/usr/bin/env python3

# author: greyshell

def three_sum(arr: list, target: int) -> bool:
    """
    time: O(n^2)
    space: O(n)
    """
    temp_arr = list()
    for i in range(0, len(arr)):
        for j in range(i + 1, len(arr)):
            temp_arr.append(arr[i] + arr[j])

    for i in range(0, len(arr)):
        if temp_arr[i] - target == 0:
            return True

    return False
