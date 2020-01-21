cmake_minimum_required(VERSION 3.2)
project(ctci)
set(CMAKE_CXX_STANDARD 17)
# include source folder
include_directories(cpp_solutions)
# include Eigen
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cpp_solutions/third_party/eigen)

# set source files
set(SOURCE_FILES
        tests.cpp
		# CHAPTER 1
        cpp_solutions/chapter_01_arrays_and_strings/problem_01_01_isUnique.cpp
        cpp_solutions/chapter_01_arrays_and_strings/problem_01_02_arePermutations.cpp
        cpp_solutions/chapter_01_arrays_and_strings/problem_01_03_URLify.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_04_palindromePermutation.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_05_oneAway.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_06_stringCompression.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_07_rotateMatrix.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_08_setZero.cpp
		cpp_solutions/chapter_01_arrays_and_strings/problem_01_09_stringRotation.cpp
		# CHAPTER 2
		# .cpp files not included because they are template functions implemented in .h files
		# CHAPTER 3
		cpp_solutions/chapter_03_stacks_and_queues/problem_03_06_animalShelter.cpp
		# CHAPTER 4
		cpp_solutions/chapter_04_trees_and_graphs/problem_04_07_buildOrder.cpp
		# CHAPTER 5
		cpp_solutions/chapter_05_bit_manipulation/problem_05_01_insertion.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_02_binaryToString.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_03_flipBitToWin.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_04_nextNumber.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_06_conversion.cpp
        cpp_solutions/chapter_05_bit_manipulation/problem_05_07_pairwiseSwap.cpp
		cpp_solutions/chapter_05_bit_manipulation/problem_05_08_drawLine.cpp
		# CHAPTER 8
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_01_tripleStep.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_02_robotGrid.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_03_magicIndex.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_04_powerSet.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_05_recursiveMultiply.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_07_permutationsNoDups.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_08_permutationsWithDups.cpp
        cpp_solutions/chapter_08_recursion_and_dynamic_programming/problem_08_10_paintFill.cpp
		# CHAPTER 10
		cpp_solutions/chapter_10_sorting_and_searching/problem_10_02_anagramSort.cpp
		cpp_solutions/chapter_10_sorting_and_searching/problem_10_04_searchNoSize.cpp
		cpp_solutions/chapter_10_sorting_and_searching/problem_10_05_sparseSearch.cpp
		cpp_solutions/chapter_10_sorting_and_searching/problem_10_07_missingInt.cpp
		cpp_solutions/chapter_10_sorting_and_searching/problem_10_08_findDuplicates.cpp
		cpp_solutions/chapter_10_sorting_and_searching/problem_10_10_rankFromStream.cpp
		# CHAPTER 12
		cpp_solutions/chapter_12_cpp/problem_12_02_reverse.cpp
		# CHAPTER 16
		cpp_solutions/chapter_16_moderate/problem_16_02_wordFrequencies.cpp
		cpp_solutions/chapter_16_moderate/problem_16_03_intersection.cpp
		cpp_solutions/chapter_16_moderate/problem_16_04_ticTacWin.cpp
		cpp_solutions/chapter_16_moderate/problem_16_05_factorialZeros.cpp
		cpp_solutions/chapter_16_moderate/problem_16_07_numberMax.cpp
		cpp_solutions/chapter_16_moderate/problem_16_10_livingPeople.cpp
		cpp_solutions/chapter_16_moderate/problem_16_11_divingBoard.cpp
		cpp_solutions/chapter_16_moderate/problem_16_17_contiguousSequence.cpp
		cpp_solutions/chapter_16_moderate/problem_16_19_pondSizes.cpp
		# MISC
        cpp_solutions/misc_exercises/misc_01_integralImage.cpp
		cpp_solutions/misc_exercises/misc_02_kernelConvolution.cpp)
# create executable
add_executable(tests ${SOURCE_FILES})
