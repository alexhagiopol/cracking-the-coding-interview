/*
 * PROBLEM:
 * You have an array with all the numbers from 1 to N, where N is at most 32,000.
 * The array may have duplicate entries and you do not know what N is. With only 4 kilobytes
 * of memory available, how would you print all duplicate elements in the array?
 *
 * TEST CASE:
 *  {3, 11, 1, 3, 4, 5, 11, 7, 8, ... } -> {3, 11, ...}
 *
 * ALGORITHM:
 * Thoughts and questions:
 * 1. The 4 KB number seems significant: 4 KB = 4000 Bytes = 4000 * 8 bits = 32,000 bits
 * 2. Thus, we have 1 bit for each and every possible number in the array.
 * 3. The problem is that 1 bit per number is not enough to determine duplicate-ness. There is no
 * way to distinguish between presence and duplicate-ness with 1 bit of data per possible number.
 * 4. Thus, we need to make 2 passes using 2 bits per possible number: 1 to indicate presence, and 1 to
 * indicate duplicate-ness.
 * 5. NOTE: In the textbook solution, the author suggests using only 1 bit per number and printing the
 * number if it's corresponding bitVector value is 1. The problem with this is that it pollutes the output
 * with "duplicate duplicates"! There is no way to know if an identified duplicate has already been printed.
 * This is why I implement my strategy that outputs *unique* duplicates.
 *
 * This leads to the following algorithm:
 *
 * 1. Initialize an array of bits pairs (bitPaiVector) that is 16000 elements long and initially contains all [0, 0]s
 * and representing numbers 1 to 16000.
 * 2. Read each number from a file line by line.
 *      a. Look at the bitPairVector pair at the index equal to the number read from file.
 *      b. If the first value is 0, make it a 1.
 *      c. If the first value is 1, make the second value 1.
 *      d. If the value of the number is not a possible array index, do nothing.
 * 3. Iterate through the bitPairVector and print every index that points to pair whose second value is a 1.
 * 4. Repeat steps 1., 2., and 3., with another 16000 element long array where the numbers represented are
 * 16001 to 32000.
 * 5. For testability, we do not print the duplicate numbers and instead add them to an std::vector whose address
 * was passed to the function.
 *
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 */

#pragma once
#include <string>
#include <vector>

namespace chapter_10 {
    void findDuplicates(std::vector<int>& duplicates, const std::string& filepath);
}
