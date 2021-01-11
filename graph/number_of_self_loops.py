#!/usr/bin/env python3

# author: greyshell
# description: find the total number of self loops

from typing import List
from collections import deque
from graph_adt import Vertex, UndirectedGraph


def number_of_self_loops(undirected_graph):
    count = 0
    for k in undirected_graph._vertices:
        node = undirected_graph.get_vertex(k)
        neighbors = node.get_neighbors()  # returns a se
        if node in neighbors:  # time: O(1)
            count += 1
    return count


def main():
    # ===================================================================
    # create an undirected undirected_graph
    # ===================================================================
    leetcode_input = [[2, 4, 1], [1, 3, 2], [2, 4], [1, 3]]
    # create the node dict that undirected_graph api can consume
    nodes = {k: v for k, v in enumerate(leetcode_input, start=1)}
    print(nodes)

    undirected_graph = UndirectedGraph()
    # add vertices
    for src_vertex in nodes.keys():
        undirected_graph.add_vertex(src_vertex)
    # add edges
    for src_vertex in nodes.keys():
        dst_vertices = nodes[src_vertex]
        for dst_vertex in dst_vertices:
            undirected_graph.add_edge(src_vertex, dst_vertex)

    # find the number of self loops
    count = number_of_self_loops(undirected_graph)
    print(f"nos of self loops: {count}")


if __name__ == '__main__':
    main()
