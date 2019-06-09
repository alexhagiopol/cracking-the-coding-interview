/*
Chapter 01 - Problem 09 - String Rotation - CTCI 6th Edition page 91

Problem Statement:
Assume you have a method isSubstring() which checks if one word is a substring of
another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
only one call to isSubstring().

Example:
stringRotation("waterbottle", "erbottlewat")

Solution:
If we concatenate s1 with itself into [s1, s1] we will create a string that contains
every possible rotation of s1. For example "waterbottlewaterbottle" contains
"erbottlewat". Thus, if we use isSubstring() to check if s2 is a substring of
[s1, s1], we will determine if s2 is a rotation of s1.

Time complexity: O(N) where N is the length of the concatenated string. Substring checking can be done in linear time.
Space complexity: O(N) because we have to allocate enough space to double the length of s1.
*/

#include "problem_01_09_stringRotation.h"

bool chapter_01::stringRotation(const std::string &s1, const std::string& s2) {
    const std::string s3 = s1 + s1;
    return s3.find(s2) != std::string::npos;  // find() is an equivalent of isSubstring() as defined above. See http://www.cplusplus.com/reference/string/string/find/
}