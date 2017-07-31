## Cracking The Coding Interview Solutions with Automated Unit Tests
[![Coverage Status](https://coveralls.io/repos/github/alexhagiopol/cracking-the-coding-interview/badge.svg?branch=master)](https://coveralls.io/github/alexhagiopol/cracking-the-coding-interview?branch=master)

### Introduction
This repo contains solutions for Gayle Laakmann McDowell's [*Cracking the Coding Interview 6th Edition*](http://a.co/baneyGe). 
Admittedly, there are lots of other GitHub repos with solutions for this book. But when you're studying and deeply confused, 
how do you know that their code *actually works*? You don't if it's untested. That's why the #1 rule for this repo is 
that every solution must have one or more unit tests in [`tests.py`](tests.py) using the [`unittest framework`](https://docs.python.org/3.6/library/unittest.html) 
framework for Python solutions or the [Catch framework](https://github.com/philsquared/Catch) for C++ solutions. 
We enforce the unit tests using [Travis CI automated testing](https://travis-ci.org/alexhagiopol/cracking-the-coding-interview) 
and [Coveralls.io test coverage statistics](https://coveralls.io/github/alexhagiopol/cracking-the-coding-interview). 
Reference and contribute solutions with confidence!

#### Setup

    git clone https://github.com/alexhagiopol/cracking-the-coding-interview.git
    cd cracking-the-coding-interview
    git submodule update --init

#### Running the Tests Locally:
In the root directory, execute the following to run all of the tests:
    
    python tests.py

#### Generating a Test Coverage Report Locally:
This will show exactly which lines are not covered by tests in each source file:

    conda install coverage
    coverage run --source=python_solutions tests.py
    coverage report -m

### Contributing
I need help on this project! PRs are very welcome. Here are some ways you can help:

1. Solving unsolved problems (see the completion indexes below).
2. Improving existing solutions with better performance or clarity.
3. Adding more unit tests or refactoring to increase the test coverage %.

### Completion Progress
#### Python Solutions:
1. Chapter 1 - Arrays and Strings: `9 / 9`  complete.    
2. Chapter 2 - Linked Lists: `8 / 8` complete.   
3. Chapter 3 - Stacks and Queues: `6 / 6`  complete.
4. Chapter 4 - Trees and Graphs: `11 / 12` complete.  
5. Chapter 5 - Bit Manipulation: `1 / 8`  complete.
6. Chapter 6 - Math and Logic: `0 / 10` complete.
7. Chapter 7 - Object Oriented Design: `0 / 12` complete. 
8. Chapter 8 - Recursion and Dynamic Programming: `1 / 12`  complete.
9. Chapter 9 - System Design and Scalability: N/A
10. Chapter 10 - Sorting and Searching: `0 / 11` complete.
11. Chapter 11 - Testing: N/A
12. Chapter 12 - C and C++: N/A
13. Chapter 13 - Java: N/A
14. Chapter 14 - Databases: N/A
15. Chapter 15 - Threads and Locks: N/A
16. Chapter 16 - Moderate: `0 / 26` complete.
17. Chapter 17 - Hard: `2 / 26` complete.

Total: `38 / 140`

#### C++ Solutions:
1. Chapter 1 - Arrays and Strings: `0 / 9`  complete.    
2. Chapter 2 - Linked Lists: `0 / 8` complete.   
3. Chapter 3 - Stacks and Queues: `0 / 6`  complete.
4. Chapter 4 - Trees and Graphs: `0 / 12` complete.  
5. Chapter 5 - Bit Manipulation: `0 / 8`  complete.
6. Chapter 6 - Math and Logic: `0 / 10` complete.
7. Chapter 7 - Object Oriented Design: `0 / 12` complete. 
8. Chapter 8 - Recursion and Dynamic Programming: `0 / 12`  complete.
9. Chapter 9 - System Design and Scalability: N/A
10. Chapter 10 - Sorting and Searching: `0 / 11` complete.
11. Chapter 11 - Testing: N/A
12. Chapter 12 - C and C++: `0 / 11`
13. Chapter 13 - Java: N/A
14. Chapter 14 - Databases: N/A
15. Chapter 15 - Threads and Locks: `0 / 7`
16. Chapter 16 - Moderate: `0 / 26` complete.
17. Chapter 17 - Hard: `0 / 26` complete.

Total: `0 / 158`