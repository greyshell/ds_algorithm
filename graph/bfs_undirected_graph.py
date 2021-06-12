#!/usr/bin/env python3

# author: greyshell
# description: bfs traversals on a connected undirected graph

from collections import deque
from graph_adt import Vertex, UndirectedGraph


def bfs(graph, src_vertex_name):
    """
    Breadth first search
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    if not graph.get_vertex_obj(src_vertex_name):
        return False

    # track the visited vertices
    visited = set()
    # add the source vertex into the visited set
    visited.add(src_vertex_name)

    # add the source vertex into the queue
    queue = deque()
    queue.append(src_vertex_name)

    while queue:
        # pop the vertex from the queue
        vertex_name = queue.popleft()
        print(vertex_name, end=" ")
        # iterate all neighbors of that node
        vertex_obj = graph.get_vertex_obj(vertex_name)
        for neighbor_obj in vertex_obj.get_all_neighbors_obj():
            # if that neighbor node is not visited then add to the queue
            if neighbor_obj.get_vertex_name() not in visited:
                visited.add(neighbor_obj.get_vertex_name())
                queue.append(neighbor_obj.get_vertex_name())


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

    src_vertex_name = 0

    print("")
    print(f"bfs traversal: ")
    bfs(undirected_graph, src_vertex_name)


if __name__ == '__main__':
    main()
