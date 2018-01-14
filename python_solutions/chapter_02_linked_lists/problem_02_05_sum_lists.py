"""
Chapter 02 - Problem 05 - Sum Lists - CTCI 6th Edition page 95

Problem Statement:
You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function
that adds the two numbers and returns the sum as a linked list.

Example:
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: (2 -> 1 -> 9). That is, 912.

Solution:
Traverse both linked lists to determine their lengths. Pad the shorter list with zeros so its length
equals that of the longer list. Create an empty linked list. Traverse both input linked lists simultaneously,
and sum each corresponding node. Add the sum a a node in the new linked list. If a sum is >= 10, carry
remainder over to next node. Return head of new linked list.

Time complexity: O(N)

Space complexity: O(N) (you need to allocate one node for each node you are passed)
"""

from . import LinkedList as ll


def pad_zeros(head, num_zeros):
    if head is None:
        return None
    node = head
    while node.next_node is not None:
        node = node.next_node

    for i in range(num_zeros):
        node.next_node = ll.Node(0, None)
        node = node.next_node


def sum_lists(node1, node2):
    if not node1 or not node2:
        return None

    l1 = ll.list_length(node1)
    l2 = ll.list_length(node2)
    if l1 > l2:
        pad_zeros(node2, l1 - l2)
    elif l2 > l1:
        pad_zeros(node1, l2 - l1)

    current1 = node1
    current2 = node2
    head = ll.Node(0, None)
    tail = head
    while current1 is not None:
        sum = current1.value + current2.value + tail.value
        if sum > 9:
            tail.value = sum - 10
            tail.next_node = ll.Node(1, None)
        else:  # sum <= 9
            tail.value = sum
            tail.next_node = ll.Node(0, None)
        tail = tail.next_node
        current1 = current1.next_node
        current2 = current2.next_node
    return head


