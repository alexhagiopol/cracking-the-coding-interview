/*
Chapter 04 - Problem 12 - Paths with Sum

Problem Statement:
You are given a binary tree in which each node contains an integer value (which might be positive or negative).
Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or
end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

Solution:
The brute force solution to this problem is to (1) DFS traverse the tree starting from the root and (2)
initiate a new DFS traversal at each node. For each of the type (2) traversals, we keep a running sum of the node values
that have been traversed. When the running sum equals the target sum, we increment a global total. To calculate the
total runtime, we observe that that a node at depth d has d ancestors. Because of the recursive nature of the
algorithm, those ancestors will each cause function (2) to be called on a given node. From the definitions of
binary trees, the depth of a tree with N nodes is equal to log(N). Thus the runtime is thus O(N*log(N)) for a balanced
tree. For an unbalanced tree (in the worst case, every node of the tree is on the same side), the depth of a tree
with N nodes is N. Thus, the worst case runtime of this algorithm is O(N^2). Because a running sum must be stored for
each node (along with the data associated with the node itself) space complexity is O(N).

A more efficient solution is to only traverse the tree once using depth first search and use a hash table to
keep track of running sums. In the hash table, the keys are running sums and the values are the numbers of times
the keys have been encountered. By definition, a path leads to the target sum if the difference between the current
running sum and *any previously encountered running sum* is equal to the target sum. At each node encountered during the
traversal, we add that node's running sum to a hash table; if that running sum is already in the hash table, then
we increment its value. Also at each node, we compute the difference between the node's running sum and the target
sum: if that difference is equal to *any* previously observed running sum, then we've discovered a path that yields
the target sum. Furthermore, if there exist multiple of the same running sum, then we've discovered multiple paths that
yield the target sum. Thus, when the difference is equal to the target sum, we increment a global path total by the
current running sum's hash table value thus computing the number of paths that lead to the target sum. One final bit
of complexity in this solution is that hashed sums from traversing one path will not apply to a totally different
path in the tree. We resolve this issue in the recursive implementation of depth first search: once a given node's
left and right recursive calls are completed, we *decrement* that node's running sum in the hash table. In this way,
we do a constant number of hash table lookups at each node in the tree yielding a O(N) worst case runtime and O(N)
space required due to the max hash table size and the sunning sums stored for each node.

Time complexity: O(N)
Space complexity: O(N)
*/

#include "../chapter_02_linked_lists/Node.h"
#include <unordered_map>

namespace chapter_04 {
    template <typename T>
    void pathsWithSumHelper(
            const T& targetSum,
            const chapter_02::BinaryNode<T>* head,
            T runningSum,
            T& globalSum,
            std::unordered_map<T, int>& hashTable) {
        if (head == nullptr) return; // terminating condition
        runningSum += head->getValue();  // update running sum for this node
        if (hashTable.find(runningSum) == hashTable.end()) {  // if running sum is not found, add it.
            hashTable[runningSum] = 1;
        } else {
            hashTable[runningSum] ++;  // else increment
        }
        T difference = runningSum - targetSum;
        if (hashTable.find(difference) != hashTable.end()) {  // if difference is found increment global sum
            globalSum += hashTable[difference];
        }
        pathsWithSumHelper(targetSum, head->getLeft(), runningSum, globalSum, hashTable);  // recurse
        pathsWithSumHelper(targetSum, head->getRight(), runningSum, globalSum, hashTable);  // recurse
        hashTable[runningSum] --;  // decrement to not affect unrelated paths
    }

    template <typename T>
    int pathsWithSum(const T& targetSum, const chapter_02::BinaryNode<T>* head) {
        std::unordered_map<T, int> hashTable;
        hashTable[static_cast<T>(0)] = 1; // if runningSum - globalSum == 0, then by definition we have found a valid path to the targetSum
        T globalSum = 0;
        T runningSum = 0;
        pathsWithSumHelper(targetSum, head, runningSum, globalSum, hashTable);
        return globalSum;
    }
}  // chapter_04
