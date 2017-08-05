def conversion(A, B):
    a = A
    b = B
    bits_to_shift = 0
    while a > 0 or b > 0:
        if a & 1 == 1 and b & 1 == 0:
            bits_to_shift += 1
        elif b & 1 == 1 and a & 1 == 0:
            bits_to_shift += 1
        a >>= 1
        b >>= 1
    return bits_to_shift
