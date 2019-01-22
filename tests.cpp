//
// Created by alex on 7/31/17.
//

#include "cpp_solutions/chapter_01_arrays_and_strings/chapter_01_includes.h"
#include "cpp_solutions/chapter_02_linked_lists/chapter_02_includes.h"
#include "cpp_solutions/chapter_03_stacks_and_queues/chapter_03_includes.h"
#include "cpp_solutions/chapter_04_trees_and_graphs/chapter_04_includes.h"
#include "cpp_solutions/chapter_05_bit_manipulation/chapter_05_includes.h"
#include "cpp_solutions/chapter_08_recursion_and_dynamic_programming/chapter_08_includes.h"
#include "cpp_solutions/chapter_10_sorting_and_searching/chapter_10_includes.h"
#include "cpp_solutions/chapter_12_cpp/chapter_12_includes.h"
#include "cpp_solutions/misc_exercises/misc_includes.h"
#define CATCH_CONFIG_MAIN
#include "cpp_solutions/third_party/Catch/include/catch.hpp"
#include <vector>
#include <Eigen/Dense>

TEST_CASE("Chapter 01 - Problem 01 - isUnique()", "test"){
    REQUIRE(chapter_01::isUnique("alex"));
    REQUIRE(!chapter_01::isUnique("aalex"));
}

TEST_CASE("Chapter 01 - Problem 02 - isPermutation()", "test"){
    REQUIRE(!chapter_01::isPermutation("alex", "alexa"));
    REQUIRE(chapter_01::isPermutation("aa", "aa"));
    REQUIRE(chapter_01::isPermutation("alex", "lexa"));
    REQUIRE(chapter_01::isPermutation("alex", "xela"));
    REQUIRE(chapter_01::isPermutation("", ""));
    REQUIRE(!chapter_01::isPermutation("cat", "ctt"));
    REQUIRE(!chapter_01::isPermutation("alexxx", "xxxxxx"));
}

TEST_CASE("Chapter 01 - Problem 03 - URLify()", "test") {
	// expect 'Mr. John Smith' -> 'Mr.%20John%20Smith'
	std::string input1 = "Mr. John Smith ";
	std::string output1 = "Mr.%20John%20Smith%20";
	chapter_01::URLify(input1);
	REQUIRE(input1 == output1);
	std::string input2 = "";
	std::string output2 = "";
	chapter_01::URLify(input2);
	REQUIRE(input2 == output2);
	std::string input3 = " ";
	std::string output3 = "%20";
	chapter_01::URLify(input3);
	REQUIRE(input3 == output3);
	std::string input4 = "Alex";
	std::string output4 = "Alex";
	chapter_01::URLify(input4);
	REQUIRE(input4 == output4);
}

TEST_CASE("Chapter 01 - Problem 04 - palindromePermutation()", "test") {
	REQUIRE(chapter_01::palindromePermutation("tact coa"));
	REQUIRE(!chapter_01::palindromePermutation("Tact Coa"));
	REQUIRE(!chapter_01::palindromePermutation("xyz"));
	REQUIRE(chapter_01::palindromePermutation("AA  B AA"));
	REQUIRE(!chapter_01::palindromePermutation("aA  B AA"));
}

TEST_CASE("Chapter 01 - Problem 05 - oneAway()", "test"){
    REQUIRE(chapter_01::oneAway("pale", "ple"));
    REQUIRE(chapter_01::oneAway("pale", "pale"));
    REQUIRE(chapter_01::oneAway("pale", "bale"));
    REQUIRE(!chapter_01::oneAway("pale", "bae"));
    REQUIRE(!chapter_01::oneAway("alex", "al"));
    REQUIRE(!chapter_01::oneAway("alex", "all"));
    REQUIRE(!chapter_01::oneAway("alex", "alll"));
    REQUIRE(chapter_01::oneAway("apple", "aple"));
    REQUIRE(chapter_01::oneAway("bale", "pale"));
    REQUIRE(chapter_01::oneAway("", ""));
}

TEST_CASE("Chapter 01 - Problem 06 - stringCompression()", "test"){
    REQUIRE("a2b1c5a3" == chapter_01::stringCompression("aabcccccaaa"));
    REQUIRE("alex" == chapter_01::stringCompression("alex"));
    REQUIRE("" == chapter_01::stringCompression(""));
    REQUIRE("a10" == chapter_01::stringCompression("aaaaaaaaaa"));
}

