class Elem:  # linked list element
    def __init__(self, val, next_elem=None):
        self.val = val
        self.next_elem = next_elem


class Node:  # binary tree node
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def node_to_ll(list_ll, node, depth):  # traverse tree using dfs and add nodes to LL
    if node is None:
        return
    last_elem = Elem(node.val, None)
    if depth <= len(list_ll) - 1:
        penultimate_elem = list_ll[depth][1]
        penultimate_elem.next_elem = last_elem
        list_ll[depth][1] = last_elem
    else:
        list_ll += [[last_elem, last_elem]]
    node_to_ll(list_ll, node.left, depth + 1)
    node_to_ll(list_ll, node.right, depth + 1)
    return


def make_ll(root):  # set up recursion. note this is the *tree* root we are given
    first_elem = Elem(root.val, None)  # first *list* element
    list_ll = [[first_elem, first_elem]]  # list of linked lists data structure. keep head and tail for O(n) total runtime
    node_to_ll(list_ll, root.left, 1)
    node_to_ll(list_ll, root.right, 1)
    return list_ll


def make_toy_tree():
    """
        our binary tree:
        10
        5,8
        1,7,_,9
        _,_,_,_,_,_,

        we return the root
    """
    n10 = Node(10)
    n5 = Node(5)
    n8 = Node(8)
    n1 = Node(1)
    n7 = Node(7)
    n9 = Node(9)
    n10.left = n5
    n10.right = n8
    n5.left = n1
    n5.right = n7
    n8.right = n9
    return n10


if __name__ == "__main__":
    my_root = make_toy_tree()
    linked_lists = make_ll(my_root)
    print "binary tree \n10\n5,8\n1,7,_,9\nrepresented by:"
    for ll in linked_lists:
        print "linked list: ",
        elem = ll[0]
        while elem is not None:
            print elem.val,
            elem = elem.next_elem
        print

