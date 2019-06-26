/*
 * PROBLEM:
 * Given an array of strings, sort the array such that all anagrams are next to each other.
 * Anagrams are strings that contain the same characters e.g. "abc" and "bca".
 *
 * TEST CASE:
 * Input: {ddd, abc, ccc, bac, aaa, cab, bbb, acb}
 * Output: {aaa, abc, acb, bac, cab, bbb, ccc, ddd}
 * Note that the only requirement is for anagrams to be next to each other. The order of the anagram groups and the
 * order of the sorted array does not matter.
 *
 * ALGORITHM:
 * 1. Initialize a hash table (std::map<std::string, std::vector<std::string>>) where keys are sorted anagrams
 * and values are vectors of unsorted anagrams. This takes advantage of the observation that anagrams, when sorted, are
 * identical. Use std::map instead of std:unordered_map to allow testability regardless of C++ compiler.
 * 2. For each string in input array:
 *  a. Create a sorted version of the string.
 *  b. If the sorted string is already in the hash table, add the unsorted string to the vector of strings associated \
 *  with the sorted version.
 *  c. If the string is not in the hash table, add the sorted version as a key and the unsorted version as a value.
 * 3. For each key in hash table, add contents of the associated vectors to a vector of strings.
 *
 * TIME COMPLEXITY:
 * Step (1) takes O(1) time.
 * Step (2) takes O(N) time assuming the strings are of constant length.
 * Step (3) takes O(N) time.
 * Thus, the algorithm takes O(N) time.
 *
 * SPACE COMPLEXITY:
 * The hash table will require O(N) space.
 *
 * CODE:
 */

#pragma once
#include <vector>
#include <string>

namespace chapter_10 {
    void anagramSort(std::vector<std::string>& array);
}
