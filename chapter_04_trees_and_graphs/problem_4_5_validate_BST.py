def validate_BST_helper(node, min, max):
    if node is None:
        return True
    if node.val < min or node.val > max:
        return False
    return validate_BST_helper(node.left, min, node.val) and validate_BST_helper(node.right, node.val, max)


def validate_BST(node):
    return validate_BST_helper(node, -1*float('inf'), float('inf'))