TEST_CASE("Chapter 01 - Problem 07 - rotateMatrix()", "test"){
    Eigen::MatrixXi input4x4(4,4);
    input4x4 << 1, 2, 3, 4,
                1, 2, 3, 4,
                1, 2, 3, 4,
                1, 2, 3, 4;

    Eigen::MatrixXi input5x5(5,5);
    input5x5 << 1, 2, 3, 4, 5,
                1, 2, 3, 4, 5,
                1, 2, 3, 4, 5,
                1, 2, 3, 4, 5,
                1, 2, 3, 4, 5;

    Eigen::MatrixXi output4x4(4,4);
    output4x4 << 1, 1, 1, 1,
                 2, 2, 2, 2,
                 3, 3, 3, 3,
                 4, 4, 4, 4;

    Eigen::MatrixXi output5x5(5,5);
    output5x5 << 1, 1, 1, 1, 1,
                 2, 2, 2, 2, 2,
                 3, 3, 3, 3, 3,
                 4, 4, 4, 4, 4,
                 5, 5, 5, 5, 5;

    chapter_01::rotate(input4x4);
    chapter_01::rotate(input5x5);
    REQUIRE(input4x4.isApprox(output4x4));
    REQUIRE(input5x5.isApprox(output5x5));
}

TEST_CASE("Chapter 01 - Problem 08 - setZero()", "test"){
    // assume rotations are clockwise
    Eigen::MatrixXi input4x4(4,4);
    input4x4 << 1, 2, 3, 4,
                1, 2, 0, 4,
                1, 2, 3, 4,
                0, 2, 3, 4;
    Eigen::MatrixXi input5x5(5,5);
    input5x5 << 0, 2, 3, 4, 5,
                1, 2, 0, 4, 5,
                1, 2, 3, 4, 5,
                1, 2, 3, 4, 0,
                1, 2, 3, 4, 5;
    Eigen::MatrixXi output4x4(4,4);
    output4x4 << 0, 2, 0, 4,
                 0, 0, 0, 0,
                 0, 2, 0, 4,
                 0, 0, 0, 0;
    Eigen::MatrixXi output5x5(5,5);
    output5x5 << 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0,
                 0, 2, 0, 4, 0,
                 0, 0, 0, 0, 0,
                 0, 2, 0, 4, 0;
    chapter_01::setZero(input4x4);
    chapter_01::setZero(input5x5);
    REQUIRE(input4x4.isApprox(output4x4));
    REQUIRE(input5x5.isApprox(output5x5));
}

TEST_CASE("Chapter 01 - Problem 09 - stringRotation()", "test"){
    REQUIRE(chapter_01::stringRotation("waterbottle", "erbottlewat"));
    REQUIRE(!chapter_01::stringRotation("waterbottle", "erbottlewatx"));
    REQUIRE(chapter_01::stringRotation("", ""));
}

TEST_CASE("Chapter 02 - Basic LinkedList Functionality", "test"){
    std::vector<int> testVector = {1,2,3,4,5,6,7};
    REQUIRE(testVector == chapter_02::listToVector(chapter_02::vectorToList(testVector)));
}

TEST_CASE("Chapter 02 - Problem 01 - removeDups()", "test"){
    std::vector<int> noDups = {1,7,3,6,5,4,2};
    std::vector<int> dups = {2,2,1,5,6,2,5,2,7,7};
    std::vector<int> fixedDups = {2,1,5,6,7};
    std::vector<int> emptyVec;

    // check that remove dups function doesn't affect lists with no dups
    chapter_02::SinglyLinkedNode<int>* noDupsHead = chapter_02::vectorToList(noDups);
    chapter_02::removeDups(noDupsHead);
    REQUIRE(noDups == chapter_02::listToVector(noDupsHead));

    // check case with duplicates
    chapter_02::SinglyLinkedNode<int>* dupsHead = chapter_02::vectorToList(dups);
    chapter_02::removeDups(dupsHead);
    REQUIRE(fixedDups == chapter_02::listToVector(dupsHead));

    // check case with empty list
    chapter_02::SinglyLinkedNode<int>* emptyHead = chapter_02::vectorToList(emptyVec);
    chapter_02::removeDups(emptyHead);
    REQUIRE(emptyVec == chapter_02::listToVector(emptyHead));
}

TEST_CASE("Chapter 02 - Problem 02 - returnKthToLast()", "test"){
    std::vector<int> testVec1 = {1,7,3,6,5,4,2};
    std::vector<int> testVec2 = {2,2,1,5,6,2,5,2,7,7};
    std::vector<int> testVec3;
    chapter_02::SinglyLinkedNode<int>* testVec1Head = chapter_02::vectorToList(testVec1);
    chapter_02::SinglyLinkedNode<int>* testVec2Head = chapter_02::vectorToList(testVec2);
    chapter_02::SinglyLinkedNode<int>* testVec3Head = chapter_02::vectorToList(testVec3);
    REQUIRE(5 == chapter_02::returnKthToLast(testVec1Head, 3)->getValue());
    REQUIRE(2 == chapter_02::returnKthToLast(testVec1Head, 1)->getValue());
    REQUIRE(1 == chapter_02::returnKthToLast(testVec1Head, testVec1.size())->getValue());
    REQUIRE(2 == chapter_02::returnKthToLast(testVec2Head, 3)->getValue());
    REQUIRE(7 == chapter_02::returnKthToLast(testVec2Head, 1)->getValue());
    REQUIRE(2 == chapter_02::returnKthToLast(testVec2Head, testVec2.size())->getValue());
    REQUIRE(nullptr == chapter_02::returnKthToLast(testVec2Head, 0));
    REQUIRE(nullptr == chapter_02::returnKthToLast(testVec1Head, 10));
    REQUIRE(nullptr == chapter_02::returnKthToLast(testVec3Head, 10));
}

