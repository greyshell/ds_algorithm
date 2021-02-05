#!/usr/bin/env python3

# author: greyshell
# description: single source path problem
# check if a path exists from src to dst via bidirectional bfs

from typing import List
from collections import deque
from graph_adt import Vertex, UndirectedGraph


def bidirectional_bfs(undirected_graph, src_v, dst_v):
    """
    time complexity:
    - assume every node has at most K adjacent nodes and the shortest path from src to dst has length d
    then at the max we need to process O(k^(d/2)) nodes
    - to find the intersection node will take O(k^2) time complexity
    space complexity: edge_to dict -> O(E)
    :param undirected_graph:
    :param src_v: str / int
    :param dst_v: str / int
    :return: bool, List
    """
    if not (undirected_graph.get_vertex(src_v) and
            undirected_graph.get_vertex(dst_v)):
        return False, [], {}

    # track the vertex, where we come from
    forward_edge_to = dict()
    backward_edge_to = dict()

    # track the visited vertices
    forward_visited = set()
    # add the source vertex into the visited set
    forward_visited.add(src_v)
    backward_visited = set()
    backward_visited.add(dst_v)

    # add the source vertex into a queue
    forward_queue = deque()
    forward_queue.append(src_v)

    backward_queue = deque()
    backward_queue.append(dst_v)

    while forward_queue and backward_queue:
        if forward_queue:
            # pop the vertex from the queue
            vertex = forward_queue.popleft()
            # iterate all neighbors of that vertex
            vertex_node = undirected_graph.get_vertex(vertex)
            for neighbor in vertex_node.get_neighbors():
                if neighbor.get_key() not in forward_visited:
                    forward_visited.add(neighbor.get_key())
                    forward_queue.append(neighbor.get_key())
                    forward_edge_to[neighbor.get_key()] = vertex_node.get_key()

        if backward_queue:
            # pop the vertex from the queue
            vertex = backward_queue.popleft()
            # iterate all neighbors of that vertex
            vertex_node = undirected_graph.get_vertex(vertex)
            for neighbor in vertex_node.get_neighbors():
                if neighbor.get_key() not in backward_visited:
                    backward_visited.add(neighbor.get_key())
                    backward_queue.append(neighbor.get_key())
                    backward_edge_to[neighbor.get_key()] = vertex_node.get_key()

        # find the intersection point
        intersection_nodes = forward_visited.intersection(backward_visited)

        if intersection_nodes:
            intersection_node = list(intersection_nodes)[0]
            # prepare forward path
            forward_path = deque()
            x = intersection_node

            while x != src_v:
                forward_path.appendleft(x)
                x = forward_edge_to[x]
            forward_path.appendleft(src_v)
            # remove the intersection node from the forward path
            forward_path.pop()

            # prepare backward path
            backward_path = deque()
            x = intersection_node
            while x != dst_v:
                backward_path.append(x)
                x = backward_edge_to[x]
            backward_path.append(dst_v)

            # join forward and backward paths
            forward_path.extend(backward_path)

            return True, list(forward_path), intersection_nodes

    return False, [], {}


def main():
    undirected_graph = UndirectedGraph()
    # ref: Sedgewick Algorithms 4th edition, page 532
    # add vertices
    for src_vertex in range(0, 6):
        undirected_graph.add_vertex(src_vertex)

    # add edges
    undirected_graph.add_edge(0, 5)
    undirected_graph.add_edge(2, 4)
    undirected_graph.add_edge(2, 3)
    undirected_graph.add_edge(1, 2)
    undirected_graph.add_edge(0, 1)
    undirected_graph.add_edge(3, 4)
    undirected_graph.add_edge(3, 5)
    undirected_graph.add_edge(0, 2)

    # find the path from source to destination using bidirectional search
    print("")
    print(f"Bi directional BFS")
    src_v = 1
    dst_v = 3
    has_path_to, path, intersection_nodes = bidirectional_bfs(undirected_graph, src_v, dst_v)
    print(f"{src_v} to {dst_v}: has_path_to = {has_path_to}")
    print(f"{src_v} to {dst_v}: {path}")
    print(f"intersection node[s]: {intersection_nodes}")
    print("")


if __name__ == '__main__':
    main()
