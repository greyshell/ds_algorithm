#!/usr/bin/env python3

# author: greyshell
# reference: https://leetcode.com/problems/clone-graph/

from typing import List
from collections import deque
from graph_adt import Vertex, UndirectedGraph


def clone_graph(node: Vertex) -> Vertex:
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
    # key -> clone node name, value -> clone node address
    visited = dict()
    # create a new node / clone with same start_node val but empty neighbours
    # because we don't know their address at this point
    # put that new node in the visited dictionary
    visited[node] = Vertex(node.get_key())

    # put the first node in the queue
    queue = deque()
    queue.append(node)

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

            # need to add the neighbor in the clone graph
            visited[vertex].add_neighbor(visited[neighbor])

    # return the start node of the cloned graph
    return visited[node]


def main():
    # ===================================================================
    # create an undirected graph
    # ===================================================================
    leetcode_input = [[2, 4], [1, 3], [2, 4], [1, 3]]
    # create the node dict that graph api can consume
    nodes = {k: v for k, v in enumerate(leetcode_input, start=1)}
    print(nodes)

    undirected_graph = UndirectedGraph()
    # add vertices
    for src_vertex in nodes.keys():
        undirected_graph.add_vertex(src_vertex)
    # add edges
    for src_vertex in nodes.keys():
        dst_vertices = nodes[src_vertex]
        for dst_vertex in dst_vertices:
            undirected_graph.add_edge(src_vertex, dst_vertex)

    # select the node 1 as start node
    start_node = undirected_graph.get_vertex(1)
    print(f"start node addr of original graph: {start_node.__repr__()}")
    print(f"start node value of original graph: {start_node}")

    out = clone_graph(start_node)
    print(f"start node addr of clone graph: {out.__repr__()}")
    print(f"start node value of clone graph: {out}")


if __name__ == '__main__':
    main()
