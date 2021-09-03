#!/usr/bin/env python3

# author: greyshell
# description: kruskal algorithm to find the mst of an undirected weighted graph

from typing import Tuple
from heap import Heap
from union_find_adt import WeightedQuickUnion
from graph import UndirectedGraph, Edge


def mst_kruskal(wug: UndirectedGraph) -> Tuple[list, int]:
    """
    time complexity: E log E -> to push and pop each node
    space complexity: E -> to maintain a min heap
    """
    mst = list()  # returns this final list of tuple - (_src_vertex, _dst_vertex, _weight) that has all minimum edges

    # create a union find object to check the connectivity between two vertices in O(1) time
    vertices = wug.get_all_vertices()
    # uf = QuickFind(vertices)
    # uf = QuickUnion(vertices)
    uf = WeightedQuickUnion(vertices)

    # create a custom min heap where each element is a weighted edge obj
    min_heap = Heap([])
    edges = wug.get_all_edges()
    for e in edges:
        src_vertex, dst_vertex, weight = e
        weighted_edge_obj = Edge(src_vertex, dst_vertex, weight)
        min_heap.insert(weighted_edge_obj)  # O(log E)
        # heapq.heappush(min_heap, weighted_edge_obj)

    weight_sum = 0
    while min_heap and len(mst) < (len(vertices) - 1):
        edge_obj = min_heap.remove()

        # extract the attributes from the object
        src_vertex = edge_obj.src_vertex
        dst_vertex = edge_obj.dst_vertex
        weight = edge_obj.weight

        if uf.connected(src_vertex, dst_vertex):  # O(log(n)) for WeightedQuickUnion
            continue

        uf.union(src_vertex, dst_vertex)  # O(1) for WeightedQuickUnion
        mst.append(edge_obj.__str__())
        weight_sum = weight_sum + weight

    return mst, weight_sum
