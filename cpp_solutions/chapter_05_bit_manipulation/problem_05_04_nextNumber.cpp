//
// Created by Alex Hagiopol on 2019-05-17.
//
#include "problem_05_04_nextNumber.h"

namespace chapter_05 {
    /*
    * PROBLEM:
    * Given a positive integer, return the next smallest and next largest
    * numbers that have the same number of 1s in their binary representations.
    *
    * TEST CASE:
    * positiveInteger -> (nextSmallest, nextLargest)
    * 0b0000 -> (0, 0)
    * 0b1000 -> (0b0100, ?)
    * 0b0001 -> (?, 0b0010)
    * 0b0101 -> (0b0011, 0b0110)
    *
    * ALGORITHM:
    * 1. To make a smaller number, shift least significant 1 that has space to move right
    *      a. Iterate through binary representation to find the rightmost 1 that has a 0 to its right
    *      b. & the input integer with 111...1110111 then | with 000...0000100
    *      c. when we've found the rightmost 1, note its index, then create masks by left shifting a 1 to that index
    * 2. To make a bigger number, shift least significant 1 that has space to move left
    *      ...same as above
    * 3. Edge cases?
    *      a. 0b00...1 -> return (the number itself, its left shift)
    *      b. 0b10...0 -> return (its left shift, the number itself)
    *      c. 0b0 -> return (0,0)
    *
    * SPACE & TIME:
    * Space: O(b) - we need to allocate masks the same size as the input
    * Time: O(b) - we need to iterate through the binary representation bit by bit
    *
    * CODE:
    */
    int getNext(int positiveInteger) {

        return positiveInteger;
    }
    int getPrev(int positiveInteger) {

        return positiveInteger;
    }
}
