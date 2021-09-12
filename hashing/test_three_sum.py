#!/usr/bin/env python3

# author: greyshell
# command: python -m pytest test_three_sum.py -v

import pytest
from three_sum import three_sum, three_sum_alternate


def test_case_1() -> None:
    arr = [1, 2, 3, 4, 5]
    target = 6
    assert three_sum(arr, target) is True


def test_case_2() -> None:
    arr = [1, 5, -4, -2, -9, 5]
    target = 14
    assert three_sum(arr, target) is False


def test_case_3() -> None:
    arr = [1, 5, -4, -2, -9, 4]
    target = 1
    assert three_sum(arr, target) is True


def test_case_4() -> None:
    arr = [1, 5, 8]
    target = 11
    assert three_sum(arr, target) is False


def test_case_5() -> None:
    arr = [1, 2, 3, 4, 5]
    target = 6
    assert three_sum_alternate(arr, target) is True


def test_case_6() -> None:
    arr = [1, 5, -4, -2, -9, 5]
    target = 14
    assert three_sum_alternate(arr, target) is False


def test_case_7() -> None:
    arr = [1, 5, -4, -2, -9, 4]
    target = 1
    assert three_sum_alternate(arr, target) is True


def test_case_8() -> None:
    arr = [1, 5, 8]
    target = 11
    assert three_sum_alternate(arr, target) is False
