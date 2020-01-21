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
#include "cpp_solutions/chapter_16_moderate/chapter_16_includes.h"
#include "cpp_solutions/chapter_17_hard/chapter_17_includes.h"
#include "cpp_solutions/misc_exercises/misc_includes.h"
#define CATCH_CONFIG_MAIN
#include "cpp_solutions/third_party/Catch/include/catch.hpp"
#include <vector>
#include <Eigen/Dense>
#include <random>

TEST_CASE("Chapter 01 - Problem 01 - isUnique()", "test"){
    REQUIRE(chapter_01::isUnique("alex"));
    REQUIRE(!chapter_01::isUnique("aalex"));
}

TEST_CASE("Chapter 01 - Problem 02 - isPermutation()", "test"){
    REQUIRE(!chapter_01::isPermutation("alex", "aalex"));
    REQUIRE(chapter_01::isPermutation("alex", "xela"));
    REQUIRE(!chapter_01::isPermutation("aabb", "aaaa"));
    REQUIRE(!chapter_01::isPermutation("aaaa", "aabb"));
    REQUIRE(!chapter_01::isPermutation("aaaa", "aa"));
    REQUIRE(chapter_01::isPermutation("", ""));
}

TEST_CASE("Chapter 01 - Problem 03 - URLify()", "test") {
	// expect 'Mr. John Smith' -> 'Mr.%20John%20Smith'
	std::string input1 = "Mr. John Smith ";
    std::string input2 = "";
    std::string input3 = " ";
    std::string input4 = "Alex";
    const std::string expectedOutput1 = "Mr.%20John%20Smith%20";
    const std::string expectedOutput2 = "";
    const std::string expectedOutput3 = "%20";
    const std::string expectedOutput4 = "Alex";
	chapter_01::URLify(input1);
    chapter_01::URLify(input2);
    chapter_01::URLify(input3);
    chapter_01::URLify(input4);
	REQUIRE(input1 == expectedOutput1);
	REQUIRE(input2 == expectedOutput2);
	REQUIRE(input3 == expectedOutput3);
	REQUIRE(input4 == expectedOutput4);
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
    const std::vector<int> noDups = {1,7,3,6,5,4,2};
    const std::vector<int> dups = {2,2,1,5,6,2,5,2,7,7};
    const std::vector<int> fixedDups = {2,1,5,6,7};
    const std::vector<int> emptyVec;

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
    const std::vector<int> testVec1 = {1,7,3,6,5,4,2};
    const std::vector<int> testVec2 = {2,2,1,5,6,2,5,2,7,7};
    const std::vector<int> testVec3;
    const chapter_02::SinglyLinkedNode<int>* testVec1Head = chapter_02::vectorToList(testVec1);
    const chapter_02::SinglyLinkedNode<int>* testVec2Head = chapter_02::vectorToList(testVec2);
    const chapter_02::SinglyLinkedNode<int>* testVec3Head = chapter_02::vectorToList(testVec3);
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
    const std::vector<std::string> testVec = {"a", "b", "c", "d", "e", "f"};
    const std::vector<std::string> expectedVec = {"a", "b", "d", "e", "f"};
    chapter_02::SinglyLinkedNode<std::string>* testVecHead = chapter_02::vectorToList(testVec);
    const chapter_02::SinglyLinkedNode<std::string>* expectedVecHead = chapter_02::vectorToList(expectedVec);
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
    const std::vector<int> inputVec = {3, 5, 8, 5, 10, 2, 1};
    const std::vector<int> expectedVec = {1, 2, 3, 5, 8, 5, 10};
    chapter_02::SinglyLinkedNode<int>* inputVecHead = chapter_02::vectorToList(inputVec);
    const chapter_02::SinglyLinkedNode<int>* expectedVecHead = chapter_02::vectorToList(expectedVec);
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
    const std::vector<uint8_t> n1Vec = {3, 2, 4, 9};
    const std::vector<uint8_t> n2Vec = {1, 5, 9};
    const std::vector<uint8_t> sumVecExpected = {4, 7, 3, 0, 1};
    const chapter_02::SinglyLinkedNode<uint8_t>* n1Head = chapter_02::vectorToList(n1Vec);
    const chapter_02::SinglyLinkedNode<uint8_t>* n2Head = chapter_02::vectorToList(n2Vec);
    const std::vector<uint8_t> sumVecActual = chapter_02::listToVector(chapter_02::sumLists(n1Head, n2Head));
    REQUIRE(sumVecExpected == sumVecActual);
}

TEST_CASE("Chapter 02 - Problem 06 - palindrome()", "test"){
    const std::vector<int> list1 = {0, 4, 7, 0, 0, 7, 4, 0};
    const std::vector<int> list2 = {3, 5, 2, 5, 3};
    const std::vector<int> list3 = {0, 1, 0, 1, 0, 1};
    const std::vector<std::string> list4 = {"a", "l", "e",  "x"};
    const std::vector<std::string> list5 = {"A", "B", "B",  "A"};
    const chapter_02::SinglyLinkedNode<int>* head1 = chapter_02::vectorToList(list1);
    const chapter_02::SinglyLinkedNode<int>* head2 = chapter_02::vectorToList(list2);
    const chapter_02::SinglyLinkedNode<int>* head3 = chapter_02::vectorToList(list3);
    const chapter_02::SinglyLinkedNode<std::string>* head4 = chapter_02::vectorToList(list4);
    const chapter_02::SinglyLinkedNode<std::string>* head5 = chapter_02::vectorToList(list5);
    REQUIRE(chapter_02::palindrome(head1));
    REQUIRE(chapter_02::palindrome(head2));
    REQUIRE(!chapter_02::palindrome(head3));
    REQUIRE(!chapter_02::palindrome(head4));
    REQUIRE(chapter_02::palindrome(head5));
}

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
    chapter_03::Stack<int> myStack;
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
    chapter_03::StackMin<int> myStack;
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

TEST_CASE("Chapter 03 - Problem 04 - QueueViaStacks()", "test"){
    chapter_03::QueueViaStacks<int> myQueue;
    for (int i = 0; i < 10; i++) myQueue.enqueue(i);
    for (int i = 0; i < 5; i++) REQUIRE(myQueue.dequeue() == i);
    for (int i = 0; i < 5; i++) myQueue.enqueue(i);
    for (int i = 5; i < 10; i++) REQUIRE(myQueue.dequeue() == i);
    for (int i = 0; i < 5; i++) REQUIRE(myQueue.dequeue() == i);
}

TEST_CASE("Chapter 03 - Problem 05 - sortStack()", "test") {
    chapter_03::Stack<int> stack;
    std::vector<int> vector = {7, 6, 3, 5, 1, 2, 4};
    for (int x : vector) {
        stack.push(x);
    }
    chapter_03::sortStack(stack);
    for (int x = 1; x <= 7; x++) {
        REQUIRE(stack.pop() == x);
    }
}

TEST_CASE("Chapter 03 - Problem 06 - AnimalShelter", "test") {
    chapter_03::AnimalShelter shelter;
    auto catA = chapter_03::Cat("a");
    auto dogB = chapter_03::Dog("b");
    auto dogC = chapter_03::Dog("c");
    auto catD = chapter_03::Cat("d");
    auto dogE = chapter_03::Dog("e");
    auto catF = chapter_03::Cat("f");
    shelter.enqueue(&catA);
    shelter.enqueue(&dogB);
    shelter.enqueue(&dogC);
    shelter.enqueue(&catD);
    shelter.enqueue(&dogE);
    shelter.enqueue(&catF);
    REQUIRE("a" == shelter.dequeueAny()->getName());
    REQUIRE("b" == shelter.dequeueAny()->getName());
    REQUIRE("c" == shelter.dequeueDog()->getName());
    REQUIRE("d" == shelter.dequeueCat()->getName());
    REQUIRE("e" == shelter.dequeueAny()->getName());
    REQUIRE("f" == shelter.dequeueAny()->getName());
    REQUIRE(nullptr == shelter.dequeueAny());
}

