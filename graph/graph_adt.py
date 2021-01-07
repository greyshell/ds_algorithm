#!/usr/bin/env python3

# author: greyshell
# description: Graph ADT

from typing import List
from collections import deque


class Vertex:
    """
    implementation of a vertex / node of graph
    """

    def __init__(self, key):
        self._key = key
        # duplicate edges are added if list() is used
        self._neighbors = set()  # each element is an object of vertex

    def add_neighbor(self, neighbor_vertex):
        self._neighbors.add(neighbor_vertex)

    def get_key(self):
        return self._key

    def get_neighbors(self):
        return self._neighbors

    # display / print a vertex / node
    def __str__(self):
        s = str(self._key)
        s += ": {"
        for neighbor in self._neighbors:
            s += str(neighbor.get_key()) + ","

        # when the node has neighbors
        if s[-1] == ',':
            s = s[:-1]  # remove the last ',' char

        s += "}"
        return s


class UndirectedGraph(object):
    """
    implementation of UndirectedGraph ADT
    """

    def __init__(self):
        self._vertices = dict()

    def add_vertex(self, vertex):
        self._vertices[vertex] = Vertex(vertex)

    def add_edge(self, from_vertex, to_vertex):
        if from_vertex not in self._vertices:
            self.add_vertex(from_vertex)

        if to_vertex not in self._vertices:
            self.add_vertex(to_vertex)

        self._vertices[from_vertex].add_neighbor(self._vertices[to_vertex])
        # add the reverse link for undirected graph
        self._vertices[to_vertex].add_neighbor(self._vertices[from_vertex])

    def get_vertex(self, vertex_key):
        return self._vertices.get(vertex_key, None)

    def get_vertices(self):
        return list(self._vertices.values())

    def get_vertices_as_key(self):
        return list(self._vertices.keys())

    def get_edges(self):
        edges_obj = []
        for src_vertex in self._vertices:
            src_vertex_obj = self._vertices[src_vertex]
            neighbors = src_vertex_obj.get_neighbors()

            for neighbor in neighbors:
                to_vertex_obj = neighbor
                edges_obj.append((src_vertex_obj, to_vertex_obj))

        return edges_obj

    def get_edges_as_key(self):
        edges_as_key = []
        for src_vertex in self._vertices:
            neighbors = self._vertices[src_vertex].get_neighbors()

            for neighbor in neighbors:
                to_vertex = neighbor.get_key()
                edges_as_key.append((src_vertex, to_vertex))

        return edges_as_key

    def get_degree(self, vertex):
        return len(self._vertices[vertex].get_neighbors())


class DirectedGraph(UndirectedGraph):
    def __init__(self):
        super().__init__()

    def add_edge(self, from_vertex, to_vertex):
        if from_vertex not in self._vertices:
            self.add_vertex(from_vertex)

        if to_vertex not in self._vertices:
            self.add_vertex(to_vertex)

        self._vertices[from_vertex].add_neighbor(self._vertices[to_vertex])

    def get_out_degree(self, vertex):
        return super().get_degree(vertex)

    def get_in_degree(self, vertex):
        """
        time complexity: O(V + E)
        :param vertex:
        :return: int
        """
        count = 0
        v = self.get_vertex(vertex)

        for k in self._vertices:
            n = self.get_vertex(k)
            for n in n.get_neighbors():
                if n == v:
                    count += 1
                    break
        return count


def demo_directed_graph():
    # ===================================================================
    # create an directed graph
    # ===================================================================
    print(f"create a directed graph")
    leetcode_input = [["1", "2"], ["3"], ["1", "3", "4"], [], ["3"]]
    # create intermediate node dict that graph api can consume
    nodes = {str(k): v for k, v in enumerate(leetcode_input, start=0)}
    print(nodes)

    directed_graph = DirectedGraph()
    # add vertices
    for src_vertex in nodes.keys():
        directed_graph.add_vertex(src_vertex)
    # add edges
    for src_vertex in nodes.keys():
        dst_vertices = nodes[src_vertex]
        for dst_vertex in dst_vertices:
            directed_graph.add_edge(src_vertex, dst_vertex)

    print(f"vertices: {directed_graph.get_vertices_as_key()}")
    print(f"edges: {directed_graph.get_edges_as_key()}")
    # exit(0)

    for v in directed_graph.get_vertices_as_key():
        out_degree = directed_graph.get_out_degree(v)
        # in_degree = directed_graph.get_vertex(v).get_in_degree()
        in_degree = directed_graph.get_in_degree(v)
        print(f"vertex: {v} => out degree: {out_degree}, in degree: {in_degree}, total: {in_degree + out_degree}")


def demo_undirected_graph():
    # ===================================================================
    # create an undirected graph
    # ===================================================================
    print(f"create an undirected graph")
    # leetcode_input = [["1", "2"], ["3"], ["1", "2", "4"], [], ["3"]]
    # create intermediate node dict that graph api can consume
    # nodes = {str(k): v for k, v in enumerate(leetcode_input, start=1)}

    nodes = {0: [1, 2, 5, 6],
             1: [0],
             2: [0],
             3: [4, 5],
             4: [5, 3],
             5: [0, 3]
             }

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

    print(f"vertices: {undirected_graph.get_vertices_as_key()}")
    print(f"edges: {undirected_graph.get_edges_as_key()}")

    print(f"vertices: {undirected_graph.get_vertices()}")
    print(f"edges: {undirected_graph.get_edges()}")

    # get the degree of each vertices
    for v in undirected_graph.get_vertices_as_key():
        # for undirected graph, total degree is equal to in_degree or out_degree
        degree = undirected_graph.get_degree(v)
        print(f"vertex: {v} => degree: {degree}")

    print("")


def demo_vertex():
    print(f"create a vertex")
    v = Vertex("A")
    print(v.__repr__())  # print the obj address
    print(v)  # if __str__() method is available then call that method else print obj address

    # we can't add neighbors like the following
    # v.add_neighbor("B")  -> wrong coz set contains Vertex objects
    b_obj = Vertex("B")  # create a vertex object of B
    v.add_neighbor(b_obj)  # -> right
    v.add_neighbor(Vertex("C"))  # -> right
    v.add_neighbor(Vertex("D"))  # -> right

    print(v.__repr__())
    print(v)
    print("")


def main():
    demo_vertex()
    demo_undirected_graph()
    # demo_directed_graph()


if __name__ == '__main__':
    main()
