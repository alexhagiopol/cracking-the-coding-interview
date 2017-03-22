class Node:
    def __init__(self, val, left=None, right=None, parent=None):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent

    def __eq__(self, other):
        if self.val == other.val:
            return True
        return False


def get_next(node):
    if node.right is not None:
        return node.right
    if node.parent is None:
        return None
    if node is node.parent.left:
        return node.parent
    candidate = node
    while candidate != candidate.parent.left:
        candidate = candidate.parent
        if candidate.parent is None:
            return None
        if candidate.parent.left == candidate:
            return candidate.parent


if __name__ == "__main__":
    node2 = Node(2)
    node4 = Node(4)
    node6 = Node(6)
    node8 = Node(8)
    node10 = Node(10)
    node20 = Node(20)

    node2.parent = node4
    node6.parent = node4
    node4.parent = node8
    node20.parent = node10
    node10.parent = node8

    node8.left = node4
    node8.right = node10
    node4.left = node2
    node4.right = node6
    node10.right = node20

    print "Successor to Node 6 is Node " + str(get_next(node6).val)
    print "Successor to Node 4 is Node " + str(get_next(node4).val)
    print "Successor to Node 2 is Node " + str(get_next(node2).val)
    print "Successor to Node 20 is " + str(get_next(node20))
