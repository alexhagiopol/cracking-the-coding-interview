/*
 * PROBLEM:
 * You have an array with all the numbers from 1 to N, where N is atmost 32,000.
 * The array may have duplicate entries and you do not know what N is. With only 4 kilobytes
 * of memory available, how would you print all duplicate elements in the array?
 *
 * TEST CASE:
 *  {3, 11, 1, 3, 4, 5, 11, 7, 8, ... } -> {3, 11, ...}
 *
 * ALGORITHM:
 *      Thoughts and questions:
 *
 */

#pragma once
#include <string>
#include <vector>

namespace chapter_10 {
    void findDuplicates(std::vector<int>& duplicates, const std::string& filepath);
}
