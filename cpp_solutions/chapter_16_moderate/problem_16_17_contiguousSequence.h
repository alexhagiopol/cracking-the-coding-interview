/*
 * PROBLEM:
 * You are given an array of integers (both positive and negative). Find the
 * contiguous sequence with the largest sum. Return the sum.
 *
 * SOLUTION:
 * We make some observations. If all #s are positive, then the result is the sum of the entire array. If all #s are
 * negative, then the result is the single largest element. So we observe next that if the sum of a subarray is
 * negative, then that subarray is guaranteed to be beaten by a single element.
 *
 * Thus we develop the following strategy:
 * Maintain a single pointer, sum so far init at 0, max sum init at -INF. Advance pointer. Add each element to sum.
 * If sum becomes negative, reset sum to 0. If sum > max sum, update max sum. Return max sum.
 *
 * O(N) time.
 * O(1) space.
 */

#pragma once
#include <vector>

namespace chapter_16 {
    int contiguousSequence(const std::vector<int>& input);
}
