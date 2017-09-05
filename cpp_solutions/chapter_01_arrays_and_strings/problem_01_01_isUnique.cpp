//
// Created by alex on 7/31/17.
//

#include "problem_01_01_isUnique.h"
#include <string>
#include <iostream>
#include <bitset>

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
