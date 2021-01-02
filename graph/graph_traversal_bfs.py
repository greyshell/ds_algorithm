#!/usr/bin/env python3

# author: greyshell
# description: bfs traversal in an undirected graph

from collections import deque
from graph_adt import Vertex, Graph


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


def main():
    # ===================================================================
    # create an undirected graph
    # ===================================================================
    leetcode_input = [["1", "2"], ["3"], ["1", "3", "4"], [], ["3"]]
    # create intermediate node dict that graph api can consume
    nodes = {str(k): v for k, v in enumerate(leetcode_input, start=0)}

    undirected_graph = Graph()
    # add vertices
    for src_vertex in nodes.keys():
        undirected_graph.add_vertex(src_vertex)
    # add edges
    for src_vertex in nodes.keys():
        dst_vertices = nodes[src_vertex]
        for dst_vertex in dst_vertices:
            undirected_graph.add_edge(src_vertex, dst_vertex)
            # IMPORTANT: need to add this reverse link to create the undirected graph
            undirected_graph.add_edge(dst_vertex, src_vertex)

    print(f"bfs traversal of a directed graph: ")
    bfs(undirected_graph, "3")


if __name__ == '__main__':
    main()
