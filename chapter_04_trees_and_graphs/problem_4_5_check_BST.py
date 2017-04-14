class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def check_BST(node, min, max):
    if node is None:
        return True
    if node.val < min or node.val > max:
        return False
    return check_BST(node.left, min, node.val) and check_BST(node.right, node.val, max)

if __name__ == "__main__":
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    node5 = Node(5)
    node6 = Node(6)
    node8 = Node(8)
    node10 = Node(10)

    node8.left = node4
    node8.right = node10
    node4.left = node2
    node4.right = node6
    node2.left = node1
    node2.right = node3
    node6.left = node5

    print "Is our tree a BST? (expect yes) " + str(check_BST(node8, -1*float('inf'), float('inf')))

    node9 = Node(9)
    node6.right = node9  # add node that breaks BST rule

    print "Is our modified tree a BST? (expect no) " + str(check_BST(node8, -1 * float('inf'), float('inf')))
