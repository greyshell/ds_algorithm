#!/usr/bin/env python3

# author: greyshell
# description: directed / un-directed graph without any weight

from typing import List
from collections import deque


class Vertex:
    """
    implementation of a vertex / node of graph
    """
    def __init__(self, key):
        self._key = key
        self._neighbors = list()

    def add_neighbor(self, neighbor_vertex):
        self._neighbors.append(neighbor_vertex)

    def get_key(self):
        return self._key

    def get_neighbors(self):
        return self._neighbors

    # display the vertex
    def __str__(self):
        s = str(self._key) + ":"
        for neighbor in self._neighbors:
            s += str(neighbor.get_key()) + " "
        return s


class Graph(object):
    """
    implementation of Graph ADT, no weight
    """
    def __init__(self, graph_dict=None):
        self._vertices = dict()
        if graph_dict is not None:
            # add vertices
            for src_vertex in graph_dict:
                self.add_vertex(src_vertex)
            # add edges
            for src_vertex in graph_dict:
                for dst_vertex in graph_dict[src_vertex]:
                    self.add_edge(src_vertex, dst_vertex)

    def add_vertex(self, vertex):
        v = Vertex(vertex)
        self._vertices[vertex] = v

    def add_edge(self, from_vertex, to_vertex):
        if from_vertex not in self._vertices:
            self.add_vertex(from_vertex)

        if to_vertex not in self._vertices:
            self.add_vertex(to_vertex)

        self._vertices[from_vertex].add_neighbor(self._vertices[to_vertex])

    def get_vertex(self, vertex_key):
        for vertex in self._vertices:
            if vertex == vertex_key:
                return self._vertices[vertex]

    def get_vertices(self):
        return self._vertices.keys()

    def get_edges(self):
        edges = []
        for vertex in self._vertices:
            neighbors = self._vertices[vertex].get_neighbors()

            for neighbor in neighbors:
                to_vertex = neighbor.get_key()
                edges.append((vertex, to_vertex))

        return edges


def main():
    # create a un-directed graph using adjacency list
    g = Graph()

    for v in range(0, 5):  # add vertex
        g.add_vertex(str(v))

    # add edges
    g.add_edge("0", "1")
    g.add_edge("0", "2")
    g.add_edge("1", "3")
    g.add_edge("2", "1")
    g.add_edge("2", "3")
    g.add_edge("2", "4")
    g.add_edge("4", "3")

    print(f"vertices: {g.get_vertices()}")
    print(f"edges: {g.get_edges()}")

    print("")
    # taking graph as a dictionary
    # d = {
    #     "0": ["1", "2"],
    #     "1": ["3"],
    #     "2": ["1", "3", "4"],
    #     "3": [],
    #     "4": ["3"]
    # }

    # un-directed graph
    d = {
        "0": ["1", "2"],
        "1": ["0", "3"],
        "2": ["0", "1", "3", "4"],
        "3": ["1", "2", "4"],
        "4": ["2", "3"]
    }

    g1 = Graph(d)
    print(f"vertices: {g1.get_vertices()}")
    print(f"edges: {g1.get_edges()}")
    node_obj = g1.get_vertex("1")
    print(f"{node_obj}")


if __name__ == '__main__':
    main()
