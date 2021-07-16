#!/usr/bin/env python3

# author: greyshell
# description: kruskal algorithm to find the mst of an undirected weighted graph

import heapq
from union_find_adt import *
from graph_adt import WeightedUndirectedGraph


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

    def __str__(self):
        return f"src_vertex:{self.src_vertex}, dst_vertex: {self.dst_vertex}, weight:{self.weight}"


def mst_kruskal(wug):
    """
    time complexity: E log E -> to push and pop each node
    space complexity: E -> to maintain a min heap
    """
    mst = list()  # returns this final list of tuple - (_src_vertex, _dst_vertex, _weight) that has all minimum edges

    # create a union find object to check the connectivity between two vertices in O(1) time
    vertices = wug.get_all_vertices()
    # uf = QuickFind(vertices)
    # uf = QuickUnion(vertices)
    uf = WeightedQuickUnion(vertices)

    # create a custom min heap where each element is a weighted edge obj
    min_heap = list()
    edges = wug.get_all_edges()
    for e in edges:
        src_vertex = e[0]
        dst_vertex = e[1]
        weight = e[2]
        weighted_edge_obj = HeapNode(src_vertex, dst_vertex, weight)
        heapq.heappush(min_heap, weighted_edge_obj)  # O(log E)

    weight_sum = 0
    while min_heap and len(mst) < (len(vertices) - 1):
        edge_obj = heapq.heappop(min_heap)

        # extract the attributes from the object
        src_vertex = edge_obj.src_vertex
        dst_vertex = edge_obj.dst_vertex
        weight = edge_obj.weight

        if uf.connected(src_vertex, dst_vertex):  # O(log(n)) for WeightedQuickUnion
            continue
        uf.union(src_vertex, dst_vertex)  # O(1) for WeightedQuickUnion
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
    print(f"minimum weight edges in mst:")
    for e in mst_edges:
        print(e)

    print("")
    print(f"total weight: {weight_sum}")


if __name__ == '__main__':
    main()
