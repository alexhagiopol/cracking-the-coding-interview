#pragma once
#include <vector>

namespace chapter_02{
    // Node base class
    template <typename T>
    class Node{
    private:
        T _value;
    public:
        Node(const T& value) : _value(value) {}  // constructor
        Node(const Node& other) : _value(other.getValue()) {}  // copy constructor
        virtual ~Node(){}  // destructor
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
        ~SinglyLinkedNode(){}
        SinglyLinkedNode* getNext() const {return _next;}
        void setNext(SinglyLinkedNode* next) {_next = next;}
    };  // class SinglyLinkedNode

    // general graph node. supports infinite number of children by maintaining pointer to head of linked list of child pointers
    template <typename T>
    class GraphNode : public Node<T> {
    private:
        SinglyLinkedNode<GraphNode<T>*>* _head;
        SinglyLinkedNode<GraphNode<T>*>* _tail;
        int _numAncestors;
    public:
        GraphNode(T value) : Node<T>(value) {
            _head = nullptr;
            _tail = nullptr;
        }
        void push(GraphNode<T>* node) {
            if (_head == nullptr) {
                _head = new SinglyLinkedNode<GraphNode<T>*>(node);
                _tail = _head;
            } else {
                _tail->setNext(new SinglyLinkedNode<GraphNode<T>*>(node));
                _tail = _tail->getNext();
            }
        }
        GraphNode<T>* pop() {
            if (_head == nullptr) {
                return nullptr;
            }
            GraphNode<T>* tempGN = _head->getValue();
            if (_tail == _head) {
                _head = nullptr;
                _tail = nullptr;
            } else {
                SinglyLinkedNode<GraphNode<T>*>* tempHead = _head;
                _head = _head->getNext();
                delete tempHead;
            }
            return tempGN;
        }
        void incAncestors() {
            _numAncestors ++;
        }
        void decAncestors() {
            _numAncestors --;
        }
        int getNumAncestors() {
            return _numAncestors;
        }
        SinglyLinkedNode<GraphNode<T>*>* getHeadOfDescendants() {
            return _head;
        }
    };

    // specialized node for 4-connected graphs; a specific child node can be retrieved in constant time
    template <typename T>
    class TetraGraphNode : public Node<T>{
    private:
        TetraGraphNode* _children[4];
    public:
        TetraGraphNode(T value) : Node<T>(value) {
            _children[0] = nullptr;
            _children[1] = nullptr;
            _children[2] = nullptr;
            _children[3] = nullptr;
        }
        void addChild(TetraGraphNode* child, int index) {
            if (index > 3 || index < 0) return;
            _children[index] = child;
        }
        void removeChild(int index) {
            if (index > 3 || index < 0) return;
            delete _children[index];
            _children[index] = nullptr;
        }
        void getChildren(std::vector<TetraGraphNode*>& children) const {
            for (int i = 0; i < 4; i++){
                if (_children[i] != nullptr){
                    children.push_back(_children[i]);
                }
            }
        }
    };  //  class TetraGraphNode

    // specialized node for binary trees
    template <typename T>
    class BinaryNode : public Node<T> {
    private:
        BinaryNode<T>* _left;
        BinaryNode<T>* _right;
        BinaryNode<T>* _parent;
    public:
        BinaryNode(T value, BinaryNode<T>* left = nullptr, BinaryNode<T>* right = nullptr, BinaryNode<T>* parent = nullptr) : Node<T>(value){
            _left = left;
            _right = right;
            _parent = parent;
        }
        void setLeft(BinaryNode<T>* left) {
            _left = left;
        }
        void setRight(BinaryNode<T>* right) {
            _right = right;
        }
        void setParent(BinaryNode<T>* parent) {
            _parent = parent;
        }
        BinaryNode<T>* getLeft() const {
            return _left;
        }
        BinaryNode<T>* getRight() const {
            return _right;
        }
        BinaryNode<T>* getParent() const {
            return _parent;
        }
        void removeLeft(){
            _left = nullptr;
        }
        void removeRight(){
            _right = nullptr;
        }
        void removeParent(){
            _parent = nullptr;
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

