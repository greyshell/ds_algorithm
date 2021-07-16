#!/usr/bin/env python3

# author: greyshell
# description: Graph ADT


class _WeightedEdge:

    def __init__(self, dst_vertex, weight):
        self.dst_vertex = dst_vertex
        self.weight = weight


class _Vertex:

    def __init__(self, vertex):
        self.vertex = vertex
        self.neighbor_edges = list()  # list is used to support self loop

    def add_neighbor_edge(self, edge_obj):
        self.neighbor_edges.append(edge_obj)

    def get_neighbor_edges(self):
        neighbor_edges = list()
        for edge_obj in self.neighbor_edges:
            neighbor_edges.append(edge_obj)
        return neighbor_edges

    def __str__(self):
        # display a vertex object
        s = str(self.vertex)
        s += ": {"
        for edge_obj in self.neighbor_edges:
            neighbor = edge_obj.dst_vertex
            s += str(neighbor) + ","

        # when the vertex / node has neighbors, remove the last ',' char
        if s[-1] == ',':
            s = s[:-1]

        s += "}"
        return s


class WeightedUndirectedGraph:

    def __init__(self):
        self.vertices = dict()

    def add_vertex(self, vertex):
        self.vertices[vertex] = _Vertex(vertex)

    def get_vertex(self, vertex):
        return self.vertices.get(vertex, False)

    def get_all_vertices(self):
        return self.vertices.keys()

    def add_edge(self, src_vertex, dst_vertex, weight=0):
        if src_vertex not in self.vertices:
            self.add_vertex(src_vertex)

        if dst_vertex not in self.vertices:
            self.add_vertex(dst_vertex)

        src_vertex_obj = self.vertices[src_vertex]
        dst_vertex_obj = self.vertices[dst_vertex]

        src_vertex_obj.add_neighbor_edge(_WeightedEdge(dst_vertex, weight))
        # add a reverse link for undirected graph
        dst_vertex_obj.add_neighbor_edge(_WeightedEdge(src_vertex, weight))

    def get_all_edges(self):
        """
        time: O(V + E)
        """
        total_edges = list()
        for vertex_obj in self.vertices.values():
            src_vertex = vertex_obj.vertex
            for edge_obj in vertex_obj.neighbor_edges:
                dst_vertex = edge_obj.dst_vertex
                weight = edge_obj.weight

                # prepare backward edge
                backward_edge = (dst_vertex, src_vertex, weight)
                if backward_edge not in total_edges:
                    total_edges.append((src_vertex, dst_vertex, weight))

        return total_edges
