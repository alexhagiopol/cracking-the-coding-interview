"""
For this problem, I use lists of single character strings to represent binary numbers because
Python has issues manipulating bits in the ways needed to solve this problem.
For example, Python automatically removes "redundant" leading zeros from a binary number. This makes it
difficult to flip all zeros in a binary number to get a desired number of ones. The workarounds
required to solve this problem using "native" binary numbers are - in my view - as ugly or uglier than using
lists of single character strings.

If you have a beautiful Python solution for this problem, please PR it. - Alex
"""


def get_prev(binary_list):
    """
    strategy:
    0. if all zeros or all ones, return none.
    1. find least significant "10". Note the position of the 1.
    2. Flip the 1 to a 0.
    3. Flip the 0 to a 1.
    """
    if all(x == binary_list[0] for x in binary_list):  # step 0
        return -1

    zero_index = -1
    one_index = -1
    for index in range(len(binary_list) - 1, 0, -1):  # step 1. traverse list starting with least significant bit
        if binary_list[index] == '0' and binary_list[index - 1] == '1':
            one_index = index - 1
            zero_index = index
            break
    if one_index == -1:
        return -1
    binary_list[one_index] = '0'  # step 2
    binary_list[zero_index] = '1'  # step 4
    return binary_list


def get_next(binary_list):
    """
    strategy:
    0. If the number is all ones e.g. [1111] insert a zero in the second most significant place e.g. [10111]
    1. Find least significant "1". Note the position of the 0.
    2. Flip the 0 to a 1.
    3. Find the least significant 1 whose position is *less significant* than the 0 we flipped.
    4. Flip that 1 to a 0.
    """
    if all(x == '1' for x in binary_list):  # step 0
        return ['1', '0'] + binary_list[1:]

    zero_index = -1
    for index in range(len(binary_list) - 1, 0, -1):  # step 1. traverse list starting with least significant bit
        if binary_list[index] == '1' and binary_list[index - 1] == '0':
            zero_index = index - 1
            break
    if zero_index == -1:
        return -1

    one_index = -1
    for index in range(len(binary_list) - 1, 0, -1):  # step 3.
        if binary_list[index] == '1':
            one_index = index
            break
    if one_index == -1:
        return -1
    if one_index <= zero_index:
        return -1

    binary_list[zero_index] = '1'  # step 2
    binary_list[one_index] = '0'  # step 4
    return binary_list
