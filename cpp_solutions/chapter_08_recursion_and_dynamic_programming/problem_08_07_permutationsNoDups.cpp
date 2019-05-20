/*
Chapter 08 - Problem 07 - Permutations Without Duplicates

Problem Statement:
Write a method to compute all permutations of a string of unique characters.

Solution:
First, we show the definition of permutations by example:
'a'    -> 'a'                                        # 1! = 1
'al'   -> 'al' , 'la'                                # 2! = 2
'ale'  -> 'ale', 'ael', 'lae', 'lea', 'eal', 'ela'   # 3! = 6

Next, we show a recursive pattern for permutation generation:
permutations('a') = 'a'  # terminating condition
permutations('al') = 'al', 'la'  # terminating condition
permutations('ale') -> return combine('a', permutations('le'))
                     = return combine('a', ['le', 'el'])
                     = return ['ale', 'lae', 'lea', 'ael', 'eal', 'ela']

Our recursive solution implementation has 2 components:

I. A function permutations(string) that takes as input a string. This function terminates when the length of the string is
2 or less. This function recurses when the length of the string is 3 or more.
II. A function combine(char, [string1, string2 ... stringN]) that takes as input a single character and a list of strings.
This function returns a list of strings that are formed by inserting the single character at every possible position in
every member of the list of strings.

When called on a string of length greater than 2, the function permutations(string) returns combine(string[0],
permutations(string[1:end])). Thus, a string of length N will cause N-2 calls of the permutations() function. At each
call of permutations(string_length_X), the combine() function will produce a list of strings that is X! long. To create
each member of the list of strings produced by combine(), O(X) work is required where X is O(N). Thus, Gayle loosely
approximates an upper bound on the total number of operations as O(N! * N^2). A more accurate expression of the runtime
would be the sum ...

O(N!*N + (N-1)!*(N-1) + (N-2)!*(N-2) ...)
The space complexity of the problem is O(N! * N) because N! of strings of length N must be stored.

Time complexity: O(N!*N^2)
Space complexity: O(N!*N)
*/

#include "problem_08_07_permutationsNoDups.h"
#include <iostream>

namespace chapter_08 {
    void combine(const std::string& toInsert, const std::unordered_set<std::string>& oldPermutations, std::unordered_set<std::string>& newPermutations) {
        for (const std::string& oldPermutation : oldPermutations) {
            for (int i = 0; i < oldPermutation.length() + 1; i++) {
                 std::string newPermutation =
                         oldPermutation.substr(0, static_cast<unsigned long>(i)) +
                         toInsert +
                         oldPermutation.substr(static_cast<unsigned long>(i), std::string::npos);
                 newPermutations.insert(newPermutation);
             }
         }
    }

    void permutationsNoDups(const std::string& string, std::unordered_set<std::string>& permutations) {
        if (string.length() == 1) {
            permutations.insert(string);
        } else if (string.length() == 2) {
            permutations.insert(string);
            std::string copy(string);
            std::reverse(copy.begin(), copy.end());
            permutations.insert(copy);
        } else if (string.length() > 2) {
            std::unordered_set<std::string> oldPermutations = {};
            std::unordered_set<std::string> newPermutations = {};
            permutationsNoDups(string.substr(1, std::string::npos), oldPermutations);
            combine(string.substr(0, 1), oldPermutations, newPermutations);
            for (const std::string& permutation : newPermutations ) {
                permutations.insert(permutation);
            }
        } // if string.length() <= 0 do nothing
    }
}
