#!/usr/bin/env python3

# author: greyshell
# description: graph traversal: BFS

from collections import deque
from graph_adt import Vertex, Graph


def bfs(graph, src_v):
    """
    Breadth first search
    - can tells if there a path exists
    - gives the shortest distance (minimum edges / intermediate nodes) between the source and destination
    time complexity:
    space complexity:
    """
    # add the first node into visited dict
    source_vertex = graph.get_vertex(src_v)
    # create a set
    visited = set()
    visited.add(source_vertex)

    # add the first node into the queue
    queue = deque()
    queue.append(source_vertex)

    while queue:
        vertex = queue.popleft()
        print(vertex, end=" ")
        # iterate all neighbors of that node
        for neighbor in vertex.get_neighbors():
            # if that neighbor node is not visited then add to the visited dict and queue
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)


def main():
    # undirected graph as a dictionary
    d = {
        "0": ["1", "2"],
        "1": ["0", "2", "3"],
        "2": ["0", "1", "3", "4"],
        "3": ["1", "2", "4"],
        "4": ["2", "3"]
    }

    graph = Graph(graph_dict=d)
    bfs(graph, "4")
    print("")


if __name__ == '__main__':
    main()
