#!/usr/bin/env python3

# author: greyshell
# description: single source path problem / check if a path exists from src to dst via bfs

from typing import List
from collections import deque
from graph_adt import Vertex, UndirectedGraph


def breadth_first_paths(undirected_graph, src_v, dst_v):
    """
    time complexity: O(V + E)
    - assume every node has at most K adjacent nodes and the shortest path from src to dst has length d
    then at the max we need to process O(k^d) nodes
    space complexity: edge_to dict -> O(E)
    :param undirected_graph:
    :param src_v:
    :param dst_v:
    :return: bool, List
    """
    if not (undirected_graph.get_vertex(src_v) and
            undirected_graph.get_vertex(dst_v)):
        return False, []

    # track the vertex, where we come from
    edge_to = dict()

    # track the visited vertices
    visited = set()
    # add the source vertex into the visited set
    visited.add(src_v)

    # add the source vertex into a queue
    queue = deque()
    queue.append(src_v)

    while queue:
        # pop the vertex from the queue
        vertex = queue.popleft()
        # we add the item into the queue after we visit that item
        if vertex == dst_v:
            break
        # iterate all neighbors of that vertex
        vertex_node = undirected_graph.get_vertex(vertex)
        for neighbor in vertex_node.get_neighbors():
            if neighbor.get_key() not in visited:
                visited.add(neighbor.get_key())
                queue.append(neighbor.get_key())
                edge_to[neighbor.get_key()] = vertex_node.get_key()

    # prepare the path
    path = deque()
    x = dst_v
    while x != src_v:
        path.appendleft(x)
        x = edge_to[x]
    path.appendleft(src_v)

    return dst_v in visited, list(path)


def main():
    undirected_graph = UndirectedGraph()
    # ref: Sedgewick Algorithms 4th edition, page 532
    # add vertices
    for src_vertex in range(0, 6):
        undirected_graph.add_vertex(src_vertex)

    # add edges
    undirected_graph.add_edge(0, 5)
    undirected_graph.add_edge(2, 4)
    undirected_graph.add_edge(2, 3)
    undirected_graph.add_edge(1, 2)
    undirected_graph.add_edge(0, 1)
    undirected_graph.add_edge(3, 4)
    undirected_graph.add_edge(3, 5)
    undirected_graph.add_edge(0, 2)

    # find the path from source to destination vertex
    print("")
    print(f"finding path using BFS")
    src_v = 3
    dst_v = 4
    has_path_to, path = breadth_first_paths(undirected_graph, src_v, dst_v)
    print(f"{src_v} to {dst_v}: has_path_to = {has_path_to}")
    print(f"{src_v} to {dst_v}: {path}")
    print("")

    # refer the output from page 541
    src_v = 0
    for node in undirected_graph.get_vertices():
        dst_v = node.get_key()
        _, path = breadth_first_paths(undirected_graph, src_v, dst_v)
        print(f"{src_v} to {dst_v}: {path}")

    # find the path from source to destination using bi directional search
    print("")


if __name__ == '__main__':
    main()
