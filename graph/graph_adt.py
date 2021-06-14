#!/usr/bin/env python3

# author: greyshell
# description: Graph ADT


class Vertex:

    def __init__(self, vertex_name) -> None:
        self._vertex_name = vertex_name
        # each element in the list is an obj of type Vertex
        self._neighbors_obj = list()  # supports self loop

    def get_vertex_name(self):
        return self._vertex_name

    def add_neighbor_obj(self, neighbor_obj):
        self._neighbors_obj.append(neighbor_obj)

    def get_all_neighbors_obj(self):
        return self._neighbors_obj

    # ===============================================================================
    # auxiliary methods
    # ===============================================================================

    def __str__(self):
        """
        display a vertex
        """
        s = str(self._vertex_name)
        s += ": {"
        for neighbor in self._neighbors_obj:
            s += str(neighbor.get_vertex_name()) + ","

        # when the vertex / node has neighbors, remove the last ',' char
        if s[-1] == ',':
            s = s[:-1]

        s += "}"
        return s


class UndirectedGraph:

    def __init__(self):
        self._vertices = dict()

    def add_vertex(self, vertex_name):
        self._vertices[vertex_name] = Vertex(vertex_name)

    def get_vertex_obj(self, vertex_name):
        # if not found then return False
        return self._vertices.get(vertex_name, False)

    def add_edge(self, src_vertex_name, dst_vertex_name):
        if src_vertex_name not in self._vertices:
            self.add_vertex(src_vertex_name)

        if dst_vertex_name not in self._vertices:
            self.add_vertex(dst_vertex_name)

        self._vertices[src_vertex_name].add_neighbor_obj(self._vertices[dst_vertex_name])
        # add reverse link - undirected graph
        self._vertices[dst_vertex_name].add_neighbor_obj(self._vertices[src_vertex_name])

    # ===============================================================================
    # auxiliary methods
    # ===============================================================================

    def get_all_vertices_obj(self):
        return list(self._vertices.values())

    def get_all_edges_obj(self):
        edges = list()
        for src_vertex_name in self._vertices:  # iterate keys
            src_vertex_obj = self._vertices[src_vertex_name]

            for neighbor_obj in src_vertex_obj.get_all_neighbors_obj():
                edges.append((src_vertex_obj, neighbor_obj))

        return edges

    def get_degree(self, vertex_name):
        """
        time complexity: O(E), where E is the edges of that vertex
        """
        return len(self._vertices[vertex_name].get_all_neighbors_obj())

    def nos_of_self_loops(self):
        count = 0
        for k in self._vertices:
            node = self.get_vertex_obj(k)
            neighbors = node.get_all_neighbors_obj()
            if node in neighbors:  # time: O(1)
                count += 1
        return count
