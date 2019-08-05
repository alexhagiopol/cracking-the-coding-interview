/*
 * PROBLEM: Given two arrays of integers, compute the pair of values (one value in each array) with the
 * smallest (non-negative) difference. Return the difference.
 *
 * TEST CASES: See tests.cpp.
 *
 * ALGORITHM:
 * 1. Sort the two arrays.
 * 2. "Merge" the two arrays as in the mergeSort() merge operation.
 * 3. Pairs of elements considered for a merge are candidates for smallest difference.
 * 4. At each potential merge, calculate the difference and update smallest difference if necessary.
 *
 * TIME COMPLEXITY: O(M*log(M) + N*log(N) + M + N)
 * SPACE COMPLEXITY: O(M + N) if the caller is not ok with having their inputs become sorted. O(1) otherwise.
 */

#pragma once
#include <algorithm>
#include <limits>
#include <vector>

namespace chapter_16 {
    int smallestDifference(std::vector<int> a1, std::vector<int> a2) {
        std::sort(a1.begin(), a1.end());
        std::sort(a2.begin(), a2.end());
        int a1i = 0;
        int a2i = 0;
        int smallestDifference = std::numeric_limits<int>::max();
        while (a1i < a1.size() && a2i < a2.size()) {
            int difference = std::abs(a1[a1i] - a2[a2i]);
            if (difference < smallestDifference) smallestDifference = difference;
            if (a1[a1i] <= a2[a2i]) {
                a1i ++;
            }
            else {
                a2i ++;
            }
        }
        return smallestDifference;
    }
}
