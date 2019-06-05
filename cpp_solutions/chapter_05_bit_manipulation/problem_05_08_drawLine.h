#pragma once
#include <string>

namespace chapter_05 {
    std::string stringifyScreen(const uint8_t* screen, uint32_t bitWidth, uint32_t bitLength);
    void drawLine(uint8_t* screen, uint32_t bitWidth, uint32_t bitLength, uint32_t x1, uint32_t x2, uint32_t y);
}