TEST_CASE("Chapter 04 - Basic Graph Functionality", "test"){
    chapter_02::TetraGraphNode<int> node(1);
    chapter_02::TetraGraphNode<int>* child0 = new chapter_02::TetraGraphNode<int>(0);
    chapter_02::TetraGraphNode<int>* child1 = new chapter_02::TetraGraphNode<int>(1);
    chapter_02::TetraGraphNode<int>* child2 = new chapter_02::TetraGraphNode<int>(2);
    chapter_02::TetraGraphNode<int>* child3 = new chapter_02::TetraGraphNode<int>(3);
    node.addChild(child0, 0);
    node.addChild(child1, 1);
    node.addChild(child2, 2);
    node.addChild(child3, 3);
    std::vector<chapter_02::TetraGraphNode<int>*> children;
    node.getChildren(children);
    REQUIRE(children[0] == child0);
    REQUIRE(children[1] == child1);
    REQUIRE(children[2] == child2);
    REQUIRE(children[3] == child3);
    node.removeChild(0);
    node.removeChild(1);
    node.removeChild(2);
    node.removeChild(3);
    std::vector<chapter_02::TetraGraphNode<int>*> deletedChildren;
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
    chapter_02::TetraGraphNode<int>* node1 = new chapter_02::TetraGraphNode<int>(1);
    chapter_02::TetraGraphNode<int>* node2 = new chapter_02::TetraGraphNode<int>(2);
    chapter_02::TetraGraphNode<int>* node3 = new chapter_02::TetraGraphNode<int>(3);
    chapter_02::TetraGraphNode<int>* node4 = new chapter_02::TetraGraphNode<int>(4);
    chapter_02::TetraGraphNode<int>* node5 = new chapter_02::TetraGraphNode<int>(5);
    chapter_02::TetraGraphNode<int>* node6 = new chapter_02::TetraGraphNode<int>(6);
    chapter_02::TetraGraphNode<int>* node7 = new chapter_02::TetraGraphNode<int>(7);
    chapter_02::TetraGraphNode<int>* node8 = new chapter_02::TetraGraphNode<int>(8);
    node1->addChild(node2, 0);
    node2->addChild(node3, 0);
    node2->addChild(node4, 1);
    node4->addChild(node5, 0);
    node4->addChild(node7, 1);
    node5->addChild(node6, 0);
    node7->addChild(node8, 0);
    node8->addChild(node5, 0);
    REQUIRE(chapter_04::pathExistsDFS(node1, node6));
    REQUIRE(chapter_04::pathExistsDFS(node7, node5));
    REQUIRE(!chapter_04::pathExistsDFS(node3, node8));
    REQUIRE(chapter_04::pathExistsDFS(node1, node8));
    REQUIRE(!chapter_04::pathExistsDFS(static_cast<chapter_02::TetraGraphNode<int>*>(nullptr), static_cast<chapter_02::TetraGraphNode<int>*>(nullptr)));
    REQUIRE(!chapter_04::pathExistsDFS(node1, static_cast<chapter_02::TetraGraphNode<int>*>(nullptr)));
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
/*
balanced tree:

node111,
node121,node122,
node131,node132,nullptr,nullptr,
nullptr,nullptr,nullptr,nullptr,
*/

chapter_02::BinaryNode<int> node132(132, nullptr, nullptr);
chapter_02::BinaryNode<int> node131(131, nullptr, nullptr);
chapter_02::BinaryNode<int> node122(122, nullptr, nullptr);
chapter_02::BinaryNode<int> node121(121, &node131, &node132);
chapter_02::BinaryNode<int> node111(111, &node121, &node122);
chapter_04::NodeStatus status1 = chapter_04::checkBalanced(&node111);
REQUIRE(status1.balanced);
REQUIRE(status1.subtreeSize == 3);

/*
unbalanced tree:

node211,
node221,node222,
node231,node232,nullptr,nullptr,
node241,nullptr,nullptr,nullptr,
nullptr,nullptr,
*/

chapter_02::BinaryNode<int> node241(241, nullptr, nullptr);
chapter_02::BinaryNode<int> node232(232, nullptr, nullptr);
chapter_02::BinaryNode<int> node231(231, &node241, nullptr);
chapter_02::BinaryNode<int> node222(222, nullptr, nullptr);
chapter_02::BinaryNode<int> node221(221, &node231, &node232);
chapter_02::BinaryNode<int> node211(211, &node221, &node222);
chapter_04::NodeStatus status2 = chapter_04::checkBalanced(&node211);
REQUIRE(!status2.balanced);
REQUIRE(status2.subtreeSize == 4);
}

TEST_CASE("Chpater 04 - Problem 05 - validateBST()", "test") {
    // construct a binary tree
    chapter_02::BinaryNode<int> node1(1);
    chapter_02::BinaryNode<int> node2(2);
    chapter_02::BinaryNode<int> node3(3);
    chapter_02::BinaryNode<int> node4(4);
    chapter_02::BinaryNode<int> node5(5);
    chapter_02::BinaryNode<int> node6(6);
    chapter_02::BinaryNode<int> node8(8);
    chapter_02::BinaryNode<int> node10(10);
    /*
                   8
            4,            10
       2,       6,
    1,    3, 5,
    */
    node8.setLeft(&node4);
    node8.setRight(&node10);
    node4.setLeft(&node2);
    node4.setRight(&node6);
    node2.setLeft(&node1);
    node2.setRight(&node3);
    node6.setLeft(&node5);
    REQUIRE(chapter_04::validateBST(&node8));

    // add node that breaks BST rule
    chapter_02::BinaryNode<int> node9(9);
    node6.setRight(&node9);
    REQUIRE(!chapter_04::validateBST(&node8));
}

TEST_CASE("Chapter 04 - Problem 06 - successor()", "test"){
    // construct a binary tree
    chapter_02::BinaryNode<int>* node0 = new chapter_02::BinaryNode<int>(0);
    chapter_02::BinaryNode<int>* node1 = new chapter_02::BinaryNode<int>(1);
    chapter_02::BinaryNode<int>* node2 = new chapter_02::BinaryNode<int>(2);
    chapter_02::BinaryNode<int>* node3 = new chapter_02::BinaryNode<int>(3);
    chapter_02::BinaryNode<int>* node4 = new chapter_02::BinaryNode<int>(4);
    chapter_02::BinaryNode<int>* node5 = new chapter_02::BinaryNode<int>(5);
    chapter_02::BinaryNode<int>* node6 = new chapter_02::BinaryNode<int>(6);
    chapter_02::BinaryNode<int>* node7 = new chapter_02::BinaryNode<int>(7);
    chapter_02::BinaryNode<int>* node8 = new chapter_02::BinaryNode<int>(8);
    chapter_02::BinaryNode<int>* node9 = new chapter_02::BinaryNode<int>(9);
    chapter_02::BinaryNode<int>* node10 = new chapter_02::BinaryNode<int>(10);
    /*
                            8
                4                       10
        2               6
    1       3       5
           0 9
    In-order traversal:
    1, 2, 0, 3, 9, 4, 5, 6, 8, 10
    */
    node0->setParent(node3);
    node1->setParent(node2);
    node3->setParent(node2);
    node2->setParent(node4);
    node5->setParent(node6);
    node6->setParent(node4);
    node4->setParent(node8);
    node9->setParent(node3);
    node10->setParent(node8);

    node8->setLeft(node4);
    node8->setRight(node10);
    node4->setLeft(node2);
    node4->setRight(node6);
    node2->setLeft(node1);
    node2->setRight(node3);
    node6->setLeft(node5);
    node3->setLeft(node0);
    node3->setRight(node9);

    REQUIRE(node8 == chapter_04::successor(node6));
    REQUIRE(node5 == chapter_04::successor(node4));
    REQUIRE(node0 == chapter_04::successor(node2));
    REQUIRE(node3 == chapter_04::successor(node0));
    REQUIRE(node4 == chapter_04::successor(node9));
    REQUIRE(nullptr == chapter_04::successor(node10));
}

TEST_CASE("Chapter 04 - Problem 07 - buildOrder()", "test") {
    // no circular dependencies
    std::vector<char> projects1 = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<std::pair<char, char>> dependencies1 = {
            std::pair<char, char>('a', 'd'),
            std::pair<char, char>('f', 'b'),
            std::pair<char, char>('b', 'd'),
            std::pair<char, char>('f', 'a'),
            std::pair<char, char>('d', 'c')};
    std::vector<char> projects2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::vector<std::pair<char, char>> dependencies2 = {
            std::pair<char, char>('f', 'c'),
            std::pair<char, char>('f', 'b'),
            std::pair<char, char>('f', 'a'),
            std::pair<char, char>('c', 'a'),
            std::pair<char, char>('b', 'a'),
            std::pair<char, char>('a', 'e'),
            std::pair<char, char>('b', 'e'),
            std::pair<char, char>('d', 'g')};
    // add circular dependency
    std::vector<std::pair<char, char>> dependencies3 = {
            std::pair<char, char>('a', 'd'),
            std::pair<char, char>('f', 'b'),
            std::pair<char, char>('b', 'd'),
            std::pair<char, char>('f', 'a'),
            std::pair<char, char>('d', 'c'),
            std::pair<char, char>('c', 'a')};
    // verify output
    std::vector<char> actualBuildOrder1 = {};
    std::vector<char> actualBuildOrder2 = {};
    std::vector<char> actualBuildOrder3 = {};
    std::vector<char> expectedBuildOrder1 = {'e', 'f', 'b', 'a', 'd', 'c'};
    std::vector<char> expectedBuildOrder2 = {'d', 'f', 'g', 'c', 'b', 'a', 'e'};
    chapter_04::buildOrder(projects1, dependencies1, actualBuildOrder1);
    chapter_04::buildOrder(projects2, dependencies2, actualBuildOrder2);
    chapter_04::buildOrder(projects1, dependencies3, actualBuildOrder3);
    for (int i = 0; i < actualBuildOrder1.size(); i++) {
        REQUIRE(actualBuildOrder1[i] == expectedBuildOrder1[i]);
    }
    for (int i = 0; i < actualBuildOrder2.size(); i++) {
        REQUIRE(actualBuildOrder2[i] == expectedBuildOrder2[i]);
    }
    REQUIRE(actualBuildOrder3.empty());
}

