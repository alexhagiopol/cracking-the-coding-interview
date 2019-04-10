/*
Chapter 08 - Problem 08 - Permutations With Duplicates

Problem Statement:
Write a method to compute all permutations of a string whose characters are not necessarily unique.
The list of permutations should not have duplicates.


Solution:
See the solution for 8.7 first.
Instead of recursively passing the problem state represented as a string, represent the problem state as a
hash table that maps string characters to their counts in the string. When creating new recursive calls,
create one recursive call for each unique character in the hash table, then decrement that character's count in the table
before passing it on. In this way, each recursive call is spawned with a unique character thus creating only unique permutations
The space and time complexities do not change because in the worst case the recursion tree is still O(N) nodes deep with
O(N!) leaf nodes and O(N) operations required at each node. One such operation is the creation of different copies of the hash
table to be passed down different recursion paths in the tree, each with O(N) entries. Another such operation is the
creation of new strings representing the permutations each with O(N) characters. The additional storage required by the
hash table is O(N) so it does not affect the existing big O analysis of the worst case storage requirement.

Time complexity: O(N!*N^2)
Space complexity: O(N!*N)
*/

#include "problem_08_08_permutationsWithDups.h"
#include <unordered_map>
#include <iostream>

namespace chapter_08 {
    void permutationsWithDupsHelper(const std::string& prefix, std::unordered_set<std::string>& permutations, const std::unordered_map<char, int>& hashTable) {
        bool found = false;
        for (auto pair : hashTable) {
            if (pair.second > 0) {
                    std::unordered_map<char, int> hashTableCopy = hashTable;  // each recursive call is passed a different hash table copy
                    hashTableCopy[pair.first] --;
                    std::string prefixCopy = prefix;  // each recursive call is passed a different prefix copy
                    prefixCopy += pair.first;
                    found = true;
                permutationsWithDupsHelper(prefixCopy, permutations, hashTableCopy);
            }
        }
        if (!found) {  // when the hash table has been depleted, add prefix to the permutations set
            permutations.insert(prefix);
        }
    }

    void permutationsWithDups(const std::string& string, std::unordered_set<std::string>& permutations) {
        if (string.length() == 1) {
            permutations.insert(string);
        } else if (string.length() >= 2) {
            // map the characters we've seen so far to their counts in a hash table
            std::unordered_map<char, int> hashTable;
            for (const char& singleChar : string) {
                if (hashTable.count(singleChar)) {
                    hashTable[singleChar] ++;
                } else {
                    hashTable[singleChar] = 1;
                }
            }
            // pass hash table representation to recursive function that computes permutations
            permutationsWithDupsHelper("", permutations, hashTable);
        }
        // if string.length() <= 0 do nothing
    }
}