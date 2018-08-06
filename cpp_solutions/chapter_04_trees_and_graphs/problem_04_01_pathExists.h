//
// Created by Alex Hagiopol on 8/5/18.
//

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_04{
    template <typename T>
    bool pathExistsDFS(const chapter_02::GraphNode<T>* start, const chapter_02::GraphNode<T>* end){
        if (start == nullptr || end == nullptr) return false;
        if (start == end) return true;
        std::vector<chapter_02::GraphNode<T>*> nextChildren;
        start->getChildren(nextChildren);
        bool returnValue = false;
        for (chapter_02::GraphNode<T>* child : nextChildren){
            returnValue = returnValue || pathExistsDFS(child, end);
        }
        return returnValue;
    }
} // namespace chapter_04
