 ## Cracking The Coding Interview Solutions with Automated Unit Tests

 * :white_check_mark: C++ Solutions 
 * :white_check_mark: Python Solutions
 * :white_check_mark: Automated Unit Tests
 * :white_check_mark: Active Development
 * :white_check_mark: Multiplatform Support: Mac, Linux, and Windows
 
### Introduction
This repo contains C++ and Python solutions for Gayle Laakmann McDowell's [*Cracking the Coding Interview 6th Edition*](http://a.co/baneyGe). 
Admittedly, there are other GitHub repositories with solutions for this book. *But
how do you know that their code is actually correct?* If it's untested, then you don't! 

In this project, every C++ solution has unit tests using the [C++ Catch framework](https://github.com/philsquared/Catch),
and every Python solution has unit tests using the [Python unittest framework](https://docs.python.org/3.6/library/unittest.html).
We enforce test correctness automatically using [continuous integration servers](https://travis-ci.org/alexhagiopol/cracking-the-coding-interview) 
ensuring that the solutions are made of *living* code that gets executed and tested on every single commit. To my knowledge, this is 
the Internet's only solutions repository with this level of testing rigor: >90% automated test coverage means you can 
reference and contribute solutions with confidence.

### Table of Contents
#### [C++ Solutions](cpp_solutions):
0. [C++ Unit Tests](tests.cpp)
1. [Chapter 1 - Arrays and Strings](cpp_solutions/chapter_01_arrays_and_strings): `9 / 9`  complete.
2. [Chapter 2 - Linked Lists](cpp_solutions/chapter_02_linked_lists): `8 / 8` complete.
3. [Chapter 3 - Stacks and Queues](cpp_solutions/chapter_03_stacks_and_queues): `4 / 6`  complete.
4. [Chapter 4 - Trees and Graphs](cpp_solutions/chapter_04_trees_and_graphs): `11 / 12` complete.  
5. [Chapter 5 - Bit Manipulation](cpp_solutions/chapter_05_bit_manipulation): `5 / 7`  complete.
6. Chapter 6 - Math and Logic: `0 / 10` complete.
7. Chapter 7 - Object Oriented Design: `0 / 12` complete. 
8. [Chapter 8 - Recursion and Dynamic Programming](cpp_solutions/chapter_08_recursion_and_dynamic_programming): `8 / 14`  complete.
9. Chapter 9 - System Design and Scalability: N/A
10. [Chapter 10 - Sorting and Searching](cpp_solutions/chapter_10_sorting_and_searching): `1 / 11` complete.
11. Chapter 11 - Testing: N/A
12. [Chapter 12 - C and C++](cpp_solutions/chapter_12_cpp): `2 / 6`
13. Chapter 13 - Java: N/A
14. Chapter 14 - Databases: N/A
15. Chapter 15 - Threads and Locks: `0 / 4`
16. Chapter 16 - Moderate: `0 / 26` complete.
17. Chapter 17 - Hard: `0 / 26` complete.

C++ Total: `48` solutions.

#### [Python Solutions](python_solutions):
0. [Python Unit tests](tests.py)
1. [Chapter 1 - Arrays and Strings](python_solutions/chapter_01_arrays_and_strings): `9 / 9`  complete.    
2. [Chapter 2 - Linked Lists](python_solutions/chapter_02_linked_lists): `8 / 8` complete.   
3. [Chapter 3 - Stacks and Queues](python_solutions/chapter_03_stacks_queues): `6 / 6`  complete.
4. [Chapter 4 - Trees and Graphs](python_solutions/chapter_04_trees_and_graphs): `11 / 12` complete.  
5. [Chapter 5 - Bit Manipulation](python_solutions/chapter_05_bit_manipulation): `7 / 7`  complete.
6. Chapter 6 - Math and Logic: `0 / 10` complete.
7. Chapter 7 - Object Oriented Design: `0 / 12` complete. 
8. [Chapter 8 - Recursion and Dynamic Programming](python_solutions/chapter_08_recursion_and_dynamic_programming): `11 / 14`  complete.
9. Chapter 9 - System Design and Scalability: N/A
10. [Chapter 10 - Sorting and Searching](python_solutions/chapter_10_sorting_and_searching): `1 / 11` complete.
11. Chapter 11 - Testing: N/A
12. Chapter 12 - C and C++: N/A
13. Chapter 13 - Java: N/A
14. Chapter 14 - Databases: N/A
15. Chapter 15 - Threads and Locks: `0 / 4` complete.
16. [Chapter 16 - Moderate](python_solutions/chapter_16_moderate): `1 / 26` complete.
17. [Chapter 17 - Hard](python_solutions/chapter_17_hard): `3 / 26` complete.

Python Total: `56` solutions.

##### Grand Total: `104` unique solutions.

### Building: 
#### Mac:
Mac usage requires the package managers Homebrew and Pip which is done for you in the Makefile: 
	
    git clone https://github.com/alexhagiopol/cracking-the-coding-interview.git ctci
    cd ctci
    make configure-mac

#### Ubuntu:

    git clone https://github.com/alexhagiopol/cracking-the-coding-interview.git
    cd ctci
    make configure-ubuntu

#### Windows:
For Windows users, I recommend developing this project using the [Windows Subsystem 
for Linux (WSL)](https://docs.microsoft.com/en-us/windows/wsl/install-win10) feature 
of Windows 10 and then following the Ubuntu build and testing instructions inside WSL. 
This recommendation is due to the use of Ubuntu, CMake, and makefile based build and execution
systems on the servers that automatically test changes to the code. For more on Windows 
development, see the `Appendix` section at the end of this page.

### Testing:
Testing is the most important part of this project: *only* 
the unit tests define the problem being solved. In the root 
directory, execute the following to run all tests in Python and C++:

    make test
    
`make test` is the command I use most while developing this project. My workflow follows:

1. I read a problem and encode the problem definition by implementing its unit tests.
2. I execute `make test` to see where the project fails to satisfy the unit tests.
3. I add to the implementation of the problem solution until `make test` succeeds.

### Optional: Generating a Test Coverage % Report Locally (Python support only):
This will show exactly which lines are not covered by tests in each Python source file:

    pip install coverage
    make test_coverage

### Contributing
The goal of this project is to write a tested Python and C++ solution for every problem in the 6th edition of the textbook.
I definitely need help, so PRs are welcome. There is much to do because each solution needs its own 
small dataset and infrastructure in order to be tested. Here are some ways you can help:

1. Fixing bugs :bug:.
2. Solving or improving solutions to problems in either language (see the completion progress in the table of contents).
3. Adding more unit tests to increase the test coverage %.
4. Implementing automated C++ test coverage measurement using [gcov](http://gcc.gnu.org/onlinedocs/gcc/Gcov.html).
5. Integrating automated test coverage % reporting for both Python and C++ via [Coveralls](Coveralls.io).
6. Adding prose solution descriptions for problems that don't have them.

If you have any contributions, please make a PR to the `master` branch. Feel free to message me for clarification on any of
the above items.

### Appendix: Windows Development
On my own Windows machine, I develop using [CLion](https://www.jetbrains.com/clion/) running
natively in Windows and test the code using `make test` in a WSL terminal window.
For users who do not want to use WSL, I have developed the build and test methodology below:

#### Building
The project can be developed purely on Windows without WSL by using Visual Studio 2017. 
First clone the code:

	git clone https://github.com/alexhagiopol/cracking-the-coding-interview.git
	cd ctci
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

#### Testing
Running the tests and seeing their output is best done from a PowerShell window since VisualStudio in CMake mode
does *not* allow the console output of the `tests.exe` and `tests.py` files to remain visible even when pressing 
CTRL + F5 as described [in this post](https://stackoverflow.com/a/1775870) which applies to 
"normal" Visual Studio use. I am monitoring the situation re: Visual Studio, and when I find better solutions
I will implement them or post them. If you know of something better, please contact me.

In the meantime, from the project root directory, you can run the Python tests using ...

	python tests.py

... and you can run the C++ tests using ...

	.\build\x64-Debug\tests.exe