TEST_CASE("Chapter 02 - Problem 03 - deleteMiddleNode()", "test"){
    // create test dataset
    std::vector<std::string> testVec = {"a", "b", "c", "d", "e", "f"};
    std::vector<std::string> expectedVec = {"a", "b", "d", "e", "f"};
    chapter_02::SinglyLinkedNode<std::string>* testVecHead = chapter_02::vectorToList(testVec);
    chapter_02::SinglyLinkedNode<std::string>* expectedVecHead = chapter_02::vectorToList(expectedVec);
    // traverse input to find node with content "c"
    chapter_02::SinglyLinkedNode<std::string>* head = testVecHead;
    while (head != nullptr && head->getValue() != "c"){
        head = head->getNext();
    }
    // head is not at location "c". call delete function
    chapter_02::deleteMiddleNode(head);
    // check that vec 1 and vec 2 are the same
    while (testVecHead != nullptr && expectedVecHead != nullptr){
        REQUIRE(testVecHead->getValue() == expectedVecHead->getValue());
        testVecHead = testVecHead->getNext();
        expectedVecHead = expectedVecHead->getNext();
    }
}

TEST_CASE("Chapter 02 - Problem 04 - partition()", "test"){
    // create test dataset
    std::vector<int> inputVec = {3, 5, 8, 5, 10, 2, 1};
    std::vector<int> expectedVec = {1, 2, 3, 5, 8, 5, 10};
    chapter_02::SinglyLinkedNode<int>* inputVecHead = chapter_02::vectorToList(inputVec);
    chapter_02::SinglyLinkedNode<int>* expectedVecHead = chapter_02::vectorToList(expectedVec);
    // perform partition
    inputVecHead = chapter_02::partition(inputVecHead, 5);
    // check that vec 1 and vec 2 are the same
    while (inputVecHead != nullptr && expectedVecHead != nullptr){
        REQUIRE(inputVecHead->getValue() == expectedVecHead->getValue());
        inputVecHead = inputVecHead->getNext();
        expectedVecHead = expectedVecHead->getNext();
    }
}

TEST_CASE("Chapter 02 - Problem 05 - sumLists()", "test"){
    // create test dataset
    // 9423 + 951 = 10374
    std::vector<uint8_t> n1Vec = {3, 2, 4, 9};
    std::vector<uint8_t> n2Vec = {1, 5, 9};
    std::vector<uint8_t> sumVecExpected = {4, 7, 3, 0, 1};
    chapter_02::SinglyLinkedNode<uint8_t>* n1Head = chapter_02::vectorToList(n1Vec);
    chapter_02::SinglyLinkedNode<uint8_t>* n2Head = chapter_02::vectorToList(n2Vec);
    std::vector<uint8_t> sumVecActual = chapter_02::listToVector(chapter_02::sumLists(n1Head, n2Head));
    REQUIRE(sumVecExpected == sumVecActual);
};

TEST_CASE("Chapter 02 - Problem 06 - palindrome()", "test"){
    // create test dataset
    std::vector<int> list1 = {0, 4, 7, 0, 0, 7, 4, 0};
    std::vector<int> list2 = {3, 5, 2, 5, 3};
    std::vector<int> list3 = {0, 1, 0, 1, 0, 1};
    std::vector<std::string> list4 = {"a", "l", "e",  "x"};
    std::vector<std::string> list5 = {"A", "B", "B",  "A"};
    chapter_02::SinglyLinkedNode<int>* head1 = chapter_02::vectorToList(list1);
    chapter_02::SinglyLinkedNode<int>* head2 = chapter_02::vectorToList(list2);
    chapter_02::SinglyLinkedNode<int>* head3 = chapter_02::vectorToList(list3);
    chapter_02::SinglyLinkedNode<std::string>* head4 = chapter_02::vectorToList(list4);
    chapter_02::SinglyLinkedNode<std::string>* head5 = chapter_02::vectorToList(list5);
    REQUIRE(chapter_02::palindrome(head1));
    REQUIRE(chapter_02::palindrome(head2));
    REQUIRE(!chapter_02::palindrome(head3));
    REQUIRE(!chapter_02::palindrome(head4));
    REQUIRE(chapter_02::palindrome(head5));
};

