#include "problem_10_02_anagramSort.h"
#include <map>
#include <algorithm>

namespace chapter_10 {
    void anagramSort(std::vector<std::string>& array) {
        std::map<std::string, std::vector<std::string>> hashMap;
        // traverse input array
        for (const std::string& string : array) {
            std::string sortedString = string;
            std::sort(sortedString.begin(), sortedString.end());
            // sortedString in hashMap
            if (hashMap.find(sortedString) != hashMap.end()) {
                hashMap[sortedString].push_back(string);
            }
            // if sortedString not in hashMap ...
            else {
                std::vector<std::string> anagramVector = {string};
                hashMap[sortedString] = anagramVector;
            }
        }
        // place all values contents of hashMap into array thus placing anagrams next to each other
        int index = 0;
        for (const std::pair<std::string, std::vector<std::string>> pair : hashMap) {
            for (const std::string& anagramString : pair.second) {
                array[index] = anagramString;
                index ++;
            }
        }
    }
}
