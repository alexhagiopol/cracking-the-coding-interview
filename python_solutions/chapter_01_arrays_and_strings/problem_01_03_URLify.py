"""
Chapter 01 - Problem 03 - URLify - CTCI 6th Edition page 90

Problem Statement:
Write a method to replace all spaces in a string with '%20: You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the
"true" length of the string.

Example:
'Mr. John Smith' -> 'Mr.%20John%20Smith%20'

Solution:
Because strings are immutable in Python, in this problem we will represent strings as lists of single
characters (e.g. ['A','l','e','x']) so that we can modify one character at a time at a given index. We will do this problem
as close to "in place" as possible i.e. we will not allocate more space than is necessary to add the "%20" characters.
First, we traverse the input string and count the number of spaces. We know that each single space in the input
string is replaced with three characters in the output. With this knowledge, we extend the length
of the input string by the computed length difference. We then traverse the extended input string using
2 pointers in a fast & slow arrangement. One "writer" pointer will start at the very end of the string. A second
"reader" pointer will start at the index of the last character of the original string. If the reader sees a non-space,
the writer writes a non-space and both pointers are advanced by 1 space towards the front. If the reader sees a space,
the writer writes "%20" and is advanced by 3 spaces towards the front while the reader is advanced one space towards
the front. The original string will thus be transformed into a URLified string.

Time complexity: O(N) where N is the length of the string.
Space complexity: O(N) even though we minimized space use, the input could still be all spaces which would force us
to extend the input string by 2*N characters.
"""


# in Python, strings are immutable, thus we are forced to implement with lists of single characters
def URLify(string):
    # compute length of new string based on # of spaces in input string
    new_len = 0
    reader = len(string) - 1  # index at end of un-extended string
    for char in string:
        if char == ' ':
            new_len += 3
        else:
            new_len += 1
    # extend length of string to fit URL
    string += [' '] * (new_len - len(string))
    writer = len(string) - 1  # index at end of extended string
    # traverse using double index technique to do this "in place"
    while reader >= 0 and writer >= 0:
        if string[reader] == ' ':  # if reader sees a space, the writer writes %20
            string[writer] = '0'
            string[writer - 1] = '2'
            string[writer - 2] = '%'
            reader -= 1  # reader and writer are advanced accordingly
            writer -= 3
        else:
            string[writer] = string[reader]  # if the reader sees a non-space, the writer copies it over
            reader -= 1  # reader and writer are advanced the same amount
            writer -= 1
