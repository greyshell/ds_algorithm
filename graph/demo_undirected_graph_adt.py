#!/usr/bin/env python3

# author: greyshell
# description: demo undirected graph adt

from graph_adt import Vertex, UndirectedGraph


def demo_undirected_graph():
    # leetcode_input = [["1", "2"], ["3"], ["1", "2", "4"], [], ["3"]]  # mention the start index
    # create a intermediate dict that our graph adt can consume
    # nodes = {str(k): v for k, v in enumerate(leetcode_input, start=1)}

    # ref: Sedgewick Algorithms 4th edition, page 522
    nodes = {
        "0": ["1", "2", "5", "6"],
        "1": [],
        "2": [],
        "3": ["4", "5"],
        "4": ["6"],
        "5": [],
        "6": [],
        "7": ["8"],
        "8": [],
        "9": ["10", "11", "12"],
        "10": [],
        "11": ["12"],
        "12": []
    }

    print("demo undirected graph")
    undirected_graph = UndirectedGraph()
    # # add vertices
    # for src_vertex in nodes:
    #     undirected_graph.add_vertex(src_vertex)
    # # add edges
    # for src_vertex in nodes:
    #     dst_vertices = nodes[src_vertex]
    #     for dst_vertex in dst_vertices:
    #         undirected_graph.add_edge(src_vertex, dst_vertex)

    undirected_graph.add_vertex("san jose")
    undirected_graph.add_vertex("kolkata")
    undirected_graph.add_vertex("bangalore")

    undirected_graph.add_edge("kolkata", "hyd")

    # print vertices
    print(f"vertices:")
    vertices = undirected_graph.get_all_vertices_obj()
    for v in vertices:
        print(f"{v.get_vertex_name()}", end=", ")

    # print edges
    print("\n")
    print(f"edges:")
    edges = undirected_graph.get_all_edges_obj()
    for e in edges:
        print(f"({e[0].get_vertex_name()}, {e[1].get_vertex_name()})", end=", ")

    # get the degree of each vertices
    print("\n")
    for v in undirected_graph.get_all_vertices_obj():
        # for undirected graph, total degree is equal to in_degree or out_degree
        vertex_name = v.get_vertex_name()
        degree = undirected_graph.get_degree(vertex_name)
        print(f"degree of {vertex_name}: {degree}")

    print("")
    self_loops = undirected_graph.nos_of_self_loops()
    print(f"nos of self loops: {self_loops}")


def main():
    # leetcode_input = [["1", "2"], ["3"], ["1", "2", "4"], [], ["3"]]  # mention the start index
    # create a intermediate dict that our graph adt can consume
    # nodes = {str(k): v for k, v in enumerate(leetcode_input, start=1)}

    # ref: Sedgewick Algorithms 4th edition, page 522
    demo_undirected_graph()


if __name__ == '__main__':
    main()
