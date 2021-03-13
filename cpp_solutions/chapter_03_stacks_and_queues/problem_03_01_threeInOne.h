/*
Chapter 03 - Problem 01 - Three in One

Problem Statement:
Describe how you could use a single array to implement three stacks

Explanation:
    Each stack item has two elements: an index of the previous item and a payload.

    For
    push(0, 11);
    push(1, 21);
    push(0, 12);
    push(1, 22);
    push(0, 13);

    The data array would be
    [(0, 0), (0, 11), (0, 21), (1, 12), (2, 22), (3, 13)]

    In this array, the first stack head index is 5 with the previous index 3 and the payload 13
    Second stack head index is 4 with the previous index 2 and payload 22

Time complexity: amortized O(1)
Space complexity: O(2n)
*/

#pragma once
#include <utility>
#include <vector>

namespace chapter_03{
class MultiStack {
public:
    typedef int TVal;

    //<index, value>
    typedef std::pair<std::size_t, TVal> TPair;

    MultiStack(const std::size_t stack_num);

    void push(const std::size_t stack_num, const TVal & val);
    TVal pop(const std::size_t stack_num);
    TVal & get(const std::size_t stack_num);
private:
    std::vector<TPair> data;
    std::size_t data_idx;
    std::vector<std::size_t> stack_heads;
    std::size_t free_list_head;
    const std::size_t stack_num;
};
}; // namespace chapter_03
