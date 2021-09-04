#!/usr/bin/env python3

# author: greyshell

import pytest
from snowowl.heap import Heap, HeapType
from heap.k_largest_elements_immutable_max_heap import *


def test_case_1() -> None:
    array = [7, 17, 16, 2, 3, 15, 14]
    immutable_max_heap = Heap(array, heap_type=HeapType.MAX)
    result = get_k_largest_elements_immutable_max_heap(immutable_max_heap, k=4)
    assert result == [17, 16, 15, 14]
