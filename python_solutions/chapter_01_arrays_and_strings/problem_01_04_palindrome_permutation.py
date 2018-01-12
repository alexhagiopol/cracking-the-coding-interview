"""
Chapter 01 - Problem 04 - Palindrome Permutation - CTCI 6th Edition page 91

Problem Statement:
Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or
phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does
not need to be limited to just dictionary words.

Example:
"tact coa" -> True (permutations: "tacocat", "atcocta", etc.)

Solution:
Assume only ASCII characters. Assume that capital letters, lower case letters are distinct.
Assume that spaces are ignored i.e. they do not count towards or against "palindromeness".
A palindrome is a string that is the same forwards as it is backwards. Examples are "AAAA", "AABAA", "ABBBA". A
palindrome permutation of even length must have an even number of each character. A palindrome permutation of
odd length must have an even number of each character except for one whose number of appearances will be odd.
Thus we check for evenness of character appearances. We traverse the input string one character at a time
and track the evenness of each character's appearance with a 128 wide bit vector. Each time we observe a character
we flip the bit corresponding to its ASCII value. At the end, if the input string has odd length and the sum of the
bit vector is 1, this string is a palindrome permutation. If the input string has even length and the sum of the bit
vector is 0, this string is a palindrome permutation. In any other case, the string is not a palindrome permutation.

Time complexity: O(N) where N is the length of the string.
Space complexity: O(1) because the bit vector size does not depend on N.
"""


def palindrome_permutation(string):
    if string is None:
        return True
    bit_vector = 128*[False]  # create bit vector whose indices correspond to ASCII values
    num_valid_chars = 0  # count the number of non-space characters
    for char in string:  # traverse string one char at a time
        if 0 <= ord(char) <= 127 and char != ' ':  # if char is a non-space ...
            num_valid_chars += 1
            bit_vector[ord(char)] = not bit_vector[ord(char)]  # flip the bit corresponding to the character
    if num_valid_chars % 2 == 0:  # even length. expect all chars to have even value i.e. False
        return sum(bit_vector) == 0
    return sum(bit_vector) == 1  # odd length. expect all chars except 1 to have even value i.e. False

