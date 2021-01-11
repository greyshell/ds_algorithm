#!/usr/bin/env python3

# author: greyshell
# description: bfs and dfs traversals on a connected undirected graph

from collections import deque
from graph_adt import Vertex, UndirectedGraph


def bfs(graph, src_v):
    """
    Breadth first search
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    queue = deque()
    visited = set()

    # add the source vertex into the queue
    source_vertex = graph.get_vertex(src_v)
    queue.append(source_vertex)
    # add the source vertex into the visited set
    visited.add(source_vertex)

    while queue:
        # pop the vertex from the queue
        vertex = queue.popleft()
        print(vertex.get_key(), end=" ")
        # iterate all neighbors of that node
        for neighbor in vertex.get_neighbors():
            # if that neighbor node is not visited then add to the queue
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)


def dfs(graph, src_v):
    """
    Depth first search
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
    # ref: Sedgewick Algorithms 4th edition, page 532
    undirected_graph = UndirectedGraph()
    # add vertices
    for src_vertex in range(0, 6):
        undirected_graph.add_vertex(src_vertex)

    # add edges
    undirected_graph.add_edge(0, 1)
    undirected_graph.add_edge(0, 5)
    undirected_graph.add_edge(0, 2)
    undirected_graph.add_edge(1, 2)
    undirected_graph.add_edge(2, 3)
    undirected_graph.add_edge(2, 4)
    undirected_graph.add_edge(3, 4)
    undirected_graph.add_edge(3, 5)

    src_v = 0
    print(f"dfs traversal: ")
    dfs(undirected_graph, src_v)

    print("")
    print(f"bfs traversal: ")
    bfs(undirected_graph, src_v)


if __name__ == '__main__':
    main()
