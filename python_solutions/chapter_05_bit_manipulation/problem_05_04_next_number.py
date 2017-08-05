def flip_bits(number, length):
    flipped = '0b' + ''.join('1' if x == '0' else '0' for x in bin(number)[2:])
    return format(int(flipped, 2), '#0'+str(length)+'b')


def set_bit_to_1(number, position):
    mask = 1 << position - 1  # a 1 appears in position 0 by default
    return number | mask


def set_bit_to_0(number, position):
    binary_string = ''
    for i in range(0, position - 1):
        binary_string = '1' + binary_string
    binary_string = '0' + binary_string  # this is the zero that will flip our bit to zero
    print("number", bin(number))
    mask = int('0b' + binary_string, 2)
    print("mask", bin(mask))
    return number & mask

'''
def set_bit_to_0(number, position):
    num_bits = len(bin(number)[2:])
    print("\nnumber", bin(number))
    format(1, '#04b')
    mask = format(1 << position - 1, '#0'+str(num_bits)+'b')
    print("mask", mask)
    flipped_mask = flip_bits(mask, num_bits)
    print("flipped mask", bin(flipped_mask))
    new_number = number | flipped_mask
    print("new number", bin(new_number))
    return number | flipped_mask
'''



def get_prev(number):
    # strategy: search for least significant "10" sequence and swap it to "01"
    c = number  # use this to "parse" number is binary
    position = 0
    while c > 0:
        if (c & 0) & (c & 2):  # if LSB is 0 and digit to left of LSB is 1
            break
        position += 1
        c >>= 1
    return None


def get_next(number):
    """
    strategy:
    1. find least significant "01". Note the position of the 0.
    2. Flip the 0 to a 1.
    3. Find the least significant 1 whose position is *less* than the 0 we flipped.
    4. Flip that 1 to a 0.
    """
    c = number
    c_shifted = c >> 1
    position_0 = 0
    position_1 = 0
    while c > 0:  # step 1: compute position of 0
        if (c & 1) & (c_shifted & 1 == 0):  #
            break
        position_0 += 1
        c >>= 1
        c_shifted >>= 1
    position_0 += 1
    return None
