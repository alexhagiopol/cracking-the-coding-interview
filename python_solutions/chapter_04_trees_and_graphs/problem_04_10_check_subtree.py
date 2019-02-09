def check_subtree(t2, t1):
    if t1 is None or t2 is None:
        return False
    if t1.val == t2.val:  # potential subtree
        if subtree_equality(t2, t1):
            return True
    return check_subtree(t2, t1.left) or check_subtree(t2, t1.right)


def subtree_equality(t2, t1):
    if t2 is None and t1 is None:
        return True
    if t1 is None or t2 is None:
        return False
    if t2.val == t1.val:
        return subtree_equality(t2.left, t1.left) and subtree_equality(t2.right, t1.right)
    return False