TEST_CASE("Chapter 02 - Problem 07 - intersection()", "test") {
	// list 1
	chapter_02::SinglyLinkedNode<int>* node1_6 = new chapter_02::SinglyLinkedNode<int>(1, nullptr);
	chapter_02::SinglyLinkedNode<int>* node1_5 = new chapter_02::SinglyLinkedNode<int>(2, node1_6);
	chapter_02::SinglyLinkedNode<int>* node1_4 = new chapter_02::SinglyLinkedNode<int>(7, node1_5);
	chapter_02::SinglyLinkedNode<int>* node1_3 = new chapter_02::SinglyLinkedNode<int>(9, node1_4);
	chapter_02::SinglyLinkedNode<int>* node1_2 = new chapter_02::SinglyLinkedNode<int>(5, node1_3);
	chapter_02::SinglyLinkedNode<int>* node1_1 = new chapter_02::SinglyLinkedNode<int>(1, node1_2);
	chapter_02::SinglyLinkedNode<int>* node1_0 = new chapter_02::SinglyLinkedNode<int>(3, node1_1);
	// list 2
	chapter_02::SinglyLinkedNode<int>* node2_1 = new chapter_02::SinglyLinkedNode<int>(6, node1_4);  // intersection point
	chapter_02::SinglyLinkedNode<int>* node2_0 = new chapter_02::SinglyLinkedNode<int>(4, node2_1);
	// list 3
	chapter_02::SinglyLinkedNode<int>* node3_1 = new chapter_02::SinglyLinkedNode<int>(6, nullptr);
	chapter_02::SinglyLinkedNode<int>* node3_0 = new chapter_02::SinglyLinkedNode<int>(4, node3_1);
	REQUIRE(node1_4 == chapter_02::intersection(node1_0, node2_0));
	REQUIRE(nullptr == chapter_02::intersection(node1_0, node3_0));
	REQUIRE(nullptr == chapter_02::intersection(static_cast<chapter_02::SinglyLinkedNode<int>*>(nullptr), static_cast<chapter_02::SinglyLinkedNode<int>*>(nullptr)));
}

TEST_CASE("Chapter 02 - Problem 08 - findLoop()", "test") {
	// see problem_2_8_explanation.pdf
	// example 1
	chapter_02::SinglyLinkedNode<int>* node1_7 = new chapter_02::SinglyLinkedNode<int>(7, nullptr);
	chapter_02::SinglyLinkedNode<int>* node1_6 = new chapter_02::SinglyLinkedNode<int>(6, node1_7);
	chapter_02::SinglyLinkedNode<int>* node1_5 = new chapter_02::SinglyLinkedNode<int>(5, node1_6);
	chapter_02::SinglyLinkedNode<int>* node1_4 = new chapter_02::SinglyLinkedNode<int>(4, node1_5);
	chapter_02::SinglyLinkedNode<int>* node1_3 = new chapter_02::SinglyLinkedNode<int>(3, node1_4);
	chapter_02::SinglyLinkedNode<int>* node1_2 = new chapter_02::SinglyLinkedNode<int>(2, node1_3);
	chapter_02::SinglyLinkedNode<int>* node1_1 = new chapter_02::SinglyLinkedNode<int>(1, node1_2);
	chapter_02::SinglyLinkedNode<int>* node1_0 = new chapter_02::SinglyLinkedNode<int>(0, node1_1);
	node1_7->setNext(node1_5);
	REQUIRE(node1_5 == chapter_02::findLoop(node1_0));

	// example 2
	chapter_02::SinglyLinkedNode<int>* node2_10 = new chapter_02::SinglyLinkedNode<int>(10, nullptr);
	chapter_02::SinglyLinkedNode<int>* node2_9 = new chapter_02::SinglyLinkedNode<int>(9, node2_10);
	chapter_02::SinglyLinkedNode<int>* node2_8 = new chapter_02::SinglyLinkedNode<int>(8, node2_9);
	chapter_02::SinglyLinkedNode<int>* node2_7 = new chapter_02::SinglyLinkedNode<int>(7, node2_8);
	chapter_02::SinglyLinkedNode<int>* node2_6 = new chapter_02::SinglyLinkedNode<int>(6, node2_7);
	chapter_02::SinglyLinkedNode<int>* node2_5 = new chapter_02::SinglyLinkedNode<int>(5, node2_6);
	chapter_02::SinglyLinkedNode<int>* node2_4 = new chapter_02::SinglyLinkedNode<int>(4, node2_5);
	chapter_02::SinglyLinkedNode<int>* node2_3 = new chapter_02::SinglyLinkedNode<int>(3, node2_4);
	chapter_02::SinglyLinkedNode<int>* node2_2 = new chapter_02::SinglyLinkedNode<int>(2, node2_3);
	chapter_02::SinglyLinkedNode<int>* node2_1 = new chapter_02::SinglyLinkedNode<int>(1, node2_2);
	chapter_02::SinglyLinkedNode<int>* node2_0 = new chapter_02::SinglyLinkedNode<int>(0, node2_1);
	node2_10->setNext(node2_3);
	REQUIRE(node2_3 == chapter_02::findLoop(node2_0));

	// example 3
	REQUIRE(static_cast<chapter_02::SinglyLinkedNode<int>*>(nullptr) == chapter_02::findLoop(static_cast<chapter_02::SinglyLinkedNode<int>*>(nullptr)));
}

