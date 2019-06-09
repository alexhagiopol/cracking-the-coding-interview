/*
Chapter 12 - Problem 02 - Reverse - CTCI 6th Edition page 163

Problem Statement:
Given a string represented as a null terminated char array, reverse it.

Example:
"Alex" -> "xelA"

Solution:
Make a copy of the pointer to the front of the string and advance it until it reaches the end of the string.
Once it reaches the end of the string, advance the front pointer forward and the end pointer backward while
swapping the pointed-to values along the way using only a single char as a buffer.

Time complexity: O(N)
Space complexity: O(1)
*/

#include "problem_12_02_reverse.h"
#include <iostream>
#include <string>

namespace chapter_12{
    void reverse(char * str){  // assume str points to the first character of a null terminated string
        char * start = str;
        char * end = str;
        while(* end) end ++;  // move end pointer to the end of th string
        end --; // point to last character
        char temp;
        while (start < end){ // swap values then advance start pointer forward and end pointer backwards
            temp = * start;
            * start = * end;
            * end = temp;
            start ++;
            end --;
        }
    }
}
