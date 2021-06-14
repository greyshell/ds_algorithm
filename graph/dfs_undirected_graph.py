#!/usr/bin/env python3

# author: greyshell
# description: dfs traversals on a connected undirected graph

from collections import deque
from graph_adt import Vertex, UndirectedGraph


def dfs(graph, src_vertex_name):
    """
    Depth first search
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    # check if the source vertex object is present in the graph dict
    if not graph.get_vertex_obj(src_vertex_name):
        return False

    # track the visited vertices
    visited = set()

    # add the source vertex into the stack
    stack = deque()
    stack.append(src_vertex_name)

    while stack:
        # pop the vertex from the stack but don't process immediately
        vertex_name = stack.pop()
        # check if the vertex is not visited then add into the visited set and process
        if vertex_name not in visited:
            visited.add(vertex_name)
            print(vertex_name, end=" ")
            # iterate all neighbors of that node
            vertex_obj = graph.get_vertex_obj(vertex_name)
            for neighbor_obj in vertex_obj.get_all_neighbors_obj():
                neighbor_vertex_name = neighbor_obj.get_vertex_name()
                # if that neighbor node is not visited then add to the stack
                if neighbor_vertex_name not in visited:
                    stack.append(neighbor_vertex_name)


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


if __name__ == '__main__':
    main()
