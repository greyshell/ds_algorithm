#!/usr/bin/env python3

# author: greyshell
# reference: grokking algorithm by Aditya Y. Bhargava,
# problem: trading a piano, page 122


class Graph:
    def __init__(self):
        # create the graph
        self._graph = dict()
        # start node: book
        # add book node into the graph
        self._graph["book"] = dict()
        # add connected directed edges as keys and their weights as values
        self._graph["book"]["lp"] = 5
        self._graph["book"]["poster"] = 0

        self._graph["lp"] = dict()
        self._graph["lp"]["guitar"] = 15
        self._graph["lp"]["drum"] = 20

        self._graph["poster"] = dict()
        self._graph["poster"]["guitar"] = 30
        self._graph["poster"]["drum"] = 35

        self._graph["drum"] = dict()
        self._graph["drum"]["piano"] = 10

        self._graph["guitar"] = dict()
        self._graph["guitar"]["guitar"] = 20

        self._graph["piano"] = dict()

        # create and initialize the costs table
        infinity = float("inf")  # define the infinity
        self._costs = dict()
        self._costs["lp"] = 5
        self._costs["poster"] = 0
        self._costs["guitar"] = infinity
        self._costs["drum"] = infinity
        self._costs["piano"] = infinity

        # the parents table
        self._parents = dict()
        self._parents["lp"] = "book"
        self._parents["poster"] = "book"
        self._parents["guitar"] = None
        self._parents["drum"] = None
        self._parents["piano"] = None

        # keep a track for the processed nodes
        self._processed = list()

    def _find_lowest_cost_node(self, costs):
        """
        find the lowest cost of a node
        :param costs:
        :return:
        """
        lowest_cost = float("inf")
        lowest_cost_node = None
        # go through each node.
        for node in self._costs:
            cost = self._costs[node]
            # if it's the lowest cost so far and hasn't been processed yet...
            if cost < lowest_cost and node not in self._processed:
                # ... set it as the new lowest-cost node.
                lowest_cost = cost
                lowest_cost_node = node
        return lowest_cost_node

    def dijkstra_algo(self):
        """
        single source shortest path variant
        :return:
        """
        # find the lowest-cost node that you haven't processed yet
        node = self._find_lowest_cost_node(self._costs)
        # if you've processed all the nodes, this while loop is done.
        while node is not None:
            cost = self._costs[node]
            # go through all the neighbors of this node.
            neighbors = self._graph[node]
            for n in neighbors.keys():
                new_cost = cost + neighbors[n]
                # if it's cheaper to get to this neighbor by going through this node...
                if self._costs[n] > new_cost:
                    # update the cost for this node.
                    self._costs[n] = new_cost
                    # this node becomes the new parent for this neighbor.
                    self._parents[n] = node
            # mark the node as processed.
            self._processed.append(node)
            # find the next node to process, and loop.
            node = self._find_lowest_cost_node(self._costs)

        return self._costs


def main():
    # create the graph
    graph = Graph()
    costs = graph.dijkstra_algo()
    print(f"[+] cost from the start to each node: {costs}")


if __name__ == '__main__':
    main()
