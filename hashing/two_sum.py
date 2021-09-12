#!/usr/bin/env python3

# author: greyshell

"""
reference: https://leetcode.com/problems/two-sum/

description:
Given an array of integers, return indices of the two numbers such that
they add up to a specific target.

You may assume that each input would have exactly one two_sum, and you may not
use the same element twice.

Example:

Given arr = [2, 7, 11, 15], target = 9,

Because arr[0] + arr[1] = 2 + 7 = 9,
return [0, 1].
"""


def two_sum(arr: list, target: int) -> list:
    """
    time complexity: O(n)
    space complexity: O(n)
    """
    lookup = dict()

    for i in range(0, len(arr)):
        num = arr[i]
        complement = target - num
        # if the complement is not present in lookup then
        # insert the number as key, index as value
        index = lookup.get(complement)  # O(1), not found return None
        if index is not None:
            return [index, i]
        lookup[num] = i

    # scenario where target is not found
    return [None, None]  # returns a list
