/*
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
*/

#include "problem_01_05_oneAway.h"
#include <stdlib.h>
#include <assert.h>

bool searchInsertion(const std::string &s1, const std::string &s2) {
    assert(abs(static_cast<int>(s1.size() - s2.size())) == 1);
    int i1 = 0, i2 = 0;
    bool foundDifference = false;
    while (i1 < s1.size() && i2 < s2.size()){
        if (s1[i1] != s2[i2]){
            if (foundDifference){  // if difference already found, return false
                return false;
            }
            foundDifference = true;
            if (s1.size() > s2.size()){  // if first difference found, assume we've found the place where a char was inserted
                i1 ++;
            } else {
                i2 ++;
            }
        } else {  // if no difference, continue iterating as normal
            i1 ++;
            i2 ++;
        }
    }
    return true;
}

bool searchReplacement(const std::string &s1, const std::string &s2) {
    assert(s1.size() == s2.size());
    int i = 0;
    bool foundDifference = false;
    while (i < s1.size()){
        if (s1[i] != s2[i]){
            if (foundDifference){  // if more that one difference found, return false
                return false;
            }
            foundDifference = true;
        }
        i ++;
    }
    return true;
}

bool chapter_01::oneAway(const std::string &s1, const std::string &s2) {
    int len_difference = abs(static_cast<int>(s1.size() - s2.size()));
    if (len_difference > 1){  // different by more than 1 edit: return false
        return false;
    }
    if (len_difference == 1){  // different by exactly one edit: could be an insertion / removal
        return searchInsertion(s1, s2);
    }
    return searchReplacement(s1, s2);  // same length: could be a replacement
}