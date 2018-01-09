## Cracking The Coding Interview Solutions with Automated Unit Tests

### Introduction
This repo contains Python and C++ solutions for Gayle Laakmann McDowell's [*Cracking the Coding Interview 6th Edition*](http://a.co/baneyGe). 
Admittedly, there are lots of other GitHub repos with solutions for this book. But when you're studying and are deeply confused,
how do you know that their code *actually works*? If it's untested, then you don't! That's why the philosophy of this repo is
that every solution must have one or more tests using the [Python unittest framework](https://docs.python.org/3.6/library/unittest.html)
or the [C++ Catch framework](https://github.com/philsquared/Catch). We enforce
the unit tests using [Travis CI automated testing](https://travis-ci.org/alexhagiopol/cracking-the-coding-interview) ensuring
that the solutions are made of *living* code that gets executed and tested on every single public commit. Reference and contribute
solutions with confidence!

### Table of Contents
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
15. Chapter 15 - Threads and Locks: `0 / 4` complete.
16. Chapter 16 - Moderate: `1 / 26` complete.
17. Chapter 17 - Hard: `3 / 26` complete.

Total: `55 / 145`

#### C++ Solutions:
1. Chapter 1 - Arrays and Strings: `3 / 9`  complete.
2. Chapter 2 - Linked Lists: `4 / 8` complete.
3. Chapter 3 - Stacks and Queues: `0 / 6`  complete.
4. Chapter 4 - Trees and Graphs: `0 / 12` complete.  
5. Chapter 5 - Bit Manipulation: `4 / 7`  complete.
6. Chapter 6 - Math and Logic: `0 / 10` complete.
7. Chapter 7 - Object Oriented Design: `0 / 12` complete. 
8. Chapter 8 - Recursion and Dynamic Programming: `5 / 14`  complete.
9. Chapter 9 - System Design and Scalability: N/A
10. Chapter 10 - Sorting and Searching: `0 / 11` complete.
11. Chapter 11 - Testing: N/A
12. Chapter 12 - C and C++: `1 / 6`
13. Chapter 13 - Java: N/A
14. Chapter 14 - Databases: N/A
15. Chapter 15 - Threads and Locks: `0 / 4`
16. Chapter 16 - Moderate: `0 / 26` complete.
17. Chapter 17 - Hard: `0 / 26` complete.

Total: `17 / 151`

### Reading the Code:
Python and C++ unit tests are in [tests.py](./tests.py) and [tests.cpp](./tests.cpp) respectively. Python and C++ solutions are
organized by chapter in [python_solutions](./python_solutions) and in [cpp_solutions](./cpp_solutions) respectively.

### Build Process
The repo contains a makefile that handles all dependency installations for you :smile:. Execute the following depending on your OS:

#### Build Process on Mac:
Mac usage requires the package managers Homebrew and Pip which is done for you in the Makefile: 
	
    git clone https://github.com/alexhagiopol/cracking-the-coding-interview.git
    cd cracking-the-coding-interview
    make configure-mac

#### Build Process on Ubuntu:

    git clone https://github.com/alexhagiopol/cracking-the-coding-interview.git
    cd cracking-the-coding-interview
    make configure-ubuntu

#### Build Process on Windows (working, but experimental):
The project can be developed on Windows using Visual Studio 2017. First get the code:

	git clone https://github.com/alexhagiopol/cracking-the-coding-interview.git
	cd cracking-the-coding-interview
	git submodule update --init

Then, install Python3 and numpy using your method of choice. I prefer installing Python3 and pip3 from 
the [official website](https://www.python.org/downloads/) then installing numpy via pip:

	pip install numpy

Then, open the project in Visual Studio 2017 which has CMake support.
I've found that best the workflow is to use Visual Studio to edit code and use debugging functionality. Before
building the code, you must follow [these instructions](https://stackoverflow.com/a/12954908)
to tell Visual Studio to download PDBs it needs. Additionally, [this article](https://blogs.msdn.microsoft.com/vcblog/2016/10/05/cmake-support-in-visual-studio/)
describes Visual Studio CMake support in more detail if you're interested. A CMakeSettings.json file in the root project
directory sets the location of the Visual Studio build folder to be inside the root folder of the project.

### Running Tests (Ubuntu & Mac):
In the root directory, execute the following to run all tests in Python and C++:

    make test

### Running Tests (Windows experimental):
Running the tests and seeing their output is best done from a PowerShell window since VisualStudio in CMake mode
does *not* allow the console output of the `tests.exe` and `tests.py` files to remain visible even when pressing 
CTRL + F5 as described [in this post](https://stackoverflow.com/a/1775870) which applies to 
"normal" Visual Studio use. I am monitoring the situation re: Visual Studio, and when I find better solutions
I will implement them or post them. If you know of something better, please contact me.

In the meantime, from the project root directory, you can run the Python tests using ...

	python tests.py

... and you can run the C++ tests using ...

	.\build\x64-Debug\tests.exe

#### Optional: Generating a Test Coverage % Report Locally (Python support only):
This will show exactly which lines are not covered by tests in each Python source file:

    pip install coverage
    make test_coverage





### Contributing
The goal of this project is to write a tested Python and C++ solution for every problem in the 6th edition of the textbook.
I definitely need help! PRs are of course very welcome. The work has become quite time consuming because each solution is *living*
code that actually gets executed. Thus, each solution needs its own small dataset and infrastructure in order to be tested.
Just writing the test for a problem is often harder than solving the problem itself. Here are some ways you can help:

0. Fixing bugs :bug:.
1. Solving unsolved problems in either language (see the completion progress in the table of contents).
2. Improving existing solutions with better performance or clarity.
3. Adding more unit tests or refactoring to increase the test coverage %.
4. Implementing C++ test coverage measurement using [gcov](http://gcc.gnu.org/onlinedocs/gcc/Gcov.html).
5. Integrating automated unit test coverage % measurement and reporting for both Python and C++ via [Coveralls](Coveralls.io).
6. Adding solution descriptions in English for problems that don't have them.

If you have any contributions, please make a PR to the `master` branch. Feel free to message me for clarification on any of
the above items.

