"""
Chapter 02 - Problem 02 - return kth to last - CTCI 6th Edition
Problem Statement:
Implement an algorithm to find K'th to last element of a singly linked list.
Note : Size of linked list is not known

"""
def return_kth_to_last(head, k):
    if k <= 0:
        return None
    slow = head
    fast = head
    for i in range(k):
        if fast is None and i < k - 1:
            return None
        fast = fast.next_node
    while fast is not None:
        slow = slow.next_node
        fast = fast.next_node
    return slow
