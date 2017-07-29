class Node:
    def __init__(self, left, right, val):
        self.left = left
        self.right = right
        self.val = val


def make_bst(sorted_list):
    if len(sorted_list) < 1:
        return None
    mid_idx = len(sorted_list) // 2
    node = Node(make_bst(sorted_list[0:mid_idx]), make_bst(sorted_list[mid_idx + 1:]), sorted_list[mid_idx])
    return node
