/*
Chapter 12 - Problem 08 - Copy Node

Problem Statement:
Write a method that takes a pointer to a Node structure as a parameter
and returns a complete copy of the passed in data structure. The Node
data structure contains two pointers to other Nodes.

Solution:
For ease of testability, we will use SinglyLinkedNode for this problem
despite the fact that it contains a pointer to only one other node. The
difference in implementation for a node with two children is only one extra
line of code with a recursive call.
We recursively explore the linked list, creating a new node for each node
we find along the way.

Time complexity: O(N) - one operation is done for each connected node.
Space complexity: O(N) - because of recursion, N function calls go on the stack.
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_12{
    template <typename T>
    chapter_02::SinglyLinkedNode<T>* copyNode(const chapter_02::SinglyLinkedNode<T>* target){
        if (target == nullptr){
            return nullptr;
        }
        return new chapter_02::SinglyLinkedNode<T>(target->getValue(), copyNode(target->getNext()));
    }
}