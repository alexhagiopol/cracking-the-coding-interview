"""
Chapter 04 - Problem 02 - Minimal Tree

Problem Statement:
Given a sorted (increasing order) array
with unique integer elements, write an algorithm
to create a binary search tree with minimal height.

Solution:
To create a minimal height BST, the input array must be traversed
according to the binary search algorithm. At each recursion of the
algorithm, we add the current array element's value to a BST node,
then divide the input array as closely to 50%/50% as possible before
recursing on each half for the left and right BST child nodes.

Time complexity: O(log(N))
Space complexity: O(log(N))
"""


class Node:
    def __init__(self, left, right, val):
        self.left = left
        self.right = right
        self.val = val


def make_bst(sorted_list):
    if len(sorted_list) < 1:
        return None
    mid_idx = (len(sorted_list) - 1) // 2
    node = Node(make_bst(sorted_list[0:mid_idx]), make_bst(sorted_list[mid_idx + 1:]), sorted_list[mid_idx])
    return node
