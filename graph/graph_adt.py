#!/usr/bin/env python3

# author: greyshell
# description: Graph ADT


class Edge:

    def __init__(self, src_vertex, dst_vertex, weight):
        self._src_vertex = src_vertex
        self._dst_vertex = dst_vertex
        self._weight = weight

    def get_edge_weight(self):
        return self._weight

    def get_edge_src(self):
        return self._src_vertex

    def get_edge_dst(self):
        return self._dst_vertex


class Vertex:

    def __init__(self, vertex):
        self._vertex = vertex
        self._neighbor_edges = list()  # list is used to support self loop

    def add_neighbor_edges(self, edge_obj):
        self._neighbor_edges.append(edge_obj)

    def get_neighbor_edges(self):
        return self._neighbor_edges

    def get_vertex(self):
        return self._vertex

    def get_neighbors(self):
        neighbors = []
        for edge_obj in self._neighbor_edges:
            neighbor = edge_obj.get_dst_vertex()
            neighbors.append(neighbor)
        return neighbors

    def __str__(self):
        # display a vertex object
        s = str(self._vertex)
        s += ": {"
        for edge_obj in self.get_neighbor_edges():
            neighbor = edge_obj.get_edge_dst()
            s += str(neighbor) + ","

        # when the vertex / node has neighbors, remove the last ',' char
        if s[-1] == ',':
            s = s[:-1]

        s += "}"
        return s


class WeightedUndirectedGraph:

    def __init__(self):
        self._vertices = dict()
        self._edges = list()  # don't allow parallel edges with same src and dst

    def add_vertex(self, vertex):
        self._vertices[vertex] = Vertex(vertex)

    def get_vertex(self, vertex):
        # if not found then return False
        return self._vertices.get(vertex, False)

    def add_edge(self, src_vertex, dst_vertex, weight):
        if src_vertex not in self._vertices:
            self.add_vertex(src_vertex)

        if dst_vertex not in self._vertices:
            self.add_vertex(dst_vertex)

        src_vertex_obj = self._vertices[src_vertex]
        dst_vertex_obj = self._vertices[dst_vertex]

        edge_obj = Edge(src_vertex, dst_vertex, weight)
        rev_edge_obj = Edge(dst_vertex, src_vertex, weight)

        src_vertex_obj.add_neighbor_edges(edge_obj)
        # add reverse link for undirected graph
        dst_vertex_obj.add_neighbor_edges(rev_edge_obj)

        # update the edges set
        self._edges.append(edge_obj)

    def get_vertices(self):
        return self._vertices

    def get_edges(self):
        return self._edges

