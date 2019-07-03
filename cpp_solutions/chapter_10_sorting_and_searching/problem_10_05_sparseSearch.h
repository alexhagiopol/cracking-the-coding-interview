/*
 * PROBLEM:
 * Assume a sparse array of strings where the contents are sorted but separated
 * by empty strings. Write an algorithm to search for a given string.
 *
 * TEST CASE:
 * sparseSearch({"at", "", "", "", "ball", "" , "", "car", "", "", "dad", "", ""}, "ball") -> 4
 *
 * ALGORITHM:
 * Brute force approach is linear search thru array. Vanilla binary search does not work
 * because comparison against query value is required at every recursive step.
 *
 * Design a modified form of binary search that handles midpoint comparison against an empty string
 * by doing a local linear search to find the nearest non-empty string.
 *
 * It is assumed that empty strings are not valid queries, i.e. searching for "" will return -1.
 *
 * TIME COMPLEXITY: O(N) worst case, O(long(N)) best case
 * SPACE COMPLEXITY: O(1)
 *
 * CODE:
 */

#pragma once
#include <string>
#include <vector>

namespace chapter_10 {
    int sparseSearch(const std::vector<std::string>& array, const std::string& query);
}
