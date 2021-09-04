#!/usr/bin/env python3

# author: greyshell

import pytest
from heap.k_largest_elements_array import *


def test_case_1() -> None:
    array = [7, 17, 16, 2, 3, 15, 14]
    expected_result = [17, 16, 15, 14]
    result = get_k_largest_elements_array(array, k=4)
    # check if the two lists are identical: order does not matter
    assert set(result) == set(expected_result)


def test_case_2() -> None:
    array = [10, 20, 30, 50, 90, 70, 80, 40]
    expected_result = [70, 80, 90]
    result = get_k_largest_elements_array(array, k=3)
    assert set(result) == set(expected_result)


def test_case_3() -> None:
    """verify the alternate solution"""
    array = [10, 20, 30, 50, 90, 70, 80, 40]
    expected_result = [70, 80, 90]
    result = get_k_largest_elements_array_alternate(array, k=3)
    assert set(result) == set(expected_result)
