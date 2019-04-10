/*
Chapter 08 - Problem 07 - Permutations Without Duplicates

See problem_08_07_permutationsNoDups.cpp for problem description.
*/
#pragma once
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iterator>

namespace chapter_08 {
    void permutationsNoDups(const std::string& string, std::unordered_set<std::string>& permutations);
}
