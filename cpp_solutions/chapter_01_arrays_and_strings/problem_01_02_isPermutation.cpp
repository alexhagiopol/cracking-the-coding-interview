//
// Created by Alex Hagiopol on 8/21/17.
//
#include <string>
#include <bitset>
namespace chapter_01{
    bool isPermutation(const std::string& s1, const std::string& s2){
        if (s1.size() != s2.size()){
            return false;
        }
        std::bitset<128> asciiTable;
        for (char letter : s1){
            asciiTable.flip((int) letter);
        }
        for (char letter : s2){
            asciiTable.flip((int) letter);
        }
        return asciiTable.none();
    };
}
