/*
Chapter 03 - Problem 05 - Sort Stack

Problem Statement:
Write a program to sort a stack such that the smallest items are on the top. You can use an
additional temporary stack, but you may not copy the elements into any other data structure
(such as an array). The stack supports the following operations: push(), pop(), peek(), and isEmpty().

Solution:
We sort a stack with N items by using an additional stack of up to size N and a single
temporary variable of size 1. We start with a full "left" stack and an empty "right"
stack. We first (1) pop every item off of the left stack and push each item onto the right
stack. During step (1), we fill the temporary variable with the smallest item seen so far.
In step (2), we pop every item off of the right stack back onto the left stack. However, when we encounter
the smallest item, we do *not* pop it back onto the left stack and instead just keep track of it with
the temporary variable. Once the right stack is empty, we pop the smallest item into the right stack
thus establishing the "first" item of the new, sorted stack. We then (3) repeat steps (1) and (2) while ignoring
the already sorted items in the right stack.

Time complexity: O(N)
Space complexity: O(N)
*/

namespace chapter_03 {
    template <typename T>
    void sortStack(chapter_03::Stack<T>& stack) {
        chapter_03::Stack<T> rightStack;
        T temp = static_cast<T>(std::numeric_limits<T>::max());
        int stackSize = stack.stackSize();
        for (int i = 0; i < stackSize; i++) {
            // transfer from left to right
            while (!stack.isEmpty()) {
                T currentItemLeft = stack.pop();
                if (currentItemLeft <= temp) temp = currentItemLeft;
                rightStack.push(currentItemLeft);
            }
            // transfer from right to left
            for (int j = 0; j < stackSize - i; j ++) {  // ignore sorted items
                T currentItemRight = rightStack.pop();
                if (currentItemRight != temp) stack.push(currentItemRight);
            }
            rightStack.push(temp);  // place sorted item
            temp = static_cast<T>(std::numeric_limits<T>::max());
        }
        while(!rightStack.isEmpty()){
            stack.push(rightStack.pop());  // copy sorted items to input stack
        }
    }
}
