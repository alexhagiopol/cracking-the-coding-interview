"""
Chapter 04 - Problem 07 - Build Order

Problem Statement:
You are given a list of projects and a list of dependencies (which is a list of pairs of projects,
where the second project is dependent on the first project). All of a project's dependencies must
be built before the project is. Find a build order that will allow the projects to be built.
If there is no valid build order, return an error.

Solution:
We first represent the projects and build dependencies as vertices and edges in a directed acyclic graph.
We then implement Kahn's algorithm for topological sorting: https://en.wikipedia.org/wiki/Topological_sorting#Algorithms

L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edge
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error   (graph has at least one cycle)
else
    return L   (a topologically sorted order)

Time complexity: O(V + E) where V is the number of vertices in the graph and E is the number of edges.
V can be interpreted as the number of projects and E can be interpreted as the number of dependencies.
Space complexity: O(V)
"""

from queue import Queue


class Node:
    def __init__(self, name):
        self.name = name
        self.in_degree = 0
        self.children = []
        self.parents = []


def build_order(project_list, deps_list):
    build_list = []  # initialize build order list
    nodes_dict = {}
    # convert string representation of project to nodes
    for project_name in project_list:
        nodes_dict[project_name] = Node(project_name)
    # convert string representation of dependencies to edges between nodes
    total_edges = 0
    for dep in deps_list:
        nodes_dict[dep[0]].children.append(nodes_dict[dep[1]])  # parent -> child
        nodes_dict[dep[1]].parents.append(nodes_dict[dep[0]])  # child <- parent
        nodes_dict[dep[1]].in_degree += 1
        total_edges += 1
    # Kahn's algorithm for topological sorting
    q = Queue()
    for name in project_list:  # place every node with 0 in_degree in queue
        node = nodes_dict[name]
        if node.in_degree == 0:
            build_list.append(node.name)
            q.put(node)
    while not q.empty():
        current = q.get()
        for child_node in current.children:
            child_node.in_degree -= 1  # reduce in degree once parent is removed from queue
            total_edges -= 1
            if child_node.in_degree == 0:  # check if in_degree is 0
                build_list.append(child_node.name)
                q.put(child_node)

    if total_edges != 0:  # result of circular dependencies - edges remain in graph after algorithm executes
        return None
    return build_list
