/*
Chapter 03 - Problem 04 - Queue Via Stacks

Problem Statement:
Implement a class which implements a queue using two stacks.

Solution:
A queue has two operations: enqueue() and dequeue(). The general idea is to always enqueue by
pushing items onto stack 1. When dequeue() is called we check if stack 2 is empty. If stack 2 is
not empty, we pop off of stack 2 to return the item expected for dequeue(). If stack 2 is empty,
we pop every item off of stack 1 and push it onto stack 2. Thus, stack 1 contains the items in
LIFO order while stack 2 contains the items in FIFO order. If we push into stack 1 and pop off
of stack 2, we will implement a queue.

Time complexity: O(1) for enqueue(). O(1) amortized for dequeue().
Space complexity: O(N) - we only store each item once.
*/

#pragma once
#include "Stack.h"

namespace chapter_03{
    template <typename T>
    class QueueViaStacks{
    protected:
        chapter_03::Stack<T> _enqStack;  // LIFO stack to enqueue onto
        chapter_03::Stack<T> _deqStack;  // FIFO stack to dequeue off of
    public:
        QueueViaStacks() : _enqStack(Stack<T>()), _deqStack(Stack<T>()) {}
        bool isEmpty(){return _enqStack.isEmpty() && _deqStack.isEmpty();}
        void enqueue(const T& value){ _enqStack.push(value); }
        T dequeue(){
            if (isEmpty()) return static_cast<T>(0);  // dequeueing empty queue returns 0
            if (_deqStack.isEmpty()){  // move items from enqStack to deqStack if there is nothing to dequeue
                while (!_enqStack.isEmpty()){
                    _deqStack.push(_enqStack.pop());
                }
            }
            return _deqStack.pop();
        }
    };
}; // namespace chapter_03