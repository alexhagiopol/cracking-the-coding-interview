//
// Created by Alex Hagiopol on 8/21/17.
//
#pragma once
#include <vector>

namespace chapter_02{
    template <typename T>
    class LinkedListNode{
    private:
        T _value;
        LinkedListNode* _next;
    public:
        LinkedListNode(T value, LinkedListNode* next = nullptr) : _value(value), _next(next) {}  // constructor
        bool operator== (const LinkedListNode& other) {return _value == other.getValue();}  // equality check
        LinkedListNode(const LinkedListNode& other) : _value(other.getValue()), _next(other.getNext()){}  // copy constructor
        ~LinkedListNode(){   // destructor
            _next = nullptr;
        }
        T getValue(){return _value;}
        LinkedListNode* getNext() {return _next;}
        void setValue(const T& value) {_value = value;}
        void setNext(LinkedListNode* next) {_next = next;}
    };

    template <typename T>
    LinkedListNode<T>* vectorToList(const std::vector<T> numbers){
        if(numbers.size() <= 0){
            return nullptr;
        }
        LinkedListNode<T>* head = new LinkedListNode<T>(numbers[0]);
        LinkedListNode<T>* runner = head;
        for (int i = 1; i < numbers.size(); i++ ){
            LinkedListNode<T>* temp = new LinkedListNode<T>(numbers[i]);
            runner->setNext(temp);
            runner = runner->getNext();
        }
        return head;
    }

    template <typename T>
    std::vector<T> listToVector(LinkedListNode<T>* head){
        std::vector<T> vector;
        LinkedListNode<T>* runner = head;
        while (runner != nullptr){
            vector.push_back(runner->getValue());
            runner = runner->getNext();
        }
        return vector;
    }
};