TEST_CASE("Chapter 04 - Problem 08 - firstCommonAncestor()", "test") {
    /*
    construct binary tree
                    7
            4               3
        10      5       6       15
                            21      17


                            25
    */
    chapter_02::BinaryNode<int> n21(21);
    chapter_02::BinaryNode<int> n17(17);
    chapter_02::BinaryNode<int> n15(15, &n21, &n17);
    chapter_02::BinaryNode<int> n6(6);
    chapter_02::BinaryNode<int> n3(3, &n6, &n15);
    chapter_02::BinaryNode<int> n10(10);
    chapter_02::BinaryNode<int> n5(5);
    chapter_02::BinaryNode<int> n4(4, &n10, &n5);
    chapter_02::BinaryNode<int> n7(7, &n4, &n3);
    chapter_02::BinaryNode<int> n25(25);

    REQUIRE(&n3 == chapter_04::firstCommonAncestor(&n7, &n6, &n21));
    REQUIRE(&n7 == chapter_04::firstCommonAncestor(&n7, &n10, &n21));
    REQUIRE(nullptr == chapter_04::firstCommonAncestor(&n7, &n15, &n25));
    REQUIRE(nullptr == chapter_04::firstCommonAncestor(&n7, &n7, &n7));  // a node is not its own ancestor
    REQUIRE(&n7 == chapter_04::firstCommonAncestor(&n7, &n3, &n4));
}

TEST_CASE("Chapter 04 - Problem 10 - checkSubtree()", "test") {
    /*
    construct binary tree
                    7
            4               3
        10      5       6       15
                            21      17


                            25
    */
    chapter_02::BinaryNode<int> n21(21);
    chapter_02::BinaryNode<int> n17(17);
    chapter_02::BinaryNode<int> n15(15, &n21, &n17);
    chapter_02::BinaryNode<int> n6(6);
    chapter_02::BinaryNode<int> n3(3, &n6, &n15);
    chapter_02::BinaryNode<int> n10(10);
    chapter_02::BinaryNode<int> n5(5);
    chapter_02::BinaryNode<int> n4(4, &n10, &n5);
    chapter_02::BinaryNode<int> n7(7, &n4, &n3);
    chapter_02::BinaryNode<int> n25(25);
    /*
    construct disconnected binary tree
        30
    31      32
    */
    chapter_02::BinaryNode<int> n31(31);
    chapter_02::BinaryNode<int> n32(32);
    chapter_02::BinaryNode<int> n30(30, &n31, &n32);

    REQUIRE(chapter_04::checkSubtree(&n7, &n15));
    REQUIRE(chapter_04::checkSubtree(&n7, &n7));
    REQUIRE(chapter_04::checkSubtree(&n7, &n21));
    REQUIRE(chapter_04::checkSubtree(&n7, &n4));
    REQUIRE(!chapter_04::checkSubtree<int>(&n7, nullptr));
    REQUIRE(!chapter_04::checkSubtree(&n7, &n30));
    REQUIRE(!chapter_04::checkSubtree(&n7, &n31));
    REQUIRE(!chapter_04::checkSubtree(&n25, &n31));
    REQUIRE(chapter_04::checkSubtree(&n30, &n31));
    REQUIRE(!chapter_04::checkSubtree<int>(nullptr, nullptr));
}

TEST_CASE("Chapter 04 - Problem 11 - randomBST()", "test"){
    std::vector<int> valuesList = {10, 13, 14, 11, 7, 7, 8, 7, 4, 10};
    chapter_04::RandBinaryNode<int> head(valuesList[0]);
    for (int i = 1; i < valuesList.size(); i++) {
        head.insert(valuesList[i]);
    }
    int occurrenceSum4 = 0;
    int occurrenceSum7 = 0;
    int occurrenceSum10 = 0;
    int occurrenceSum13 = 0;
    // using 10,000 random samples, assert that occurence of values in random samples approximately
    // the same as the occurence of the values in the tree
    std::mt19937 gen(0);  // standard mersenne_twister_engine seeded with zero
    for (int i = 0; i < 10000; i++) {
        int randValue = head.getRandomNode(-1, &gen)->getValue();
        switch (randValue){
            case 4 : occurrenceSum4 ++; break;
            case 7 : occurrenceSum7 ++; break;
            case 10 : occurrenceSum10 ++; break;
            case 13 : occurrenceSum13 ++; break;
        }
    }
    REQUIRE(((950 <= occurrenceSum4) && (occurrenceSum4 <= 1050)));
    REQUIRE(((2950 <= occurrenceSum7) && (occurrenceSum7 <= 3050)));
    REQUIRE(((1950 <= occurrenceSum10) && (occurrenceSum10 <= 2050)));
    REQUIRE(((950 <= occurrenceSum13) && (occurrenceSum13 <= 1050)));
}

