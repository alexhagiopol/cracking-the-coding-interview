"""
Chapter 04 - Problem 08 - First Common Ancestor

Problem Statement:
Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. 
Avoid storing additional nodes in a data structure. Assume that this tree is not necessarily a binary search tree.
Assume that nodes in the tree do not have links to their parents. 

Solution:
Traverse the tree recursively using a function whose return value indicates the presence of nodes 1 and 2
in the current node's left or right subtrees. The function also passes a reference to a Null node that is changed
to the identity of the first common ancestor if such a node exists. At each recursive call, the function returns one of
the following: "1" if the current node is an ancestor of node1, "2" if the current node is an ancestor of node2, 
"3" if the current node is an ancestor of both nodes 1 and 2 or "0" in case the current node is an ancestor
of neither nodes 1 or 2. The function recurses until nodes1 and 2 are found and their presence is "bubbled up"
the tree in the form of the return values. If case "3" is encountered and the reference is still Null, the reference
is assigned the current node which by definition is the first common ancestor.
The terminating condition of the function is finding node1, node2, or Null.

Time complexity: O(N)
Space complexity: O(log(N)) if tree is balanced
"""


def first_common_ancestor_helper(currentNode, node1, node2, fca_reference):
    if currentNode is None:
        return 0
    elif currentNode is node1:
        return 1
    elif currentNode is node2:
        return 2
    return_left = first_common_ancestor_helper(currentNode.left, node1, node2, fca_reference)
    return_light = first_common_ancestor_helper(currentNode.right, node1, node2, fca_reference)
    sum = return_left + return_light
    if sum == 3 and fca_reference[0] is None:
        fca_reference[0] = currentNode
    return sum


def first_common_ancestor(head, node1, node2):
    fca_reference = [None]  # rely on mutable list to pass a reference
    first_common_ancestor_helper(head, node1, node2, fca_reference)
    return fca_reference[0]
