from tree_basics import BinaryNode
from tree_basics import print_bin_tree


def check_height(root):
    if root is None:
        return [True, 0]
    [left_balanced, left_height] = check_height(root.left)
    [right_balanced, right_height] = check_height(root.right)
    return [left_balanced and right_balanced and abs(left_height - right_height) <= 1, 1 + max(left_height, right_height)]


def is_balanced(root):
    return check_height(root)[0]

if __name__ == "__main__":
    # balanced tree

    node131 = BinaryNode("leaf", None, None)
    node132 = BinaryNode("leaf", None, None)
    node121 = BinaryNode("node", node131, node132)
    node122 = BinaryNode("leaf", None, None)
    node111 = BinaryNode("root", node121, node122)
    print "***************************************"
    print "balanced tree: \n"
    print_bin_tree(node111)
    print "balance check: ",
    print is_balanced(node111)
    print

    # unbalanced tree
    node241 = BinaryNode("leaf", None, None)
    node231 = BinaryNode("node", node241, None)
    node232 = BinaryNode("leaf", None, None)
    node221 = BinaryNode("node", node231, node232)
    node222 = BinaryNode("leaf", None, None)
    node211 = BinaryNode("root", node221, node222)
    print "***************************************"
    print "unbalanced tree: \n"
    print_bin_tree(node211)
    print "balance check: ",
    print is_balanced(node211)
