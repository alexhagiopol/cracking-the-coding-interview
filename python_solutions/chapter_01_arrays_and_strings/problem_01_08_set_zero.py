def set_zero(matrix):
    # most optimal solution: O(RxC) time and O(1) space
    R, C = matrix.shape
    # determine with first row and column contain zeros
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
