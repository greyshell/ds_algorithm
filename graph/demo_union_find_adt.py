#!/usr/bin/env python3

# author: greyshell

from union_find_adt import UnionFind


def main():
    # robert sedgewick page: 221
    edges = ((4, 3), (3, 8), (6, 5), (9, 4), (2, 1), (5, 0), (7, 2), (6, 1))
    vertices = [n for n in range(0, 10)]

    uf = UnionFind(vertices)
    for edge in edges:
        if uf.is_connected(edge[0], edge[1]):
            continue
        uf.union(edge[0], edge[1])
        print(f"{edge[0]}, {edge[1]}")

    print(f"components: {uf.get_components()}")


if __name__ == '__main__':
    main()
