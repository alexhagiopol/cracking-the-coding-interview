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


def get_next(positive_integer):
    one_index = 0
    zero_index = 0

    if positive_integer == 0 or positive_integer == np.uint32(0xffffffff):
        return -1

    # find least significant 1
    positive_integer_copy = positive_integer
    while positive_integer_copy != 0 and (positive_integer_copy & 1) != 1:
        one_index = one_index + 1
        positive_integer_copy = positive_integer_copy >> 1

    # find least significant 0 that is to the left of the least significant 1
    positive_integer_copy = positive_integer >> (one_index + 1)
    zero_index = zero_index + one_index + 1
    while positive_integer_copy != 0 and (positive_integer_copy & 1) != 0:
        zero_index = zero_index + 1
        positive_integer_copy = positive_integer_copy >> 1

    # flip the 0 to a 1
    positive_integer = positive_integer | (1 << zero_index)

    # clear all 1s to the right of zero_index
    positive_integer = positive_integer & (np.uint32(0xffffffff) << zero_index)

    # add in zero_index - one_index - 1 number of 1s in the least significant positions
    ones = (1 << (zero_index - one_index - 1)) - 1
    positive_integer = positive_integer | ones
    return positive_integer
