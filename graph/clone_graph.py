#!/usr/bin/env python3

# author: greyshell
# reference: https://leetcode.com/problems/clone-graph/

from typing import List
from collections import deque
from graph_adt import Vertex, Graph


def clone_graph(node):
    """
    deep copy / clone graph
    traversal approach: bfs
    time complexity: O(V + E)
    space complexity: O(
    """
    # when the start node is empty
    if not node:
        return node

    # dictionary to save the visited node and it's respective clone as key and value respectively
    # this helps to avoid cycles
    visited = {}
    queue = deque()

    # put the first node in the queue
    queue.append(node)
    # create a new node / clone with same start_node val but empty neighbours
    # because we don't know their address at this point
    # put that new node in the visited dictionary
    visited[node] = Vertex(node.get_key())

    # perform bfs traversal
    while queue:  # if queue is not empty
        # dequeue a vertex from the queue
        vertex = queue.popleft()

        # iterate through its neighbors
        for neighbor in vertex.get_neighbors():
            if neighbor not in visited:
                # create a new node / clone
                visited[neighbor] = Vertex(neighbor.get_key())
                # add the newly encountered node to the queue
                queue.append(neighbor)

            # wiring: get the clone node of the original from visit dict
            visited[vertex].add_neighbor(visited[neighbor])

    # return the start node of the cloned graph
    return visited[node]


def main():
    leetcode_input = [[2, 4], [1, 3], [2, 4], [1, 3]]
    # format the user input that graph api can consume
    graph = {k: v for k, v in enumerate(leetcode_input, start=1)}

    g = Graph(graph_dict=graph)
    start_node = g.get_vertex(1)
    print(f"start node addr: {start_node.__repr__()}")
    print(f"start node: {start_node}")

    out = clone_graph(start_node)
    print(f"start node addr of clone: {out.__repr__()}")
    print(f"start node of clone: {out}")


if __name__ == '__main__':
    main()
