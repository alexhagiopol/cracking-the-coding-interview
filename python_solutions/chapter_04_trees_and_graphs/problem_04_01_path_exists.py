"""
Chapter 04 - Problem 01 - Path Between Nodes

Problem Statement:
Given a directed graph, design an algorithm to find out whether there is a
route between two nodes.

Solution:
Use breadth first search (BFS) or depth first search (DFS) from node 1 to node 2.
If node 2 is found return true. If node 2 is not found, return false. This solution
implements BFS.

Time complexity: O(N)
Space complexity: O(N)
"""


class TetraGraphNode:
    def __init__(self, value, frontier=False, explored=False):
        self.value = value
        self.frontier = frontier
        self.explored = explored


class Graph:
    def __init__(self):
        self.nodes_list = []

    def get_children(self, node):
        return self.nodes_list[node.value - 1][1:]

    def get_node(self, value):
        return self.nodes_list[value - 1][0]


def reset(graph):
    """
    Implements this directed graph
    with an adjacency list:
                    1 -> 2 -> 3
                         |
                         v
                         4 -> 5 -> 6
                         |    ^
                         v    |
                         7 -> 8
    """
    graph.nodes_list = []
    n1 = TetraGraphNode(1, False, False)
    n2 = TetraGraphNode(2, False, False)
    n3 = TetraGraphNode(3, False, False)
    n4 = TetraGraphNode(4, False, False)
    n5 = TetraGraphNode(5, False, False)
    n6 = TetraGraphNode(6, False, False)
    n7 = TetraGraphNode(7, False, False)
    n8 = TetraGraphNode(8, False, False)
    graph.nodes_list += [[n1, n2]]  # adj to n1
    graph.nodes_list += [[n2, n3, n4]]  # adj to n2
    graph.nodes_list += [[n3]]  # adj to n3
    graph.nodes_list += [[n4, n5, n7]]  # adj to n4
    graph.nodes_list += [[n5, n6]]  # adj to n5
    graph.nodes_list += [[n6]]  # adj to n6
    graph.nodes_list += [[n7, n8]]  # adj to n7
    graph.nodes_list += [[n8, n5]]  # adj to n8


def path_exists_BFS(graph, start, end):
    if start is None or end is None:
        return False
    start.frontier = True
    frontier = [start]
    temp_frontier = []
    while len(frontier) > 0:
        for node in frontier:
            if node.value == end.value:
                return True
            for child in graph.get_children(node):
                if not child.frontier and not child.explored:
                    temp_frontier += [child]
                    child.frontier = True
            node.explored = True
        frontier = temp_frontier
        temp_frontier = []
    return False
