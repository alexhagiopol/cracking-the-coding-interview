def rotate_matrix(matrix):
    # assume clockwise rotation
    N, M = matrix.shape
    assert(N == M)  # must be NxN matrix
    for i in range(N - 1):
        # from top row to right column
        right_col_temp = matrix[i, -1]  # save first number from right column
        matrix[i, -1] = matrix[0, i]

        # from left column to top row
        matrix[0, i] = matrix[N - 1 - i, 0]

        # from bottom row to left column
        matrix[N - 1 - i, 0] = matrix[-1, N - 1 - i]

        # from right column to bottom row
        matrix[-1, N - 1 - i] = right_col_temp

    if N > 3:
        matrix[1:-1, 1:-1] = rotate_matrix(matrix[1:-1, 1:-1])
    return matrix
