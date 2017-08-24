## Cracking The Coding Interview Solutions with Automated Unit Tests

### Introduction
This repo contains Python and C++ solutions for Gayle Laakmann McDowell's [*Cracking the Coding Interview 6th Edition*](http://a.co/baneyGe). 
Admittedly, there are lots of other GitHub repos with solutions for this book. But when you're studying and deeply confused, 
how do you know that their code *actually works*? If it's untested, you don't! That's why the #1 rule for this repo is 
that every solution must have one or more tests using the [Python unittest framework](https://docs.python.org/3.6/library/unittest.html)
or the [C++ Catch framework](https://github.com/philsquared/Catch). We enforce
the unit tests using [Travis CI automated testing](https://travis-ci.org/alexhagiopol/cracking-the-coding-interview).
 Reference and contribute solutions with confidence!

#### Reading the Code:
Python and C++ unit tests are in [tests.py](./tests.py) and [tests.cpp](./tests.cpp) respectively. Python and C++ solutions are
organized by chapter in [python_solutions](./python_solutions) and in [cpp_solutions](./cpp_solutions) respectively.

#### Setup:

    git clone https://github.com/alexhagiopol/cracking-the-coding-interview.git
    cd cracking-the-coding-interview
    make configure

#### Running Tests:
In the root directory, execute the following to run all tests in Python and C++:

    make test

#### Optional: Generating a Test Coverage % Report Locally (Python support only):
This will show exactly which lines are not covered by tests in each Python source file:

    pip install coverage
    make test_coverage

### Contributing
I definitely need help on this project. The project has become very time consuming because each solution is living
code that actually gets executed. Thus, each solution needs its own small dataset and infrastructure in order to be tested.
As a result, just writing the test for a problem is often harder than solving the problem itself. The goal for this
repository is to have a "living" solution for each problem in the book. PRs are of course very welcome.
Here are some ways you can help:

0. Fixing mistakes.
1. Solving unsolved problems in either language (see the completion progress table below).
2. Improving existing solutions with better performance or clarity.
3. Adding more unit tests or refactoring to increase the test coverage %.
4. Implementing C++ test coverage measurement using [gcov](http://gcc.gnu.org/onlinedocs/gcc/Gcov.html).
5. Integrating automated unit test coverage % measurement and reporting for both Python and C++ via [Coveralls](Coveralls.io).

If you have any contributions, please make a PR to the master branch. Feel free to message me for clarification on any of
the above items.

### Problem Completion Progress
#### Python Solutions:
1. Chapter 1 - Arrays and Strings: `9 / 9`  complete.    
2. Chapter 2 - Linked Lists: `8 / 8` complete.   
3. Chapter 3 - Stacks and Queues: `6 / 6`  complete.
4. Chapter 4 - Trees and Graphs: `11 / 12` complete.  
5. Chapter 5 - Bit Manipulation: `7 / 7`  complete.
6. Chapter 6 - Math and Logic: `0 / 10` complete.
7. Chapter 7 - Object Oriented Design: `0 / 12` complete. 
8. Chapter 8 - Recursion and Dynamic Programming: `11 / 14`  complete.
9. Chapter 9 - System Design and Scalability: N/A
10. Chapter 10 - Sorting and Searching: `0 / 11` complete.
11. Chapter 11 - Testing: N/A
12. Chapter 12 - C and C++: N/A
13. Chapter 13 - Java: N/A
14. Chapter 14 - Databases: N/A
15. Chapter 15 - Threads and Locks: `0 / 7` complete.
16. Chapter 16 - Moderate: `1 / 26` complete.
17. Chapter 17 - Hard: `3 / 26` complete.

Total: `55 / 148`

#### C++ Solutions:
1. Chapter 1 - Arrays and Strings: `2 / 9`  complete.    
2. Chapter 2 - Linked Lists: `1 / 8` complete.   
3. Chapter 3 - Stacks and Queues: `0 / 6`  complete.
4. Chapter 4 - Trees and Graphs: `0 / 12` complete.  
5. Chapter 5 - Bit Manipulation: `4 / 7`  complete.
6. Chapter 6 - Math and Logic: `0 / 10` complete.
7. Chapter 7 - Object Oriented Design: `0 / 12` complete. 
8. Chapter 8 - Recursion and Dynamic Programming: `5 / 14`  complete.
9. Chapter 9 - System Design and Scalability: N/A
10. Chapter 10 - Sorting and Searching: `0 / 11` complete.
11. Chapter 11 - Testing: N/A
12. Chapter 12 - C and C++: `0 / 11`
13. Chapter 13 - Java: N/A
14. Chapter 14 - Databases: N/A
15. Chapter 15 - Threads and Locks: `0 / 7`
16. Chapter 16 - Moderate: `0 / 26` complete.
17. Chapter 17 - Hard: `0 / 26` complete.

Total: `12 / 159`
