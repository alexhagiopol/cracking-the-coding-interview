/*
Chapter 04 - Problem 01 - Path Between Nodes

Problem Statement:
Given a directed graph, design an algorithm to find out whether there is a
route between two nodes.

Solution:
Use breadth first search (BFS) or depth first search (DFS) from node 1 to node 2.
If node 2 is found return true. If node 2 is not found, return false. This solution
implements DFS.

Time complexity: O(N)
Space complexity: O(N)
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_04{
    template <typename T>
    bool pathExistsDFS(const chapter_02::TetraGraphNode<T>* start, const chapter_02::TetraGraphNode<T>* end){
        if (start == nullptr || end == nullptr) return false;
        if (start == end) return true;
        std::vector<chapter_02::TetraGraphNode<T>*> nextChildren;
        start->getChildren(nextChildren);
        bool returnValue = false;
        for (chapter_02::TetraGraphNode<T>* child : nextChildren){
            returnValue = returnValue || pathExistsDFS(child, end);
        }
        return returnValue;
    }
} // namespace chapter_04
