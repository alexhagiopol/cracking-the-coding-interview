/*
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

Time complexity: O(N) where N is the length of the shorter string.
Space complexity: O(N).
*/

#include "problem_01_06_stringCompression.h"

int computeCompressedLength(const std::string& s){
    if (s.size() <= 0){
        return 0;
    } else if (s.size() == 1) {
        return 2;
    }
    int compressedLength = 1;
    int numDupes = 1;
    for (int i = 1; i < s.size(); i++){
        if (s[i] == s[i-1]){
            numDupes ++;  // count number of duplicates
        } else {
            compressedLength += (1 + std::to_string(numDupes).size());  // increase length by 1 letter + number of digits in num_dupes
            numDupes = 1;  // reset number of duplicates
        }
    }
    return compressedLength;
}
#include <iostream>
std::string chapter_01::stringCompression(const std::string& s){
    int compressedLength = computeCompressedLength(s);
    if (s.size() <= compressedLength){
        return s;
    }
    std::string compressed(compressedLength, '_');
    compressed[0] = s[0];
    int j = 1;  // index for compressed string
    int numDupes = 1;
    for (int i = 1; i < s.size(); i++){
        if (s[i] == s[i-1]){
            numDupes ++;
        } else {
			std::string encoding(std::to_string(numDupes) + s[i]);  // create compressed version of repeated chars
            compressed.replace(j, encoding.size(), encoding);
            numDupes = 1;
            j += (encoding.size());  // increase write position
        }
    }
	std::string encoding(std::to_string(numDupes));
    compressed.replace(j, encoding.size(), encoding);
    return compressed;
}