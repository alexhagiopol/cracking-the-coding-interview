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
Create a node representing the head of a new linked list. Traverse the input linked lists one node at a time until
both pointers are None. Append a new node to the output linked list for every sum computed between pairs of nodes.
Add two input nodes and store the sum in the output node. If the sum is > 9, store the carry value in a variable.
If one pointer is nullptr but the other isn't, copy the value of the non-null pointer into the new list.
Add the sum to a node in the new linked list. If a sum is >= 10, carry remainder over to next node. Return
head of new linked list.

Time complexity: O(N)
Space complexity: O(N)
"""

from . import SinglyLinkedNode as sln

def sum_lists(node1, node2):
    carry = 0
    head = None
    runner = None
    while node1 is not None or node2 is not None:  # continue traversing so long as one pointer is not null
        if head is None:  # create head of output linked list
            head = sln.SinglyLinkedNode(0, None)
            runner = head
        else:  # add new node to existing list
            temp = sln.SinglyLinkedNode(0, None)
            runner.next_node = temp
            runner = runner.next_node
        sum = 0
        if node1 is None:  # if head1 is null, use only head2 to compute sum
            assert(node2.value < 10)
            sum = node2.value + carry
            node2 = node2.next_node
        elif node2 is None:  # if head2 is null use only head1 to compute sum
            assert(node1.value < 10)
            sum = node1.value + carry
            node1 = node1.next_node
        else:
            assert(node1.value < 10 and node2.value < 10)
            sum = node1.value + node2.value + carry
            node1 = node1.next_node
            node2 = node2.next_node
        carry = 0
        if sum > 9:  # if sum is too large for 1 digit, carry over to next digit
            carry = sum // 10
            sum = sum - 10
        runner.value = sum
    if carry > 0:
        runner.next_node = sln.SinglyLinkedNode(carry, None)
    return head
