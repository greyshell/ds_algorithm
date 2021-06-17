#!/usr/bin/env python3

# author: greyshell
# description: demo undirected graph adt

import heapq
from graph_adt import WeightedUndirectedGraph
from union_find_adt import UnionFind


class HeapNode:
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

    def __gt__(self, other_obj):
        # compare based on weight
        return self.weight > other_obj.weight

    def __str__(self):
        return f"src_vertex:{self._src_vertex}, dst_vertex: {self._dst_vertex}, weight:{self._weight}"


def mst_kruskal(wug):
    mst = list()  # returns a list of tuple - src_vertex, dst_vertex, weight
    min_heap = list()
    # create uf data structure to check connectivity between two vertices
    vertices = wug.get_vertices()
    uf = UnionFind(vertices)

    # create the min heap
    edges = wug.get_edges()
    for edge_obj in edges:
        src_vertex = edge_obj.get_edge_src()
        dst_vertex = edge_obj.get_edge_dst()
        weight = edge_obj.get_edge_weight()
        heapq.heappush(min_heap, HeapNode(src_vertex, dst_vertex, weight))

    weight_sum = 0
    while min_heap and len(mst) < (len(vertices) - 1):
        edge_obj = heapq.heappop(min_heap)

        src_vertex = edge_obj.src_vertex
        dst_vertex = edge_obj.dst_vertex
        weight = edge_obj.weight

        if uf.is_connected(src_vertex, dst_vertex):
            continue
        uf.union(src_vertex, dst_vertex)
        mst.append((src_vertex, dst_vertex, weight))
        weight_sum = weight_sum + weight

    return mst, weight_sum


def main():
    # ref: Sedgewick Algorithms 4th edition, page 614
    wug = WeightedUndirectedGraph()
    # add vertices
    wug.add_vertex("0")
    wug.add_vertex("1")
    wug.add_vertex("2")
    wug.add_vertex("3")
    wug.add_vertex("4")
    wug.add_vertex("5")
    wug.add_vertex("6")
    wug.add_vertex("7")

    # add edges
    wug.add_edge("0", "7", 0.16)
    wug.add_edge("0", "4", 0.38)
    wug.add_edge("0", "2", 0.26)
    wug.add_edge("1", "5", 0.32)
    wug.add_edge("1", "7", 0.19)
    wug.add_edge("1", "2", 0.36)
    wug.add_edge("1", "3", 0.39)
    wug.add_edge("2", "3", 0.17)
    wug.add_edge("2", "7", 0.34)
    wug.add_edge("3", "6", 0.52)
    wug.add_edge("4", "5", 0.35)
    wug.add_edge("4", "7", 0.37)
    wug.add_edge("5", "7", 0.28)
    wug.add_edge("6", "2", 0.40)
    wug.add_edge("6", "0", 0.58)
    wug.add_edge("6", "4", 0.93)

    mst_edges, weight_sum = mst_kruskal(wug)
    for e in mst_edges:
        print(e)
    print(f"total weight: {weight_sum}")


if __name__ == '__main__':
    main()