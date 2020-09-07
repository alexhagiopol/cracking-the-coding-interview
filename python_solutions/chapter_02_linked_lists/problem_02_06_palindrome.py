"""
Chapter 02 - Problem 06 - Palindrome - CTCI 6th Edition page 95

Problem Statement:
Implement a function to check if a linked list is a palindrome.

Example:
Input: 1 -> 3 -> 5 -> 3 -> 1
Output: True

Solution:

A palindrome is a list that is the same forwards as it is backwards. We traverse the input list
once and count its length. We then use this count to create a new list that is the reverse of the first
half of the input list. This is done by traversing the first half of the input list a second time.
We then compare the reversed list with the second half of the input list.

Time complexity: O(N)
Space complexity: O(N)
"""
from . import SinglyLinkedNode as sln


def palindrome(head):
    if head is None:
        return None
    count = 0
    runner = head
    while runner is not None:  # loop to count # of nodes in list
        count += 1
        runner = runner.next_node
    half_count = count // 2  # compute halfway point
    rev_first = sln.SinglyLinkedNode(head.value, None)  # start of list that is the reverse of first half of input list
    runner = head
    for i in range(1, half_count):  # create a list that is reverse of first half of input list
        runner = runner.next_node
        node = sln.SinglyLinkedNode(runner.value, rev_first)
        rev_first = node
    runner = runner.next_node  # advance runner from first half to second half
    if count % 2 != 0:  # odd numbered lists require an extra pointer advancement
        runner = runner.next_node
    runner2 = rev_first
    while runner2 is not None:  # traverse second half of input list simultaneously with reversed list
        if runner2.value != runner.value:  # equality check
            return False
        runner2 = runner2.next_node
        runner = runner.next_node
    return True
