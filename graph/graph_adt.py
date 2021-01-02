#!/usr/bin/env python3

# author: greyshell
# description: Graph ADT, no weight

from typing import List
from collections import deque


class Vertex:
    """
    implementation of a vertex / node of graph
    """
    def __init__(self, key):
        self._key = key
        # duplicate edges are added if list() is used
        self._neighbors = set()
        self._in_degree = 0

    def add_neighbor(self, neighbor_vertex):
        self._neighbors.add(neighbor_vertex)

    def get_key(self):
        return self._key

    def get_neighbors(self):
        return self._neighbors

    def get_out_degree(self):
        return len(self._neighbors)

    def get_in_degree(self):
        return self._in_degree

    # display the vertex
    def __str__(self):
        s = str(self._key) + ":"
        for neighbor in self._neighbors:
            s += str(neighbor.get_key()) + " "
        return s


class Graph(object):
    """
    implementation of Graph ADT
    """

    def __init__(self):
        self._vertices = dict()

    def add_vertex(self, vertex):
        v = Vertex(vertex)
        self._vertices[vertex] = v

    def add_edge(self, from_vertex, to_vertex):
        if from_vertex not in self._vertices:
            self.add_vertex(from_vertex)

        if to_vertex not in self._vertices:
            self.add_vertex(to_vertex)

        self._vertices[from_vertex].add_neighbor(self._vertices[to_vertex])
        # increment in_degree of the to_vertex
        self.get_vertex(to_vertex)._in_degree += 1

    def get_vertex(self, vertex_key):
        for vertex in self._vertices:
            if vertex == vertex_key:
                return self._vertices[vertex]

    def get_vertices(self):
        return list(self._vertices.keys())

    def get_edges(self):
        edges = []
        for vertex in self._vertices:
            neighbors = self._vertices[vertex].get_neighbors()

            for neighbor in neighbors:
                to_vertex = neighbor.get_key()
                edges.append((vertex, to_vertex))

        return edges


def main():
    # ===================================================================
    # create an undirected graph
    # ===================================================================
    print(f"create an undirected graph")
    leetcode_input = [["1", "2"], ["3"], ["1", "3", "4"], [], ["3"]]
    # create intermediate node dict that graph api can consume
    nodes = {str(k): v for k, v in enumerate(leetcode_input, start=0)}
    print(nodes)

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

    print(f"vertices: {undirected_graph.get_vertices()}")
    print(f"edges: {undirected_graph.get_edges()}")

    # get the degree of each vertices
    for v in undirected_graph.get_vertices():
        # for undirected graph, total degree is equal to in_degree or out_degree
        degree = undirected_graph.get_vertex(v).get_out_degree()
        print(f"vertex: {v} => degree: {degree}")

    print("")

    # ===================================================================
    # create an directed graph
    # ===================================================================
    print(f"create a directed graph")
    leetcode_input = [["1", "2"], ["3"], ["1", "3", "4"], [], ["3"]]
    # create intermediate node dict that graph api can consume
    nodes = {str(k): v for k, v in enumerate(leetcode_input, start=0)}
    print(nodes)

    directed_graph = Graph()
    # add vertices
    for src_vertex in nodes.keys():
        directed_graph.add_vertex(src_vertex)
    # add edges
    for src_vertex in nodes.keys():
        dst_vertices = nodes[src_vertex]
        for dst_vertex in dst_vertices:
            directed_graph.add_edge(src_vertex, dst_vertex)

    print(f"vertices: {directed_graph.get_vertices()}")
    print(f"edges: {directed_graph.get_edges()}")

    for v in directed_graph.get_vertices():
        out_degree = directed_graph.get_vertex(v).get_out_degree()
        in_degree = directed_graph.get_vertex(v).get_in_degree()
        print(f"vertex: {v} => out degree: {out_degree}, in degree: {in_degree}, total: {in_degree + out_degree}")


if __name__ == '__main__':
    main()
