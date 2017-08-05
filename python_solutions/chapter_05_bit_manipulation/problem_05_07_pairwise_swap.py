def pairwise_swap(x):
    even_mask_1010 = 0b10101010101010101010101010101010
    odd_mask_0101 = 0b01010101010101010101010101010101
    return (x & even_mask_1010) >> 1 | (x & odd_mask_0101) << 1
