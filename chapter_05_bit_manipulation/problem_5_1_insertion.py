def printbin(int_num, name):  # prints an integer in binary. useful for debugging.
    print(name, str(bin(int_num))[2:])


def insertion(N, M, i, j):
    right = int('1' * len(N), 2) >> len(N) - i
    left = int('1' * (len(N) - (j + 1)), 2) << j + 1
    mask = right | left
    N_cleared = int(N, 2) & mask
    M_shifted = int(M, 2) << i
    return str(bin(N_cleared | M_shifted))[2:]

