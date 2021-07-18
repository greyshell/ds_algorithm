#!/usr/bin/env python3

# author: greyshell
# description: prims algorithm (lazy approach) to find the mst of an undirected weighted graph (connected, no cycle)

import heapq
from graph_adt import WeightedUndirectedGraph


def mark_node(vertex_obj, min_heap, visited):
    visited.add(vertex_obj.vertex_name)
    for edge_obj in vertex_obj.neighbor_edges_obj:
        dst_vertex = edge_obj.dst_vertex
        if dst_vertex not in visited:
            heapq.heappush(min_heap, edge_obj)


def mst_prims(wug):
    """
    lazy approach
    time complexity: E log E -> to push and pop each node
    space complexity: E -> to maintain a min heap
    """
    mst = list()  # returns minimum list of edges

    vertices = wug.get_all_vertices()
    start_vertex_obj = wug.get_vertex_obj(vertices[0])

    # create a min heap where each element is a weighted edge obj
    min_heap = list()
    visited = set()

    mark_node(start_vertex_obj, min_heap, visited)

    weight_sum = 0
    while min_heap:
        edge_obj = heapq.heappop(min_heap)

        # extract the attributes from the object
        src_vertex = edge_obj.src_vertex
        dst_vertex = edge_obj.dst_vertex
        weight = edge_obj.weight

        if src_vertex in visited and dst_vertex in visited:
            continue

        mst.append(edge_obj.__str__())
        weight_sum = weight_sum + weight

        if src_vertex not in visited:
            mark_node(wug.get_vertex_obj(src_vertex), min_heap, visited)

        if dst_vertex not in visited:
            mark_node(wug.get_vertex_obj(dst_vertex), min_heap, visited)

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

    mst_edges, weight_sum = mst_prims(wug)
    print(f"minimum weight edges in mst:")
    for e in mst_edges:
        print(e)

    print("")
    print(f"total weight: {weight_sum}")


if __name__ == '__main__':
    main()
