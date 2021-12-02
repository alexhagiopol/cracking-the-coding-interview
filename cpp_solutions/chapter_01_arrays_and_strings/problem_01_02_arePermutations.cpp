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
We count character appearances using an int array of size 128. We
traverse each string one character at a time. Each time we observe a character,
we increase the count by 1, while traversing the second we decrease the count by 1 for the same character. 
If both the strings do match then the array will be in its initial state with all zeroes, if they don't match the count will become less than 0 for the disimilar character.

Time complexity: O(N) where N is the length of the linearly traversed strings.
Space complexity: O(1) because array does not scale with string length.
*/

#include "problem_01_02_arePermutations.h"


bool chapter_01::isPermutation(const std::string& s1, const std::string& s2){
    if (s1.size() != s2.size()){
        return false;
    }
    int characterCounts[128] = {0};
    for (char letter : s1){
        characterCounts[static_cast<size_t>(letter)] ++;
    }
    for (char letter : s2){
        characterCounts[static_cast<size_t>(letter)] --;
        if (characterCounts[static_cast<size_t>(letter)] < 0) {
            return false;
        }
    }
    return true;
};

