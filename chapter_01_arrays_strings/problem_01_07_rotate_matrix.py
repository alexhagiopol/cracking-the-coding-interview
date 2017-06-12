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
