"""
Chapter 01 - Problem 08 - Set Zero - CTCI 6th Edition page 91

Problem Statement:
Write an algorithm such that if an element in an MxN matrix is 0, its entire
row and column are set to 0.

Example:
[1, 2, 0, 4,      [0, 0, 0, 0,
 1, 2, 3, 4,  ->   0, 2, 0, 4,
 0, 2, 3, 4]       0, 0, 0, 0]

Solution:
We will implement this with allocating constant additional space. Use two boolean
variables firstZeroRow and firstZeroCol that indicate whether the first row and column
must be zeroed out. Search the first row and column for zeros to determine the value of
these boolean values. Next, use the first row as storage to note which columns must be zeroed.
Use the first column as storage to determine which rows must be zeroed. Set matrix[i][0] and matrix[0][j] to zero
whenever there's a zero in matrix[i][j]. Finally, iterate through the first row and column
to zero out the rows and columns indicated.

Time complexity: O(MxN).
Space complexity: O(1).
"""

def set_zero(matrix):
    # most optimal solution: O(RxC) time and O(1) space
    R, C = matrix.shape
    # determine if first row and column contain zeros
    first_zero_row = False
    first_zero_col = False
    for c in range(C):
        if matrix[0, c] == 0:
            first_zero_row = True
            break
    for r in range(R):
        if matrix[r, 0] == 0:
            first_zero_col = True
            break
    # check the rest of the matrix for zeros and use first row and col to
    # store this information
    for r in range(1, R):
        for c in range(1, C):
            if matrix[r, c] == 0:
                matrix[0, c] = 0
                matrix[r, 0] = 0
    # look at storage and apply zeros to appropriate rows and columns
    for r in range(1, R):
        if matrix[r, 0] == 0:
            matrix[r, :] = 0
    for c in range(1, C):
        if matrix[0, c] == 0:
            matrix[:, c] = 0
    # look at first row and first col booleans to zero out first row and col
    if first_zero_row:
        matrix[0, :] = 0
    if first_zero_col:
        matrix[:, 0] = 0
    return matrix
