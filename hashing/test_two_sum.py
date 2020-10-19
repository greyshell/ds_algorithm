#!/usr/bin/env python3

# author: greyshell

# python -m unittest test_two_sum.TestSolution

import unittest
# noinspection PyUnresolvedReferences
from two_sum import LeetCode


class TestSolution(unittest.TestCase):
    def test_case_1(self):
        self.assertEqual(LeetCode.solution([12, 7, 11, 15, 35], 50), [3, 4])

    def test_case_2(self):
        self.assertEqual(LeetCode.solution([12, 7, 11, 15, 35], 19), [0, 1])

    def test_case_3(self):
        self.assertEqual(LeetCode.solution([12, 7, 11, 15, 35], 89), [None, None])

    def test_case_4(self):
        self.assertEqual(LeetCode.solution([12, 7, 11, -15, 35], 20), [3, 4])


if __name__ == '__main__':
    unittest.main()
