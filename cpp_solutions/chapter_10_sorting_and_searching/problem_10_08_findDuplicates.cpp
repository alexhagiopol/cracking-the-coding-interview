#include "problem_10_08_findDuplicates.h"
#include <cstring>
#include <fstream>

namespace chapter_10 {
    // Returns pair associated with number
    std::pair<bool, bool> getPairValues(int number, const bool* array) {
        std::pair<bool, bool> pair;
        pair.first = array[(number - 1)];
        pair.second = array[(number - 1) + 16000];
        return pair;
    }

    // Sets pair associated with number
    void setPairValues(int number, bool* array, const std::pair<bool, bool>& pair) {
        array[(number - 1)] = pair.first;
        array[(number - 1) + 16000] = pair.second;
    }

    void findDuplicates(std::vector<int>& duplicates, const std::string& filepath) {
        bool bitVector[32000] = {false};

        // first pass of duplicate detection for values 1 to 16000
        std::ifstream file(filepath);
        std::string line = "";
        while (std::getline(file, line)){
            int number = std::stoi(line);
            if (number < 1 || number > 16000) continue;
            std::pair <bool, bool> pair = getPairValues(number, &bitVector[0]);
            if (!pair.first) {
                pair.first = true;
            }
            else {
                if (!pair.second) {
                    pair.second = true;
                }
            }
            setPairValues(number, &bitVector[0], pair);
        }
        file.close();

        // iterate over bit vector and add duplicates
        for (int number = 1; number <= 16000; number ++) {
            std::pair<bool, bool> pair = getPairValues(number, bitVector);
            if (pair.second) {
                duplicates.push_back(number);
            }
        }

        // reset bitVector
        memset(&bitVector[0], false, 32000 * sizeof(bool));

        // second pass of duplicate detection for values 16001 to 32000
        file.open(filepath);
        while (std::getline(file, line)){
            int number = std::stoi(line);
            number -= 16000;  // convert numbers from range 16001-32000 to range 1-16000
            if (number < 1 || number > 16000) continue;
            std::pair <bool, bool> pair = getPairValues(number, &bitVector[0]);
            if (!pair.first) {
                pair.first = true;
            }
            else {
                if (!pair.second) {
                    pair.second = true;
                }
            }
            setPairValues(number, &bitVector[0], pair);
        }
        file.close();

        // iterate over bit vector and add duplicates
        for (int number = 1; number <= 16000; number ++) {
            int convertedNumber = number + 16000;
            std::pair<bool, bool> pair = getPairValues(number, bitVector);
            if (pair.second) {
                duplicates.push_back(convertedNumber);
            }
        }
    }
}
