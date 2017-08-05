//
// Created by alex on 7/31/17.
//

#include <string>
#include <iostream>

namespace chapter_01 {
    bool isUnique(const std::string input) {
        bool bitVector[128] = {false};
        for (char character : input) {
            if (bitVector[int(character)] == true) {  // if character already exists in "hash table"
                return false;
            }
            bitVector[int(character)] = true;
        }
        return true;
    }
}
