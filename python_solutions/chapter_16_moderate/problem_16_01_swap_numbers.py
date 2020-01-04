"""
Write a function to swap a number in place (that is, without temporary variables) .
"""


def swap_numbers(pair_ab):
    if not len(pair_ab) == 2:
        return
    # assume a = 9; b = 5
    pair_ab[0] = pair_ab[1] - pair_ab[0]  # a = -4; b = 5
    pair_ab[1] = pair_ab[1] - pair_ab[0]  # a = -4; b = 9
    pair_ab[0] = pair_ab[1] + pair_ab[0]  # a = 5; b = 9
