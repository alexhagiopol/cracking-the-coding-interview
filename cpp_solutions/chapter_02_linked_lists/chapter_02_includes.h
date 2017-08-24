//
// Created by Alex Hagiopol on 8/21/17.
//

#pragma once
#include "problem_02_01_removeDups.cpp"
#include "problem_02_02_returnKthToLast.cpp"

namespace chapter_02{
    template <typename T>
    void removeDups(LinkedListNode<T>* head);  // problem 02-01
    template <typename T>
    LinkedListNode<T>* returnKthToLast(LinkedListNode<T>* head, int k);  // problem 02-02
}
