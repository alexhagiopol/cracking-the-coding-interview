/*
 * PROBLEM: Given an input file with 4 billion non-negative integers, provide an algorithm
 * to generate an integer that is not contained in the file. Assume you have 1GB of memory
 * available for this task.
 *
 *      Questions and thoughts:
 *      1. Are these 32 bit integers? I.e. what is the possible range of numbers?
 *      2. For example, if the integers were limited to 8 unsigned bit ints, then all possible
 *      numbers in the file would range between 0 and 255. We would thus only need a 2^8 = 256
 *      element array of bits to determine uniqueness for any size of input file stored on disk.
 *      3. If the integers are 32 bit unsigned integers (uint32_t), then we will need a 2^32
 *      element array of bits to keep track of the uniqueness of the numbers in the file.
 *      4. 2^32 = 4,294,967,296 bits, so if only 4 billion numbers are stored, there must be possible
 *      positive unsigned ints that are not in the file.
 *      5. 4,294,967,296 bits = 536,870,912 bytes = approximately 500MB. Thus, this array will fit within our
 *      allotted 1GB of space.
 *      6. Thus, one algorithm would be:
 *          a. Allocate an array of 2^32 bits all set to zero.
 *          b. For each integer in the file...
 *              i. Use the integer itself as the index of the array.
 *              ii. Flip the bit associated with that index if it is not already a 1.
 *          c. Iterate through the array of bits and return the index with the first 0.
 *
 * TEST CASE:
 *  {11, 1, 3, 4, 5, 7, 8, ... } -> 0
 *
 * ALGORITHM: See above.
 *
 * TIME COMPLEXITY: O(N)
 *
 * SPACE COMPLEXITY: O(1) (2^32 is a constant)
 *
 * CODE:
 */

#pragma once
#include <cstdint>
#include <string>

namespace chapter_10 {
    uint32_t missingInt(const std::string& filename);
}
