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
