"""
Chapter 02 - Problem 07 - Intersection - CTCI 6th Edition page 95

Problem Statement:
Given two singly linked lists, determine if the two lists intersect. Return the intersecting node. 
Note that the intersection is defined based on reference, not value. That is, if the kth node of the 
first linked list is the exact same node (by reference) as the jth node of the second linked list, 
then they are intersecting.

Example:
3 -> 1 -> 5 -> 9 -> 7 -> 2 -> 1 
                    ^
                    |
               4 -> 6  

Solution:
Given pointers to the heads of both lists, determine the difference in list length first by advancing
each head pointer to the end of each list and updating the length count of each list at the end of each
pointer advancement operation. Once pointers of both lists have reached the end of each list,
check if the pointers point to the same node in memory: if they do not, this means the lists do not
intersect at all and we return nullptr in C++ or None in Python. Assuming the tails of the lists are the same,
move pointers back to the heads of both lists and advance the pointer of the longer list by the number of
nodes equal to the length difference between the lists. This will make both pointers point to the kth node 
from the end of each list. Now advance both pointers one node at a time until they intersect and return the
node at which the intersection occurs.


Time complexity: O(N)
Space complexity: O(1)
"""

def intersection(head1, head2):
    runner1 = head1
    runner2 = head2
    length1 = length2 = 0
    while runner1 is not None:  # advance pointer 1 to end and compute list size
        runner1 = runner1.next_node
        length1 += 1
    while runner2 is not None:  # advance pointer 2 to end and compute list size
        runner2 = runner2.next_node
        length2 += 1
    if runner2 is not runner1:  # if the lists don't intersect at all
        return None
    diff = length1 - length2  # determine difference between list lengths
    if diff > 0:  # make new pointers for larger and smaller lists
        larger = head1
        smaller = head2
    else:
        larger = head2
        smaller = head1
        diff = diff * -1  # compute absolute value of sizeDiff
    for i in range(diff):  # advance pointer for larger list to be "equal" to smaller list
        larger = larger.next_node
    while larger is not smaller:  # advance pointers simultaneously until they are equal
        larger = larger.next_node
        smaller = smaller.next_node
    return smaller
