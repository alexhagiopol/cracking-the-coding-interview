from . import tree_basics as tb


def node_to_ll(list_ll, node, depth):  # traverse tree using dfs and add nodes to LL
    if node is None:
        return
    last_elem = tb.LLElem(node.val, None)
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
    first_elem = tb.LLElem(root.val, None)  # first *list* element
    list_ll = [[first_elem, first_elem]]  # list of linked lists data structure. keep head and tail for O(n) total runtime
    node_to_ll(list_ll, root.left, 1)
    node_to_ll(list_ll, root.right, 1)
    return list_ll
