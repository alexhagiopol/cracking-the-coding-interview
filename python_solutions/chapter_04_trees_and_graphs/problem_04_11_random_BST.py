"""
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
"""

import random


class RandBinNode:

    def __init__(self, value=None, left=None, right=None, children=0):
        self.value = value
        self.left = left
        self.right = right
        self.children = children

    def left_children(self):
        if self.left is None:
            return 0
        else:
            return 1 + self.left.children

    def right_children(self):
        if self.right is None:
            return 0
        else:
            return 1 + self.right.children

    def insert(self, value):
        if value is None:  # disallow adding no value
            return
        if self.value is None:  # create children only if the current node has no value
            self.value = value
            return
        self.children += 1
        if value > self.value:
            if self.right is not None:
                self.right.insert(value)
            else:
                self.right = RandBinNode(value)
        else:
            if self.left is not None:
                self.left.insert(value)
            else:
                self.left = RandBinNode(value)

    def get_random(self, rand_int=None):
        if rand_int is None:
            rand_int = random.randint(1, 1 + self.children)
        if rand_int <= 1:
            return self.value
        elif 1 < rand_int <= 1 + self.left_children():
            return self.left.get_random(rand_int - 1)  # no need to compute new random number
        else:
            return self.right.get_random(rand_int - self.left_children() - 1)  # if we traverse right, make rand_int stay in range of # of children

    def find(self):
        pass

    def delete(self):
        pass