TEST_CASE("Chapter 03 - Stack", "test"){
    chapter_03::Stack<int> myStack = chapter_03::Stack<int>();
    for (int i = 1; i <= 4; i++){
        myStack.push(i);
    }
    std::vector<int> tooShort = {3,2,1};
    std::vector<int> incorrect = {5,3,2,1};
    std::vector<int> justRight = {4,3,2,1};
    std::vector<int> tooLong = {4,3,2,1,1};
    std::vector<int> empty = {};
    REQUIRE(myStack!=tooShort);
    REQUIRE(myStack!=tooLong);
    REQUIRE(myStack!=incorrect);
    REQUIRE(myStack==justRight);
    REQUIRE(myStack.peek()==4);
    REQUIRE(!myStack.isEmpty());
    while (!myStack.isEmpty()){
        empty.push_back(myStack.pop());
    }
    REQUIRE(empty==justRight);
    REQUIRE(myStack.isEmpty());
    REQUIRE(myStack.pop()==0);
    REQUIRE(myStack.peek()==0);
}

TEST_CASE("Chapter 03 - Problem 02 - StackMin()", "test"){
    chapter_03::StackMin<int> myStack = chapter_03::StackMin<int>();
    myStack.push(-8);
    myStack.push(-5);
    myStack.push(1);
    myStack.push(-6);
    REQUIRE(myStack.seeMin() == -8);
    myStack.push(-9);
    REQUIRE(myStack.seeMin() == -9);
    myStack.push(-15);
    myStack.push(-30);
    myStack.pop();
    myStack.pop();
    REQUIRE(myStack.seeMin() == -9);
}

TEST_CASE("Chapter 03 - Problem 04 - QueueViStacks()", "test"){
    chapter_03::QueueViaStacks<int> myQueue = chapter_03::QueueViaStacks<int>();
    for (int i = 0; i < 10; i++) myQueue.enqueue(i);
    for (int i = 0; i < 5; i++) REQUIRE(myQueue.dequeue() == i);
    for (int i = 0; i < 5; i++) myQueue.enqueue(i);
    for (int i = 5; i < 10; i++) REQUIRE(myQueue.dequeue() == i);
    for (int i = 0; i < 5; i++) REQUIRE(myQueue.dequeue() == i);
}

TEST_CASE("Chapter 04 - Basic Graph Functionality", "test"){
    chapter_02::GraphNode<int> node(1);
    chapter_02::GraphNode<int>* child0 = new chapter_02::GraphNode<int>(0);
    chapter_02::GraphNode<int>* child1 = new chapter_02::GraphNode<int>(1);
    chapter_02::GraphNode<int>* child2 = new chapter_02::GraphNode<int>(2);
    chapter_02::GraphNode<int>* child3 = new chapter_02::GraphNode<int>(3);
    node.addChild(child0, 0);
    node.addChild(child1, 1);
    node.addChild(child2, 2);
    node.addChild(child3, 3);
    std::vector<chapter_02::GraphNode<int>*> children;
    node.getChildren(children);
    REQUIRE(children[0] == child0);
    REQUIRE(children[1] == child1);
    REQUIRE(children[2] == child2);
    REQUIRE(children[3] == child3);
    node.removeChild(0);
    node.removeChild(1);
    node.removeChild(2);
    node.removeChild(3);
    std::vector<chapter_02::GraphNode<int>*> deletedChildren;
    node.getChildren(deletedChildren);
    REQUIRE(deletedChildren.size() == 0);
    // no need to delete children, because removeChildren does that for us.
}

TEST_CASE("Chapter 04 - Problem 01 - Route Between Nodes", "test"){
    /*
    Implements this directed graph:
    1 -> 2 -> 3
         |
         v
         4 -> 5 -> 6
         |    ^
         v    |
         7 -> 8
     */
    chapter_02::GraphNode<int>* node1 = new chapter_02::GraphNode<int>(1);
    chapter_02::GraphNode<int>* node2 = new chapter_02::GraphNode<int>(2);
    chapter_02::GraphNode<int>* node3 = new chapter_02::GraphNode<int>(3);
    chapter_02::GraphNode<int>* node4 = new chapter_02::GraphNode<int>(4);
    chapter_02::GraphNode<int>* node5 = new chapter_02::GraphNode<int>(5);
    chapter_02::GraphNode<int>* node6 = new chapter_02::GraphNode<int>(6);
    chapter_02::GraphNode<int>* node7 = new chapter_02::GraphNode<int>(7);
    chapter_02::GraphNode<int>* node8 = new chapter_02::GraphNode<int>(8);
    node1->addChild(node2, 0);
    node2->addChild(node3, 0);
    node2->addChild(node4, 1);
    node4->addChild(node5, 0);
    node4->addChild(node7, 1);
    node5->addChild(node6, 0);
    node7->addChild(node8, 0);
    node8->addChild(node5, 0);
    REQUIRE(chapter_04::pathExistsDFS(node1, node6) == true);
    REQUIRE(chapter_04::pathExistsDFS(node7, node5) == true);
    REQUIRE(chapter_04::pathExistsDFS(node3, node8) == false);
    REQUIRE(chapter_04::pathExistsDFS(node1, node8) == true);
    REQUIRE(chapter_04::pathExistsDFS(static_cast<chapter_02::GraphNode<int>*>(nullptr), static_cast<chapter_02::GraphNode<int>*>(nullptr)) == false);
    REQUIRE(chapter_04::pathExistsDFS(node1, static_cast<chapter_02::GraphNode<int>*>(nullptr)) == false);
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;
}

