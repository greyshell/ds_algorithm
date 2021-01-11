#!/usr/bin/env python3

# author: greyshell
# description: find the shortest path in the undirected unweighted graph from src to dst

from typing import List
from collections import deque
from graph_adt import Vertex, UndirectedGraph


def find_shortest_path(undirected_graph, src_v, dst_v):
    """
    Breadth first search
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    path = list()
    queue = deque()
    visited = set()

    # add the source vertex into the queue
    source_vertex = undirected_graph.get_vertex(src_v)
    queue.append(source_vertex)
    # add the source vertex into the visited set
    visited.add(source_vertex)

    while queue:
        # pop the vertex from the queue
        vertex = queue.popleft()

        if vertex.get_key() == dst_v:
            return path

        path.append(vertex.get_key())

        # iterate all neighbors of that node
        for neighbor in vertex.get_neighbors():
            # if that neighbor node is not visited then add to the queue
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)


def main():
    undirected_graph = UndirectedGraph()
    # add vertices
    for src_vertex in range(0, 7):
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

    # find the shortest path from src to dst
    src_v = 0
    dst_v = 3
    path = find_shortest_path(undirected_graph, src_v, dst_v)
    print(f"shortest path from {src_v} to {dst_v}: {path}")


if __name__ == '__main__':
    main()
