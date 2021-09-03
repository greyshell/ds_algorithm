#!/usr/bin/env python3

# author: greyshell
# description: prims algorithm (lazy approach) to find the mst of an undirected weighted graph (connected, no cycle)

from typing import Tuple
from heap import Heap
from graph import UndirectedGraph


def mark_node(vertex_obj, min_heap, visited):
    visited.add(vertex_obj.vertex_name)
    for edge_obj in vertex_obj.neighbor_edges_obj:
        dst_vertex = edge_obj.dst_vertex
        if dst_vertex not in visited:
            min_heap.insert(edge_obj)


def mst_prims_lazy(wug: UndirectedGraph) -> Tuple[list, int]:
    """
    lazy approach
    time complexity: E log E -> to push and pop each node
    space complexity: E -> to maintain a min heap
    """
    mst = list()  # returns minimum list of edges

    vertices = wug.get_all_vertices()
    start_vertex_obj = wug.get_vertex_obj(vertices[0])

    # create a min heap where each element is a weighted edge obj
    min_heap = Heap(list())
    visited = set()

    mark_node(start_vertex_obj, min_heap, visited)

    weight_sum = 0
    while min_heap:
        edge_obj = min_heap.remove()

        # extract the attributes from the object
        src_vertex = edge_obj.src_vertex
        dst_vertex = edge_obj.dst_vertex
        weight = edge_obj.weight

        if src_vertex in visited and dst_vertex in visited:
            continue

        mst.append(edge_obj.__str__())
        weight_sum = weight_sum + weight

        if src_vertex not in visited:
            mark_node(wug.get_vertex_obj(src_vertex), min_heap, visited)

        if dst_vertex not in visited:
            mark_node(wug.get_vertex_obj(dst_vertex), min_heap, visited)

    return mst, weight_sum

