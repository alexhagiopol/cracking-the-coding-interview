/*
Chapter 04 - Problem 07 - Build Order

Problem Statement:
You are given a list of projects and a list of dependencies (which is a list of pairs of projects,
where the second project is dependent on the first project). All of a project's dependencies must
be built before the project is. Find a build order that will allow the projects to be built.
If there is no valid build order, return an error.

Solution:
We first represent the projects and build dependencies as vertices and edges in a directed acyclic graph.
We then implement Kahn's algorithm for topological sorting: https://en.wikipedia.org/wiki/Topological_sorting#Algorithms

L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edge
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error   (graph has at least one cycle)
else
    return L   (a topologically sorted order)

Time complexity: O(V + E) where V is the number of vertices in the graph and E is the number of edges.
V can be interpreted as the number of projects and E can be interpreted as the number of dependencies.
Space complexity: O(V)
*/

#include "problem_04_07_buildOrder.h"
#include <unordered_map>
#include <queue>

namespace chapter_04 {
    void buildOrder(std::vector<char>& projects, std::vector<std::pair<char, char>>& dependencies, std::vector<char>& buildOrder) {
        // convert list of project identifiers to graph nodes
        std::vector<chapter_02::GraphNode<char>*> projectsGN = {};  // store pointers to GraphNodes used in topological sort
        std::unordered_map<char, int> charToIndexMap;  // map project identifier char to index for fast lookup based on project identifier
        for (int i = 0; i < projects.size(); i++) {
            auto iterator = charToIndexMap.find(projects[i]);  // check for project uniqueness
            if (iterator != charToIndexMap.end()) return;  // the same project exists twice in the project manifest
            projectsGN.push_back(new chapter_02::GraphNode<char>(projects[i]));
            charToIndexMap[projects[i]] = i;
        }
        // convert list of project dependencies to graph edges
        int totalEdges = 0;
        for (auto dependency : dependencies) {
            // the first node in a pair must be build before the second.
            chapter_02::GraphNode<char>* first = projectsGN[charToIndexMap[dependency.first]];
            chapter_02::GraphNode<char>* second = projectsGN[charToIndexMap[dependency.second]];
            // add edge from the first node to the second node
            first->push(second);
            second->incAncestors();
            totalEdges ++;
        }
        // create queue containing all nodes with no dependencies
        std::queue<chapter_02::GraphNode<char>*> Q;
        for (auto node : projectsGN) {
            if (node->getNumAncestors() == 0) Q.push(node);
        }
        // traverse graph in depth first order starting from nodes without dependencies
        while (!Q.empty()) {
            chapter_02::GraphNode<char>* node = Q.front();
            Q.pop();
            buildOrder.push_back(node->getValue());
            chapter_02::SinglyLinkedNode<chapter_02::GraphNode<char>*>* child = node->getHeadOfDescendants();
            while (child != nullptr) {
                child->getValue()->decAncestors();
                totalEdges --;  // keep track of total edges in graph as we remove them
                if (child->getValue()->getNumAncestors() == 0) Q.push(child->getValue());
                child = child->getNext();
                node->pop();
            }
        }
        // if edges remain in the graph, at least one circular dependency exists
        if (totalEdges != 0) {
            buildOrder.clear();
        }
        // free memory consumed by graph nodes
        for (auto node : projectsGN) {
            delete node;
        }
    }
}  // namespace chapter_04