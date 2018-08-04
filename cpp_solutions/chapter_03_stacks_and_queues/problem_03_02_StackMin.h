/*
Chapter 03 - Problem 02 - Stack Min

Problem Statement:
Implement a stack which, in addition to push and pop, has a function min
which returns the minimum element. Push, pop and min should all operate in 0(1) time.

Solution:
StackMin will be a derived class of Stack that - along with implementing the normal
stack data structure - will keep a second stack of minimum values. When a value is pushed to
the stack that is less than the value at the top of the min stack, both the min stack and
the main stack are pushed upon. When a stack value is popped off that equals the value
at the top of the min stack, both the min stack and the main stack are popped. The best
case space complexity is O(1) for the min stack and O(N) for the main stack. This is the
case in which we have N of the same large numbers and 1 small number. The worst case space
complexity is O(N) for the min stack and O(N) for the main stack. This is the case in which
N numbers are pushed onto the stack in monotonically descending order.

Time complexity: O(1)
Space complexity: O(2N)
*/

#pragma once
#include "Stack.h"

namespace chapter_03{
    template <typename T>
    class StackMin : public chapter_03::Stack<T> {
    private:
        chapter_03::Stack<T> _minStack;
    public:
        StackMin(){
            _minStack = chapter_03::Stack<T>();
        }
        // override push() function from base class
        void push(const T& data){
            if (_minStack.isEmpty() || data < _minStack.peek()){ // new min found
                _minStack.push(data);
                chapter_03::Stack<T>::push(data);
            }
        }
        // override pop() function from base class
        T pop(){
            if (!chapter_03::Stack<T>::isEmpty() && chapter_03::Stack<T>::_head->getValue() <= _minStack.peek()){
                T temp = _minStack.pop();
            }
            return chapter_03::Stack<T>::pop();
        }

        T seeMin(){
            return _minStack.peek();
        }

    }; // class StackMin
}; // namespace chapter_03
