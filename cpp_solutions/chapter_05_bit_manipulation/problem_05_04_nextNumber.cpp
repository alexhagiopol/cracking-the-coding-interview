//
// Created by Alex Hagiopol on 2019-05-17.
//
#include "problem_05_04_nextNumber.h"
#include <iostream>

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
    * getNext():
    * 1. Use bit shifting to find the least significant 1.
    * 2. Use bit shifting to find the least significant 0 *to the left of* the least significant 1
    * 3. Flip the zero position to 1.
    * 4. Clear all ones to the right of the flipped bit.
    * 5. Add in zeroIndex - oneIndex - 1 ones in the least significant positions that have been cleared out
    *
    * SPACE & TIME:
    * Space: O(b) - we need to allocate masks the same size as the input
    * Time: O(b) - we need to iterate through the binary representation bit by bit
    *
    * CODE:
    */

    uint32_t getNext(uint32_t positiveInteger) {
        uint32_t oneIndex = 0;   // index of the rightmost 1
        uint32_t zeroIndex = 0;  // index of the rightmost 0 that has 1s to the right of it

        if (positiveInteger == 0 || positiveInteger == UINT32_MAX) return -1;

        // find rightmost (i.e. least significant) "1" in bit sequence
        uint32_t positiveIntegerCopy = positiveInteger;
        while (positiveIntegerCopy != 0 && (positiveIntegerCopy & 1) != 1) {
            oneIndex ++;
            positiveIntegerCopy >>= 1;
        }

        // find rightmost non-trailing "0" in bit sequence that is more significant than "1" position
        positiveIntegerCopy = positiveInteger >> oneIndex + 1;  // for zero to be non-trailing, we need to right shift before checking
        zeroIndex += oneIndex + 1;
        while (positiveIntegerCopy != 0 && (positiveIntegerCopy & 1) != 0) {
            zeroIndex ++;
            positiveIntegerCopy >>= 1;
        }

        std::cout << "zeroIndex=" << zeroIndex << " \noneIndex=" << oneIndex << std::endl;
        std::cout << "positiveInteger before flips" << positiveInteger << std::endl;

        // flip the zeroIndex bit to 1
        positiveInteger = positiveInteger | (1 << zeroIndex);

        // clear all bits to the right of zeroIndex
        positiveInteger = positiveInteger & (UINT32_MAX << zeroIndex);

        // add in zeroIndex - oneIndex - 1 number of 1s to the end of the number (this accounts for examples like
        // 0b11011001111100 where zeroIndex and oneIndex are separated by ones that need to be added in least significant
        // places.
        positiveInteger = positiveInteger | ((1 << (zeroIndex - oneIndex - 1)) - 1);
        return positiveInteger;
    }

    uint32_t getPrev(uint32_t positiveInteger) {

        return positiveInteger;
    }
}
