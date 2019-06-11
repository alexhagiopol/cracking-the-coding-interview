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
    # iterate through arrays A and B from back to front performing the merge operation along the way
    while lastB >= 0:  # note that you don't need to copy the contents of A after running out of elements of B. they are already correct.
        if A[lastA] > B[lastB] and lastA >= 0:  # do not allow copying from A if we have run out of A values
            A[mergeA] = A[lastA]
            lastA -= 1
        else:
            A[mergeA] = B[lastB]
            lastB -= 1
        mergeA -= 1
