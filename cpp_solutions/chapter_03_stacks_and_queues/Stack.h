#pragma once
#include "chapter_02_linked_lists/Node.h"

namespace chapter_03{
    template <typename T>
    class Stack{
    protected:
        std::shared_ptr<chapter_02::SinglyLinkedNode<T>> _head;
        int _stackSize;
    public:
        Stack(){
            _head = nullptr;
            _stackSize = 0;
        }
        // check if stack is empty
        bool isEmpty() const {return _head == nullptr;}
        // add item to top of stack
        virtual void push(const T& data) {
            auto node = std::make_shared<chapter_02::SinglyLinkedNode<T>>(data, _head);
            _head = node;
            _stackSize ++;
        }
        // remove item from top of stack
        virtual T pop(){
            if (_head != nullptr){
                auto temp = _head;
                T tempValue =  temp->getValue();
                _head = _head->getNext();
                _stackSize --;
                return tempValue;
            } else {
                return static_cast<T>(0);  // nothing to return if stack is empty;
            }
        }
        // inspect item at top of stack without removing
        T peek(){
            if (_head != nullptr){
                return _head->getValue();
            } else {
                return static_cast<T>(0);  // nothing to return if stack is empty;
            }
        }
        int stackSize() const {return _stackSize;}
        // destructor
        ~Stack(){
            while (_head != nullptr){
                auto temp = _head;
                _head = _head->getNext();
            }
        }

        // compare values in stack top-to-bottom to values in vector front-to-back for easy unit testing
        bool operator==(const std::vector<T>& vector){
            auto temp = _head;
            for (T item : vector){
                if (temp == nullptr || item != temp->getValue()){
                    return false;  // vector length > stack height
                }
                if (item != temp->getValue()){
                    return false;  // value inequality
                }
                temp = temp->getNext();
            }
            if (temp != nullptr) return false; // stack height > vector length
            return true;
        }
        bool operator!=(const std::vector<T>& vector){
            return !(*this==vector);
        }
    }; // class Stack
}; // namespace chapter_03
