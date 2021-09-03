#!/usr/bin/env python3

# author: greyshell
# command: python -m pytest test_continuous_median.py -v

import pytest
from heap.continuous_median import MedianFinder


def test_case_1() -> None:
    s = MedianFinder()
    s.add_num(1)
    assert s.get_median() == 1

    s.add_num(2)
    assert s.get_median() == 1.5
    s.add_num(3)
    assert s.get_median() == 2
