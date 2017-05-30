from tree_basics import print_bin_tree


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

if __name__ == "__main__":
    my_list = [8, 9, 10, 11, 12, 13, 14]
    print("Problem 4.2: Making BST from list " + str(my_list))
    root = make_bst(my_list)
    print_bin_tree(root)
