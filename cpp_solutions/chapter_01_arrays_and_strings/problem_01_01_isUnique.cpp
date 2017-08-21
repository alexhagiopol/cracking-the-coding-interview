//
// Created by alex on 7/31/17.
//

#include <string>
#include <iostream>

namespace chapter_01 {
    bool isUnique(const std::string& input) {
        std::bitset<128> asciiTable;
        for (char character : input) {
            if (asciiTable[(int) character]) {  // if character already exists in "hash table"
                return false;
            }
            asciiTable.flip((int) character);
        }
        return true;
    }
}