TEST_CASE("Chapter 04 - Problem 12 - pathsWithSum()", "test"){
    /*
    construct binary tree like in textbook example
                        10
                5                   -3
        3              1        __      11
    3     -2         __    2
    */
    // leaf nodes at depth = 3
    chapter_02::BinaryNode<int> n3_leaf(3);
    chapter_02::BinaryNode<int> n_minus2(-2);
    chapter_02::BinaryNode<int> n2(2);
    // nodes at depth = 2
    chapter_02::BinaryNode<int> n3(3, &n3_leaf, &n_minus2);
    chapter_02::BinaryNode<int> n1(1, nullptr, &n2);
    chapter_02::BinaryNode<int> n11(11);
    // nodes at depth = 1
    chapter_02::BinaryNode<int> n5(5, &n3, &n1);
    chapter_02::BinaryNode<int> n_minus3(-3, nullptr, &n11);
    // root node at depth = 0
    chapter_02::BinaryNode<int> n10(10, &n5, &n_minus3);
    // count paths that sum to 8
    REQUIRE(3 == chapter_04::pathsWithSum(8, &n10));
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

TEST_CASE("Chapter 05 - Problem 03 - flipBitToWin()", "test") {
    REQUIRE(chapter_05::flipBitToWin(1775) == 8);
    REQUIRE(chapter_05::flipBitToWin(0b0000) == 1);
    REQUIRE(chapter_05::flipBitToWin(0b1011) == 4);
    REQUIRE(chapter_05::flipBitToWin(0b1010111) == 5);
    REQUIRE(chapter_05::flipBitToWin(0b1110101) == 5);
    REQUIRE(chapter_05::flipBitToWin(0b00) == 1);
    REQUIRE(chapter_05::flipBitToWin(0b10) == 2);
}

TEST_CASE("Chapter 05 - Problem 04 - nextNumber()", "test"){
    REQUIRE(chapter_05::getPrev(0b0001) == -1);
    REQUIRE(chapter_05::getNext(0b0001) == 0b0010);
    REQUIRE(chapter_05::getPrev(0b0100) == 0b0010);
    REQUIRE(chapter_05::getNext(0b0100) == 0b1000);
    REQUIRE(chapter_05::getPrev(0b0101) == 0b0011);
    REQUIRE(chapter_05::getNext(0b0101) == 0b0110);
    REQUIRE(chapter_05::getPrev(0b1111) == -1);        // there is no previous number possible
    REQUIRE(chapter_05::getNext(0b1111) == 0b10111);
    REQUIRE(chapter_05::getPrev(0b0000) == -1);        // there is no previous number possible
    REQUIRE(chapter_05::getNext(0b0000) == -1);        // there is no next number possible
    REQUIRE(chapter_05::getPrev(UINT32_MAX) == -1);    // there is no previous number possible
    REQUIRE(chapter_05::getNext(UINT32_MAX) == -1);    // there is no next number possible
    REQUIRE(chapter_05::getPrev(0b1001) == 0b0110);
    // 0b1001 = 1*2^0 + 0*2^1 + 0*2^2 + 1*2^3 = 9
    // 0b0101 = 1*2^0 + 0*2^1 + 1*2^2 + 0*2^3 = 5
    // 0b0110 = 0*2^0 + 1*2^1 + 1*2^2 + 0*2^3 = 6 <- N.B. this is the true getPrev(0b1001) result, not 5
    REQUIRE(chapter_05::getNext(0b1001) == 0b1010);
    REQUIRE(chapter_05::getPrev(0b0110) == 0b0101);
    REQUIRE(chapter_05::getNext(0b0110) == 0b1001);
    REQUIRE(chapter_05::getPrev(0b10011110000011) == 0b10011101110000);  // example from textbook
    REQUIRE(chapter_05::getNext(0b11011001111100) == 0b11011010001111);  // example from textbook
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

TEST_CASE("Chapter 05 - Problem 08 - drawLine()", "test"){
    // Screen #1: Line goes middle to end. Line spans less than 8 bits.
    uint32_t bitWidth1 = 8;
    uint32_t bitLength1 = 64;
    uint8_t screen1[64 / 8] = {0};
    uint32_t x1_1 = 3;
    uint32_t x2_1 = 7;
    uint32_t y_1 = 5;
    std::string expectedInitialScreen1 = "00000000\n"
                                         "00000000\n"
                                         "00000000\n"
                                         "00000000\n"
                                         "00000000\n"
                                         "00000000\n"
                                         "00000000\n"
                                         "00000000\n";
    std::string expectedFinalScreen1 = "00000000\n"
                                       "00000000\n"
                                       "00000000\n"
                                       "00000000\n"
                                       "00000000\n"
                                       "00011111\n"
                                       "00000000\n"
                                       "00000000\n";
    REQUIRE(expectedInitialScreen1 == chapter_05::stringifyScreen(screen1, bitWidth1, bitLength1));
    chapter_05::drawLine(screen1, bitWidth1, bitLength1, x1_1, x2_1, y_1);
    REQUIRE(expectedFinalScreen1 == chapter_05::stringifyScreen(screen1, bitWidth1, bitLength1));


    // Screen #2: Line spans more than 8 bits.
    uint32_t bitWidth2 = 32;
    uint32_t bitLength2 = 64;
    uint8_t screen2[64 / 8] = {0};
    uint32_t x1_2 = 0;
    uint32_t x2_2 = 13;
    uint32_t y_2 = 1;
    std::string expectedInitialScreen2 = "00000000000000000000000000000000\n"
                                         "00000000000000000000000000000000\n";
    std::string expectedFinalScreen2 = "00000000000000000000000000000000\n"
                                       "11111111111111000000000000000000\n";
    REQUIRE(expectedInitialScreen2 == chapter_05::stringifyScreen(screen2, bitWidth2, bitLength2));
    chapter_05::drawLine(screen2, bitWidth2, bitLength2, x1_2, x2_2, y_2);
    REQUIRE(expectedFinalScreen2 == chapter_05::stringifyScreen(screen2, bitWidth2, bitLength2));

    // Screen #3: Line spans more than 8 bits.
    uint32_t bitWidth3 = 64;
    uint32_t bitLength3 = 256;
    uint8_t screen3[256 / 8] = {0};
    uint32_t x1_3 = 5;
    uint32_t x2_3 = 24;
    uint32_t y_3 = 1;
    std::string expectedInitialScreen3 = "0000000000000000000000000000000000000000000000000000000000000000\n"
                                         "0000000000000000000000000000000000000000000000000000000000000000\n"
                                         "0000000000000000000000000000000000000000000000000000000000000000\n"
                                         "0000000000000000000000000000000000000000000000000000000000000000\n";
    std::string expectedFinalScreen3 = "0000000000000000000000000000000000000000000000000000000000000000\n"
                                       "0000011111111111111111111000000000000000000000000000000000000000\n"
                                       "0000000000000000000000000000000000000000000000000000000000000000\n"
                                       "0000000000000000000000000000000000000000000000000000000000000000\n";
    REQUIRE(expectedInitialScreen3 == chapter_05::stringifyScreen(screen3, bitWidth3, bitLength3));
    chapter_05::drawLine(screen3, bitWidth3, bitLength3, x1_3, x2_3, y_3);
    REQUIRE(expectedFinalScreen3 == chapter_05::stringifyScreen(screen3, bitWidth3, bitLength3));

    // Screen #4: Line spans a single bit.
    uint32_t bitWidth4 = 8;
    uint32_t bitLength4 = 8;
    uint8_t screen4[1] = {0};
    uint32_t x1_4 = 3;
    uint32_t x2_4 = 3;
    uint32_t y_4 = 0;
    std::string expectedInitialScreen4 = "00000000\n";
    std::string expectedFinalScreen4 = "00010000\n";
    REQUIRE(expectedInitialScreen4 == chapter_05::stringifyScreen(screen4, bitWidth4, bitLength4));
    chapter_05::drawLine(screen4, bitWidth4, bitLength4, x1_4, x2_4, y_4);
    REQUIRE(expectedFinalScreen4 == chapter_05::stringifyScreen(screen4, bitWidth4, bitLength4));
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
}

TEST_CASE("Chapter 08 - Problem 05 - recursiveMultiply()", "test"){
    REQUIRE(chapter_08::recursiveMultiply(1, 1) == 1);
    REQUIRE(chapter_08::recursiveMultiply(1, 2) == 2);
    REQUIRE(chapter_08::recursiveMultiply(0, 1) == 0);
    REQUIRE(chapter_08::recursiveMultiply(9, 10) == 90);
    REQUIRE(chapter_08::recursiveMultiply(9, 11) == 99);
    REQUIRE(chapter_08::recursiveMultiply(12, 12) == 144);
}

TEST_CASE("Chapter 08 - Problem 07 - permutationsNoDups()", "test") {
    std::unordered_set<std::string> actual1 = {};
    std::unordered_set<std::string> actual2 = {};
    std::unordered_set<std::string> actual3 = {};
    std::unordered_set<std::string> actual4 = {};
    std::unordered_set<std::string> expected1 = {"a"};
    std::unordered_set<std::string> expected2 = {"al", "la"};
    std::unordered_set<std::string> expected3 = {"ela", "lea", "lae", "eal", "ael", "ale"};
    std::unordered_set<std::string> expected4 = {"xela", "exla", "elxa", "elax",
                                       "xlea", "lxea", "lexa", "leax",
                                       "xlae", "lxae", "laxe", "laex",
                                       "xeal", "exal", "eaxl", "ealx",
                                       "xael", "axel", "aexl", "aelx",
                                       "xale", "axle", "alxe", "alex"};
    chapter_08::permutationsNoDups("a", actual1);
    chapter_08::permutationsNoDups("al", actual2);
    chapter_08::permutationsNoDups("ale", actual3);
    chapter_08::permutationsNoDups("alex", actual4);
    REQUIRE(actual1 == expected1);
    REQUIRE(actual2 == expected2);
    REQUIRE(actual3 == expected3);
    REQUIRE(actual4 == expected4);
}

TEST_CASE("Chapter 08 - Problem 08 - permutationsWithDups()", "test") {
    std::unordered_set<std::string> actual1 = {};
    std::unordered_set<std::string> actual2 = {};
    std::unordered_set<std::string> actual3 = {};
    std::unordered_set<std::string> expected1 = {"ala", "laa", "aal"};
    std::unordered_set<std::string> expected2 = {"aala", "alaa", "alaa", "laaa", "aala", "aaal"};
    std::unordered_set<std::string> expected3 = {"xela", "exla", "elxa", "elax",
                                                 "xlea", "lxea", "lexa", "leax",
                                                 "xlae", "lxae", "laxe", "laex",
                                                 "xeal", "exal", "eaxl", "ealx",
                                                 "xael", "axel", "aexl", "aelx",
                                                 "xale", "axle", "alxe", "alex"};
    chapter_08::permutationsWithDups("ala", actual1);
    chapter_08::permutationsWithDups("alaa", actual2);
    chapter_08::permutationsWithDups("alex", actual3);
    REQUIRE(actual1 == expected1);
    REQUIRE(actual2 == expected2);
    REQUIRE(actual3 == expected3);
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

TEST_CASE("Chapter 10 - mergeSort()", "test"){
    std::vector<int> input1 = {1000, 10, 7, 3, -1000, 5, 100, 9, 1, 10000, -10000, 6, 2, -10, 4, 8, -100, 0};
    std::vector<int> expectedOutput1 = {-10000, -1000, -100, -10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000};
    std::vector<int> input2 = {};
    std::vector<int> expectedOutput2 = {};
    std::vector<float> input3 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    std::vector<float> expectedOutput3 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    std::vector<float> input4 = {1.1};
    std::vector<float> expectedOutput4 = {1.1};
    std::vector<float> input5 = {1.4, 1.6, 1.1, 1.3, 1.5, 1.7, 1.2};
    std::vector<float> expectedOutput5 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    chapter_10::mergeSort(input1);
    chapter_10::mergeSort(input2);
    chapter_10::mergeSort(input3);
    chapter_10::mergeSort(input4);
    chapter_10::mergeSort(input5);
    REQUIRE(expectedOutput1 == input1);
    REQUIRE(expectedOutput2 == input2);
    REQUIRE(expectedOutput3 == input3);
    REQUIRE(expectedOutput4 == input4);
    REQUIRE(expectedOutput5 == input5);
}

TEST_CASE("Chapter 10 - quickSort()", "test"){
    std::vector<int> input1 = {1000, 10, 7, 3, -1000, 5, 100, 9, 1, 10000, -10000, 6, 2, -10, 4, 8, -100, 0};
    std::vector<int> expectedOutput1 = {-10000, -1000, -100, -10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000};
    std::vector<int> input2 = {};
    std::vector<int> expectedOutput2 = {};
    std::vector<float> input3 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    std::vector<float> expectedOutput3 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    std::vector<float> input4 = {1.1};
    std::vector<float> expectedOutput4 = {1.1};
    std::vector<float> input5 = {1.4, 1.6, 1.1, 1.3, 1.5, 1.7, 1.2};
    std::vector<float> expectedOutput5 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    chapter_10::quickSort(input1);
    chapter_10::quickSort(input2);
    chapter_10::quickSort(input3);
    chapter_10::quickSort(input4);
    chapter_10::quickSort(input5);
    REQUIRE(expectedOutput1 == input1);
    REQUIRE(expectedOutput2 == input2);
    REQUIRE(expectedOutput3 == input3);
    REQUIRE(expectedOutput4 == input4);
    REQUIRE(expectedOutput5 == input5);
}

TEST_CASE("Chapter 10 - binarySearch()", "test"){
    std::vector<int> input1 = {-10000, -1000, -100, -10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000};
    std::vector<int> input2 = {};
    std::vector<float> input3 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    REQUIRE(-1 == chapter_10::binarySearch(input1, 101));
    REQUIRE(16 == chapter_10::binarySearch(input1, 1000));
    REQUIRE(4 == chapter_10::binarySearch(input1, 0));
    REQUIRE(15 == chapter_10::binarySearch(input1, 100));
    REQUIRE(13 == chapter_10::binarySearch(input1, 9));
    REQUIRE(10 == chapter_10::binarySearch(input1, 6));
    REQUIRE(-1 == chapter_10::binarySearch(input2, 101));
    REQUIRE(3 == chapter_10::binarySearch<float>(input3, 1.4));
    REQUIRE(5 == chapter_10::binarySearch<float>(input3, 1.6));
}

TEST_CASE("Chapter 10 - Problem 01 - sortedMerge()", "test"){
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

TEST_CASE("Chapter 10 - Problem 02 - anagramSort()", "test"){
    std::vector<std::string> example1 = {"ddd", "abc", "ccc", "bac", "aaa", "cab", "bbb", "acb"};
    std::vector<std::string> expected1 = {"aaa", "abc", "bac", "cab", "acb", "bbb", "ccc", "ddd" };
    std::vector<std::string> example2 = {"aaa"};
    std::vector<std::string> expected2 = {"aaa"};
    std::vector<std::string> example3 = {};
    std::vector<std::string> expected3 = {};
    std::vector<std::string> example4 = {"a", "ddd", "abc", "ccc", "a", "bac", "aaa", "cab", "bbb", "acb", "a"};
    std::vector<std::string> expected4 = {"a", "a", "a", "aaa", "abc", "bac", "cab", "acb", "bbb", "ccc", "ddd" };
    std::vector<std::string> example5 = {"", "a", "", "b", ""};
    std::vector<std::string> expected5 = { "", "", "", "a", "b" };
    chapter_10::anagramSort(example1);
    chapter_10::anagramSort(example2);
    chapter_10::anagramSort(example3);
    chapter_10::anagramSort(example4);
    chapter_10::anagramSort(example5);
    REQUIRE(expected1 == example1);
    REQUIRE(expected2 == example2);
    REQUIRE(expected3 == example3);
    REQUIRE(expected4 == example4);
    REQUIRE(expected5 == example5);
}

TEST_CASE("Chapter 10 - Problem 03 - rotatedSearch()", "test"){
    // test unrotated
    std::vector<int> input1 = {-10000, -1000, -100, -10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000};
    std::vector<int> input2 = {};
    std::vector<float> input3 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    REQUIRE(-1 == chapter_10::rotatedSearch(input1, 101));
    REQUIRE(16 == chapter_10::rotatedSearch(input1, 1000));
    REQUIRE(4 == chapter_10::rotatedSearch(input1, 0));
    REQUIRE(15 == chapter_10::rotatedSearch(input1, 100));
    REQUIRE(13 == chapter_10::rotatedSearch(input1, 9));
    REQUIRE(10 == chapter_10::rotatedSearch(input1, 6));
    REQUIRE(-1 == chapter_10::rotatedSearch(input2, 101));
    REQUIRE(3 == chapter_10::rotatedSearch<float>(input3, 1.4));
    REQUIRE(5 == chapter_10::rotatedSearch<float>(input3, 1.6));
    // test rotated
    std::vector<int> rotatedInput1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000, -10000, -1000, -100, -10, 0};  // -5 rotation
    std::vector<int> rotatedInput2 = {};
    std::vector<float> rotatedInput3 = {1.5, 1.6, 1.7, 1.1, 1.2, 1.3, 1.4};  // +3 rotation
    REQUIRE(-1 == chapter_10::rotatedSearch(rotatedInput1, 101));
    REQUIRE(11 == chapter_10::rotatedSearch(rotatedInput1, 1000));
    REQUIRE(17 == chapter_10::rotatedSearch(rotatedInput1, 0));
    REQUIRE(10 == chapter_10::rotatedSearch(rotatedInput1, 100));
    REQUIRE(8 == chapter_10::rotatedSearch(rotatedInput1, 9));
    REQUIRE(5 == chapter_10::rotatedSearch(rotatedInput1, 6));
    REQUIRE(-1 == chapter_10::rotatedSearch(rotatedInput2, 101));
    REQUIRE(6 == chapter_10::rotatedSearch<float>(rotatedInput3, 1.4));
    REQUIRE(1 == chapter_10::rotatedSearch<float>(rotatedInput3, 1.6));
}

TEST_CASE("Chapter 10 - Problem 04 - rotatedSearch()", "test"){
    chapter_10::Listy input1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000};
    chapter_10::Listy input2 = {};
    REQUIRE(-1 == chapter_10::searchNoSize(input1, 101));
    REQUIRE(11 == chapter_10::searchNoSize(input1, 1000));
    REQUIRE(10 == chapter_10::searchNoSize(input1, 100));
    REQUIRE(8 == chapter_10::searchNoSize(input1, 9));
    REQUIRE(5 == chapter_10::searchNoSize(input1, 6));
    REQUIRE(-1 == chapter_10::searchNoSize(input2, 101));
}

TEST_CASE("Chapter 10 - Problem 05 - sparseSearch()", "test"){
    std::vector<std::string> input1 = {"at", "", "", "", "ball", "" , "", "car", "", "", "dad", "", ""};
    std::vector<std::string> input2 = {"", "", "", "", ""};
    std::vector<std::string> input3 = {};
    std::vector<std::string> input4 = {"alex"};
    REQUIRE(0 == chapter_10::sparseSearch(input1, "at"));
    REQUIRE(4 == chapter_10::sparseSearch(input1, "ball"));
    REQUIRE(7 == chapter_10::sparseSearch(input1, "car"));
    REQUIRE(10 == chapter_10::sparseSearch(input1, "dad"));
    REQUIRE(-1 == chapter_10::sparseSearch(input1, "alex"));
    REQUIRE(-1 == chapter_10::sparseSearch(input2, "alex"));
    REQUIRE(-1 == chapter_10::sparseSearch(input3, ""));
    REQUIRE(-1 == chapter_10::sparseSearch(input3, "alex"));
    REQUIRE(0 == chapter_10::sparseSearch(input4, "alex"));
}

TEST_CASE("Chapter 10 - Problem 07 - missingInt()", "test") {
    REQUIRE(64 == chapter_10::missingInt("../cpp_solutions/chapter_10_sorting_and_searching/chapter_10_dataset_generation/random_number_dataset.csv"));
}

TEST_CASE("Chapter 10 - Problem 08 - findDuplicates()", "test") {
    const std::string filepath = "../cpp_solutions/chapter_10_sorting_and_searching/chapter_10_dataset_generation/random_number_dataset_32000.csv";
    const std::vector<int> expectedDuplicates = { 1827, 3769, 5645, 5824, 8767,
                                                  8969, 12565, 12862, 13643, 13803,
                                                  13854, 17496, 18281, 20776, 23323,
                                                  25799, 26371, 27343, 30323 };
    std::vector<int> actualDuplicates = {};
    chapter_10::findDuplicates(actualDuplicates, filepath);
    REQUIRE(expectedDuplicates == actualDuplicates);
}

TEST_CASE("Chapter 10 - Problem 09 - matrixSearch()", "test") {
    Eigen::Matrix<int, 6, 6> example1;
    example1 << 0, 1, 1, 1, 2, 3,
                1, 1, 1, 1, 2, 2,
                1, 1, 1, 2, 2, 5,
                1, 2, 2, 3, 5, 5,
                1, 5, 5, 5, 5, 5,
                1, 5, 5, 5, 5, 5;
    Eigen::Matrix<int, 6, 7> example2;
    example2 << 0,  1,  2,  3,  4,  5,   6,
                1, 11, 21, 31, 41, 51,  61,
                2, 22, 32, 42, 52, 62,  72,
                3, 33, 43, 53, 63, 73,  83,
                4, 44, 54, 64, 74, 84,  94,
                5, 55, 65, 75, 85, 95, 105;
    chapter_10::Point2 expectedCoordinate1(3, 1);
    chapter_10::Point2 expectedCoordinate2(2, 4);
    chapter_10::Point2 expectedCoordinate3(5, 6);
    chapter_10::Point2 expectedCoordinate4(0, 5);
    chapter_10::Point2 expectedCoordinate5(5, 4);
    chapter_10::Point2 expectedCoordinate6(3, 3);
    chapter_10::Point2 actualCoordinate1 = chapter_10::matrixSearch(example1, 2);
    chapter_10::Point2 actualCoordinate2 = chapter_10::matrixSearch(example2, 52);
    chapter_10::Point2 actualCoordinate3 = chapter_10::matrixSearch(example2, 105);
    chapter_10::Point2 actualCoordinate4 = chapter_10::matrixSearch(example2, 5);
    chapter_10::Point2 actualCoordinate5 = chapter_10::matrixSearch(example2, 85);
    chapter_10::Point2 actualCoordinate6 = chapter_10::matrixSearch(example1, 3);
    REQUIRE(expectedCoordinate1 == actualCoordinate1);
    REQUIRE(expectedCoordinate2 == actualCoordinate2);
    REQUIRE(expectedCoordinate3 == actualCoordinate3);
    REQUIRE(expectedCoordinate4 == actualCoordinate4);
    REQUIRE(expectedCoordinate5 == actualCoordinate5);
    REQUIRE(expectedCoordinate6 == actualCoordinate6);
}

TEST_CASE("Chapter 10 - Problem 10 - rankFromStream()", "test") {
    chapter_10::RankTracker rankTracker;
    rankTracker.track(5);
    rankTracker.track(1);
    rankTracker.track(4);
    rankTracker.track(4);
    rankTracker.track(5);
    rankTracker.track(9);
    rankTracker.track(7);
    rankTracker.track(13);
    rankTracker.track(3);
    rankTracker.track(6);
    rankTracker.track(7);
    REQUIRE(rankTracker.getRank(1) == 0);
    REQUIRE(rankTracker.getRank(3) == 1);
    REQUIRE(rankTracker.getRank(4) == 3);
    REQUIRE(rankTracker.getRank(0) == -1);
    REQUIRE(rankTracker.getRank(7) == 8);
    REQUIRE(rankTracker.getRank(13) == 10);
    REQUIRE(rankTracker.getRank(6) == 6);
}

TEST_CASE("Chapter 10 - Problem 11 - peaksAndValleys()", "test") {
    std::vector<int> input1 = {5, 3, 1, 2, 3};
    const std::vector<int> expectedOutput1 = {5, 1, 3, 2, 3};
    std::vector<int> input2 = {5, 8, 6, 2, 3, 4, 6};
    std::vector<int> expectedOutput2 = {5, 8, 2, 6, 3, 6, 4};
    std::vector<int> input3 = {};
    std::vector<int> expectedOutput3 = {};
    std::vector<int> input4 = {5};
    std::vector<int> expectedOutput4 = {5};
    std::vector<int> input5 = {55};
    std::vector<int> expectedOutput5 = {55};
    std::vector<int> input6 = {54};
    std::vector<int> expectedOutput6 = {54};
    std::vector<int> input7 = {45};
    std::vector<int> expectedOutput7 = {45};
    std::vector<int> input8 = {554};
    std::vector<int> expectedOutput8 = {554};
    std::vector<int> input9 = {5, 5, 8, 6, 6, 2, 3, 3, 4, 6, 6};
    std::vector<int> expectedOutput9 = {5, 5, 8, 6, 6, 2, 3, 3, 6, 4, 6};
    chapter_10::peaksAndValleys(input1);
    chapter_10::peaksAndValleys(input2);
    chapter_10::peaksAndValleys(input3);
    chapter_10::peaksAndValleys(input4);
    chapter_10::peaksAndValleys(input5);
    chapter_10::peaksAndValleys(input6);
    chapter_10::peaksAndValleys(input7);
    chapter_10::peaksAndValleys(input8);
    chapter_10::peaksAndValleys(input9);
    REQUIRE(input1 == expectedOutput1);
    REQUIRE(input2 == expectedOutput2);
    REQUIRE(input3 == expectedOutput3);
    REQUIRE(input4 == expectedOutput4);
    REQUIRE(input5 == expectedOutput5);
    REQUIRE(input6 == expectedOutput6);
    REQUIRE(input7 == expectedOutput7);
    REQUIRE(input8 == expectedOutput8);
    REQUIRE(input9 == expectedOutput9);
}

TEST_CASE("Chapter 12 - Problem 01 - lastKLines()", "test"){
    const std::string filepath1 = "../cpp_solutions/chapter_12_cpp/problem_12_01_data_1.txt";
    const std::string filepath2 = "../cpp_solutions/chapter_12_cpp/problem_12_01_data_2.txt";
    const std::string filepath3 = "../cpp_solutions/chapter_12_cpp/problem_12_01_data_3.txt";
    std::vector<std::string> lines1 = {"", "", "", ""};
    std::vector<std::string> lines2 = {"", "", "", ""};
    std::vector<std::string> lines3 = {"", "", "", ""};
    const std::vector<std::string> expectedLines1 = {"It matters not how strait the gate, ",
                                                     "How charged with punishments the scroll, ",
                                                     "I am the master of my fate, ",
                                                     "I am the captain of my soul."};
    const std::vector<std::string> expectedLines2 = {"this is a single line", "", "", ""};
    const std::vector<std::string> expectedLines3 = {"", "", "", ""};
    chapter_12::lastKLines(lines1, filepath1);
    chapter_12::lastKLines(lines2, filepath2);
    chapter_12::lastKLines(lines3, filepath3);
    REQUIRE(lines1 == expectedLines1);
    REQUIRE(lines2 == expectedLines2);
    REQUIRE(lines3 == expectedLines3);
}

TEST_CASE("Chapter 12 - Problem 02 - reverse()", "test"){
    char s1[] = "Alex";
    const char s1Rev[] = "xelA";
    char s2[] = "a";
    const char s2Rev[] = "a";
    chapter_12::reverse(&s1[0]);
    chapter_12::reverse(&s2[0]);
    // strcmp returns 0 if the 2 strings are equal.
    REQUIRE(strcmp(&s1[0], &s1Rev[0]) == 0);
    REQUIRE(strcmp(&s2[0], &s2Rev[0]) == 0);
}

TEST_CASE("Chapter 12 - Problem 08 - copyNode()", "test"){
    std::vector<int> targetVector = {1,2,3,4,5,6,7};
    chapter_02::SinglyLinkedNode<int>* head = chapter_02::vectorToList(targetVector);
    chapter_02::SinglyLinkedNode<int>* copy = chapter_12::copyNode(head);
    REQUIRE(targetVector == chapter_02::listToVector(copy));  //  check that the values contained in nodes are identical
    // Check that the pointers in the head linked list are *not* the same as the pointers in the copy linked list
    // This is to verify a copy was actually made.
    while (head != nullptr && copy != nullptr){
        REQUIRE(head != copy);
        head = head->getNext();
        copy = copy->getNext();
    }
}

TEST_CASE("Chapter 12 - Problem 09 - smartPointer()", "test"){
    chapter_12::SmartPointer<int> intSP(new int(5));
    REQUIRE(intSP.getRefCount() == 1);
    auto doSomethingLambda = [](chapter_12::SmartPointer<int> sp){
        sp.setValue(6);
        REQUIRE(sp.getRefCount() == 2);
        chapter_12::SmartPointer<int> intSP2(sp);
        REQUIRE(intSP2.getRefCount() == 3);
        REQUIRE(sp.getRefCount() == 3);
    };
    doSomethingLambda(intSP);
    REQUIRE(intSP.getRefCount() == 1);
}

TEST_CASE("Chapter 12 - Problem 10 - alignedMalloc()", "test"){
    int* intPointer = (int*) chapter_12::alignedMalloc(sizeof(int), 128);
    double* doublePointer = (double*) chapter_12::alignedMalloc(sizeof(double), 32);
    long* longPointer = (long*) chapter_12::alignedMalloc(sizeof(long), 64);
    REQUIRE(reinterpret_cast<long>(intPointer) % 128 == 0);
    REQUIRE(reinterpret_cast<long>(doublePointer) % 32 == 0);
    REQUIRE(reinterpret_cast<long>(longPointer) % 64 == 0);
    chapter_12::alignedFree(intPointer);
    chapter_12::alignedFree(doublePointer);
    chapter_12::alignedFree(longPointer);
}

TEST_CASE("Chapter 16 - Problem 01 - swapNumbers()") {
    int a = 5;
    int b = 9;
    chapter_16::swapNumbers(a, b);
    REQUIRE(a == 9);
    REQUIRE(b == 5);
    float c = 5.1f;
    float d = -9.6f;
    chapter_16::swapNumbers(c, d);
    REQUIRE(c == -9.6f);
    REQUIRE(d == 5.1f);
    long e = -50435;
    long f = -89048;
    chapter_16::swapNumbers(e, f);
    REQUIRE(e == -89048);
    REQUIRE(f == -50435);
}

TEST_CASE("Chapter 16 - Problem 02 - wordFrequencies()") {
    std::vector<std::string> book = {"Invictus\n",
                                     "By",
                                     "William","Ernest","Henley\n",
                                     "\n",
                                     "Out", "of", "the", "night", "that","covers","me,\n",
                                     "Black","as","the","pit","from","pole","to","pole,\n",
                                     "I","thank","whatever","gods","may","be\n",
                                     "For","my","unconquerable soul.\n",
                                     "\n",
                                     "In","the","fell","clutch","of","circumstance\n",
                                     "I","have","not","winced","nor","cried","aloud.\n",
                                     "Under","the","bludgeonings","of","chance\n",
                                     "My","head","is","bloody,","but","unbowed.\n",
                                     "\n",
                                     "Beyond","this","place","of","wrath","and","tears\n",
                                     "Looms","but","the","Horror","of","the","shade,\n",
                                     "And","yet","the","menace","of","the","years\n",
                                     "Finds","and","shall","find","me","unafraid.\n",
                                     "\n",
                                     "It","matters","not","how","strait","the","gate,\n",
                                     "How","charged","with","punishments","the","scroll,\n",
                                     "I","am","the","master","of","my","fate,\n",
                                     "I","am","the","captain","of","my","soul."};
    std::unordered_map<std::string, int> database;
    chapter_16::makeDatabase(book, database);
    REQUIRE(8 == chapter_16::wordFrequencies("of", database));
    REQUIRE(1 == chapter_16::wordFrequencies("captain", database));
    REQUIRE(4 == chapter_16::wordFrequencies("my", database));
    REQUIRE(12 == chapter_16::wordFrequencies("the", database));
    REQUIRE(1 == chapter_16::wordFrequencies("it", database));
    REQUIRE(2 == chapter_16::wordFrequencies("but", database));
}

TEST_CASE("Chapter 16 - Problem 03 - intersection()") {
    // follow book implementation: ignore vertical slopes, ignore colinear overlap
    auto s1 = chapter_16::LineSegment2(chapter_16::Point2(5, 5), chapter_16::Point2(0, 0));
    auto s2 = chapter_16::LineSegment2(chapter_16::Point2(0, 3), chapter_16::Point2(3, 0));
    auto s3 = chapter_16::LineSegment2(chapter_16::Point2(3, 0), chapter_16::Point2(6, 0));
    auto s4 = chapter_16::LineSegment2(chapter_16::Point2(4, 0), chapter_16::Point2(7, 0));
    auto s5 = chapter_16::LineSegment2(chapter_16::Point2(7, 7), chapter_16::Point2(5, 5));
    chapter_16::Point2 expected_p1(1.5, 1.5);
    chapter_16::Point2 expected_p4(5, 5);
    auto actual_p1 = chapter_16::intersection(s1, s2);
    auto actual_p2 = chapter_16::intersection(s1, s3);
    auto actual_p3 = chapter_16::intersection(s4, s3);
    auto actual_p4 = chapter_16::intersection(s1, s5);
    REQUIRE(expected_p1 == *actual_p1);
    REQUIRE(nullptr == actual_p2);
    REQUIRE(nullptr == actual_p3);
    REQUIRE(expected_p4 == *actual_p4);
    delete actual_p1;
    delete actual_p2;
    delete actual_p3;
    delete actual_p4;
}

TEST_CASE("Chapter 16 - Problem 04 - ticTacWin()") {
    // store data in row major order
    char board0[9] = {'O', 'O', 'X',
                      'O', 'X', '_',
                      'X', '_', '_'};
    char board1[9] = {'_', '_', 'O',
                      '_', 'X', 'O',
                      'X', 'X', 'O'};
    // this is a board that violates TTT rules but we still judge it as a winner
    char board2[9] = {'X', 'X', 'X',
                      'O', 'O', 'O',
                      'X', 'O', 'O'};
    // we judge a character that is not X or O as a blank
    char board3[9] = {'_', '_', 'X',
                      '_', '_', 'O',
                      '_', 'Z', '_'};
    // complete garbage board
    char board4[9] = {'a', 'l', 'e',
                      'x', 'a', 'l',
                      'e', 'x', 'a'};
    char board5[9] = {'O', 'O', 'X',
                      'X', 'X', 'X',
                      'X', 'O', 'O'};
    char board6[9] = {'X', 'X', 'X',
                      'O', 'O', 'X',
                      'X', 'O', 'O'};
    char board7[9] = {'O', 'O', 'X',
                      'X', 'O', 'O',
                      'X', 'X', 'X'};
    char board8[9] = {'X', 'O', 'X',
                      'X', 'O', 'X',
                      'O', 'X', 'O'};
    char board9[9] = {'O', 'X', 'O',
                      'O', 'X', 'X',
                      'O', 'O', 'X'};
    char board10[9] = {'X', 'O', 'O',
                       'X', 'O', 'X',
                       'O', 'O', 'X'};
    char board11[9] = {'X', 'O', 'O',
                       'X', 'X', 'O',
                       'O', 'X', 'O'};
    char board12[9] = {'X', 'X', 'O',
                       'X', 'O', '_',
                       'O', '_', '_'};
    char board13[9] = {'X', 'O', 'O',
                       'X', 'X', '_',
                       'O', '_', 'X'};
    char board14[9] = {'_', '_', 'X',
                       '_', '_', 'O',
                       '_', 'X', '_'};
    char board15[9] = {'X', '_', 'X',
                       '_', 'O', 'O',
                       'X', 'X', '_'};
    char board16[9] = {'X', 'O', '_',
                       'O', 'X', 'O',
                       'X', 'X', '_'};
    auto database = chapter_16::TTTDatabase();
    REQUIRE(database.ticTacWin(&board0[0]) == true);
    REQUIRE(database.ticTacWin(&board1[0]) == true);
    REQUIRE(database.ticTacWin(&board2[0]) == true);
    REQUIRE(database.ticTacWin(&board3[0]) == false);
    REQUIRE(database.ticTacWin(&board4[0]) == false);
    REQUIRE(database.ticTacWin(&board5[0]) == true);
    REQUIRE(database.ticTacWin(&board6[0]) == true);
    REQUIRE(database.ticTacWin(&board7[0]) == true);
    REQUIRE(database.ticTacWin(&board8[0]) == false);
    REQUIRE(database.ticTacWin(&board9[0]) == true);
    REQUIRE(database.ticTacWin(&board10[0]) == true);
    REQUIRE(database.ticTacWin(&board11[0]) == true);
    REQUIRE(database.ticTacWin(&board12[0]) == true);
    REQUIRE(database.ticTacWin(&board13[0]) == true);
    REQUIRE(database.ticTacWin(&board14[0]) == false);
    REQUIRE(database.ticTacWin(&board15[0]) == false);
    REQUIRE(database.ticTacWin(&board16[0]) == false);
}

TEST_CASE("Chapter 16 - Problem 05 - factorialZeros()") {
    REQUIRE(-1 == chapter_16::factorialZeros(-1));
    REQUIRE(0 == chapter_16::factorialZeros(1));
    REQUIRE(0 == chapter_16::factorialZeros(2));
    REQUIRE(1 == chapter_16::factorialZeros(5));
    REQUIRE(1 == chapter_16::factorialZeros(7));
    REQUIRE(2 == chapter_16::factorialZeros(10));
    REQUIRE(2 == chapter_16::factorialZeros(14));
    REQUIRE(3 == chapter_16::factorialZeros(15));
    REQUIRE(3 == chapter_16::factorialZeros(16));
    REQUIRE(3 == chapter_16::factorialZeros(19));
    REQUIRE(4 == chapter_16::factorialZeros(20));
    REQUIRE(4 == chapter_16::factorialZeros(21));
    REQUIRE(6 == chapter_16::factorialZeros(25));
    REQUIRE(6 == chapter_16::factorialZeros(26));
}

TEST_CASE("Chapter 16 - Problem 06 - smallestDifference()") {
    std::vector<int> example1 = {1, 3, 15, 11, 2};
    std::vector<int> example2 = {23, 127, 235, 19, 8};
    std::vector<int> example3 = {-5, 4, -3, 2, 12};
    std::vector<int> example4 = {-7, 6, 12, 1, -3};
    std::vector<int> example5 = {-5, 3};
    std::vector<int> example6 = {};
    REQUIRE(3 == chapter_16::smallestDifference(example1, example2));
    REQUIRE(0 == chapter_16::smallestDifference(example3, example4));
    REQUIRE(2 == chapter_16::smallestDifference(example4, example5));
    REQUIRE(std::numeric_limits<int>::max() == chapter_16::smallestDifference(example5, example6));
    REQUIRE(std::numeric_limits<int>::max() == chapter_16::smallestDifference(example6, example6));
}

TEST_CASE("Chapter 16 - Problem 07 - numberMax()", "test") {
    REQUIRE(8 == chapter_16::numberMax(8,4));
    REQUIRE(8 == chapter_16::numberMax(4,8));
    REQUIRE(65535 == chapter_16::numberMax(65535, 65534));
    REQUIRE(1 == chapter_16::numberMax(1,0));
    REQUIRE(0b10001 == chapter_16::numberMax(0b10001,0b1001));
    REQUIRE(0 == chapter_16::numberMax(0,0));
    REQUIRE(5 == chapter_16::numberMax(5,0));
    REQUIRE(8 == chapter_16::numberMax(8,8));
}

TEST_CASE("Chapter 16 - Problem 10 - livingPeople()", "test") {
    std::vector<chapter_16::Person> people1 = {
            chapter_16::Person(1930, 2000),
            chapter_16::Person(1940, 2010),
            chapter_16::Person(1920, 2000),
            chapter_16::Person(1980, 1990),
            chapter_16::Person(1982, 1982),
            chapter_16::Person(1900, 1920),
            chapter_16::Person(1910, 1920),
            chapter_16::Person(1945, 1995)};
    std::vector<chapter_16::Person> people2 = {};
    REQUIRE(1982 == livingPeople(people1, 1900, 2020));
    REQUIRE(1945 == livingPeople(people1, 1900, 1950));
    REQUIRE(1900 == livingPeople(people2, 1900, 2020));
}

TEST_CASE("Chapter 16 - Problem 11 - divingBoard()") {
    const int short1 = 2;
    const int long1 = 3;
    const int K1 = 5;
    const std::unordered_set<int> lengths1Expected = {10,  // 0 long + 5 short
                                                      11,  // 1 long + 4 short
                                                      12,  // 2 long + 3 short
                                                      13,  // 3 long + 2 short
                                                      14,  // 4 long + 1 short
                                                      15}; // 5 long + 0 short

    const int short2 = 2;
    const int long2 = 2;
    const int K2 = 5;
    const std::unordered_set<int> lengths2Expected = {10};
    const int short3 = 1;
    const int long3 = 5;
    const int K3 = 5;
    const std::unordered_set<int> lengths3Expected = {5,  // 0 long + 5 short
                                                      9,  // 1 long + 4 short
                                                      13,  // 2 long + 3 short
                                                      17,  // 3 long + 2 short
                                                      21,  // 4 long + 1 short
                                                      25}; // 5 long + 0 short
    REQUIRE(chapter_16::divingBoard(short1, long1, K1) == lengths1Expected);
    REQUIRE(chapter_16::divingBoard(short2, long2, K2) == lengths2Expected);
    REQUIRE(chapter_16::divingBoard(short3, long3, K3) == lengths3Expected);
}

TEST_CASE("Chapter 16 - Problem 17 - contiguousSubarray()", "test") {
    REQUIRE(0 == chapter_16::contiguousSequence({}));
    REQUIRE(29 == chapter_16::contiguousSequence({2, 8, 3, 2, 4, 10}));
    REQUIRE(-2 == chapter_16::contiguousSequence({-2, -8, -3, -2, -4, -10}));
    REQUIRE(5 == chapter_16::contiguousSequence({2, -8, 3, -2, 4, -10}));
    REQUIRE(6 == chapter_16::contiguousSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}));
};

