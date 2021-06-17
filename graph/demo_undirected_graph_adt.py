#!/usr/bin/env python3

# author: greyshell
# description: demo undirected graph adt

from graph_adt import WeightedUndirectedGraph


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

    # print vertices
    vertices = wug.get_vertices()
    print(f"total vertices: {len(vertices)}")
    for v in vertices:
        print(f"{v}", end="\n")

    # print edges
    edges = wug.get_edges()
    print(f"total edges: {len(edges)}")
    for e in edges:
        print(f"{e.get_edge_src()}, {e.get_edge_dst()}, {e.get_edge_weight()}", end="\n")

    print("\n")
    print(f"inspect a vertex: {wug.get_vertices()['0']}")


if __name__ == '__main__':
    main()
