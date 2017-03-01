class Node:
    def __init__(self, left, right, val):
        self.left = left
        self.right = right
        self.val = val


def print_graph(root):
    frontier = [root] #Queue.Queue()
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


def makeBST(array):
    if len(array) < 1:
        return None
    mid_idx = len(array) // 2
    node = Node(makeBST(array[0:mid_idx]), makeBST(array[mid_idx + 1:]), array[mid_idx])
    return node

if __name__ == "__main__":
    array = [8, 9, 10, 11, 12, 13]
    root = makeBST(array)
    print_graph(root)