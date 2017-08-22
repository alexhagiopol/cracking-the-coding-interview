//
// Created by Alex Hagiopol on 8/21/17.
//

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
            delete _next;
            _next = nullptr;
        }
        T getValue(){return _value;}
        LinkedListNode* getNext() {return _next;}
        void setValue(const T& value) {_value = value;}
        void setNext(const LinkedListNode& next) {_next = &next;}
    };
};
