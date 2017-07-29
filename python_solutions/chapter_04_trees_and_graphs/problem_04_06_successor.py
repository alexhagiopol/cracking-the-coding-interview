def get_leftmost(node):
    while node.left is not None:
        node = node.left
    return node


def successor(node):
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
