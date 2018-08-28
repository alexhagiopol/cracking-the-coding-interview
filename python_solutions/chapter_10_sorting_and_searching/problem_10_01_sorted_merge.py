"""
Chapter 10 - Problem 01 - Sorted Merge

Problem Statement:
You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B.
Write a method to merge B into A in sorted order.

Solution:
First create 3 runner pointers: one to the last useful element of A, one to the last useful element of B,
and one to the very end of A. Iterate through the elements of A and B in order from back to front, and copy
the greater one to the back of A. Check the address to which the pointers point to ensure that we have not
run out of A or B elements before advancing pointers.

Time complexity: O(N)
Space complexity: O(1) because our lists are mutable in Python, we do not send copies to the function. Thus
the function does not cause more memory allocations that scale with the size of the input
"""

def sorted_merge(A, lastA, B, lastB):
    mergeA = lastA + lastB + 1