TEST_CASE("Chapter 04 - Problem 02 - minimalTree()", "test"){
    // test 1
    std::vector<int> sortedArray1 = {8, 9, 10, 11, 12, 13, 14};
    chapter_02::BinaryNode<int>* head1 = chapter_04::minimalTree(sortedArray1);
    std::vector<int> expectedPostOrderTraversal1 = {8, 10, 9, 12, 14, 13, 11};
    std::vector<int> actualPostOrderTraversal1;
    chapter_02::bstToVector(actualPostOrderTraversal1, head1);
    REQUIRE(expectedPostOrderTraversal1.size() == actualPostOrderTraversal1.size());
    for (int i = 0; i < actualPostOrderTraversal1.size(); i++) {
        REQUIRE(actualPostOrderTraversal1[i] == expectedPostOrderTraversal1[i]);
    }

    // test 2
    std::vector<int> sortedArray2 = {9, 10, 11, 12, 13, 14};
    chapter_02::BinaryNode<int>* head2 = chapter_04::minimalTree(sortedArray2);
    std::vector<int> expectedPostOrderTraversal2 = {10, 9, 12, 14, 13, 11};
    std::vector<int> actualPostOrderTraversal2;
    chapter_02::bstToVector(actualPostOrderTraversal2, head2);
    REQUIRE(expectedPostOrderTraversal2.size() == actualPostOrderTraversal2.size());
    for (int i = 0; i < actualPostOrderTraversal2.size(); i++) {
        REQUIRE(actualPostOrderTraversal2[i] == expectedPostOrderTraversal2[i]);
    }
}

TEST_CASE("Chapter 04 - Problem 03 - makeLL()", "test"){
    /*
     * Construct a binary tree of the form
     * 0
     * 12
     * 3456
     */
    chapter_02::BinaryNode<int>* head = new chapter_02::BinaryNode<int>(0);
    chapter_02::BinaryNode<int>* child1 = new chapter_02::BinaryNode<int>(1);
    chapter_02::BinaryNode<int>* child2 = new chapter_02::BinaryNode<int>(2);
    chapter_02::BinaryNode<int>* child3 = new chapter_02::BinaryNode<int>(3);
    chapter_02::BinaryNode<int>* child4 = new chapter_02::BinaryNode<int>(4);
    chapter_02::BinaryNode<int>* child5 = new chapter_02::BinaryNode<int>(5);
    chapter_02::BinaryNode<int>* child6 = new chapter_02::BinaryNode<int>(6);
    head->setLeft(child1);
    head->setRight(child2);
    child1->setLeft(child3);
    child1->setRight(child4);
    child2->setLeft(child5);
    child2->setRight(child6);
    // execute conversion to linked list
    std::vector<chapter_02::SinglyLinkedNode<int>*> vectorOfHeads;
    std::vector<chapter_02::SinglyLinkedNode<int>*> vectorOfTails;
    std::vector<int> expected = {0, 1, 2, 3, 4, 5, 6};
    chapter_04::makeLL(vectorOfHeads, vectorOfTails, head);
    std::vector<int> actual = chapter_04::vectorFromVectorOfLLs(vectorOfHeads);
    // test
    for (int i = 0; i < expected.size(); i++) {
        REQUIRE(expected[i] == actual[i]);
    }
}

TEST_CASE("Chapter 04 - Problem 04 - checkBalanced()", "test") {

}

TEST_CASE("Chapter 05 - Problem 01 - insertion()", "test"){
    REQUIRE(chapter_05::insertion(0b10000000000, 0b10011, 2, 6) == 0b10001001100);
}

TEST_CASE("Chapter 05 - Problem 02 - binaryToString()", "test") {
    std::string binary_string_1 = "";
    std::string binary_string_2 = "";
    std::string binary_string_3 = "";
    std::string binary_string_4 = "";
    REQUIRE(chapter_05::binaryToString(0.5, binary_string_1) == 0);
    REQUIRE(chapter_05::binaryToString(0.25, binary_string_2) == 0);
    REQUIRE(chapter_05::binaryToString(1.5, binary_string_3) == -1);
    REQUIRE(chapter_05::binaryToString(0.722, binary_string_4) == 0);
    REQUIRE(binary_string_1 == "0.1");
    REQUIRE(binary_string_2 == "0.01");
    REQUIRE(binary_string_3 == "");
    REQUIRE(binary_string_4 == "0.10111000110101001111110111110011"); // needs double precision to work
}

TEST_CASE("Chapter 05 - Problem 06 - conversion()", "test"){
    REQUIRE(chapter_05::conversion(0b11001100, 0b11110000) == 4);
    REQUIRE(chapter_05::conversion(29, 15) == 2);
}

