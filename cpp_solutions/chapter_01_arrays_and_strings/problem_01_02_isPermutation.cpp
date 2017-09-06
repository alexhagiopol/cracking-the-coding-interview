//
// Created by Alex Hagiopol on 8/21/17.
//

/*
Chapter 01 - Problem 02 - Check Permutation - CTCI 6th Edition page 90

Problem Statement:
Given two strings, write a method to decide if one is a permutation of the
other.

Example:
        ("alex", "lexa") -> True

Solution:
We assume that the input strings will contain only ASCII characters and that upper
case characters are distinct from lower case ones i.e. "Alex" is not a permutation
of "alex". We define a permutation as a rearrangement of characters i.e. two strings
that are permutations of each other must contain exactly the same characters with the
same frequency. If two strings have unequal length they cannot be permutations.
We count character appearances using a 128 wide bit vector. We
traverse each string one character at a time. Each time we observe a character, we flip
the bit corresponding at the index corresponding to its ASCII value. If we traverse two
strings which both contain exactly the same number of characters with the same character
frequency, the bit vector will be all 0s at the end of the two traversals. This is because
for two strings that are permutations, each bit will be flipped an even number of
times in total.

Time complexity: O(N) where N is the length of the linearly traversed strings.
Space complexity: O(1) because bit vector does not scale with string length.
*/

#include "problem_01_02_isPermutation.h"
#include <bitset>

namespace chapter_01{
    bool isPermutation(const std::string& s1, const std::string& s2){
        if (s1.size() != s2.size()){
            return false;
        }
        std::bitset<128> asciiTable;
        for (char letter : s1){
            asciiTable.flip((int) letter);
        }
        for (char letter : s2){
            asciiTable.flip((int) letter);
        }
        return asciiTable.none();
    };
}
