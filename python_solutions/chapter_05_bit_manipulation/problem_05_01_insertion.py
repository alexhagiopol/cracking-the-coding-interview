def printbin(int_num, name):  # prints an integer in binary. useful for debugging.
    print(name, str(bin(int_num))[2:])


def insertion(N, M, i, j):
    """
    example input: N = 10000000000, M = 10011, i = 2, j = 6
    example output:    10001001100
    """
    M_shifted = M << i
    right_mask = (1 << i) - 1  # produces 0...011
    left_mask = -1 << j + 1  # produces 1...1000000
    full_mask = right_mask | left_mask
    N_cleared = N & full_mask
    return N_cleared | M_shifted

