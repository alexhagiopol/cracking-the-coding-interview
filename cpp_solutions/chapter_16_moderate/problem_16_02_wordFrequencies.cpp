#include "problem_16_02_wordFrequencies.h"

namespace chapter_16 {
    void trimCopy(std::string& target, const std::string& source) {
        for (char c : source) {
            char c_lower = static_cast<char>(std::tolower(c));
            if (c_lower >= 97 && c_lower <= 122) {
                target += c_lower;
            }
        }
    }

    void makeDatabase(const std::vector<std::string>& book, std::unordered_map<std::string, int>& database) {
        for (const std::string& word : book) {
            std::string trimmedWord;
            trimCopy(trimmedWord, word);
            if (!trimmedWord.empty()) {
                if (database.count(trimmedWord) == 0) {
                    database[trimmedWord] = 1;
                }
                else {
                    database[trimmedWord] ++;
                }
            }
        }
    }

    int wordFrequencies(const std::string& word, const std::unordered_map<std::string, int>& database) {
        return database.count(word) ? database.at(word) : 0;
    }
}

