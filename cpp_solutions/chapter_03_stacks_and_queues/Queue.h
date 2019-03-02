#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_03 {
    template <typename T>
    class Queue {
    private:
        chapter_02::SinglyLinkedNode<T>* _first;
        chapter_02::SinglyLinkedNode<T>* _last;
    public:
        Queue() {
            _first = nullptr;  // first element is the place where we *add* elements
            _last = nullptr;   // last element is the place from which we *remove* elements
            // first <- C <- B <- A <- last
            // nodes are linked "backwards" from last to first
        }

        bool isEmpty() const {return _last == nullptr;}

        void push(const T& data) {
            chapter_02::SinglyLinkedNode<T>* node = new chapter_02::SinglyLinkedNode<T>(data, nullptr);
            if (_first == nullptr || _last == nullptr) {  // if queue contains nothing, first and last element are the same
                _first = node;
                _last = node;
            } else {  // if queue contains something, connect new node to existing first node.
                _first->setNext(node);
                _first = node;
            }
        }

        T pop(){
            if (_last == nullptr) return static_cast<T>(0);
            T tempValue = _last->getValue();
            chapter_02::SinglyLinkedNode<T>* tempNode = _last;
            _last = _last->getNext();
            delete tempNode;
            return tempValue;
        }

        T peek() const {
            if (_last == nullptr) return static_cast<T>(0);
            return _last->getValue();
        }

        ~Queue(){
            while (_last != nullptr){
                chapter_02::SinglyLinkedNode<T>* tempNode = _last;
                _last = _last->getNext();
                delete tempNode;
            }
        }
    };
}
