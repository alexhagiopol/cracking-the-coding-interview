/*
Chapter 01 - Problem 03 - URLify - CTCI 6th Edition page 90

Problem Statement :
Write a method to replace all spaces in a string with '%20: You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the
"true" length of the string.

Example :
'Mr. John Smith ' -> 'Mr.%20John%20Smith%20'

Solution :
We will do this problem "in place" i.e. we will not allocate more space than is necessary to add the "%20" characters.
First, we traverse the input string and count the number of spaces. We know that each single space in the input
string is replaced with three characters in the output.With this knowledge, we extend the length
of the input string by the computed length difference. We then traverse the extended input string using
2 indices in a fast & slow arrangement. One "writer" index will start at the very end of the string. A second
"reader" index will start at the last character of the original string. If the reader sees a non - space,
the writer writes a non - space and both indices are advanced by 1 space towards the front. If the reader sees a space,
the writer writes "%20" and is advanced by 3 spaces towards the front while the reader is advanced one space towards
the front. The original string will thus be transformed into a URLified string.

Time complexity : O(N) where N is the length of the string.
Space complexity : O(N) even though we minimized space use, the input could still be all spaces which would force us
to extend the input string by 2 * N characters.
*/

#include "problem_01_03_URLify.h"
#include <iostream>

void chapter_01::URLify(std::string& input) {
	// count how much extra space needs to be added to the string.
	int extraSpace = 0;
	for (const char c : input) {
		if (c == ' ') {
			extraSpace += 2;
		}
	}
	if (extraSpace <= 0) return; // if no extra space is needed, do nothing.
	int fastIndex = input.size() - 1;
	input.append(extraSpace, ' ');
	int slowIndex = input.size() - 1;
	while (fastIndex >= 0 && slowIndex >= 0) {
		if (input[fastIndex] == ' ') {  // if fast index sees a space, add a %20 at slow index's location
			input[slowIndex] = '0';
			input[slowIndex - 1] = '2';
			input[slowIndex - 2] = '%';
			fastIndex--;
			slowIndex-=3;
		} else {  // if fast index does not see a space, simply copy over what it sees
			input[slowIndex] = input[fastIndex];
			fastIndex--;
			slowIndex--;
		}
	}
}
