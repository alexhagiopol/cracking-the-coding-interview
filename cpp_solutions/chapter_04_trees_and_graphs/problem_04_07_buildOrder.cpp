/*
Chapter 04 - Problem 07 - Build Order

Problem Statement:
You are given a list of projects and a list of dependencies (which is a list of pairs of projects,
where the second project is dependent on the first project). All of a project's dependencies must
be built before the project is. Find a build order that will allow the projects to be built.
If there is no valid build order, return an error.

Solution:
We first represent the projects and build dependencies as vertices and edges in a directed acyclic graph.
We then implement a depth first search based algorithm for topological sorting: https://en.wikipedia.org/wiki/Topological_sorting#Algorithms

L ← Empty list that will contain the sorted nodes
while there are unmarked nodes do:
    select an unmarked node n
    visit(n)

function visit(node n)
    if n has a permanent mark: // n has already been visited
        return
    if n has a temporary mark: // (not a DAG)
        stop
    mark n temporarily
    for each node m with an edge from n to m:
        visit(m)
    mark n permanently
    add n to head of L

Time complexity: O(V + E) where V is the number of vertices in the graph and E is the number of edges.
V can be interpreted as the number of projects and E can be interpreted as the number of dependencies.
Space complexity: O(V)
*/

#include "problem_04_07_buildOrder.h"
#include <unordered_map>

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
        for (int i = 0; i < dependencies.size(); i++) {
            // the first node in a pair must be build before the second.
            chapter_02::GraphNode<char>* first = projectsGN[charToIndexMap[dependencies[i].first]];
            chapter_02::GraphNode<char>* second = projectsGN[charToIndexMap[dependencies[i].second]];
            // add edge from the first node to the second node
            first->push(second);
            second->incAncestors();
        }


    }
}  // namespace chapter_04