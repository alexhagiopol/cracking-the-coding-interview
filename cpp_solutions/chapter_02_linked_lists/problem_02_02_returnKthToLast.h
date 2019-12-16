#pragma once
#include "Node.h"

namespace chapter_02{
    template <typename T>
    std::shared_ptr<const SinglyLinkedNode<T>> returnKthToLast(const std::shared_ptr<const SinglyLinkedNode<T>> head, int k) {
        if (head == nullptr) return nullptr;
        std::shared_ptr<const SinglyLinkedNode<T>> slowRunner = head;
        std::shared_ptr<const SinglyLinkedNode<T>> fastRunner = head;
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
