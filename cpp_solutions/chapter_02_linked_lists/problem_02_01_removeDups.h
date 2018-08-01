//
// Created by Alex Hagiopol on 9/5/17.
//
#pragma once
#include "SinglyLinkedNode.h"
#include <unordered_map>

namespace chapter_02{
    // template function implemented in header file
    template <typename T>
    void removeDups(SinglyLinkedNode<T>* head){
        SinglyLinkedNode<T>* slowRunner = head;
        if (slowRunner == nullptr || slowRunner->getNext() == nullptr) return;  // a list of length 0 or 1 cannot have dups
        SinglyLinkedNode<T>* fastRunner = slowRunner->getNext();
        std::unordered_map<T, bool> hashTable;
        hashTable[slowRunner->getValue()] = true;
        while (fastRunner != nullptr){
            if (hashTable.count(fastRunner->getValue())){
                slowRunner->setNext(fastRunner->getNext());
                fastRunner->setNext(nullptr);
                delete fastRunner;
                fastRunner = slowRunner->getNext();
            } else {
                hashTable[fastRunner->getValue()] = true;
                slowRunner = fastRunner;
                fastRunner = fastRunner->getNext();
            }
        }
    }
}
