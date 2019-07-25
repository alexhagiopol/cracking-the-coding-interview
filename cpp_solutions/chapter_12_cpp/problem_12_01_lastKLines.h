/*
 * PROBLEM:
 * Read the last K lines of a file.
 *
 * TEST CASE:
 * We would provide a text file with multiple lines
 * and test for equality against the last K lines.
 * Edge cases include empty file and file with less
 * than K lines.
 *
 * ALGORITHM:
 * We can maintain a circular array of length K. We can
 * implement this circular array as a circular singly linked
 * list whose node values are std::string. Initially, each
 * string has an empty value.
 *
 * After the circularly linked list of K nodes is initialized,
 * we assign a runner pointer to a node in the list.
 *
 * As we read the input text file line by line, we store the
 * contents of the line in the node to which the runner
 * currently points. We then advance the pointer without regard
 * to overwriting node contents. In this way, the runner always
 * points to either an empty string or the oldest line.
 *
 * Once the file is done reading, the pointer can be advanced
 * K times to copy data from the circular array to a non-circular
 * std::vector of std::strings for testing.
 *
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 */

/*
#pragma once
#include "../chapter_02_linked_lists/Node.h"
#include <vector>
#include <string>
//#include <cstring>
//#include <iostream>
#include <fstream>
//#include <istream>

namespace chapter_12 {
    void lastKLines(std::vector<std::string> lines, const std::string& filepath) {
        int K = lines.size();
        if (K <= 0) return; // handle empty lines vector
        // initialize circular array
        auto head = new chapter_02::SinglyLinkedNode<std::string>("");
        auto prev = head;
        for (int i = 1; i < K; i++) {
            auto node = new chapter_02::SinglyLinkedNode<std::string>("");
            prev->setNext(node);
            prev = node;
        }
        prev->setNext(head);
        // read from file
        std::ifstream file(filepath);
        std::string line = "";
        while (std::getline(file, line)){

        }
    }
}
*/