cmake_minimum_required(VERSION 3.2)
project(ctci)
set(CMAKE_CXX_STANDARD 11)
# include source folder
include_directories(cpp_solutions)
# include Eigen
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cpp_solutions/third_party/eigen)

# set source files
set(SOURCE_FILES
        tests.cpp
		# chapter 1
        cpp_solutions/chapter_01_arrays_and_strings/problem_01_01_isUnique.cpp
        cpp_solutions/chapter_01_arrays_and_strings/problem_01_02_arePermutations.cpp
        cpp_solutions/chapter_01_arrays_and_strings/problem_01_03_URLify.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_04_palindromePermutation.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_05_oneAway.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_06_stringCompression.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_07_rotateMatrix.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_08_setZero.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_09_stringRotation.cpp
		# chapter 2 .cpp files not included because they are template functions implemented in .h files
		# chapter 3 .cpp files not included because they are template functions implemented in .h files
		cpp_solutions/chapter_03_stacks_and_queues/problem_03_06_animalShelter.cpp
		# chapter 4 .cpp files not included because they are template functions implemented in .h files
		cpp_solutions/chapter_04_trees_and_graphs/problem_04_07_buildOrder.cpp
		# chapter 5
		cpp_solutions/chapter_05_bit_manipulation/problem_05_01_insertion.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_02_binaryToString.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_03_flipBitToWin.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_04_nextNumber.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_06_conversion.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_07_pairwiseSwap.cpp
		cpp_solutions/chapter_05_bit_manipulation/problem_05_08_drawLine.cpp
		# chapter 8
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_01_tripleStep.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_02_robotGrid.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_03_magicIndex.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_04_powerSet.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_05_recursiveMultiply.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_07_permutationsNoDups.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_08_permutationsWithDups.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_10_paintFill.cpp
		# problem 10.01 not included because it is a template function implemented in .h file
		cpp_solutions/chapter_10_sorting_and_searching/problem_10_02_anagramSort.cpp
		cpp_solutions/chapter_12_cpp/problem_12_02_reverse.cpp
		# problem 12.08 not included because it is a template function implemented in .h file
        cpp_solutions/misc_exercises/integralImage.cpp)
# create executable
add_executable(tests ${SOURCE_FILES})
