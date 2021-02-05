#!/usr/bin/env python3

# author: greyshell
# description: find connected component in an undirected graph

from collections import deque, defaultdict
from graph_adt import Vertex, UndirectedGraph


class ConnectedComponent(UndirectedGraph):

    def __init__(self):
        super().__init__()
        self._component_table = dict()  # key: component id, value: vertex
        self._visited = set()
        self._count = 0

    def _dfs(self, vertex_node):
        vertex = vertex_node.get_key()

        self._visited.add(vertex)
        self._component_table[vertex] = self._count

        for neighbor in vertex_node.get_neighbors():
            if neighbor.get_key() not in self._visited:
                self._dfs(neighbor)

    def compute_connected_component(self):
        for vertex_node in self.get_vertices():
            if vertex_node.get_key() not in self._visited:
                self._dfs(vertex_node)
                self._count += 1

    def is_connected(self, src_v, dst_v):
        if not (self.get_vertex(src_v) or self.get_vertex(dst_v)):
            return False
        return self._component_table.get(src_v) == self._component_table.get(dst_v)

    def get_component_id(self, vertex):
        return self._component_table.get(vertex, False)

    def total_connected_components(self):
        return self._count

    def get_component_table(self):
        comp_table = defaultdict(list)

        for node in self._component_table.keys():
            comp_id = self._component_table.get(node)
            comp_table[comp_id].append(node)
        return comp_table


def main():
    # ref: Sedgewick Algorithms 4th edition, page 544
    cc = ConnectedComponent()
    # add vertices
    for src_vertex in range(0, 13):
        cc.add_vertex(src_vertex)

    # add edges
    cc.add_edge(0, 6)
    cc.add_edge(0, 2)
    cc.add_edge(0, 1)
    cc.add_edge(0, 5)

    cc.add_edge(3, 4)
    cc.add_edge(3, 5)

    cc.add_edge(4, 5)
    cc.add_edge(4, 6)

    cc.add_edge(7, 8)

    cc.add_edge(9, 10)
    cc.add_edge(9, 11)
    cc.add_edge(9, 12)
    cc.add_edge(11, 12)

    cc.compute_connected_component()
    total_cc = cc.total_connected_components()
    print(f"total connected component[s]: {total_cc}")

    src_v = 9
    dst_v = 12
    print(f"is {src_v} connected with {dst_v}: {cc.is_connected(src_v, dst_v)}")

    component_table = cc.get_component_table()
    print(f"{component_table}")


if __name__ == '__main__':
    main()
