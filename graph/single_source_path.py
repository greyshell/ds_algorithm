#!/usr/bin/env python3

# author: greyshell
# description: single source path problem / finding path

from typing import List
from collections import deque
from graph_adt import Vertex, UndirectedGraph


def depth_first_paths(undirected_graph, src_v, dst_v):
    """
    time complexity: O(V + E)
    space complexity: O(V) -> to maintain the visited set
    :param undirected_graph:
    :param src_v:
    :param dst_v:
    :return: bool, List
    """
    if not (undirected_graph.get_vertex(src_v) and
            undirected_graph.get_vertex(dst_v)):
        return False, []

    # track the vertex, where we come from
    edge_to = dict()

    # track the visited vertices, we can mark the vertex visited when it is popped out from stack
    visited = set()

    # add the source vertex into a queue
    stack = deque()
    stack.append(src_v)

    while stack:
        # pop the vertex from the stack
        vertex = stack.pop()
        if vertex not in visited:
            # if the vertex is not visited then add into the visited set
            visited.add(vertex)
            if vertex == dst_v:
                break
            # iterate all neighbors of that vertex
            vertex_node = undirected_graph.get_vertex(vertex)
            for neighbor in vertex_node.get_neighbors():
                # if that neighbor node is not visited then add to the stack
                if neighbor.get_key() not in visited:
                    stack.append(neighbor.get_key())
                    edge_to[neighbor.get_key()] = vertex_node.get_key()

    # prepare the path
    path = deque()
    x = dst_v
    while x != src_v:
        path.appendleft(x)
        x = edge_to[x]
    path.appendleft(src_v)

    return dst_v in visited, list(path)


def breadth_first_paths(undirected_graph, src_v, dst_v):
    """
    time complexity: O(V + E)
    - assume every node has at most K adjacent nodes and the shortest path from src to dst has length d
    then at the max we need to process O(k^d) nodes
    space complexity: edge_to dict -> O(E)
    :param undirected_graph:
    :param src_v:
    :param dst_v:
    :return: bool, List
    """
    if not (undirected_graph.get_vertex(src_v) and
            undirected_graph.get_vertex(dst_v)):
        return False, []

    # track the vertex, where we come from
    edge_to = dict()

    # track the visited vertices
    visited = set()
    # add the source vertex into the visited set
    visited.add(src_v)

    # add the source vertex into a queue
    queue = deque()
    queue.append(src_v)

    while queue:
        # pop the vertex from the queue
        vertex = queue.popleft()
        # we add the item into the queue after we visit that item
        if vertex == dst_v:
            break
        # iterate all neighbors of that vertex
        vertex_node = undirected_graph.get_vertex(vertex)
        for neighbor in vertex_node.get_neighbors():
            if neighbor.get_key() not in visited:
                visited.add(neighbor.get_key())
                queue.append(neighbor.get_key())
                edge_to[neighbor.get_key()] = vertex_node.get_key()

    # prepare the path
    path = deque()
    x = dst_v
    while x != src_v:
        path.appendleft(x)
        x = edge_to[x]
    path.appendleft(src_v)

    return dst_v in visited, list(path)


def bidirectional_search(undirected_graph, src_v, dst_v):
    """
    time complexity:
    - assume every node has at most K adjacent nodes and the shortest path from src to dst has length d
    then at the max we need to process O(k^(d/2)) nodes
    - to find the intersection node will take O(k^2) time complexity
    space complexity: edge_to dict -> O(E)
    :param undirected_graph:
    :param src_v:
    :param dst_v:
    :return:
    """
    if not (undirected_graph.get_vertex(src_v) and
            undirected_graph.get_vertex(dst_v)):
        return False, []

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
        intersection_nodes = list(forward_visited.intersection(backward_visited))

        if intersection_nodes:
            # if the intersection node more than 1 then take any nodes
            if len(intersection_nodes) > 1:
                intersection_node = intersection_nodes[0]
            else:
                intersection_node = intersection_nodes

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

    return False, []


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

    print("")
    print(f"finding the path using DFS")
    src_v = 0
    dst_v = 4
    has_path_to, path = depth_first_paths(undirected_graph, src_v, dst_v)
    print(f"{src_v} to {dst_v}: has_path_to = {has_path_to}")
    print(f"{src_v} to {dst_v}: {path}")
    print("")

    # refer the output from page 535
    src_v = 0
    for node in undirected_graph.get_vertices():
        dst_v = node.get_key()
        _, path = depth_first_paths(undirected_graph, src_v, dst_v)
        print(f"{src_v} to {dst_v}: {path}")

    # find the path from source to destination vertex
    print("")
    print(f"finding shortest path using BFS")
    src_v = 3
    dst_v = 4
    has_path_to, path = breadth_first_paths(undirected_graph, src_v, dst_v)
    print(f"{src_v} to {dst_v}: has_path_to = {has_path_to}")
    print(f"{src_v} to {dst_v}: {path}")
    print("")

    # refer the output from page 541
    src_v = 0
    for node in undirected_graph.get_vertices():
        dst_v = node.get_key()
        _, path = breadth_first_paths(undirected_graph, src_v, dst_v)
        print(f"{src_v} to {dst_v}: {path}")

    # find the path from source to destination using bi directional search
    print("")
    print(f"Bi directional BFS")
    src_v = 0
    dst_v = 1
    has_path_to, path, intersection_nodes = bidirectional_search(undirected_graph, src_v, dst_v)
    print(f"{src_v} to {dst_v}: has_path_to = {has_path_to}")
    print(f"{src_v} to {dst_v}: {path}")
    print(f"intersection node[s]: {intersection_nodes}")
    print("")


if __name__ == '__main__':
    main()
