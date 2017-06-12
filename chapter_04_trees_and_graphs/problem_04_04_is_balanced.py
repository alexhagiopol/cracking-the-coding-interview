def check_height(root):
    if root is None:
        return [True, 0]
    [left_balanced, left_height] = check_height(root.left)
    [right_balanced, right_height] = check_height(root.right)
    return [left_balanced and right_balanced and abs(left_height - right_height) <= 1, 1 + max(left_height, right_height)]


def is_balanced(root):
    """
    For the purposes of this question, a balanced tree is defined to be a tree
    such that the heights of the two subtrees of any node never differ by more than one.
    """
    return check_height(root)[0]
