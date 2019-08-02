/*
 * PROBLEM:
 * Implement a smart pointer class that performs reference counting.
 * I.e. implement a class that performs the work a programmer would have
 * to perform if using raw pointers.
 *
 * ALGORITHM:
 * The times when an object's reference count would have to be adjusted
 * are when the object is (1) constructed, (2) copied, or (3) destructed.
 * Case (2) is covered by the copy constructor and copy assignment operator.
 * The textbook does not cover a move constructor and move assignment operator,
 * although for C++ 11 and beyond, we should.
 *
 * We thus implement a constructor, copy constructor, copy assignment operator,
 * and a destructor that are member functions of a SmartPointer class template. Member
 * variables of the SmartPointer class are a pointer to an actual object and a
 * pointer to a reference count. Note that it is crucial that these are pointers:
 * there can be only one object and only one reference count in memory for one
 * object of interest. The member functions increment and decrement the reference
 * counter as needed and delete the object when the reference counter reaches 0.
 *
 * The way to test this functionality (see tests.cpp) is to
 * use lambda functions to simulate copies of the SmartPointer object coming onto
 * and off of the call stack and check the reference count before and after the lambda
 * is executed.
 *
 * TIME COMPLEXITY: O(1)
 * SPACE COMPLEXITY: O(1)
 */

#pragma once

namespace chapter_12 {
    template <typename T>
    class SmartPointer {
    protected:
        T* _obj;
        size_t* _referenceCount;
        void remove() {
            (*_referenceCount) --;
            if ((*_referenceCount) == 0) {
                delete _obj;
                delete _referenceCount;
            }
        }
    public:
        // regular constructor
        SmartPointer(T* object) : _obj(object), _referenceCount(new size_t(1)) {};
        // copy constructor
        SmartPointer(const SmartPointer& other) : _obj(other._obj) {
            _referenceCount = other._referenceCount;
            (*_referenceCount) ++;
        }
        // assignment operator
        SmartPointer& operator=(const SmartPointer& other) {
            if (this == &other) {
                return *this;
            }
            remove();
            _obj = other._obj;
            _referenceCount = other._referenceCount;
            (*_referenceCount) ++;
            return *this;
        }
        // destructor
        ~SmartPointer() {
            remove();
        }
        // getters and setters
        T getValue() const {return *_obj;}
        void setValue(T objectValue) {*_obj = objectValue;}
        size_t getRefCount() {return *_referenceCount;}
    };
}