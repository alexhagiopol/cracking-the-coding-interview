/*
PROBLEM:
A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte.
The screen has width W which is a multiple of 8. So, a screen with dimensions 2x16 will require 2x2 8-bit
integers to represent it. The goal is to write a program to draw a horizontal line given coordinates (x1, y) and (x2, y).

TEST CASES:
x1 = 1
x2 = 14
y = 1

00000000 00000000 00000000 00000000             00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000    -->      01111111 11111111 11111111 11111110
00000000 00000000 00000000 00000000             00000000 00000000 00000000 00000000

x1 = 1
x2 = 7
y = 1

00000000 00000000 00000000 00000000             00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000    -->      01111111 00000000 00000000 00000000
00000000 00000000 00000000 00000000             00000000 00000000 00000000 00000000

ALGORITHM:
Determine in which bytes x1 and x2 reside. Handle the following cases:
1. x1 < 0 || x1 > W || x2 < 0 || x2 > W || x2 > x1 || y < 0 || y > height
    Do nothing. Invalid input.
2. x1 and x2 in the same byte:
    Add (x2 - x1 + 1) 1s and left shift them by 8 - x2.
3. x1 and x2 are one whole byte apart or more
    Set all in-between bytes to 0xFF. Assign the appropriate number of 1s to the x1 and x2 bytes by left shifting a 1 and then subtracting 1.

SPACE & TIME:
Time: O(W): the number of operations required to do this procedure scale linearly with W.
Space: O(1): the amount of extra memory required to do this procedure does not scale with the input size

CODE:
*/

#include "problem_05_08_drawLine.h"
#include <assert.h>
#include <iostream>

namespace chapter_05 {
    std::string stringifyScreen(const uint8_t* screen, uint32_t bitWidth, uint32_t bitLength) {
        assert((bitWidth % 8) == 0);
        assert((bitLength % 8) == 0);
        int byteWidth = bitWidth / 8;
        int byteLength = bitLength / 8;
        assert((byteLength % byteWidth) == 0);
        int height = byteLength / byteWidth;
        // we use one character for each pixel plus byteWidth * height extra characters for spaces and newline characters
        std::string stringScreen(bitLength + height, ' ');
        int i = 0;
        for (int r = 0; r < height; r++) {
            for (int c = 0; c < byteWidth; c++) {
                uint8_t currentByte = screen[r * byteWidth + c];
                for (int b = 0; b < 8; b++) {
                    stringScreen[i] = static_cast<char>(((currentByte >> b) & 1) + 48);  // ASCII table: 48 = 0; 49 = 1
                    i++;
                }
                if (c == (byteWidth - 1)) {
                    stringScreen[i] = '\n';
                    i++;
                }
            }
        }
        return stringScreen;
    }

    void drawLine(
            uint8_t* screen,
            uint32_t bitWidth,
            uint32_t bitLength,
            uint32_t x1,
            uint32_t x2,
            uint32_t y) {

    }
}
