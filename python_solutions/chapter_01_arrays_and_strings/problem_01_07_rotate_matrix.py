"""
Chapter 01 - Problem 07 - Rotate Matrix - CTCI 6th Edition page 91

Problem Statement:
Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. Can you do this in place?

Example:
[1,2,3,       [7,4,1,
 4,5,6,   ->   8,5,2,
 7,8,9]        9,6,3]

Solution:
We rotate one matrix cell at a time in a counter clockwise pattern to achieve a clockwise rotation.
In Gayle's words: "We perform such a swap on each layer, starting from the outermost layer and working our way
inwards. (Alternatively, we could start from the inner layer and work outwards.)"

Time complexity: O(N^2). One operation per pixel in the image.
Space complexity: O(1). We only need to allocate enough space for one matrix cell.
"""

import math


def rotate_matrix(matrix):
    # assume clockwise rotation
    N, M = matrix.shape
    assert(N == M)  # must be NxN matrix
    for l in range(math.floor(N / 2)):
        for i in range(l, N - 1 - l):
            # from top row to right column
            right_col_temp = matrix[i, - 1 - l]  # save first number from right column
            matrix[i, - 1 - l] = matrix[l, i]

            # from left column to top row
            matrix[l, i] = matrix[N - 1 - i, l]

            # from bottom row to left column
            matrix[N - 1 - i, l] = matrix[-1 - l, N - 1 - i]

            # from right column to bottom row
            matrix[-1 - l, N - 1 - i] = right_col_temp
    return matrix
