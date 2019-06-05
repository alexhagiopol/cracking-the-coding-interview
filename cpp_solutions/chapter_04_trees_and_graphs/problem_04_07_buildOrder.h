/*
Chapter 04 - Problem 07 - Build Order

See problem_04_07_buildOrder.cpp for problem description.
*/
#include <vector>
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_04 {
    void buildOrder(std::vector<char>& projects, std::vector<std::pair<char, char>>& dependencies, std::vector<char>& buildOrder);
}  // namespace chapter_04
