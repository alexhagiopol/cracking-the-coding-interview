#include <cassert>

#include "problem_03_01_threeInOne.h"

namespace chapter_03 {

MultiStack::MultiStack(const std::size_t stack_num) :
    data(stack_num * 10 + 1), data_idx(1), stack_heads(stack_num, 0), free_list_head(0), stack_num(stack_num)
{}

void MultiStack::push(const std::size_t stack_num, const TVal & val) {
    assert(stack_num < this->stack_num);

    if(data_idx >= data.capacity()) {
        data.resize(data.capacity() * 2);
    }

    std::size_t & stack_head = stack_heads[stack_num]; // zero by default

    if(free_list_head > 0) {
        const auto free_list_head_new = data[free_list_head].first;
        data[free_list_head].first = stack_head; // the index of the previous item
        data[free_list_head].second = val;
        stack_head = free_list_head;
        free_list_head = free_list_head_new;
    } else {
        data[data_idx].first = stack_head; // the index of the previous item
        data[data_idx].second = val;
        stack_head = data_idx;
        ++data_idx;
    }
}

MultiStack::TVal MultiStack::pop(const std::size_t stack_num) {
    assert(stack_num < this->stack_num);

    std::size_t & stack_head = stack_heads[stack_num]; // zero by default
    assert(stack_head > 0);
    const auto stack_head_prev = stack_head;
    stack_head = data[stack_head_prev].first;
    data[stack_head_prev].first = free_list_head;
    free_list_head = stack_head_prev;
    return data[stack_head_prev].second;
}

MultiStack::TVal & MultiStack::get(const std::size_t stack_num) {
    assert(stack_num < this->stack_num);
    const std::size_t stack_head = stack_heads[stack_num]; // zero by default
    assert(stack_head > 0);
    return data[stack_head].second;
}

}

