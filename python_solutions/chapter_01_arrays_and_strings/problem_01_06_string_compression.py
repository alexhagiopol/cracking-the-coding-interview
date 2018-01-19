"""
Chapter 01 - Problem 06 - String Compression - CTCI 6th Edition page 91

Problem Statement:
Implement a method to perform basic string compression using the counts of repeated characters. For example,
the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the
original string, your method should return the original string. You can assume the string has only uppercase
and lowercase letters (a - z).

Example:
aabcccccaaa -> a2b1c5a3

Solution:
1. The compressed length of a string can be checked in linear time without actually allocating
a new string. Thus, check compressed length by counting the number of identical consecutive characters.

2. If the compressed length of the string is lower than the normal length of the string, allocate a new string
of length equal to the compressed length, and repeat the procedure in (1) with an added step to populate the
new string while the original string is being traversed.

In Python, strings are immutable so the allocation will not happen all at once because individual characters
of a string can't be edited. The compressed string will be initialized with the first character of the uncompressed
string and appended to.

Time complexity: O(N) where N is the length of the shorter string.
Space complexity: O(N).
"""

def compute_compressed_length(string):
    if string is None:
        return 0
    if len(string) == 1:
        return 2
    compressed_length = 1
    num_dupes = 1
    for i in range(1, len(string)):
        if string[i] == string[i - 1]:
            num_dupes += 1
        else:
            compressed_length += (1 + len(str(num_dupes)))  # increase length by 1 letter + number of digits in num_dupes
            num_dupes = 1
    return compressed_length


def string_compression(string):
    if string is None:
        return None
    if len(string) <= compute_compressed_length(string):
        return string
    compressed = string[0]
    num_dupes = 1
    for i in range(1, len(string)):
        if string[i] == string[i-1]:
            num_dupes += 1
        else:
            compressed += str(num_dupes) + string[i]
            num_dupes = 1
    compressed += str(num_dupes)
    return compressed


