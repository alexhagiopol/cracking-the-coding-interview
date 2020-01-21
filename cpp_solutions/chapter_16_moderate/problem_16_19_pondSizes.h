/* PROBLEM:
 * You have an integer matrix representing a plot of land, where the value at that location
 * represents the height above sea level. A value of zero indicates water. A pond is a region of
 * water connected vertically, horizontally, or diagonally. The size of the pond is the total number of
 * connected water cells. Write a method to compute the sizes of all ponds in the matrix.
 *
 * ALGORITHM:
 * Iterate over every cell of the matrix.
 *
 */

#pragma once
#include <set>
#include <vector>

namespace chapter_16 {
    std::multiset<int> pondSizes(std::vector<std::vector<int>> plot);
}