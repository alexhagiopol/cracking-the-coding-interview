#include "problem_10_07_missingInt.h"
#include <iostream>
#include <fstream>
#include <istream>


namespace chapter_10 {
    uint32_t missingInt(const std::string& filename) {
        // problem 10.7 specifies a max value of 2^32 = 0xFFFFFFFF ~= 4,294,967,296
        // for reasonable test dataset size, we use a smaller range of [0,2000]
        // create a bitVector with one bit for each possible number
        const int numberRange = 1000;
        bool bitVector[numberRange + 1] = {false};
        // problem 10.7 specifies 4 billion numbers, for testing speed, we only read 4000
        // read integers from file
        std::ifstream file(filename);
        std::string line = "";
        while (std::getline(file, line)){
            uint32_t number = static_cast<uint32_t>(std::stoi(line));
            if (0 <= number && number <= numberRange && !bitVector[number]) bitVector[number] = true;
        }
        // search bitVector for first occurrence of unique number
        for (uint32_t i = 0; i <= numberRange; i++) {
            if (!bitVector[i]) return static_cast<uint32_t>(i);
        }
        return -1;
    }
}
