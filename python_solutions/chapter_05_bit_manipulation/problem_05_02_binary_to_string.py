def binary_to_string(fraction):
    if fraction >= 1 or fraction <= 0:
        return None
    binary_string = '0.'
    i = 0
    while i < 32 and fraction > 0:  # assume our algorithm can only compute the first 32 bits of the fractional value
        if fraction * 2 >= 1:
            binary_string += '1'
            fraction = fraction * 2 - 1
        else:
            binary_string += '0'
            fraction *= 2
        i += 1
    return binary_string
