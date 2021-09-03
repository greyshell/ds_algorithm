#!/usr/bin/env python3

# author: greyshell
# description: dfs traversals on a connected undirected graph

from collections import deque
from graph import UndirectedGraph


def dfs(ug, start_vertex):
    """
    depth first search
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    # check if the start vertex_name is present in the ug
    if not ug.get_vertex_obj(start_vertex):
        return False

    # track the visited vertices
    visited = set()

    # add the start vertex_name into the stack
    stack = deque()
    stack.append(start_vertex)

    while stack:
        # pop the vertex_name from the stack but don't process that immediately
        vertex = stack.pop()
        # check if the vertex_name is not in visited set then add into the visited set and process
        if vertex not in visited:
            visited.add(vertex)
            print(vertex, end=" ")
            # iterate all neighbors of that node
            vertex_obj = ug.vertices[vertex]
            # iterate all neighbors of that vertex_name
            for edge_obj in vertex_obj.neighbor_edges_obj:
                neighbor = edge_obj.dst_vertex
                # if that neighbor is not in the visited set then add that into the stack
                if neighbor not in visited:
                    stack.append(neighbor)


def main():
    # ref: Sedgewick Algorithms 4th edition, page 532
    ug = UndirectedGraph()
    # add vertices
    for vertex in range(0, 6):
        ug.add_vertex(str(vertex))

    # add edges
    ug.add_edge("0", "1")
    ug.add_edge("0", "5")
    ug.add_edge("0", "2")
    ug.add_edge("1", "2")
    ug.add_edge("2", "3")
    ug.add_edge("2", "4")
    ug.add_edge("3", "4")
    ug.add_edge("3", "5")

    start_vertex = "0"

    print(f"dfs traversal: ")
    dfs(ug, start_vertex)


if __name__ == '__main__':
    main()
