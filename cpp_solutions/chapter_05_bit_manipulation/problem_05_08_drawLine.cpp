//
// Created by alex on 6/3/2019.
//
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
        std::string stringScreen(byteLength * 8 + byteWidth * height, ' ');
        int i = 0;
        for (int r = 0; r < height; r++) {
            for (int c = 0; c < byteWidth; c++) {
                uint8_t currentByte = screen[r * byteWidth + c];
                for (int b = 0; b < 8; b++) {
                    stringScreen[i] = static_cast<char>(((currentByte >> b) & 1) + 48);  // ASCII table: 48 = 0; 49 = 1
                    i++;
                }
                stringScreen[i] = '\n';
                i++;
            }
        }
        return stringScreen;
    }
}
