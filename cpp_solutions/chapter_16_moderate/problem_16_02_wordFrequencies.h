/*
 * PROBLEM: Design a method to find the frequency of occurrences of any given word in a book.
 * What if we were running this algorithm mUltiple times?
 *
 * TEST CASES: See tests.cpp
 *
 * ALGORITHM: Make a hash table that stores the counts of each word. Then simply look up the counts
 * in the hash table when queried.
 *
 * TIME COMPLEXITY: O(1) lookup
 * SPACE COMPLEXITY: O(N)
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

namespace chapter_16 {
    void trimCopy(std::string& target, const std::string& source);
    void makeDatabase(const std::vector<std::string>& book, std::unordered_map<std::string, int>& database);
    int wordFrequencies(const std::string& word, const std::unordered_map<std::string, int>& database);
}
