/*
Chapter 01 - Problem 04 - Palindrome Permutation - CTCI 6th Edition page 91

Problem Statement :
Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or
phrase that is the same forwards and backwards. A permutation is a rearrangement of letters.The palindrome does
not need to be limited to just dictionary words.

Example :
	"tact coa"->true(permutations : "tacocat", "atcocta", etc.)

	Solution :
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

	Time complexity : O(N) where N is the length of the string.
	Space complexity : O(1) because the bit vector size does not depend on N.
*/

#include "problem_01_04_palindromePermutation.h"
#include <bitset>

bool chapter_01::palindromePermutation(const std::string& input) {
	std::bitset<128> alphabet;  // use bitset as a hash table to store which characters we've seen
	size_t numValidChars = 0;
	for (const char c : input) {
		if ((c >= 0 || c > 127) && c != ' ') {  // ignore non-ASCII & spaces
			numValidChars++;
			alphabet.flip(c); // flip bit corresponding to valid char
		}
	}
	// if even number of chars and all bits are zero, we've seen each char an even # of times
	if ((numValidChars % 2 == 0) && alphabet.none()) {  
		return true;
	}
	// if odd number of chars and just one bit is 1, we've seen each char except for 1 an even # of times
	else if (((numValidChars % 2 != 0) && alphabet.count() == 1)) {
		return true;
	}
	return false; 
}