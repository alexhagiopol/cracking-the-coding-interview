"""
PROBLEM:
Given a positive integer, return the next smallest and next largest
numbers that have the same number of 1s in their binary representations.

TEST CASES:
getPrev(0b0000) -> -1
getNext(0b0000) -> -1
getPrev(0b1000) -> 0b0100
getNext(0b1000) -> 0b10000
getPrev(0b0001) -> -1
getNext(0b0001) -> 0b0010
getPrev(0b0101) -> 0b0011
getNext(0b0101) -> 0b0110

ALGORITHM:
getNext():
1. Use bit shifting to find the least significant 1.
2. Use bit shifting to find the least significant 0 *to the left of* the least significant 1
3. Flip the 0 position to 1.
4. Clear all 1s to the right of the flipped bit.
5. Add in zeroIndex - oneIndex - 1 ones in the *least significant* positions that have been cleared out

getPrev():
1. Use bit shifting to find least significant 0.
2. Use bit shifting to find least significant 1 *to the left of* the least significant 0.
3. Flip the 1 position to 0.
4. Clear all 1s to the right of the flipped bit.
5. Add in zeroIndex + 1 ones in the *most significant* positions that have been cleared out.

SPACE & TIME:
Space: O(b) - we need to allocate masks the same size as the input
Time: O(b) - we need to iterate through the binary representation bit by bit

CODE:
"""
import numpy as np


def get_prev(positive_integer):
    one_index = 0
    zero_index = 0

    if positive_integer == 0 or positive_integer >= np.uint32(0xffffffff):
        return -1

    positive_integer_copy = positive_integer
    # find the least significant zero
    while positive_integer_copy != 0 and (positive_integer_copy & 1) != 0:
        zero_index = zero_index + 1
        positive_integer_copy = positive_integer_copy >> 1

    # find the least significant one that is to the left of the least significant zero
    positive_integer_copy = positive_integer >> (zero_index + 1)
    if positive_integer_copy == 0:  # check for 0b0...001111 edge case
        return -1
    one_index = zero_index + 1  # account for the right shift before computing one index
    while positive_integer_copy != 0 and (positive_integer_copy & 1) != 1:
        one_index = one_index + 1
        positive_integer_copy = positive_integer_copy >> 1

    # flip the 1 to a 0
    positive_integer = positive_integer & (~(1 << one_index))

    # clear all 1s to the right of one_index
    positive_integer = positive_integer & (np.uint32(0xffffffff) << one_index)

    # add in zero_index + 1 number of ones in most significant positions to the right of one_index
    ones = (1 << (zero_index + 1)) - 1
    ones = ones << (one_index - zero_index - 1)
    positive_integer = positive_integer | ones
    return positive_integer


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