TEST_CASE("Chapter 16 - problem 19 - pondSizes()", "test") {
    // test 1
    const std::vector<std::vector<int>> plot1 = {{0, 2, 1, 0},
                                                 {0, 1, 0, 1},
                                                 {1, 1, 0, 1},
                                                 {0, 1, 0, 1}};
    std::multiset<int> expected1 = {2, 4, 1};
    REQUIRE(chapter_16::pondSizes(plot1) == expected1);
    // test 2
    const std::vector<std::vector<int>> plot2 = {{}};
    std::multiset<int> expected2 = {};
    REQUIRE(chapter_16::pondSizes(plot2) == expected2);
    // test 3
    const std::vector<std::vector<int>> plot3 = {{0, 2, 1, 0}};
    std::multiset<int> expected3 = {1, 1};
    REQUIRE(chapter_16::pondSizes(plot3) == expected3);
    // test 4
    const std::vector<std::vector<int>> plot4 = {{0, 2, 1, 0},
                                                 {0, 0, 1, 1},
                                                 {0, 1, 0, 1},
                                                 {0, 0, 0, 1}};
    std::multiset<int> expected4 = {8, 1};
    REQUIRE(chapter_16::pondSizes(plot4) == expected4);
    // test 5
    const std::vector<std::vector<int>> plot5= {{0, 2, 0, 2},
                                                {2, 0, 1, 0},
                                                {0, 1, 3, 1},
                                                {1, 0, 2, 0}};
    std::multiset<int> expected5 = {6, 1};
    REQUIRE(chapter_16::pondSizes(plot5) == expected5);
};

