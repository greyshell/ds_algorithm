#!/usr/bin/env python3

# author: greyshell
# description: UnionFind data structure is used to solve dynamic connectivity problems


class QuickFind:
    """
    find() operation is quick but union() operation is expensive
    """

    def __init__(self, vertices):
        """
        time complexity: O(n)
        """
        # initially assume total component is equal to the length of the vertices
        self._components_count = len(vertices)
        self._vertices_lookup = dict()
        # initialize the dict with it's own value
        for vertex_name in vertices:
            self._vertices_lookup[vertex_name] = vertex_name

    def get_components(self):
        """
        get the nos of components
        time complexity: O(1)
        """
        return self._components_count

    def find(self, node):
        """
        identify component for a node
        time complexity: O(1)
        """
        return self._vertices_lookup.get(node, False)

    def connected(self, src_node, dst_node):
        """
        returns true if src_node and dst_node ae in same component
        time complexity: O(1)
        """
        if self.find(src_node) == self.find(dst_node):
            return True
        else:
            return False

    def union(self, src_node, dst_node):
        """
        add connection between src_node and dst_node
        time complexity: O(v)
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
        self._components_count -= 1


class QuickUnion:
    """
    union() operation is quick but find() operation is expensive
    """

    def __init__(self, vertices):
        """
        time complexity: O(n)
        """
        # initially assume total component is equal to the length of the vertices
        self._components_count = len(vertices)
        self._vertices_lookup = dict()
        # initialize the dict with it's own value
        for vertex_name in vertices:
            self._vertices_lookup[vertex_name] = vertex_name

    def get_components(self):
        """
        get the nos of components
        time complexity: O(1)
        """
        return self._components_count

    def find(self, node):
        """
        find the root or parent of a node / vertex
        time complexity: O(n)
        """
        while node != self._vertices_lookup[node]:
            node = self._vertices_lookup[node]
        return node

    def connected(self, src_node, dst_node):
        """
        returns true if src_node and dst_node ae in same component
        time complexity: O(1)
        """
        if self.find(src_node) == self.find(dst_node):
            return True
        else:
            return False

    def union(self, src_node, dst_node):
        """
        add connection between src_node and dst_node
        time complexity: O(1)
        """
        src_node_root = self.find(src_node)
        dst_node_root = self.find(dst_node)
        self._vertices_lookup[dst_node_root] = src_node_root

        self._components_count -= 1


class WeightedQuickUnion:
    """
    improved version QuickUnion with path compression
    - without path compression, find() takes Log(n) time without
    - whereas with path compression it takes liner time (amortized analysis)
    """

    def __init__(self, vertices):
        """
        time complexity: O(n)
        """
        # initially assume total component is equal to the length of the vertices
        self._components_count = len(vertices)
        self._sz = dict()  # holds size of components for roots
        self._vertices_lookup = dict()
        # initialize the dict with it's own value
        for vertex_name in vertices:
            self._vertices_lookup[vertex_name] = vertex_name

        # ste the initial size
        for key in self._vertices_lookup.keys():
            self._sz[key] = 1

    def get_components(self):
        """
        get the nos of components
        time complexity: O(1)
        """
        return self._components_count

    def find(self, node):
        """
        find the root of a node / vertex
        time complexity: with path compression it takes liner time - O(n) -> amortized analysis
        - without path compression improvement it takes O(log(n))
        """
        while node != self._vertices_lookup[node]:
            # path compression improvement: flatten the tree
            grand_parent = self._vertices_lookup[self._vertices_lookup[node]]
            # make every other node in the path point to its grandparent thereby halving the path
            self._vertices_lookup[node] = grand_parent
            node = self._vertices_lookup[node]
        return node

    def connected(self, src_node, dst_node):
        """
        returns true if src_node and dst_node ae in same component
        time complexity: O(1)
        overall time complexity: O(log(n)) for find() method
        """
        if self.find(src_node) == self.find(dst_node):
            return True
        else:
            return False

    def union(self, src_node, dst_node):
        """
        add connection between src_node and dst_node
        time complexity: O(1)
        """
        src_node_root = self.find(src_node)
        dst_node_root = self.find(dst_node)

        if src_node_root == dst_node_root:
            return

        # need to make sure that smaller tree comes below
        if self._sz[src_node_root] < self._sz[dst_node_root]:
            self._vertices_lookup[src_node_root] = dst_node_root
            self._sz[dst_node_root] += self._sz[src_node_root]
        else:
            self._vertices_lookup[dst_node_root] = src_node_root
            self._sz[src_node_root] += self._sz[dst_node_root]

        self._components_count -= 1
