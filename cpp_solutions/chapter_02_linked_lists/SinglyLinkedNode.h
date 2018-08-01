//
// Created by Alex Hagiopol on 8/21/17.
//
#pragma once
#include <vector>

namespace chapter_02{
    template <typename T>
    class SinglyLinkedNode{
    private:
        T _value;
        SinglyLinkedNode* _next;
    public:
        SinglyLinkedNode(T value, SinglyLinkedNode* next = nullptr) : _value(value), _next(next) {}  // constructor
        bool operator== (const SinglyLinkedNode& other) {return _value == other.getValue();}  // equality check
        SinglyLinkedNode(const SinglyLinkedNode& other) : _value(other.getValue()), _next(other.getNext()){}  // copy constructor
        ~SinglyLinkedNode(){   // destructor
            _next = nullptr;
        }
        T getValue() const {return _value;}
        SinglyLinkedNode* getNext() const {return _next;}
        void setValue(const T& value) {_value = value;}
        void setNext(SinglyLinkedNode* next) {_next = next;}
    };  // class SinglyLinkedNode

    template <typename T>
    SinglyLinkedNode<T>* vectorToList(const std::vector<T> numbers){
        if(numbers.size() <= 0){
            return nullptr;
        }
        SinglyLinkedNode<T>* head = new SinglyLinkedNode<T>(numbers[0]);
        SinglyLinkedNode<T>* runner = head;
        for (int i = 1; i < numbers.size(); i++ ){
            SinglyLinkedNode<T>* temp = new SinglyLinkedNode<T>(numbers[i]);
            runner->setNext(temp);
            runner = runner->getNext();
        }
        return head;
    }

    template <typename T>
    std::vector<T> listToVector(SinglyLinkedNode<T>* head){
        std::vector<T> vector;
        SinglyLinkedNode<T>* runner = head;
        while (runner != nullptr){
            vector.push_back(runner->getValue());
            runner = runner->getNext();
        }
        return vector;
    }
};  // namespace chapter_02

