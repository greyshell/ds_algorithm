#!/usr/bin/env python3

# author: greyshell
# command: python -m pytest test_three_sum.py -v

import pytest
from three_sum import three_sum


def test_case_1() -> None:
    arr = [1, 2, 3, 4, 5]
    target = 6
    assert three_sum(arr, target) is True


def test_case_2() -> None:
    arr = [1, 5, -4, -2, -9, 5]
    target = 14
    assert three_sum(arr, target) is False
