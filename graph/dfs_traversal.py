#!/usr/bin/env python3

# author: greyshell
# description: dfs traversal in a connected undirected graph

from collections import deque
from graph_adt import Vertex, UndirectedGraph


def dfs(graph, src_v):
    """
    Depth first search on undirected graph
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    stack = deque()
    visited = set()

    # add the source vertex into the stack
    source_vertex = graph.get_vertex(src_v)
    stack.append(source_vertex)

    while stack:
        # pop the vertex from the stack
        vertex = stack.pop()
        if vertex in visited:
            continue

        # if the vertex is not visited then add into the visited set
        visited.add(vertex)
        print(vertex.get_key(), end=" ")
        # iterate all neighbors of that node
        for neighbor in vertex.get_neighbors():
            # if that neighbor node is not visited then add to the stack
            if neighbor not in visited:
                stack.append(neighbor)


def main():
    # ===================================================================
    # create an undirected graph
    # ===================================================================
    leetcode_input = [["1", "2"], ["3"], ["1", "3", "4"], [], ["3"]]
    # create intermediate node dict that graph api can consume
    nodes = {str(k): v for k, v in enumerate(leetcode_input, start=0)}

    undirected_graph = UndirectedGraph()
    # add vertices
    for src_vertex in nodes.keys():
        undirected_graph.add_vertex(src_vertex)
    # add edges
    for src_vertex in nodes.keys():
        dst_vertices = nodes[src_vertex]
        for dst_vertex in dst_vertices:
            undirected_graph.add_edge(src_vertex, dst_vertex)

    print(f"dfs traversal in a connected undirected graph: ")
    dfs(undirected_graph, "3")
    print("")


if __name__ == '__main__':
    main()
