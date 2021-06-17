#!/usr/bin/env python3

# author: greyshell


class UnionFind:

    def __init__(self, vertices):
        # initially assume total component is equal to the length of the vertices
        self._components = len(vertices)
        self._vertices_lookup = dict()
        # initialize the dict with it's own value
        for vertex_name in vertices:
            self._vertices_lookup[vertex_name] = vertex_name

    def get_components(self):
        """
        get the nos of components
        """
        return self._components

    def find(self, node):
        """
        identify component for a node
        """
        return self._vertices_lookup.get(node, False)

    def is_connected(self, src_node, dst_node):
        """
        returns true if src_node and dst_node ae in same component
        """
        if self.find(src_node) == self.find(dst_node):
            return True
        else:
            return False

    def union(self, src_node, dst_node):
        """
        add connection between src_node and dst_node
        """
        src_node_id = self.find(src_node)
        dst_node_id = self.find(dst_node)

        # nothing to do if both src_node and dst_node are in the same component
        if src_node_id == dst_node_id:
            return

        # change values from
        for vertex_name in self._vertices_lookup:
            if self._vertices_lookup[vertex_name] == src_node_id:
                self._vertices_lookup[vertex_name] = dst_node_id

        # decrease the component count by 1
        self._components -= 1