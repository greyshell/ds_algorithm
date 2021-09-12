#!/usr/bin/env python3
# author: greyshell
# how to run: python -m unittest test_balance_bracket.TestSolution

import unittest
from blance_bracket import balance_bracket


class TestSolution(unittest.TestCase):

    def test_case_1(self):
        self.assertEqual(balance_bracket(['(', '(']), False)

    def test_case_2(self):
        self.assertEqual(balance_bracket(['(', ')']), True)

    def test_case_3(self):
        self.assertEqual(balance_bracket([')', '(']), False)

    def test_case_4(self):
        self.assertEqual(balance_bracket(['(', '(', ')', ')']), True)

    def test_case_5(self):
        self.assertEqual(balance_bracket([')', ')']), False)

    def test_case_6(self):
        self.assertEqual(balance_bracket(['(', '(', ')', '(', ')']), False)

    def test_case_7(self):
        self.assertEqual(balance_bracket(['(', ')', '(']), False)

    def test_case_8(self):
        self.assertEqual(balance_bracket(['(', ')', ')']), False)

    def test_case_9(self):
        self.assertEqual(balance_bracket(['(', '(', ')', '(', ')', ')']), True)


if __name__ == '__main__':
    unittest.main()
