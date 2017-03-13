class Node:
    def __init__(self, value, frontier=False, explored=False):
        self.value = value
        self.frontier = frontier
        self.explored = explored


class Graph:
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
    def __init__(self):
        self.nodes_list = []

    def reset(self):
        self.nodes_list = []
        n1 = Node(1, False, False)
        n2 = Node(2, False, False)
        n3 = Node(3, False, False)
        n4 = Node(4, False, False)
        n5 = Node(5, False, False)
        n6 = Node(6, False, False)
        n7 = Node(7, False, False)
        n8 = Node(8, False, False)
        self.nodes_list += [[n1, n2]]  # adj to n1
        self.nodes_list += [[n2, n3, n4]]  # adj to n2
        self.nodes_list += [[n3]]  # adj to n3
        self.nodes_list += [[n4, n5, n7]]  # adj to n4
        self.nodes_list += [[n5, n6]]  # adj to n5
        self.nodes_list += [[n6]]  # adj to n6
        self.nodes_list += [[n7, n8]]  # adj to n7
        self.nodes_list += [[n8, n5]]  # adj to n8

    def get_children(self, node):
        return self.nodes_list[node.value - 1][1:]

    def get_node(self, value):
        return self.nodes_list[value - 1][0]


def path_exists(graph, start, end):
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


if __name__ == "__main__":
    my_graph = Graph()
    my_graph.reset()
    print "Is there a path between nodes 7 and 5?"
    print path_exists(my_graph, my_graph.get_node(7), my_graph.get_node(5)) or path_exists(my_graph, my_graph.get_node(5), my_graph.get_node(7))
    my_graph.reset()
    print "Is there a path between nodes 8 and 3?"
    print path_exists(my_graph, my_graph.get_node(3), my_graph.get_node(8)) or path_exists(my_graph, my_graph.get_node(8), my_graph.get_node(3))
    my_graph.reset()
    print "Is there a path between nodes 1 and 8?"
    print path_exists(my_graph, my_graph.get_node(1), my_graph.get_node(8)) or path_exists(my_graph, my_graph.get_node(8), my_graph.get_node(1))
    my_graph.reset()
