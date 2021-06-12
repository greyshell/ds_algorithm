#!/usr/bin/env python3

# author: greyshell
# description: Graph ADT

from typing import List
from collections import deque


class WeightedVertex:

    def __init__(self, ):
        self._key = key
        self._neighbors = list()  # each element is a dict, node -> addr, weight -> w

    def add_neighbor(self, neighbor_vertex, weight):
        # prepare a list
        neighbor_weighted_vertex = list()
        neighbor_weighted_vertex.append(neighbor_vertex, weight)
        self._neighbors.append(neighbor_weighted_vertex)

    def get_key(self):
        return self._key

    def get_neighbors(self):
        return self._neighbors

    # display / print a vertex
    def __str__(self):
        s = str(self._key)
        s += ": {"
        for neighbor in self._neighbors:
            s += str(neighbor.get_key()) + ","

        # when the vertex / node has neighbors, remove the last ',' char
        if s[-1] == ',':
            s = s[:-1]

        s += "}"
        return s


class WeightedUndirectedGraph(object):

    def __init__(self):
        self._vertices = dict()

    def add_vertex(self, vertex):
        self._vertices[vertex] = WeightedVertex(vertex)

    def add_edge(self, from_vertex, to_vertex, weight):
        if from_vertex not in self._vertices:
            self.add_vertex(from_vertex)

        if to_vertex not in self._vertices:
            self.add_vertex(to_vertex)

        self._vertices[from_vertex].add_neighbor(self._vertices[to_vertex], weight)
        # add the reverse link
        self._vertices[to_vertex].add_neighbor(self._vertices[from_vertex], weight)

    def get_vertex(self, vertex_key):
        # if not found then return False
        return self._vertices.get(vertex_key, False)

    def get_vertices(self):
        return list(self._vertices.values())

    def get_edges(self):
        edges = []
        for src_vertex in self._vertices:  # iterate keys
            src_vertex_obj = self._vertices[src_vertex]

            for neighbor_obj in src_vertex_obj.get_neighbors():
                edges.append((src_vertex_obj, neighbor_obj))

        return edges

    def get_degree(self, vertex):
        """
        time complexity: O(E), where E is the edges of that vertex
        :param vertex:
        :return: int
        """
        return len(self._vertices[vertex].get_neighbors())

    # ===============================================================================
    # auxiliary methods
    # ===============================================================================
    def nos_of_self_loops(self):
        count = 0
        for k in self._vertices:
            node = self.get_vertex(k)
            neighbors = node.get_neighbors()  # returns a se
            if node in neighbors:  # time: O(1)
                count += 1
        return count


# class DirectedGraph(UndirectedGraph):
#
#     def __init__(self):
#         super().__init__()
#
#     def add_edge(self, from_vertex, to_vertex):
#         if from_vertex not in self._vertices:
#             self.add_vertex(from_vertex)
#
#         if to_vertex not in self._vertices:
#             self.add_vertex(to_vertex)
#
#         self._vertices[from_vertex].add_neighbor(self._vertices[to_vertex])
#
#     def get_out_degree(self, vertex):
#         return super().get_degree(vertex)
#
#     def get_in_degree(self, vertex):
#         """
#         time complexity: O(V)
#         :param vertex:
#         :return: int
#         """
#         count = 0
#         v = self.get_vertex(vertex)
#
#         for k in self._vertices:
#             node = self.get_vertex(k)
#             neighbors = node.get_neighbors()  # returns a set
#             if v in neighbors:  # time: O(1)
#                 count += 1
#         return count


def demo_vertex():
    print(f"demo the vertex node")
    v = Vertex("A")
    print(v.__repr__())  # print the obj address
    print(v)  # if __str__() method is available then call that method else print obj address

    # we can't add a neighbor by v.add_neighbor("B")  -> wrong approach
    # coz internal list contains objects of type Vertex
    b_obj = Vertex("B")  # create a vertex object of B
    v.add_neighbor(b_obj)
    v.add_neighbor(Vertex("C"))

    print(v.__repr__())
    print(v)
    print("")


