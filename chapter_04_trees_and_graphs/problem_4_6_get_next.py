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


def get_leftmost(node):
    while node.left is not None:
        node = node.left
    return node


def get_next(node):
    if node.right is not None:
        return get_leftmost(node.right)
    if node.parent is None:
        return None
    while node != node.parent.left:
        node = node.parent
        if node.parent is None:
            return None
        if node.parent.left == node:
            return node.parent
    return node.parent


if __name__ == "__main__":
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    node5 = Node(5)
    node6 = Node(6)
    node8 = Node(8)
    node10 = Node(10)

    node1.parent = node2
    node3.parent = node2
    node2.parent = node4
    node5.parent = node6
    node6.parent = node4
    node4.parent = node8
    node10.parent = node8

    node8.left = node4
    node8.right = node10
    node4.left = node2
    node4.right = node6
    node2.left = node1
    node2.right = node3
    node6.left = node5

    print "Node " + str(get_next(node6).val) + " is the successor to Node " + str(node6.val)
    print "Node " + str(get_next(node4).val) + " is the successor to Node " + str(node4.val)
    print "Node " + str(get_next(node2).val) + " is the successor to Node " + str(node2.val)
    print "Node " + str(get_next(node10)) + " is the successor to Node " + str(node10.val)
