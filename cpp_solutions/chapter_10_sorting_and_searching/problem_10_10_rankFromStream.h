/*
 * PROBLEM:
 * Assuming we are reading in a stream of integers, write code to look up the rank of a given integer
 * in the stream. The rank of an integer is equal to the number of integers less than or equal to it.
 * Assume that a function track(x) is called on every member of the stream. Also assume that a
 * function getRank(x) is called to compute the rank.
 *
 * TEST CASE:
 * track(5);
 * track(1);
 * track(4);
 * track(4);
 * track(5);
 * track(9);
 * track(7);
 * track(13);
 * track(3);
 * track(6);
 * track(7);
 * getRank(1) = 0;
 * getRank(3) = 1;
 * getRank(4) = 3;
 * getRank(0) = -1;
 * getRank(7) = 8;
 * getRank(13) = 10;
 * getRank(6) = 6;
 *
 * ALGORITHM:
 * Implement a binary search tree where each node's value is the value of a number
 * in the stream. Each track() call will take O(log(N)) time and each getRank()
 * call will also take O(log(N)) time.
 *
 *                                                   5(2)
 *                                                 /   \
 *                                                1     9
 *                                                 \   /  \
 *                                               4(2) 7(2) 13
 *                                                /  /
 *                                               3  6
 * In both cases the tree will have to be traversed. In the case of track(), we will traverse
 * the tree until we find the correct node placement for a gien number. In the case of getRank(), we
 * traverse the tree to find the node we are looking for (return -1 if we do not find it)
 * then count all nodes to the left of the target node. We can optimize this counting procedure
 * by storing the number of left children per node as the tree is being built up. The
 * number of nodes to the left of a given node is equal to the sum of a given node's left children
 * plus all left-branch ancestors and their children. We can keep track of duplicate numbers also within
 * this left children count: simply add to left children when a duplicate is encountered. In this way,
 * the algorithm will account for duplicates when computing rank.
 *
 * To compute the rank, we traverse the tree and increment a rank counter by the current node's number of
 * left children every time we traverse right. If we traverse left, we do not increment the rank counter.
 * If we find the node we are looking for, we increment the rank counter by its number of left children -1
 * to account for the node itself. If we do not find the node we are looking for, we return -1.
 *
 * TIME COMPLEXITY: O(log(N)) for track(), O(log(N)) for getRank().
 * SPACE COMPLEXITY: O(N) - one node is required for each number in stream.
 *
 * CODE:
 */

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_10 {
    // binary node class that keeps track of left and right children
    template <typename T>
    class RankBinaryNode : public chapter_02::BinaryNode<T> {
    private:
        int _leftChildrenCount;
    public:
        RankBinaryNode(T value) : chapter_02::BinaryNode<T>(value) {
            _leftChildrenCount = 1;  // consider itself as part of left children count
        }
        RankBinaryNode(const RankBinaryNode& other) = delete;  // for simplicity, don't allow copy construction
        ~RankBinaryNode() {
            RankBinaryNode<T>* tempLeft = static_cast<RankBinaryNode<T>*>(this->getLeft());
            RankBinaryNode<T>* tempRight = static_cast<RankBinaryNode<T>*>(this->getRight());
            delete tempLeft;
            delete tempRight;
        }
        int getLeftChildrenCount() const {return _leftChildrenCount; }
        void incrementLeft() { _leftChildrenCount ++; }
    };

    class RankTracker {
    private:
        RankBinaryNode<int>* _head;
    public:
        RankTracker() {
            _head = nullptr;
        }
        RankTracker(const RankTracker& other) = delete;  // for simplicity, don't allow copy construction
        ~RankTracker() { delete _head; }
        void track(int number);
        int getRank(int number);
    };
}
