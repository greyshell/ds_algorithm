#!/usr/bin/env python3

# author: greyshell
# description: bfs traversals on a connected undirected graph

from collections import deque
from graph import UndirectedGraph


def bfs(ug, start_vertex):
    """
    breadth first search
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    """
    # check if the start vertex_name is present in the graph
    if not ug.get_vertex_obj(start_vertex):
        return False

    # track the visited vertices
    visited = set()
    # add the start vertex_name into the visited set
    visited.add(start_vertex)

    # add the start vertex_name into the queue
    queue = deque()
    queue.append(start_vertex)

    while queue:
        # pop the vertex_name from the queue and process
        vertex = queue.popleft()
        print(vertex, end=" ")

        vertex_obj = ug.vertices[vertex]
        # iterate all neighbors of that vertex_name
        for edge_obj in vertex_obj.neighbor_edges_obj:
            neighbor = edge_obj.dst_vertex
            # if that neighbor is not in the visited set then add to the queue and set
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)


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

    print(f"bfs traversal: ")
    bfs(ug, start_vertex)


if __name__ == '__main__':
    main()
