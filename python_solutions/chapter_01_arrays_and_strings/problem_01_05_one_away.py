"""
Chapter 01 - Problem 05 - One Away - CTCI 6th Edition page 91

Problem Statement:
There are three types of edits that can be performed on strings:
insert a character, remove a character, or replace a character.
Given two strings, write a function to check if they are one edit (or zero edits) away.

Example:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bae -> false

Solution:
1. If the strings differ in length by more than 1 character, return false.

2. If two strings differ in length by exactly one character, then search for an insertion / removal.
Traverse each string until a difference is found. If a difference is found, advance the index of the
longer string by 1 and the index of the shorter string by 0. If another difference is found, return false.
If no other difference is found, return true.

3. If the strings have the same length, search for a replacement: traverse each string counting differences.
If more than one difference is found, return false else return true.

Time complexity: O(N) where N is the length of the shorter string.
Space complexity: O(1)
"""


def search_insertion(s1, s2):
    assert(abs(len(s1) - len(s2)) == 1)
    i1 = i2 = 0  # initialize search indices
    difference_found = False
    while i1 < len(s1) and i2 < len(s2):
        if s1[i1] != s2[i2]:
            if difference_found:  # if a difference has already been found, return false
                return False
            difference_found = True
            if len(s1) > len(s2):  # if first difference found, assume we've found the place where a char was inserted
                i1 += 1
            else:
                i2 += 1
        else:  # if no difference found, continue traversing as normal
            i1 += 1
            i2 += 1
    return True


def search_replacement(s1, s2):
    assert(len(s1) == len(s2))
    i = 0
    difference_found = False
    while i < len(s1):
        if s1[i] != s2[i]:
            if difference_found:  # if a difference has already been found, return False
                return False
            difference_found = True
        i += 1
    return True


def one_away(s1, s2):
    len_difference = abs(len(s1) - len(s2))
    if len_difference > 1:
        return False  # different by more than 1 edit
    if len_difference == 1:
        return search_insertion(s1, s2)
    return search_replacement(s1, s2)
