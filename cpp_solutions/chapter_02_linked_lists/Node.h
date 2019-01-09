//
// Created by Alex Hagiopol on 8/21/17.
//
#pragma once
#include <vector>

namespace chapter_02{
    // Node base class
    template <typename T>
    class Node{
    protected:
        T _value;
    public:
        Node(T value) : _value(value) {}  // constructor
        Node(const Node& other) : _value(other.getValue()) {}  // copy constructor
        ~Node(){}  // destructor
        bool operator== (const Node& other) {return _value == other.getValue();}  // equality check
        T getValue() const {return _value;}
        void setValue(const T& value) {_value = value;}
    };

    // specialized node for singly linked lists
    template <typename T>
    class SinglyLinkedNode : public Node<T>{
    private:
        SinglyLinkedNode* _next;
    public:
        SinglyLinkedNode(T value, SinglyLinkedNode* next = nullptr) : Node<T>(value), _next(next) {}  // constructor
        SinglyLinkedNode(const SinglyLinkedNode& other) : Node<T>::_value(other.getValue()), _next(other.getNext()){}  // copy constructor
        ~SinglyLinkedNode(){   // destructor
            _next = nullptr;
        }
        SinglyLinkedNode* getNext() const {return _next;}
        void setNext(SinglyLinkedNode* next) {_next = next;}
    };  // class SinglyLinkedNode

    // specialized node for 4-connected graphs
    template <typename T>
    class GraphNode : public Node<T>{
    private:
        GraphNode* _children[4];
    public:
        GraphNode(T value) : Node<T>(value) {
            _children[0] = nullptr;
            _children[1] = nullptr;
            _children[2] = nullptr;
            _children[3] = nullptr;
        }
        void addChild(GraphNode* child, int index) {
            if (index > 3 || index < 0) return;
            _children[index] = child;
        }
        void removeChild(int index) {
            if (index > 3 || index < 0) return;
            delete _children[index];
            _children[index] = nullptr;
        }
        void getChildren(std::vector<GraphNode*>& children) const {
            for (int i = 0; i < 4; i++){
                if (_children[i] != nullptr){
                    children.push_back(_children[i]);
                }
            }
        }
    };  //  class GraphNode

    // specialized node for binary trees
    template <typename T>
    class BinaryNode : public Node<T> {
    private:
        BinaryNode* _left;
        BinaryNode* _right;
    public:
        BinaryNode(T value) : Node<T>(value){
            _left = nullptr;
            _right = nullptr;
        }
        void addLeft(BinaryNode<T>* left) {
            _left = left;
        }
        void addRight(BinaryNode<T>* right) {
            _right = right;
        }
        BinaryNode<T>* getLeft() const {
            return _left;
        }
        BinaryNode<T>* getRight() const {
            return _right;
        }
        void removeLeft(){
            _left = nullptr;
        }
        void removeRight(){
            _left = nullptr;
        }
    };

    // utility function that converts contents of std::vector to linked list
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

    // utility function that converts contents of linked list to std::vector
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

    // utility function that converts contents of BST to std::vector using post order traversal
    template <typename T>
    void bstToVector(std::vector<T>& vector, const BinaryNode<T>* head) {
        if (head != nullptr) {
            bstToVector<T>(vector, head->getLeft());
            bstToVector<T>(vector, head->getRight());
            vector.push_back(head->getValue());
        }
    }
};  // namespace chapter_02

