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
    if not graph.get_vertex(src_v):
        return False

    # track the visited vertices
    visited = set()
    # add the source vertex into the visited set
    visited.add(src_v)

    # add the source vertex into the queue
    queue = deque()
    queue.append(src_v)

    while queue:
        # pop the vertex from the queue
        vertex = queue.popleft()
        print(vertex, end=" ")
        # iterate all neighbors of that node
        vertex_node = graph.get_vertex(vertex)
        for neighbor in vertex_node.get_neighbors():
            # if that neighbor node is not visited then add to the queue
            if neighbor.get_key() not in visited:
                visited.add(neighbor.get_key())
                queue.append(neighbor.get_key())


def dfs(graph, src_v):
    """
    Depth first search
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    if not graph.get_vertex(src_v):
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
            print(vertex, end=" ")
            # iterate all neighbors of that node
            vertex_node = graph.get_vertex(vertex)
            for neighbor in vertex_node.get_neighbors():
                # if that neighbor node is not visited then add to the stack
                if neighbor.get_key() not in visited:
                    stack.append(neighbor.get_key())


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
