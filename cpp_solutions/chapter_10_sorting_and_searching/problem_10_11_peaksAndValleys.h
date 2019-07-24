/*
 * PROBLEM:
 * Given an array of integers, sort the array into one of alternating peaks and valleys
 * where a peak is an integer greater than or equal to its neighbors and a valley is an
 * integer less than or equal to its neighbors.
 *
 * TEST CASES:
 * {5, 3, 1, 2, 3} --> {5, 1, 3, 2, 3}
 * {5, 8, 6, 2, 3, 4, 6} --> {5, 8, 2, 6, 3, 6, 4};
 * {}   --> {}
 * {5}  --> {5}
 * {54} --> {54}
 * {554} --> {554}
 *
 * ALGORITHM:
 * Examine three numbers at a time, determine if second and third numbers need
 * to be swapped to conform to peaks and valleys rule, modify the array if a swap is needed,
 * move on to next group of 3 numbers as shown in example below:
 *
 * Example 1:
 * {5, 3, 1, 2, 3}
 * {5, 3, 1} -> {5, 1, 3} (swap 2nd & 3rd)
 * array is now {5, 1, 3, 2, 3}
 * {1, 3, 2} -> (no change)
 * {3, 2, 3} -> (no change)
 *
 * Example 2:
 * {5, 8, 6, 2, 3, 4, 6}
 * {5, 8, 6} -> no change
 * {8, 6, 2} -> swap second and last -> {8, 2, 6}
 * array is now {5, 8, 2, 6, 3, 4, 6}
 * {2, 6, 3} -> no change
 * {6, 3, 4} -> no change
 * {3, 4, 6} -> swap second and last -> {3, 6, 4}
 * array is now {5, 8, 2, 6, 3, 6, 4}
 *
 * When processing each triple, we follow this logic:
 *  1. If first <= second <= third:
 *      a. swap second and third
 *  2. If first >= second >= third:
 *      a. swap second and third
 *  3. If first <= second >= third:
 *      a. do nothing
 *  4. If first >= second <= third:
 *      a. do nothing
 *
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 */

#pragma once

namespace chapter_10 {
    void peaksAndValleys(std::vector<int>& array) {
        for (int i = 0; i < (static_cast<int>(array.size()) - 2); i++) {
            if ((array[i] < array[i + 1] && array[i + 1] < array[i + 2]) || (array[i] > array[i + 1] && array[i + 1] > array[i + 2])) {
                std::swap(array[i + 1], array[i + 2]);
            }
        }
    }
}
