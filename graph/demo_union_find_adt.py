#!/usr/bin/env python3

# author: greyshell

from union_find_adt import QuickFind, QuickUnion, WeightedQuickUnion


def main():
    # robert sedgewick page: 221
    vertices = [str(n) for n in range(0, 10)]
    edges = (("4", "3"),
             ("3", "8"),
             ("6", "5"),
             ("9", "4"),
             ("2", "1"),
             ("5", "0"),
             ("7", "2"),
             ("6", "1")
             )

    print("\ndemo QuickFind")
    uf = QuickFind(vertices)
    for edge in edges:
        if uf.connected(edge[0], edge[1]):
            continue
        uf.union(edge[0], edge[1])

    print(f"is 0 connected with 6: {uf.connected('0', '6')}")
    print(f"is 0 connected with 8: {uf.connected('0', '8')}")
    print(f"total components: {uf.get_components()}")
    # lookup dict final state
    # for k, v in uf._vertices_lookup.items():
    #     print(f"{k} => {v}")

    print("\ndemo QuickUnion")
    uf2 = QuickUnion(vertices)
    for edge in edges:
        if uf2.connected(edge[0], edge[1]):
            continue
        uf2.union(edge[0], edge[1])

    print(f"is 0 connected with 6: {uf2.connected('0', '6')}")
    print(f"is 0 connected with 8: {uf2.connected('0', '8')}")
    print(f"total components: {uf2.get_components()}")

    print("\ndemo WeightedQuickUnion")
    uf3 = WeightedQuickUnion(vertices)
    for edge in edges:
        if uf3.connected(edge[0], edge[1]):
            continue
        uf3.union(edge[0], edge[1])

    print(f"is 0 connected with 6: {uf3.connected('0', '6')}")
    print(f"is 0 connected with 8: {uf3.connected('0', '8')}")
    print(f"total components: {uf3.get_components()}")


if __name__ == '__main__':
    main()
