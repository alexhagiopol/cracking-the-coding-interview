//
// Created by Alex Hagiopol on 8/24/17.
//
#include "LinkedListNode.h"

namespace chapter_02{
    template <typename T>
    LinkedListNode<T>* returnKthToLast(LinkedListNode<T>* head, int k){
        if (head == nullptr) return nullptr;
        LinkedListNode<T>* slowRunner = head;
        LinkedListNode<T>* fastRunner = head;
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
