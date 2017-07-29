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
    for dep in deps_list:
        nodes_dict[dep[0]].children.append(nodes_dict[dep[1]])  # parent -> child
        nodes_dict[dep[1]].parents.append(nodes_dict[dep[0]])  # child <- parent
        nodes_dict[dep[1]].in_degree += 1
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
            if child_node.in_degree == 0:  # check if in_degree is 0
                build_list.append(child_node.name)
                q.put(child_node)

    if len(build_list) != len(project_list):
        return None
    return build_list

