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

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""


class LeetCode:
    @staticmethod
    def solution(nums: list, target: int) -> list:
        """
        time complexity: O(n)
        space complexity: O(n) -> size of the hash table
        """
        lookup = {}

        for index in range(0, len(nums)):
            complement = target - nums[index]
            # if the complement is not present in hash_map then
            # insert the number as key, index as value
            found_value = lookup.get(complement)  # O(1), not found return None
            if found_value is None:
                key = nums[index]
                lookup[key] = index

            else:  # found the complement in the hash_map
                index_of_prev_number = lookup[complement]
                return [index_of_prev_number, index]

        # scenario where target is not found
        return [None, None]  # returns a list


def main():
    # sample test case
    nums = [12, 7, 11, 15, 35, 17, 2]
    target = 26

    result = LeetCode.solution(nums, target)

    print(f"{result}")  # expected result: [1, 2]


if __name__ == '__main__':
    main()
