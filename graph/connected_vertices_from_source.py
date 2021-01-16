#!/usr/bin/env python3

# author: greyshell
# description: find connected vertices from source

from typing import List
from collections import deque
from graph_adt import Vertex, UndirectedGraph


def connected_vertices_from_source(undirected_graph, src_v):
    """
    dfs approach
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    if not undirected_graph.get_vertex(src_v):
        return False

    # track the visited vertices
    visited = set()

    # add the source vertex into the stack
    stack = deque()
    stack.append(src_v)

    while stack:
        # pop the vertex from the stack
        vertex = stack.pop()
        if vertex not in visited:
            # if the vertex is not visited then add into the visited set
            visited.add(vertex)
            # iterate all neighbors of that node
            vertex_node = undirected_graph.get_vertex(vertex)
            for neighbor in vertex_node.get_neighbors():
                # if that neighbor node is not visited then add to the stack
                if neighbor.get_key() not in visited:
                    stack.append(neighbor.get_key())

    return visited


def main():
    # ref: Sedgewick Algorithms 4th edition, page 529
    undirected_graph = UndirectedGraph()
    # add vertices
    for src_vertex in range(0, 13):
        undirected_graph.add_vertex(src_vertex)

    # add edges
    undirected_graph.add_edge(0, 1)
    undirected_graph.add_edge(0, 2)
    undirected_graph.add_edge(0, 5)
    undirected_graph.add_edge(0, 6)
    undirected_graph.add_edge(5, 3)
    undirected_graph.add_edge(5, 4)
    undirected_graph.add_edge(3, 4)
    undirected_graph.add_edge(4, 6)
    undirected_graph.add_edge(7, 8)
    undirected_graph.add_edge(9, 10)
    undirected_graph.add_edge(9, 11)
    undirected_graph.add_edge(9, 12)
    undirected_graph.add_edge(11, 12)

    # find all vertices connected from the source
    src_v = 9
    vertices = connected_vertices_from_source(undirected_graph, src_v)

    print(f"vertices connected form: {src_v}")
    for v in vertices:
        print(f"{v}", end=" ")


if __name__ == '__main__':
    main()
