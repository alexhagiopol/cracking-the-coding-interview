"""
Chapter 04 - Problem 04 - Check Balanced

Problem Statement:
Implement a function to check if a binary tree is balanced.
For the purposes of this question, a balanced tree is defined to be a tree
such that the heights of the two subtrees of any node never differ by more than one.


Solution:
Implement a recursion-based solution in which a recursive checkBalanced() is called on
every node. At each recursive call, the function returns (1) the number of child nodes beneath
it and (2) boolean if the numbers returned by its left and right children differ by more than 1. The recursive
terminating condition is a node which does not have any children: in this case the node returns 0 and true.

Time complexity: O(N)
Space complexity: O(H) where H is the height of the tree
"""


def check_height(root):
    if root is None:
        return [True, 0]
    [left_balanced, left_height] = check_height(root.left)
    [right_balanced, right_height] = check_height(root.right)
    return [left_balanced and right_balanced and abs(left_height - right_height) <= 1, 1 + max(left_height, right_height)]


def check_balanced(root):
    return check_height(root)[0]
