#!/usr/bin/env python3

# author: greyshell
# description: Graph ADT


class WeightedEdge:

    def __init__(self, src_vertex, dst_vertex, weight):
        self.src_vertex = src_vertex
        self.dst_vertex = dst_vertex
        self.weight = weight

    def __eq__(self, other_obj):
        # compare based on weight
        return self.weight == other_obj.weight

    def __lt__(self, other_obj):
        # compare based on weight
        return self.weight < other_obj.weight

    def __str__(self):
        edge = list()
        edge.append(self.src_vertex)
        edge.append(self.dst_vertex)
        edge.append(self.weight)
        return str(edge)


class Vertex:

    def __init__(self, vertex):
        self.vertex_name = vertex
        self.neighbor_edges_obj = list()  # list is used to support self loop

    def add_neighbor_edge_obj(self, edge_obj):
        self.neighbor_edges_obj.append(edge_obj)

    def __str__(self):
        vertex_name = str(self.vertex_name)
        edges = list()
        for edge_obj in self.neighbor_edges_obj:
            neighbor = edge_obj.dst_vertex
            edges.append(str(neighbor))
        node = {vertex_name: edges}
        return str(node)


class WeightedUndirectedGraph:

    def __init__(self):
        self.vertices = dict()

    def add_vertex(self, vertex):
        self.vertices[vertex] = Vertex(vertex)

    def get_vertex_obj(self, vertex):
        return self.vertices.get(vertex, False)

    def get_all_vertices(self):
        # self.vertices.keys returns <class 'dict_keys'> thus converting that to list
        return list(self.vertices.keys())

    def add_edge(self, src_vertex, dst_vertex, weight=0):
        if src_vertex not in self.vertices:
            self.add_vertex(src_vertex)

        if dst_vertex not in self.vertices:
            self.add_vertex(dst_vertex)

        src_vertex_obj = self.vertices[src_vertex]
        dst_vertex_obj = self.vertices[dst_vertex]

        src_vertex_obj.add_neighbor_edge_obj(WeightedEdge(src_vertex, dst_vertex, weight))
        # undirected graph -> add a backward edge
        dst_vertex_obj.add_neighbor_edge_obj(WeightedEdge(dst_vertex, src_vertex, weight))

    def get_all_edges(self):
        """
        time complexity: O(V + E)
        :return: list[list]
        """
        total_edges = list()
        for vertex_obj in self.vertices.values():
            for edge_obj in vertex_obj.neighbor_edges_obj:
                src_vertex = edge_obj.src_vertex
                dst_vertex = edge_obj.dst_vertex
                weight = edge_obj.weight

                # prepare backward edge
                backward_edge = [dst_vertex, src_vertex, weight]
                if backward_edge not in total_edges:
                    total_edges.append([src_vertex, dst_vertex, weight])
        return total_edges

    def __str__(self):
        g = list()
        for vertex_obj in self.vertices.values():
            g.append(vertex_obj.__str__())
        return str(g)