TEST_CASE("Chapter 17 - Problem 21 - histogramVolume()", "test") {
    const std::vector<int> histogram1 = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 8, 0, 2, 0, 5, 2, 0, 3, 0, 0};
    const std::vector<int> histogram2 = {5, 0, 0, 0, 1};
    const std::vector<int> histogram3 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  // test case from leetcode problem https://leetcode.com/problems/trapping-rain-water/
    REQUIRE(chapter_17::histogramVolume(histogram1) == 46);
    REQUIRE(chapter_17::histogramVolume(histogram2) == 3);
    REQUIRE(chapter_17::histogramVolume(histogram3) == 6);
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
    REQUIRE(output1.isApprox(*misc::makeIntegralImage(input1)));
    Eigen::MatrixXd output2(4, 4);
    output2 << 1,   3,  6,  10,
               3,   9, 18,  30,
               6,  18, 36,  60,
               10, 30, 60, 100;
    REQUIRE(output2.isApprox(*misc::makeIntegralImage(output1)));
}

TEST_CASE("Misc Exercises - kernelConvolution()", "test") {
       Eigen::MatrixXd input1(4,4);
       input1 << 0, 0, 0, 1,
                 0, 1, 0, 0,
                 0, 0, 0, 0,
                 0, 0, 0, 0;
       Eigen::MatrixXd kernel1(3, 3);
       kernel1 << 0, 1, 0,
                  1, 1, 1,
                  0, 1, 0;
       Eigen::MatrixXd output1(4, 4);
       output1 << 0, 1, 1, 1,
                  1, 1, 1, 1,
                  0, 1, 0, 0,
                  0, 0, 0, 0;
       REQUIRE(output1.isApprox(*misc::kernelConvolution(input1, kernel1)));
}