TEST_CASE("Chapter 05 - Problem 07 - pairwiseSwap()", "test"){
    REQUIRE(chapter_05::pairwiseSwap(0b10101010) == 0b01010101);
    REQUIRE(chapter_05::pairwiseSwap(0b11110000) == 0b11110000);
    REQUIRE(chapter_05::pairwiseSwap(0b110) == 0b1001);
}

TEST_CASE("Chapter 08 - Problem 01 - tripleStep()", "test"){
    REQUIRE(chapter_08::tripleStep(3) == 4);
    REQUIRE(chapter_08::tripleStep(4) == 7);
    REQUIRE(chapter_08::tripleStep(5) == 13);
}

TEST_CASE("Chapter 08 - Problem 02 - robotGrid()", "test"){

    Eigen::MatrixXd maze(5, 5);
    maze << 1, 1, 1, 0, 1,
            0, 0, 1, 1, 1,
            0, 1, 1, 0, 0,
            0, 1, 1, 0, 1,
            1, 1, 1, 1, 1;
    std::vector<Eigen::Vector2d> expectedPath = {Eigen::Vector2d(0,0),
                                                 Eigen::Vector2d(0,1),
                                                 Eigen::Vector2d(0,2),
                                                 Eigen::Vector2d(1,2),
                                                 Eigen::Vector2d(2,2),
                                                 Eigen::Vector2d(3,2),
                                                 Eigen::Vector2d(4,2),
                                                 Eigen::Vector2d(4,3),
                                                 Eigen::Vector2d(4,4)};
    std::vector<Eigen::Vector2d> path;
    REQUIRE(chapter_08::robotGrid(maze, path));
    REQUIRE(path == expectedPath);
}

TEST_CASE("Chapter 08 - Problem 03 - magicIndex()", "test"){
    std::vector<int> noMagicIndex = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> magicIndex5 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> magicIndex7 = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    REQUIRE(chapter_08::magicIndex(noMagicIndex) == -1);
    REQUIRE(chapter_08::magicIndex(magicIndex5) == 5);
    REQUIRE(chapter_08::magicIndex(magicIndex7) == 7);
}

TEST_CASE("Chapter 08 - Problem 04 - powerSet()", "test"){
    std::vector<int> set123 = {1, 2, 3};
    std::vector<int> set12 = {1, 2};
    std::vector<int> set13 = {1, 3};
    std::vector<int> set23 = {2, 3};
    std::vector<int> set1 = {1};
    std::vector<int> set2 = {2};
    std::vector<int> set3 = {3};
    std::vector<int> emptySet = {};

    std::vector<std::vector<int>> powerSet123 = {emptySet, set1, set2, set12, set3, set13, set23, set123};
    std::vector<std::vector<int>> powerSet12 = {emptySet, set1, set2, set12};
    std::vector<std::vector<int>> powerSet1 = {emptySet, set1};

    std::vector<std::vector<int>> testPowerSet = {};
    chapter_08::createPowerSet(set123, testPowerSet);
    REQUIRE(testPowerSet == powerSet123);
    testPowerSet = {};
    chapter_08::createPowerSet(set12, testPowerSet);
    REQUIRE(testPowerSet == powerSet12);
    testPowerSet = {};
    chapter_08::createPowerSet(set1, testPowerSet);
    REQUIRE(testPowerSet == powerSet1);
};

TEST_CASE("Chapter 08 - Problem 05 - recursiveMultiply()", "test"){
    REQUIRE(chapter_08::recursiveMultiply(1, 1) == 1);
    REQUIRE(chapter_08::recursiveMultiply(1, 2) == 2);
    REQUIRE(chapter_08::recursiveMultiply(0, 1) == 0);
    REQUIRE(chapter_08::recursiveMultiply(9, 10) == 90);
    REQUIRE(chapter_08::recursiveMultiply(9, 11) == 99);
    REQUIRE(chapter_08::recursiveMultiply(12, 12) == 144);
}

