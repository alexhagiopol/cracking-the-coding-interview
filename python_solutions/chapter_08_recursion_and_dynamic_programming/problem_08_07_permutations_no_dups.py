"""
Chapter 08 - Problem 07 - Permutations Without Duplicates

Problem Statement:
Write a method to compute all permutations of a string of unique characters.

Solution:
First, we show the definition of permutations by example:
'a'    -> 'a'                                        # 1! = 1
'al'   -> 'al' , 'la'                                # 2! = 2
'ale'  -> 'ale', 'ael', 'lae', 'lea', 'eal', 'ela'   # 3! = 6

Next, we show a recursive pattern for permutation generation:
permutations('a') = 'a'  # terminating condition
permutations('al') = 'al', 'la'  # terminating condition
permutations('ale') -> return combine('a', permutations('le'))
                     = return combine('a', ['le', 'el'])
                     = return ['ale', 'lae', 'lea', 'ael', 'eal', 'ela']

Our recursive solution implementation has 2 components:

I. A function permutations(string) that takes as input a string. This function terminates when the length of the string is
2 or less. This function recurses when the length of the string is 3 or more.
II. A function combine(char, [string1, string2 ... stringN]) that takes as input a single character and a list of strings.
This function returns a list of strings that are formed by inserting the single character at every possible position in
every member of the list of strings.

When called on a string of length greater than 2, the function permutations(string) returns combine(string[0],
permutations(string[1:end])). Thus, a string of length N will cause N-2 calls of the permutations() function. At each
call of permutations(string_length_X), the combine() function will produce a list of strings that is X! long. To create
each member of the list of strings produced by combine(), O(X) work is required where X is O(N). Thus, Gayle loosely
approximates an upper bound on the total number of operations as O(N! * N^2). A more accurate expression of the runtime
would be the sum ...

O(N!*N + (N-1)!*(N-1) + (N-2)!*(N-2) ...)
The space complexity of the problem is O(N! * N) because N! of strings of length N must be stored.

Time complexity: O(N!*N^2)
Space complexity: O(N!*N)
"""


def permutations_no_dups(string):
    if len(string) <= 0:
        return [""]
    elif len(string) == 1:
        return [string]
    elif len(string) == 2:
        return [string, string[::-1]]
    else:
        return combine(string[0], permutations_no_dups(string[1:]))


def combine(char, string_list):
    output_string_list = []
    for string in string_list:
        for i in range(len(string) + 1):
            output_string_list += [string[0:i] + char + string[i:]]
    return output_string_list
