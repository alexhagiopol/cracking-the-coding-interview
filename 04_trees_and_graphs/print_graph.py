# useful functions for printing out graphs for debugging


def print_bin_tree(root):
    """print out binary tree given its root"""
    frontier = [root]
    next_frontier = []
    while len(frontier) > 0:
        for node in frontier:
            if node is not None:
                print node.val,
                next_frontier += [node.left, node.right]
            else:
                print '_',
        print
        frontier = next_frontier
        next_frontier = []
