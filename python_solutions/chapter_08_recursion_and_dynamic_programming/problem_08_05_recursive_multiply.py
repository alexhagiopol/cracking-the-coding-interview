def recursive_multiply(a, b):
    A = max(a, b)
    B = min(a, b)
    return helper_recursive_multiply(A, B)


def helper_recursive_multiply(a, b):
    if b == 1:
        return a
    if b == 0:
        return 0
    half_b = int(b >> 1)
    if b > half_b + half_b:  # odd b. shifting with truncation eliminates a 1
        return a + helper_recursive_multiply(a << 1, half_b)  # odd case
    else:
        return helper_recursive_multiply(a << 1, half_b)  # even case
