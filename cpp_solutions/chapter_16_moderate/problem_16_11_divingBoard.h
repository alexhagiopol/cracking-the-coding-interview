/*
 * PROBLEM:
 * You are building a diving board by placing a bunch of planks of wood end-to-end.
 * There are two types of planks, one of length shorter and one of length longer. You must use
 * exactly K planks of wood. Write a method to generate all possible lengths for the diving board.
 *
 * SOLUTION:
 * The order of the K plans doesn't matter. 3 long + 2 short planks will yield the same length
 * as 2 short + 3 long planks. Thus there are K + 1 possible lengths for the diving board.
 *
 * For example, if K = 3:
 *
 * Length 1: 0 short + 3 long
 * Length 2: 1 short + 2 long
 * Length 3: 2 short + 1 long
 * Length 4: 3 short + 0 long
 *
 * Thus, to solve this problem, we iterate from i = 0 to K and
 * create one length for each value of i short planks and k-i long planks.
 * We can get in trouble with this approach if there are duplicate lengths,
 * so we add each length to an unordered_set to ensure uniqueness.
 *
 * TIME: O(N)
 * SPACE: O(N)
 */

#pragma once
#include <unordered_set>

namespace chapter_16 {
    std::unordered_set<int> divingBoard(int shorter, int longer, int K );
}
