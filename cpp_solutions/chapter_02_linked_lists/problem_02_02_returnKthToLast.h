//
// Created by Alex Hagiopol on 9/5/17.
//
#pragma once
#include "LinkedListNode.h"

namespace chapter_02{
    template <typename T>
    LinkedListNode<T>* returnKthToLast(LinkedListNode<T>* head, int k);
}

#include "problem_02_02_returnKthToLast.cpp"  // include implementation of template function