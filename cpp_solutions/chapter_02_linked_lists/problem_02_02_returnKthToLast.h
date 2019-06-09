#pragma once
#include "Node.h"

namespace chapter_02{
    template <typename T>
    SinglyLinkedNode<T>* returnKthToLast(SinglyLinkedNode<T>* head, int k){
        if (head == nullptr) return nullptr;
        SinglyLinkedNode<T>* slowRunner = head;
        SinglyLinkedNode<T>* fastRunner = head;
        while(k > 0){
            if (fastRunner == nullptr) return nullptr;
            fastRunner = fastRunner->getNext();
            k--;
        }
        while (fastRunner != nullptr){
            slowRunner = slowRunner->getNext();
            fastRunner = fastRunner->getNext();
        }
        return slowRunner;
    }
}