TEST_CASE("Chapter 08 - Problem 10 - paintFill()", "test"){
    Eigen::MatrixXi image(6, 6);
    image << 0, 1, 1, 0, 0, 3,
             1, 1, 1, 1, 0, 0,
             0, 1, 1, 0, 0, 2,
             0, 0, 0, 0, 2, 2,
             0, 2, 2, 2, 2, 2,
             0, 0, 0, 2, 2, 2;
    Eigen::MatrixXi zerosFilled(6, 6);
    zerosFilled << 0, 1, 1, 5, 5, 3,
                   1, 1, 1, 1, 5, 5,
                   5, 1, 1, 5, 5, 2,
                   5, 5, 5, 5, 2, 2,
                   5, 2, 2, 2, 2, 2,
                   5, 5, 5, 2, 2, 2;
    Eigen::MatrixXi onesFilled(6, 6);
    onesFilled << 0, 5, 5, 0, 0, 3,
                  5, 5, 5, 5, 0, 0,
                  0, 5, 5, 0, 0, 2,
                  0, 0, 0, 0, 2, 2,
                  0, 2, 2, 2, 2, 2,
                  0, 0, 0, 2, 2, 2;
    Eigen::MatrixXi twosFilled(6, 6);
    twosFilled << 0, 1, 1, 0, 0, 3,
                  1, 1, 1, 1, 0, 0,
                  0, 1, 1, 0, 0, 5,
                  0, 0, 0, 0, 5, 5,
                  0, 5, 5, 5, 5, 5,
                  0, 0, 0, 5, 5, 5;
    Eigen::MatrixXi threeFilled(6, 6);
    threeFilled << 0, 1, 1, 0, 0, 5,
                   1, 1, 1, 1, 0, 0,
                   0, 1, 1, 0, 0, 2,
                   0, 0, 0, 0, 2, 2,
                   0, 2, 2, 2, 2, 2,
                   0, 0, 0, 2, 2, 2;
    Eigen::MatrixXi expectedZerosFilled = image;
    Eigen::MatrixXi expectedOnesFilled = image;
    Eigen::MatrixXi expectedTwosFilled = image;
    Eigen::MatrixXi expectedThreeFilled = image;
    chapter_08::paintFill(expectedZerosFilled, Eigen::Vector2i(2, 0), 5);
    chapter_08::paintFill(expectedOnesFilled, Eigen::Vector2i(1, 2), 5);
    chapter_08::paintFill(expectedTwosFilled, Eigen::Vector2i(4, 3), 5);
    chapter_08::paintFill(expectedThreeFilled, Eigen::Vector2i(0, 5), 5);
    REQUIRE(zerosFilled.isApprox(expectedZerosFilled));
    REQUIRE(onesFilled.isApprox(expectedOnesFilled));
    REQUIRE(twosFilled.isApprox(expectedTwosFilled));
    REQUIRE(threeFilled.isApprox(expectedThreeFilled));
}

TEST_CASE("Chapter 10 - Problem 01 - sortedMerge()","test"){
    int A[10] = {5, 5, 10, 10, 15};  // remainder of uninitialized values set to zero implicitly
    int B[5]  = {3, 6,  9, 12, 15};
    int lastA = 4;  // index of last item placed in A
    int lastB = 4;  // index of last item placed in B
    int C[10] = {3, 5, 5, 6, 9, 10, 10, 12, 15, 15};
    chapter_10::sortedMerge(&A[0], lastA, &B[0], lastB);
    for (int i = 0; i < 10; i++){
        REQUIRE(A[i] == C[i]);
    }


    int D[10] = {5, 5, 10, 10};  // remainder of uninitialized values set to zero implicitly
    int E[6]  = {3, 6,  9, 12, 15, 15};
    int lastD = 3;  // index of last item placed in D
    int lastE = 5;  // index of last item placed in E
    chapter_10::sortedMerge(&D[0], lastD, &E[0], lastE);
    for (int i = 0; i < 10; i++){
        REQUIRE(D[i] == C[i]);
    }
}

TEST_CASE("Chapter 12 - Problem 02 - reverse()", "test"){
    char s1[] = "Alex";
    char s1Rev[] = "xelA";
    char s2[] = "a";
    char s2Rev[] = "a";
    chapter_12::reverse(&s1[0]);
    chapter_12::reverse(&s2[0]);
    // strcmp returns 0 if the 2 strings are equal.
    REQUIRE(strcmp(&s1[0], &s1Rev[0]) == 0);
    REQUIRE(strcmp(&s2[0], &s2Rev[0]) == 0);
}

TEST_CASE("Chapter 12 - Problem 12 - copyNode()", "test"){
    std::vector<int> targetVector = {1,2,3,4,5,6,7};
    chapter_02::SinglyLinkedNode<int>* head = chapter_02::vectorToList(targetVector);
    chapter_02::SinglyLinkedNode<int>* copy = chapter_12::copyNode(head);
    REQUIRE(targetVector == chapter_02::listToVector(copy));  //  check that the values contained in nodes are identical
    // Check that the pointers in the head linked list are *not* the same as the pointers in the copy likned list
    // This is to verify a copy was actually made.
    while (head != nullptr && copy != nullptr){
        REQUIRE(head != copy);
        head = head->getNext();
        copy = copy->getNext();
    }
}

TEST_CASE("Misc Exercises - makeIntegralImage()", "test"){
    Eigen::MatrixXd input1(4, 4);
    input1 << 1, 1, 1, 1,
              1, 1, 1, 1,
              1, 1, 1, 1,
              1, 1, 1, 1;
    Eigen::MatrixXd output1(4, 4);
    output1 << 1,  2,  3,  4,
               2,  4,  6,  8,
               3,  6,  9, 12,
               4,  8, 12, 16;
    REQUIRE(output1.isApprox(misc::makeIntegralImage(input1)));
    Eigen::MatrixXd output2(4, 4);
    output2 << 1,   3,  6,  10,
               3,   9, 18,  30,
               6,  18, 36,  60,
               10, 30, 60, 100;
    REQUIRE(output2.isApprox(misc::makeIntegralImage(output1)));
}

TEST_CASE("Misc Exercises - boxFilter()", "test"){

}
