"""
Note from textbook:

Regardless of whether or not you use memoization, note that the
number of ways will quickly overflow the bounds of an integer.
By the time you get to just n = 37, the result has already overflowed.
Using a long will delay, but not completely solve, this issue.
"""


def triple_step(n, memo=None):
    if n == 0:
        return 0
    if n == 3:
        return 4
    if n == 2:
        return 2
    if n == 1:
        return 1
    if memo is None:
        memo = [0] * (n + 1)
    if memo[n] == 0:
        memo[n] = triple_step(n - 1) + triple_step(n - 2) + triple_step(n - 3)
    return memo[n]
