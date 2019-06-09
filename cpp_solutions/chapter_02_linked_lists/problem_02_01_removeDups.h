#pragma once
#include "Node.h"
#include <unordered_map>

namespace chapter_02{
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
