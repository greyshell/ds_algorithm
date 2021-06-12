#!/usr/bin/env python3

# author: greyshell
# description: Graph ADT

from graph_adt import Vertex, UndirectedGraph


def demo_vertex():
    print(f"demo the vertex node")
    a_obj = Vertex("A")
    print(a_obj.__repr__())  # print the obj address
    print(a_obj)  # if __str__() method is available then call that method else print obj address

    # we can't add a neighbor by v.add_neighbor("B")  -> wrong approach
    # coz internal list contains objects of type Vertex
    b_obj = Vertex("B")  # create a vertex object of B
    a_obj.add_neighbor_obj(b_obj)
    a_obj.add_neighbor_obj(Vertex("C"))

    print(a_obj.__repr__())
    print(a_obj)
    print("")


def main():
    # leetcode_input = [["1", "2"], ["3"], ["1", "2", "4"], [], ["3"]]  # mention the start index
    # create a intermediate dict that our graph adt can consume
    # nodes = {str(k): v for k, v in enumerate(leetcode_input, start=1)}

    # ref: Sedgewick Algorithms 4th edition, page 522
    demo_vertex()


if __name__ == '__main__':
    main()
