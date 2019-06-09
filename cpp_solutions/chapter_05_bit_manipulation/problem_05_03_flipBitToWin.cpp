#include "problem_05_03_flipBitToWin.h"

namespace chapter_05 {
    int flipBitToWin(int input) {
        /*
        * PROBLEM:
        * Flip Bit to Win: You have an integer and you can flip exactly one bit from a 13 to a 1.Write code to
        * find the length of the longest sequence of ls you could create.
        *
        * TEST CASE:
        * 0b000 -> 1
        * 0b100 -> 1
        * 0b1011011 -> 5
        *
        * ALGORITHM:
        * 1. Iterate through binary representation by using logical right shift on copy of int
        * 2. Keep 3 tallys: prev tally, current tally, max tally.
        * 3. Loop over binary representation:
        *      a. Count the number of 1s seen so far in current tally.
        *      b. If a zero is seen:
        *          i. add 1 to current tally
        *          ii. set max tally to sum of pre and post tally if the sum is > max tally
        *          iii. prev tally = current tally
        *      c. logical shift the input to the right with >>>
        * 4. In case where binary representation ends in 1, we have to do the check in b.ii. again.
        * 5. return max tally
        *
        * SPACE & TIME:
        * Space: O(1): extra space we use does not scale with length of int
        * Time: O(b) because we have to iterate thru each bit
        *
        * CODE:
        */
        int prevTally = 0;
        int currentTally = 0;
        int maxTally = 0;
        if (input == 0) return 1; // edge case where we do not need to run the algorithm
        while (input != 0) {
            if ((input & 0b1) == 1) {
                currentTally ++;
            } else {
                int sum = prevTally + currentTally + 1;
                if (sum > maxTally) maxTally = sum;
                prevTally = currentTally;
                currentTally = 0;
            }
            input = input >> 1;
        }
        int sum = prevTally + currentTally + 1;
        if (sum > maxTally) maxTally = sum;
        return maxTally;
    }
}
