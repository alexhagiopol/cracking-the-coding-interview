"""
Chapter 02 - Problem 08 - Find Loop - CTCI 6th Edition page 95

Problem Stetement:
Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop. 

Example: 
A -> B -> C -> D -> E -> C [the same C as earlier] 
Return C

Solution:
See problem_02_08_explanation.pdf for an in-depth explanation of the solution to this problem.
1. Create two runner pointers, a fast one and a slow one.
2. Advance the pointers simultaneously in a loop, but advance the fast pointer 2 nodes per iterations while
advancing the slow pointer 1 node per iteration.
3. When the pointers meet, stop the loop.
4. Leave the fast pointer at the meeting point, but move the slow pointer to the head of the list.
5. Advance the two pointers simultaneously at the same rate. The node where they meet will be the node at 
the start of the loop.

Time complexity: O(N)
Space complexity: O(1)
"""

def find_loop(head):
    S = head  # fast
    F = head  # slow
    # set up first meeting
    while True:
        # if there is no loop, we will detect it
        if S is None or F is None:
            return None
        # advance slow and fast pointers
        S = S.next_node
        F = F.next_node.next_node
        if S is F:
            break
    # reset S to beginning
    S = head
    # set up second meeting
    while True:
        # advance pointers at same speed
        S = S.next_node
        F = F.next_node
        if S is F:
            break
    return S