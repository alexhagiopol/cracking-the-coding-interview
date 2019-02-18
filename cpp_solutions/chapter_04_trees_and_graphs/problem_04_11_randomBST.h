/*
Chapter 04 - Problem 11 - Random Node

Problem Statement:
You are implementing a binary search tree class from scratch, which, in addition to insert, find, and delete,
has a method getRandomNode() which returns a random node from the tree. All nodes should be equally likely to
be chosen. Design and implement an algorithm for getRandomNode(), and explain how you would implement the rest
of the methods.

Solution:
The obvious - but not necessarily optimal - solution is to create and maintain an array of pointers to each node in the
tree. When a random node is desired, a random number between zero and the maximum index of the array is generated and
the pointer at the random index is returned. This solution has a time complexity of O(1) for getRandomNode() calls and space
complexity of O(N) due to the space required for the array of pointers. If nodes were never removed from the tree, this
solution would be fine. However, if nodes are removed from the tree, modifying and resizing pointer array requires O(N) time.

A solution that is more optimal in the case of possible node removal is to randomly traverse the tree and
return the node reached after random traversal. In this case, adding nodes to the tree requires O(log(N)) time, removing
nodes from the tree requires O(log(N)) time, and getting a random node requires O(log(N)) time. The random traversal is
enabled by incrementing and decrementing each node's number of children during operations that insert or delete a node from
the tree. At each instance of a recursive traversal, the value of a random number is used to decide whether to
traverse left, traverse right, or return the current node. The probabilities of the choices will be proportional to the
number of nodes that each choice represents i.e. if a node has 4 left children and 3 right children, the probability to
return itself is 1/8, the probability to traverse left is 4/8, and the probability to traverse right is 3/8. Since random
number generator calls can be expensive, we employ an optimization in which we only generate a random number at the head
of the tree, then propagate the random value to the recursive traversals after accounting for the reduction in node children
at every level. This solution also uses O(N) space because each node must store its total number of children.

Time complexity: O(log(N)) for a balanced tree. O(D) for an unbalanced tree where D is the depth of the tree.
Space complexity: O(N) because the number of children must be stored for each node.
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"
#include <random>

namespace chapter_04 {
    // specialized node for binary trees that allow random node access
    template <typename T>
    class RandBinaryNode : public chapter_02::BinaryNode<T> {
    private:
        int _children;
    public:
        RandBinaryNode(
                T value,
                RandBinaryNode<T>* left = nullptr,
                RandBinaryNode<T>* right = nullptr,
                RandBinaryNode<T>* parent = nullptr) : chapter_02::BinaryNode<T>(value, left, right, parent) {
            _children = 0;
        }

        void insert(const T& value) {
            incrementChildren();
            if (value > this->getValue()) {
                if (this->getRight() != nullptr) {
                    static_cast<RandBinaryNode<T>*>(this->getRight())->insert(value);
                } else {
                    this->setRight(new RandBinaryNode<T>(value));
                }
            } else {
                if (this->getLeft() != nullptr) {
                    static_cast<RandBinaryNode<T>*>(this->getLeft())->insert(value);
                } else {
                    this->setLeft(new RandBinaryNode<T>(value));
                }
            }
        }

        RandBinaryNode<T>* getRandomNode(int randInt = -1, std::mt19937* gen = nullptr) {
            if (gen != nullptr) {
                std::uniform_int_distribution<> dis(1, 1 + getChildren());
                randInt = dis(*gen);
            }
            if (randInt <= 1) {
                return this;
            } else if (1 < randInt && randInt <= 1 + getLeftChildren()) {
                return static_cast<RandBinaryNode<T>*>(this->getLeft())->getRandomNode(randInt - 1, nullptr);
            } else {
                return static_cast<RandBinaryNode<T>*>(this->getRight())->getRandomNode(randInt - 1 - getLeftChildren(), nullptr);
            }
        }

        int getChildren() const { return _children; }

        int getLeftChildren() const {
            if (static_cast<RandBinaryNode<T>*>(this->getLeft()) == nullptr) {
                return 0;
            } else {
                return 1 + static_cast<RandBinaryNode<T>*>(this->getLeft())->getChildren();
            }
        }

        int getRightChildren() const {
            if (static_cast<RandBinaryNode<T>*>(this->getRight()) == nullptr) {
                return 0;
            } else {
                return 1 + static_cast<RandBinaryNode<T>*>(this->getRight())->getChildren();
            }
        }

        void incrementChildren() {_children ++;}
        void decrementChildren() {_children --;}
    };
}  // namespace chapter_04