def demo_undirected_graph():
    # leetcode_input = [["1", "2"], ["3"], ["1", "2", "4"], [], ["3"]]  # mention the start index
    # create a intermediate dict that our graph adt can consume
    # nodes = {str(k): v for k, v in enumerate(leetcode_input, start=1)}

    # ref: Sedgewick Algorithms 4th edition, page 522
    nodes = {
        0: [1, 2, 5, 6],
        1: [],
        2: [],
        3: [4, 5],
        4: [6],
        5: [],
        6: [],
        7: [8],
        8: [],
        9: [10, 11, 12],
        10: [],
        11: [12],
        12: []
    }
    print("demo undirected graph")
    undirected_graph = UndirectedGraph()
    # add vertices
    for src_vertex in nodes:
        undirected_graph.add_vertex(src_vertex)
    # add edges
    for src_vertex in nodes:
        dst_vertices = nodes[src_vertex]
        for dst_vertex in dst_vertices:
            undirected_graph.add_edge(src_vertex, dst_vertex)

    # print vertices
    print(f"vertices:")
    vertices = undirected_graph.get_vertices()
    for v in vertices:
        print(f"{v.get_key()}", end=", ")

    # print edges
    print("")
    print(f"edges:")
    edges = undirected_graph.get_edges()
    for e in edges:
        print(f"({e[0].get_key()}, {e[1].get_key()})", end=", ")

    # get the degree of each vertices
    print("\n")
    for v in undirected_graph.get_vertices():
        # for undirected graph, total degree is equal to in_degree or out_degree
        vertex_key = v.get_key()
        degree = undirected_graph.get_degree(vertex_key)
        print(f"degree of {vertex_key}: {degree}")

    print("")
    self_loops = undirected_graph.nos_of_self_loops()
    print(f"nos of self loops: {self_loops}")


# def demo_directed_graph(nodes):
#     """
#     TBD
#     :param nodes:
#     :return:
#     """
#     demo_vertex()
#     exit(0)
#     print("demo directed graph")
#     directed_graph = DirectedGraph()
#     # add vertices
#     for src_vertex in nodes:
#         directed_graph.add_vertex(src_vertex)
#         # add edges
#     for src_vertex in nodes:
#         dst_vertices = nodes[src_vertex]
#         for dst_vertex in dst_vertices:
#             directed_graph.add_edge(src_vertex, dst_vertex)
#
#         # print vertices
#     print(f"vertices:")
#     vertices = directed_graph.get_vertices()
#     for v in vertices:
#         print(f"{v.get_key()}", end=", ")
#
#     # print edges
#     print("")
#     print(f"edges:")
#     edges = directed_graph.get_edges()
#     for e in edges:
#         print(f"({e[0].get_key()}, {e[1].get_key()})", end=", ")
#
#     # get the out_degree and in_degree of each vertices
#     print("\n")
#     for v in directed_graph.get_vertices():
#         # for undirected graph, total degree is equal to in_degree or out_degree
#         vertex_key = v.get_key()
#         out_degree = directed_graph.get_out_degree(vertex_key)
#         in_degree = directed_graph.get_in_degree(vertex_key)
#         print(f"{vertex_key}: out_degree={out_degree}, in_degree={in_degree}")
#
#     print("")


def main():
    # leetcode_input = [["1", "2"], ["3"], ["1", "2", "4"], [], ["3"]]  # mention the start index
    # create a intermediate dict that our graph adt can consume
    # nodes = {str(k): v for k, v in enumerate(leetcode_input, start=1)}

    # ref: Sedgewick Algorithms 4th edition, page 522
    # demo_vertex()
    demo_undirected_graph()
    # demo_directed_graph(nodes)


if __name__ == '__main__':
    main()
