#include "problem_10_10_rankFromStream.h"

namespace chapter_10 {
    void RankTracker::track(int number) {
        // if BST does not exist, make new head
        if (_head == nullptr) {
            _head = new RankBinaryNode<int>(number);
        }
        else {
            // if BST does exist, traverse it
            RankBinaryNode<int>* temp = _head;
            // traverse BST until proper location for number is found
            while (temp != nullptr) {
                if (number == temp->getValue()) {
                    temp->incrementLeft();
                    return;
                } else if (number < temp->getValue()) {
                    temp->incrementLeft();
                    if (temp->getLeft() == nullptr) {
                        temp->setLeft(new RankBinaryNode<int>(number));
                        return;
                    }
                    temp = static_cast<RankBinaryNode<int>*>(temp->getLeft());
                } else {
                    // no need to track right children in this algorithm
                    if (temp->getRight() == nullptr) {
                        temp->setRight(new RankBinaryNode<int>(number));
                        return;
                    }
                    temp = static_cast<RankBinaryNode<int>*>(temp->getRight());
                }
            }
        }
    }

    int RankTracker::getRank(int number) {
        int rank = 0;
        RankBinaryNode<int>* temp = _head;
        while (temp != nullptr) {
            if (number == temp->getValue()) {
                rank += (temp->getLeftChildrenCount() - 1);
                return rank;
            } else if (number < temp->getValue()) {
                temp = static_cast<RankBinaryNode<int>*>(temp->getLeft());
            } else {
                rank += (temp->getLeftChildrenCount());
                temp = static_cast<RankBinaryNode<int>*>(temp->getRight());
            }
        }
        return -1;
    }
}
