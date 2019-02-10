"""
Chapter 04 - Problem 10 - Check Subtree

Problem Statement:
T1 and T2 are two very large binary trees, with T1 much bigger than T2.
Create an algorithm to determine if T2 is a subtree of T1. A tree T2 is a subtree of T1
if there exists a node n in T1 such that the subtree of n is identical to T2. That is,
if you cut off the tree at node n, the two trees would be identical.

Solution:
Traverse T1 recursively in the main function. If during the recursive traversal a node with the same
value as the head of T2 is found in T1, use a helper function to traverse T2 from its head and T1 from
simultaneously to check that every node in each subtree has the same value. If this helper function
returns True, the main function will return True. If the main function reaches the end of T1 without
the helper function having returned True, the main function will return false.

Time complexity: O(N + KM) where K is the number of times the head of T2 appears in T1.
Space complexity: O(log(N) + log(M)) assuming trees are balanced
"""


def subtree_equality(t1, t2):
    if t2 is None and t1 is None:
        return True
    if t1 is None or t2 is None:
        return False
    if t2.val == t1.val:
        return subtree_equality(t1.left, t2.left) and subtree_equality(t1.right, t2.right)
    return False


def check_subtree(t1, t2):
    if t1 is None or t2 is None:
        return False
    if t1.val == t2.val:  # potential subtree
        if subtree_equality(t1, t2):
            return True
    return check_subtree(t1.left, t2) or check_subtree(t1.right, t2)
