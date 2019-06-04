#pragma once
#include <string>

namespace chapter_05 {
    std::string stringifyScreen(const uint8_t* screen, uint32_t bitWidth, uint32_t bitLength);
    void drawLine(uint8_t* screen, uint32_t bitWidth, uint32_t bitLength);
}
