import unittest
import random
import numpy as np
from python_solutions.chapter_01_arrays_and_strings import problem_01_01_is_unique as p_1_1
from python_solutions.chapter_01_arrays_and_strings import problem_01_02_are_permuations as p_1_2
from python_solutions.chapter_01_arrays_and_strings import problem_01_03_URLify as p_1_3
from python_solutions.chapter_01_arrays_and_strings import problem_01_04_palindrome_permutation as p_1_4
from python_solutions.chapter_01_arrays_and_strings import problem_01_05_one_away as p_1_5
from python_solutions.chapter_01_arrays_and_strings import problem_01_06_string_compression as p_1_6
from python_solutions.chapter_01_arrays_and_strings import problem_01_07_rotate_matrix as p_1_7
from python_solutions.chapter_01_arrays_and_strings import problem_01_08_set_zero as p_1_8
from python_solutions.chapter_01_arrays_and_strings import problem_01_09_string_rotation as p_1_9
from python_solutions.chapter_02_linked_lists import SinglyLinkedNode as sln
from python_solutions.chapter_02_linked_lists import problem_02_01_remove_dups as p_2_1
from python_solutions.chapter_02_linked_lists import problem_02_02_return_kth_to_last as p_2_2
from python_solutions.chapter_02_linked_lists import problem_02_03_delete_middle as p_2_3
from python_solutions.chapter_02_linked_lists import problem_02_04_partition as p_2_4
from python_solutions.chapter_02_linked_lists import problem_02_05_sum_lists as p_2_5
from python_solutions.chapter_02_linked_lists import problem_02_06_palindrome as p_2_6
from python_solutions.chapter_02_linked_lists import problem_02_07_intersection as p_2_7
from python_solutions.chapter_02_linked_lists import problem_02_08_find_loop as p_2_8
from python_solutions.chapter_03_stacks_queues import Stack
from python_solutions.chapter_03_stacks_queues import Queue
from python_solutions.chapter_03_stacks_queues import problem_03_01_three_in_one as p_3_1
from python_solutions.chapter_03_stacks_queues import problem_03_02_stack_min as p_3_2
from python_solutions.chapter_03_stacks_queues import problem_03_03_stack_of_plates as p_3_3
from python_solutions.chapter_03_stacks_queues import problem_03_04_queue_via_stacks as p_3_4
from python_solutions.chapter_03_stacks_queues import problem_03_05_sort_stack as p_3_5
from python_solutions.chapter_03_stacks_queues import problem_03_06_animal_shelter as p_3_6
from python_solutions.chapter_04_trees_and_graphs import tree_basics as tb
from python_solutions.chapter_04_trees_and_graphs import problem_04_01_path_exists as p_4_1
from python_solutions.chapter_04_trees_and_graphs import problem_04_02_make_bst as p_4_2
from python_solutions.chapter_04_trees_and_graphs import problem_04_03_make_ll as p_4_3
from python_solutions.chapter_04_trees_and_graphs import problem_04_04_check_balanced as p_4_4
from python_solutions.chapter_04_trees_and_graphs import problem_04_05_validate_BST as p_4_5
from python_solutions.chapter_04_trees_and_graphs import problem_04_06_successor as p_4_6
from python_solutions.chapter_04_trees_and_graphs import problem_04_07_build_order as p_4_7
from python_solutions.chapter_04_trees_and_graphs import problem_04_08_first_common_ancestor as p_4_8
from python_solutions.chapter_04_trees_and_graphs import problem_04_10_check_subtree as p_4_10
from python_solutions.chapter_04_trees_and_graphs import problem_04_11_random_BST as p_4_11
from python_solutions.chapter_04_trees_and_graphs import problem_04_12_paths_with_sum as p_4_12
from python_solutions.chapter_05_bit_manipulation import problem_05_00_convert_binary as p_5_0
from python_solutions.chapter_05_bit_manipulation import problem_05_01_insertion as p_5_1
from python_solutions.chapter_05_bit_manipulation import problem_05_02_binary_to_string as p_5_2
from python_solutions.chapter_05_bit_manipulation import problem_05_03_flip_bit_to_win as p_5_3
from python_solutions.chapter_05_bit_manipulation import problem_05_04_next_number as p_5_4
from python_solutions.chapter_05_bit_manipulation import problem_05_06_conversion as p_5_6
from python_solutions.chapter_05_bit_manipulation import problem_05_07_pairwise_swap as p_5_7
from python_solutions.chapter_05_bit_manipulation import problem_05_08_draw_line as p_5_8
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_01_triple_step as p_8_1
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_02_robot_grid as p_8_2
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_03_magic_index as p_8_3
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_04_power_set as p_8_4
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_05_recursive_multiply as p_8_5
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_06_hanoi_towers as p_8_6
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_07_permutations_no_dups as p_8_7
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_08_permutations_with_dups as p_8_8
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_09_parens as p_8_9
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_10_paint_fill as p_8_10
from python_solutions.chapter_08_recursion_and_dynamic_programming import problem_08_11_coins as p_8_11
from python_solutions.chapter_10_sorting_and_searching import merge_sort
from python_solutions.chapter_10_sorting_and_searching import quick_sort
from python_solutions.chapter_10_sorting_and_searching import problem_10_01_sorted_merge as p_10_1
from python_solutions.chapter_16_moderate import problem_16_01_swap_numbers as p_16_01
from python_solutions.chapter_16_moderate import problem_16_03_intersection as p_16_03
from python_solutions.chapter_17_hard import problem_17_10_majority_element as p_17_10
from python_solutions.chapter_17_hard import problem_17_15_longest_combination as p_17_15
from python_solutions.chapter_17_hard import problem_17_21_histogram_volume as p_17_21


class Tests(unittest.TestCase):
    def setUp(self):
        pass

    def test_problem_1_1(self):
        s1 = "alex"
        s2 = "aalex"
        self.assertTrue(p_1_1.is_unique(s1))
        self.assertFalse(p_1_1.is_unique(s2))

    def test_problem_1_2(self):
        self.assertFalse(p_1_2.are_permutations("alex", "aalex"))
        self.assertTrue(p_1_2.are_permutations("alex", "xela"))
        self.assertFalse(p_1_2.are_permutations("aabb", "aaaa"))
        self.assertFalse(p_1_2.are_permutations("aaaa", "aabb"))
        self.assertFalse(p_1_2.are_permutations("aaaa", "aa"))
        self.assertTrue(p_1_2.are_permutations("", ""))

    def test_problem_1_3(self):
        # python strings are immutable, so we use a list of chars to do this "in place"
        # Expect 'Mr. John Smith' -> 'Mr.%20John%20Smith'
        input_string_1 = ['M', 'r', '.', ' ', 'J', 'o', 'h', 'n', ' ', 'S', 'm', 'i', 't', 'h', ' ']
        output_string_1 = ['M', 'r', '.', '%', '2', '0', 'J', 'o', 'h', 'n', '%', '2', '0', 'S', 'm', 'i', 't', 'h', '%', '2', '0']
        p_1_3.URLify(input_string_1)
        self.assertEqual(input_string_1, output_string_1)
        input_string_2 = []
        output_string_2 = []
        p_1_3.URLify(input_string_2)
        self.assertEqual(input_string_2, output_string_2)
        input_string_3 = [' ']
        output_string_3 = ['%', '2', '0']
        p_1_3.URLify(input_string_3)
        self.assertEqual(input_string_3, output_string_3)
        input_string_4 = ['A', 'l', 'e', 'x']
        output_string_4 = ['A', 'l', 'e', 'x']
        p_1_3.URLify(input_string_4)
        self.assertEqual(input_string_4, output_string_4)

    def test_problem_1_4(self):
        # spaces don't matter
        self.assertTrue(p_1_4.palindrome_permutation('tact coa'))  # calitalization matters
        self.assertFalse(p_1_4.palindrome_permutation('Tact Coa'))  # capitalization matters
        self.assertFalse(p_1_4.palindrome_permutation('xyz'))
        self.assertTrue(p_1_4.palindrome_permutation('AA  B AA'))
        self.assertFalse(p_1_4.palindrome_permutation('aA  B AA'))

    def test_problem_1_5(self):
        self.assertTrue(p_1_5.one_away('pale', 'ple'))
        self.assertTrue(p_1_5.one_away('pale', 'pale'))
        self.assertTrue(p_1_5.one_away('pale', 'bale'))
        self.assertFalse(p_1_5.one_away('pale', 'bae'))
        self.assertFalse(p_1_5.one_away('alex', 'al'))
        self.assertFalse(p_1_5.one_away('alex', 'all'))
        self.assertFalse(p_1_5.one_away('alex', 'alll'))
        self.assertTrue(p_1_5.one_away('apple', 'aple'))
        self.assertTrue(p_1_5.one_away('bale', 'pale'))
        self.assertTrue(p_1_5.one_away('', ''))

    def test_problem_1_6(self):
        self.assertEqual('a2b1c5a3', p_1_6.string_compression('aabcccccaaa'))
        self.assertEqual('alex', p_1_6.string_compression('alex'))  # strings that don't benefit from compression don't get compressed
        self.assertEqual('', p_1_6.string_compression(''))
        self.assertEqual('a10', p_1_6.string_compression('aaaaaaaaaa'))

    def test_problem_1_7(self):
        input_4x4 = np.array([[1, 2, 3, 4],
                              [1, 2, 3, 4],
                              [1, 2, 3, 4],
                              [1, 2, 3, 4]])
        input_5x5 = np.array([[1, 2, 3, 4, 5],
                              [1, 2, 3, 4, 5],
                              [1, 2, 3, 4, 5],
                              [1, 2, 3, 4, 5],
                              [1, 2, 3, 4, 5]])
        # assume rotations are clockwise
        output_4x4 = np.array([[1, 1, 1, 1],
                               [2, 2, 2, 2],
                               [3, 3, 3, 3],
                               [4, 4, 4, 4]])
        output_5x5 = np.array([[1, 1, 1, 1, 1],
                               [2, 2, 2, 2, 2],
                               [3, 3, 3, 3, 3],
                               [4, 4, 4, 4, 4],
                               [5, 5, 5, 5, 5]])
        self.assertTrue(np.array_equal(p_1_7.rotate_matrix(input_4x4), output_4x4))
        self.assertTrue(np.array_equal(p_1_7.rotate_matrix(input_5x5), output_5x5))

    def test_problem_1_8(self):
        input_4x4 = np.array([[1, 2, 3, 4],
                              [1, 2, 0, 4],
                              [1, 2, 3, 4],
                              [0, 2, 3, 4]])
        input_5x5 = np.array([[0, 2, 3, 4, 5],
                              [1, 2, 0, 4, 5],
                              [1, 2, 3, 4, 5],
                              [1, 2, 3, 4, 0],
                              [1, 2, 3, 4, 5]])
        # assume rotations are clockwise
        output_4x4 = np.array([[0, 2, 0, 4],
                               [0, 0, 0, 0],
                               [0, 2, 0, 4],
                               [0, 0, 0, 0]])
        output_5x5 = np.array([[0, 0, 0, 0, 0],
                               [0, 0, 0, 0, 0],
                               [0, 2, 0, 4, 0],
                               [0, 0, 0, 0, 0],
                               [0, 2, 0, 4, 0]])
        self.assertTrue(np.array_equal(p_1_8.set_zero(input_4x4), output_4x4))
        self.assertTrue(np.array_equal(p_1_8.set_zero(input_5x5), output_5x5))

    def test_problem_1_9(self):
        self.assertTrue(p_1_9.string_rotation('waterbottle', 'erbottlewat'))
        self.assertFalse(p_1_9.string_rotation('waterbottlex', 'erbottlewat'))
        self.assertTrue(p_1_9.string_rotation('', ''))

    def test_problem_2_1(self):
        n0 = sln.SinglyLinkedNode(9, None)
        n1 = sln.SinglyLinkedNode(7, n0)
        n2 = sln.SinglyLinkedNode(2, n1)
        n3 = sln.SinglyLinkedNode(5, n2)
        n4 = sln.SinglyLinkedNode(3, n3)
        n5 = sln.SinglyLinkedNode(3, n4)
        n6 = sln.SinglyLinkedNode(7, n5)
        self.assertEqual('7,3,3,5,2,7,9,', sln.stringify_linked_list(n6))
        p_2_1.remove_dups(n6)
        self.assertEqual('7,3,5,2,9,', sln.stringify_linked_list(n6))

    def test_problem_2_1_alternative(self):
        n0 = sln.SinglyLinkedNode(9, None)
        n1 = sln.SinglyLinkedNode(7, n0)
        n2 = sln.SinglyLinkedNode(2, n1)
        n3 = sln.SinglyLinkedNode(5, n2)
        n4 = sln.SinglyLinkedNode(3, n3)
        n5 = sln.SinglyLinkedNode(3, n4)
        n6 = sln.SinglyLinkedNode(7, n5)
        self.assertEqual('7,3,3,5,2,7,9,', sln.stringify_linked_list(n6))
        p_2_1.remove_dups_alternative(n6)
        self.assertEqual('7,3,5,2,9,', sln.stringify_linked_list(n6))

    def test_problem_2_2(self):
        n0 = sln.SinglyLinkedNode(9, None)
        n1 = sln.SinglyLinkedNode(7, n0)
        n2 = sln.SinglyLinkedNode(2, n1)
        n3 = sln.SinglyLinkedNode(5, n2)
        n4 = sln.SinglyLinkedNode(3, n3)
        n5 = sln.SinglyLinkedNode(3, n4)
        n6 = sln.SinglyLinkedNode(7, n5)
        self.assertEqual(n2, p_2_2.return_kth_to_last(n6, 3))
        self.assertEqual(n5, p_2_2.return_kth_to_last(n6, 6))
        self.assertEqual(None, p_2_2.return_kth_to_last(n6, 0))

    def test_problem_2_3(self):
        n1 = sln.SinglyLinkedNode(1, None)
        n2 = sln.SinglyLinkedNode(2, n1)
        n10 = sln.SinglyLinkedNode(10, n2)
        n5 = sln.SinglyLinkedNode(5, n10)
        string_representation = ''
        head = n5
        p_2_3.delete_middle(n10)
        while head is not None:
            string_representation += str(head.value)
            head = head.next_node
        self.assertEqual(string_representation, '521')

    def test_problem_2_4(self):
        n1 = sln.SinglyLinkedNode(1, None)
        n2 = sln.SinglyLinkedNode(2, n1)
        n10 = sln.SinglyLinkedNode(10, n2)
        n5_1 = sln.SinglyLinkedNode(5, n10)
        n8 = sln.SinglyLinkedNode(8, n5_1)
        n5_0 = sln.SinglyLinkedNode(5, n8)
        n3 = sln.SinglyLinkedNode(3, n5_0)
        new_head = p_2_4.partition(n3, 5)
        string_representation = ''
        while new_head is not None:
            string_representation += str(new_head.value)
            new_head = new_head.next_node
        self.assertEqual(string_representation, '12358510')

    def test_problem_2_5(self):
        """
        List1: 3 -> 2 -> 4 -> 9 -> NONE
        List2: -> NONE

         9423
        + 951
        -----
        10374
        """
        # first list
        n14 = sln.SinglyLinkedNode(9, None)
        n13 = sln.SinglyLinkedNode(4, n14)
        n12 = sln.SinglyLinkedNode(2, n13)
        n11 = sln.SinglyLinkedNode(3, n12)
        # second list
        n23 = sln.SinglyLinkedNode(9, None)
        n22 = sln.SinglyLinkedNode(5, n23)
        n21 = sln.SinglyLinkedNode(1, n22)
        sum_head = p_2_5.sum_lists(n11, n21)
        list_num = ""
        while sum_head is not None:
            list_num = str(sum_head.value) + list_num  # careful to reverse order!
            sum_head = sum_head.next_node
        self.assertEqual(list_num, '10374')

    def test_problem_2_6(self):
        # list 1
        node1_7 = sln.SinglyLinkedNode(0, None)
        node1_6 = sln.SinglyLinkedNode(4, node1_7)
        node1_5 = sln.SinglyLinkedNode(7, node1_6)
        node1_4 = sln.SinglyLinkedNode(0, node1_5)
        node1_3 = sln.SinglyLinkedNode(0, node1_4)
        node1_2 = sln.SinglyLinkedNode(7, node1_3)
        node1_1 = sln.SinglyLinkedNode(4, node1_2)
        node1_0 = sln.SinglyLinkedNode(0, node1_1)

        # list 2
        node2_4 = sln.SinglyLinkedNode(3, None)
        node2_3 = sln.SinglyLinkedNode(5, node2_4)
        node2_2 = sln.SinglyLinkedNode(2, node2_3)
        node2_1 = sln.SinglyLinkedNode(5, node2_2)
        node2_0 = sln.SinglyLinkedNode(3, node2_1)

        # list 3
        node3_5 = sln.SinglyLinkedNode(1, None)
        node3_4 = sln.SinglyLinkedNode(0, node3_5)
        node3_3 = sln.SinglyLinkedNode(1, node3_4)
        node3_2 = sln.SinglyLinkedNode(0, node3_3)
        node3_1 = sln.SinglyLinkedNode(1, node3_2)
        node3_0 = sln.SinglyLinkedNode(0, node3_1)

        # list 4
        node4_3 = sln.SinglyLinkedNode("a", None)
        node4_2 = sln.SinglyLinkedNode("l", node4_3)
        node4_1 = sln.SinglyLinkedNode("e", node4_2)
        node4_0 = sln.SinglyLinkedNode("x", node4_1)

        # list 5
        node5_3 = sln.SinglyLinkedNode("A", None)
        node5_2 = sln.SinglyLinkedNode("B", node5_3)
        node5_1 = sln.SinglyLinkedNode("B", node5_2)
        node5_0 = sln.SinglyLinkedNode("A", node5_1)

        self.assertTrue(p_2_6.palindrome(node1_0))
        self.assertTrue(p_2_6.palindrome(node2_0))
        self.assertFalse(p_2_6.palindrome(node3_0))
        self.assertFalse(p_2_6.palindrome(node4_0))
        self.assertTrue(p_2_6.palindrome(node5_0))

    def test_problem_2_7(self):
        # list 1
        node1_6 = sln.SinglyLinkedNode(1, None)
        node1_5 = sln.SinglyLinkedNode(2, node1_6)
        node1_4 = sln.SinglyLinkedNode(7, node1_5)
        node1_3 = sln.SinglyLinkedNode(9, node1_4)
        node1_2 = sln.SinglyLinkedNode(5, node1_3)
        node1_1 = sln.SinglyLinkedNode(1, node1_2)
        node1_0 = sln.SinglyLinkedNode(3, node1_1)
        # list 2
        node2_1 = sln.SinglyLinkedNode(6, node1_4)  # intersection point
        node2_0 = sln.SinglyLinkedNode(4, node2_1)
        # list 3
        node3_1 = sln.SinglyLinkedNode(6, None)
        node3_0 = sln.SinglyLinkedNode(4, node3_1)
        self.assertEqual(node1_4, p_2_7.intersection(node2_0, node1_0))
        self.assertEqual(None, p_2_7.intersection(node1_0, node3_0))
        self.assertEqual(None, p_2_7.intersection(None, None))

    def test_problem_2_8(self):
        # see problem_2_8_explanation.pdf
        # example 1
        node1_7 = sln.SinglyLinkedNode(7, None)
        node1_6 = sln.SinglyLinkedNode(6, node1_7)
        node1_5 = sln.SinglyLinkedNode(5, node1_6)
        node1_4 = sln.SinglyLinkedNode(4, node1_5)
        node1_3 = sln.SinglyLinkedNode(3, node1_4)
        node1_2 = sln.SinglyLinkedNode(2, node1_3)
        node1_1 = sln.SinglyLinkedNode(1, node1_2)
        node1_0 = sln.SinglyLinkedNode(0, node1_1)
        node1_7.next_node = node1_5
        self.assertEqual(p_2_8.find_loop(node1_0), node1_5)

        # example 2
        node2_10 = sln.SinglyLinkedNode(7, None)
        node2_9 = sln.SinglyLinkedNode(7, node2_10)
        node2_8 = sln.SinglyLinkedNode(7, node2_9)
        node2_7 = sln.SinglyLinkedNode(7, node2_8)
        node2_6 = sln.SinglyLinkedNode(6, node2_7)
        node2_5 = sln.SinglyLinkedNode(5, node2_6)
        node2_4 = sln.SinglyLinkedNode(4, node2_5)
        node2_3 = sln.SinglyLinkedNode(3, node2_4)
        node2_2 = sln.SinglyLinkedNode(2, node2_3)
        node2_1 = sln.SinglyLinkedNode(1, node2_2)
        node2_0 = sln.SinglyLinkedNode(0, node2_1)
        node2_10.next_node = node2_3
        self.assertEqual(p_2_8.find_loop(node2_0), node2_3)

        # example 3
        self.assertEqual(p_2_8.find_loop(None), None)

    def test_stack(self):
        my_stack = Stack.Stack()
        for i in range(1,5):
            my_stack.push(i)
        self.assertEqual(str(my_stack), '4 3 2 1')
        self.assertEqual(my_stack.peek(), 4)
        test_array = []
        for i in range(4):
            test_array += [my_stack.pop()]
        self.assertEqual(test_array, [4, 3, 2, 1])
        self.assertEqual(my_stack.is_empty(), True)
        self.assertEqual(my_stack.pop(), None)
        self.assertEqual(my_stack.peek(), None)

    def test_queue(self):
        my_q = Queue.Queue()
        my_q.enqueue(1)
        my_q.enqueue(2)
        my_q.enqueue(3)
        my_q.enqueue(4)
        test_array = []
        for i in range(4):
            test_array += [my_q.dequeue()]
        self.assertEqual(test_array, [1, 2, 3, 4])
        self.assertTrue(my_q.is_empty())

    def test_problem_3_1(self):
        stack = p_3_1.TripleStack()
        actual_list = []
        correct_list = [7, 6, 5, 4, 3, 2, 1, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1]
        for i in range(1, 8):
            stack.push(0, i)
        for i in range(1, 8):
            actual_list += [stack.pop(0)]
        for i in range(1, 8):
            stack.push(1, i)
            stack.push(2, i)
        for i in range(1, 8):
            actual_list += [stack.pop(1)]
            actual_list += [stack.pop(2)]
        self.assertEqual(actual_list, correct_list)

    def test_problem_3_2(self):
        stack_min = p_3_2.StackMin()
        stack_min.push(-8)
        stack_min.push(-5)
        stack_min.push(1)
        stack_min.push(-6)
        self.assertEqual(stack_min.see_min(), -8)
        stack_min.push(-9)
        self.assertEqual(stack_min.see_min(), -9)
        stack_min.push(-15)
        stack_min.push(-30)
        stack_min.pop()
        stack_min.pop()
        self.assertEqual(stack_min.see_min(), -9)

    def test_problem_3_3(self):
        stacks = p_3_3.SetOfStacks(3)
        for i in range(10):
            stacks.push(i)
        self.assertEqual([3, 3, 3, 1], [x.size for x in stacks.stacks])
        for i in [5, 4, 3, 2]:
            self.assertEqual(i, stacks.pop_at(1))
        self.assertEqual([2, 3, 1], [x.size for x in stacks.stacks])
        for i in [9, 8, 7, 6, 1, 0, None]:
            self.assertEqual(i, stacks.pop())
        self.assertEqual(stacks.pop_at(-1), None)

    def test_problem_3_4(self):
        queue = p_3_4.QueueViaStacks()
        for i in range(10):
            queue.enqueue(i)
        for i in range(5):
            self.assertEqual(i, queue.dequeue())
        for i in range(5):
            queue.enqueue(i)
        for i in range(5,10):
            self.assertEqual(i, queue.dequeue())
        for i in range(5):
            self.assertEqual(i, queue.dequeue())

    def test_problem_3_5(self):
        stack = Stack.Stack()
        for i in [7, 6, 3, 5, 1, 2, 4]:
            stack.push(i)
        p_3_5.sort_stack(stack)
        for i in range(7, 0, -1):
            self.assertEqual(i, stack.pop())

    def test_problem_3_6(self):
        shelter = p_3_6.AnimalShelter()
        self.assertEqual(None, shelter.dequeue_cat())
        shelter.enqueue("cat", "a")
        shelter.enqueue("dog", "b")
        shelter.enqueue("dog", "c")
        shelter.enqueue("cat", "d")
        shelter.enqueue("dog", "e")
        shelter.enqueue("cat", "f")
        self.assertEqual("a", shelter.dequeue_any().name)
        self.assertEqual("b", shelter.dequeue_any().name)
        self.assertEqual("c", shelter.dequeue_dog().name)
        self.assertEqual("d", shelter.dequeue_cat().name)
        self.assertEqual("e", shelter.dequeue_any().name)
        self.assertEqual("f", shelter.dequeue_any().name)
        self.assertEqual(None, shelter.dequeue_any())

    def test_tree_binary_tree_traversals(self):
        """
                 8
               /  \
              4   10
             /\    \
            2 6    20
        """
        n2 = tb.BinaryNode(2)
        n6 = tb.BinaryNode(6)
        n20 = tb.BinaryNode(20)
        n4 = tb.BinaryNode(4, n2, n6)
        n10 = tb.BinaryNode(10, None, n20)
        n8 = tb.BinaryNode(8, n4, n10)
        in_order_sequence = []
        tb.in_order_traversal(n8, in_order_sequence)
        self.assertEqual(in_order_sequence, [2, 4, 6, 8, 10, 20])
        pre_order_sequence = []
        tb.pre_order_traversal(n8, pre_order_sequence)
        self.assertEqual(pre_order_sequence, [8, 4, 2, 6, 10, 20])
        post_order_sequence = []
        tb.post_order_traversal(n8, post_order_sequence)
        self.assertEqual(post_order_sequence, [2, 6, 4, 20, 10, 8])

    def test_graph_exploration(self):
        """
             1 <- 8 -> 17
                /  \
          3 <- 4   10 -> 15
              /\   /\
        0 <- 2 6  9 20 -> 23
        """
        n0 = tb.Node(0)
        n2 = tb.Node(2, (n0,))
        n6 = tb.Node(6)
        n9 = tb.Node(9)
        n23 = tb.Node(23)
        n20 = tb.Node(20, (n23,))
        n3 = tb.Node(3)
        n4 = tb.Node(4, (n2, n3, n6))
        n15 = tb.Node(15)
        n10 = tb.Node(10, (n9, n15, n20))
        n1 = tb.Node(1)
        n17 = tb.Node(17)
        n8 = tb.Node(8, (n1, n4, n10, n17))
        # expected DFS visiting sequence
        dfs_sequence = []
        tb.dfs(n8, dfs_sequence)
        self.assertEqual(dfs_sequence, [8, 1, 4, 2, 0, 3, 6, 10, 9, 15, 20, 23, 17])
        # expected BFS visiting sequence
        bfs_sequence = []
        tb.bfs(n8, bfs_sequence)
        self.assertEqual(bfs_sequence, [8, 1, 4, 10, 17, 2, 3, 6, 9, 15, 20, 0, 23])
        # test None input
        self.assertEqual(tb.dfs(None, []), None)
        self.assertEqual(tb.bfs(None, []), None)

    def test_problem_4_1(self):
        my_graph = p_4_1.Graph()
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists_BFS(my_graph, my_graph.get_node(1), my_graph.get_node(6)), True)
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists_BFS(my_graph, my_graph.get_node(7), my_graph.get_node(5)), True)
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists_BFS(my_graph, my_graph.get_node(3), my_graph.get_node(8)), False)
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists_BFS(my_graph, my_graph.get_node(1), my_graph.get_node(8)), True)
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists_BFS(my_graph, None, None), False)
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists_BFS(my_graph, my_graph.get_node(1), None), False)

    def test_problem_4_2(self):
        # test 1
        my_list_1 = [8, 9, 10, 11, 12, 13, 14]
        root1 = p_4_2.make_bst(my_list_1)
        self.assertEqual('11,\n9,13,\n8,10,12,14,\n_,_,_,_,_,_,_,_,\n', tb.stringify_bin_tree(root1))
        # test 2
        my_list_2 = [9, 10, 11, 12, 13, 14]
        root2 = p_4_2.make_bst(my_list_2)
        self.assertEqual('11,\n9,13,\n_,10,12,14,\n_,_,_,_,_,_,\n', tb.stringify_bin_tree(root2))

    def test_problem_4_3(self):
        """
        create binary tree:
        10,
        5,8,
        1,7,_,9,
        _,_,_,_,_,_,
        """
        root = tb.BinaryNode(10)
        n5 = tb.BinaryNode(5)
        n8 = tb.BinaryNode(8)
        n1 = tb.BinaryNode(1)
        n7 = tb.BinaryNode(7)
        n9 = tb.BinaryNode(9)
        root.left = n5
        root.right = n8
        n5.left = n1
        n5.right = n7
        n8.right = n9
        linked_lists = p_4_3.make_ll(root)
        self.assertEqual('10,\n5,8,\n1,7,9,\n', tb.stringify_list_of_linked_lists(linked_lists))

    def test_problem_4_4(self):
        # For the purposes of this question, a balanced tree is defined to be a tree
        # such that the heights of the two subtrees of any node never differ by more than one.
        """
        balanced tree:
        root,
        node,leaf,
        leaf,leaf,_,_,
        _,_,_,_,
        """
        node131 = tb.BinaryNode("leaf", None, None)
        node132 = tb.BinaryNode("leaf", None, None)
        node121 = tb.BinaryNode("node", node131, node132)
        node122 = tb.BinaryNode("leaf", None, None)
        node111 = tb.BinaryNode("root", node121, node122)
        self.assertTrue(p_4_4.check_balanced(node111))
        """
        unbalanced tree:
        root,
        node,leaf,
        node,leaf,_,_,
        leaf,_,_,_,
        _,_,
        """
        node241 = tb.BinaryNode("leaf", None, None)
        node231 = tb.BinaryNode("node", node241, None)
        node232 = tb.BinaryNode("leaf", None, None)
        node221 = tb.BinaryNode("node", node231, node232)
        node222 = tb.BinaryNode("leaf", None, None)
        root211 = tb.BinaryNode("root", node221, node222)
        self.assertFalse(p_4_4.check_balanced(root211))

    def test_problem_4_5(self):
        # construct a binary tree
        node1 = tb.BinaryNode(1)
        node2 = tb.BinaryNode(2)
        node3 = tb.BinaryNode(3)
        node4 = tb.BinaryNode(4)
        node5 = tb.BinaryNode(5)
        node6 = tb.BinaryNode(6)
        node8 = tb.BinaryNode(8)
        node10 = tb.BinaryNode(10)
        """
                       8
                4,            10
           2,       6,
        1,    3, 5,
        """
        node8.left = node4
        node8.right = node10
        node4.left = node2
        node4.right = node6
        node2.left = node1
        node2.right = node3
        node6.left = node5
        self.assertTrue(p_4_5.validate_BST(node8))
        # add node that breaks BST rule
        node9 = tb.BinaryNode(9)
        node6.right = node9
        self.assertFalse(p_4_5.validate_BST(node8))

    def test_problem_4_6(self):
        # construct a binary tree
        node0 = tb.BinaryNodeLP(0)
        node1 = tb.BinaryNodeLP(1)
        node2 = tb.BinaryNodeLP(2)
        node3 = tb.BinaryNodeLP(3)
        node4 = tb.BinaryNodeLP(4)
        node5 = tb.BinaryNodeLP(5)
        node6 = tb.BinaryNodeLP(6)
        node8 = tb.BinaryNodeLP(8)
        node9 = tb.BinaryNodeLP(9)
        node10 = tb.BinaryNodeLP(10)
        """
                                    8
                        4                       10
                2               6
            1       3       5
                   0 9
        In-order traversal: 
        1, 2, 0, 3, 9, 4, 5, 6, 8, 10
        """
        node0.parent = node3
        node1.parent = node2
        node3.parent = node2
        node2.parent = node4
        node5.parent = node6
        node6.parent = node4
        node4.parent = node8
        node9.parent = node3
        node10.parent = node8

        node8.left = node4
        node8.right = node10
        node4.left = node2
        node4.right = node6
        node2.left = node1
        node2.right = node3
        node6.left = node5
        node3.left = node0
        node3.right = node9

        self.assertEqual(node8, p_4_6.successor(node6))
        self.assertEqual(node5, p_4_6.successor(node4))
        self.assertEqual(node0, p_4_6.successor(node2))
        self.assertEqual(node3, p_4_6.successor(node0))
        self.assertEqual(node4, p_4_6.successor(node9))
        self.assertEqual(None, p_4_6.successor(node10))

    def test_problem_4_7(self):
        # no circular dependencies
        projects1 = ['a', 'b', 'c', 'd', 'e', 'f']
        dependencies1 = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c')]
        projects2 = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
        dependencies2 = [('f', 'c'), ('f', 'b'), ('f', 'a'), ('c', 'a'), ('b', 'a'), ('a', 'e'), ('b', 'e'), ('d', 'g')]
        # add circular dependency
        dependencies3 = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c'), ('c', 'a')]
        self.assertEqual(['e', 'f', 'b', 'a', 'd', 'c'], p_4_7.build_order(projects1, dependencies1))
        self.assertEqual(['d', 'f', 'g', 'c', 'b', 'a', 'e'], p_4_7.build_order(projects2, dependencies2))
        self.assertEqual(None, p_4_7.build_order(projects1, dependencies3))

    def test_problem_4_8(self):
        """
        construct binary tree
                        7
                4               3
            10      5       6       15
                                21      17


                                25
        """
        n21 = tb.BinaryNode(21)
        n17 = tb.BinaryNode(17)
        n15 = tb.BinaryNode(15, n21, n17)
        n6 = tb.BinaryNode(6)
        n3 = tb.BinaryNode(3, n6, n15)
        n10 = tb.BinaryNode(10)
        n5 = tb.BinaryNode(5)
        n4 = tb.BinaryNode(4, n10, n5)
        n7 = tb.BinaryNode(7, n4, n3)
        n25 = tb.BinaryNode(25)  # unconnected node

        self.assertEqual(n3, p_4_8.first_common_ancestor(n7, n6, n21))
        self.assertEqual(n7, p_4_8.first_common_ancestor(n7, n10, n21))
        self.assertEqual(None, p_4_8.first_common_ancestor(n7, n15, n25))
        self.assertEqual(None, p_4_8.first_common_ancestor(n7, n7, n7))  # a node is not its own ancestor
        self.assertEqual(n7, p_4_8.first_common_ancestor(n7, n3, n4))

    def test_problem_4_10(self):
        """
        construct binary tree
                        7
                4               3
            10      5       6       15
                                21      17


                                25
        """
        n21 = tb.BinaryNode(21)
        n17 = tb.BinaryNode(17)
        n15 = tb.BinaryNode(15, n21, n17)
        n6 = tb.BinaryNode(6)
        n3 = tb.BinaryNode(3, n6, n15)
        n10 = tb.BinaryNode(10)
        n5 = tb.BinaryNode(5)
        n4 = tb.BinaryNode(4, n10, n5)
        n7 = tb.BinaryNode(7, n4, n3)
        n25 = tb.BinaryNode(25)  # unconnected node

        """
        construct disconnected binary tree
                30
            31      32
        """
        n31 = tb.BinaryNode(31)
        n32 = tb.BinaryNode(32)
        n30 = tb.BinaryNode(30, n31, n32)

        self.assertEqual(True, p_4_10.check_subtree(n7, n15))
        self.assertEqual(True, p_4_10.check_subtree(n7, n7))
        self.assertEqual(True, p_4_10.check_subtree(n7, n21))
        self.assertEqual(True, p_4_10.check_subtree(n7, n4))
        self.assertEqual(False, p_4_10.check_subtree(n7, None))
        self.assertEqual(False, p_4_10.check_subtree(n7, n30))
        self.assertEqual(False, p_4_10.check_subtree(n4, n31))
        self.assertEqual(False, p_4_10.check_subtree(n25, n31))
        self.assertEqual(True, p_4_10.check_subtree(n30, n31))
        self.assertEqual(False, p_4_10.check_subtree(None, None))

    def test_problem_4_11(self):
        random.seed(0)
        rnd_bst_head = p_4_11.RandBinNode()
        values_list = [10, 13, 14, 11, 7, 7, 8, 7, 4, 10]
        for i in values_list:
            rnd_bst_head.insert(i)
        occurrence_sum_4 = 0
        occurrence_sum_7 = 0
        occurrence_sum_10 = 0
        occurrence_sum_13 = 0
        # using 10,000 random samples, assert that occurence of values in random samples approximately
        # the same as the occurence of the values in the tree
        for i in range(10000):
            rand_value = rnd_bst_head.get_random()
            if rand_value == 4:
                occurrence_sum_4 += 1
            elif rand_value == 7:
                occurrence_sum_7 += 1
            elif rand_value == 10:
                occurrence_sum_10 += 1
            elif rand_value == 13:
                occurrence_sum_13 += 1
        self.assertAlmostEqual(occurrence_sum_4, 1000, delta=50)
        self.assertAlmostEqual(occurrence_sum_7, 3000, delta=50)  # 7 occurs 3 times more than 4
        self.assertAlmostEqual(occurrence_sum_10, 2000, delta=50)  # 10 occurs 2 times more than 4
        self.assertAlmostEqual(occurrence_sum_13, 1000, delta=50)

    def test_problem_4_12(self):
        """
        construct binary tree like in textbook example
                            10
                    5                   -3
            3              1        __      11
        3     -2         __    2
        """
        # leaf nodes at depth = 3
        n_3_leaf = tb.BinaryNode(3)
        n_minus_2 = tb.BinaryNode(-2)
        n_2 = tb.BinaryNode(2)
        # nodes at depth = 2
        n_3 = tb.BinaryNode(3, n_3_leaf, n_minus_2)
        n_1 = tb.BinaryNode(1, None, n_2)
        n_11 = tb.BinaryNode(11)
        # nodes at depth = 1
        n_5 = tb.BinaryNode(5, n_3, n_1)
        n_minus_3 = tb.BinaryNode(-3, None, n_11)
        # root node at depth = 0
        n_10 = tb.BinaryNode(10, n_5, n_minus_3)
        # count paths that sum to 8
        self.assertEqual(p_4_12.paths_with_sum(n_10, 8), 3)

    def test_problem_5_0(self):
        self.assertEqual(p_5_0.convert_to_base2(122), '1111010')
        self.assertEqual(p_5_0.convert_to_base(255, 10, 16), 'ff')
        self.assertEqual(p_5_0.convert_to_base('11110100', 2, 16), 'f4')

    def test_problem_5_1(self):
        self.assertEqual(p_5_1.insertion(0b10000000000, 0b10011, 2, 6), 0b10001001100)

    def test_problem_5_2(self):
        self.assertEqual(p_5_2.binary_to_string(0.5), '0.1')
        self.assertEqual(p_5_2.binary_to_string(0.25), '0.01')
        self.assertEqual(p_5_2.binary_to_string(1.5), None)
        self.assertEqual(p_5_2.binary_to_string(0.722), '0.10111000110101001111110111110011')

    def test_problem_5_3(self):
        self.assertEqual(p_5_3.flip_bit_to_win(1775), 8)
        self.assertEqual(p_5_3.flip_bit_to_win(0b0000), 1)
        self.assertEqual(p_5_3.flip_bit_to_win(0b1011), 4)
        self.assertEqual(p_5_3.flip_bit_to_win(0b1010111), 5)
        self.assertEqual(p_5_3.flip_bit_to_win(0b1110101), 5)
        self.assertEqual(p_5_3.flip_bit_to_win(0b00), 1)
        self.assertEqual(p_5_3.flip_bit_to_win(0b10), 2)

    def test_problem_5_4(self):
        self.assertEqual(p_5_4.get_prev(0b0001), -1)
        self.assertEqual(p_5_4.get_next(0b0001), 0b0010)
        self.assertEqual(p_5_4.get_prev(0b0100), 0b0010)
        self.assertEqual(p_5_4.get_next(0b0100), 0b1000)
        self.assertEqual(p_5_4.get_prev(0b0101), 0b0011)
        self.assertEqual(p_5_4.get_next(0b0101), 0b0110)
        self.assertEqual(p_5_4.get_prev(0b1111), -1)
        self.assertEqual(p_5_4.get_next(0b1111), 0b10111)
        self.assertEqual(p_5_4.get_prev(0b0000), -1)
        self.assertEqual(p_5_4.get_next(0b0000), -1)
        self.assertEqual(p_5_4.get_prev(np.uint32(0xffffffff)), -1)
        self.assertEqual(p_5_4.get_next(np.uint32(0xffffffff)), -1)
        self.assertEqual(p_5_4.get_prev(0b1001), 0b0110)
        self.assertEqual(p_5_4.get_next(0b1001), 0b1010)
        self.assertEqual(p_5_4.get_prev(0b0110), 0b0101)
        self.assertEqual(p_5_4.get_next(0b0110), 0b1001)
        self.assertEqual(p_5_4.get_prev(0b10011110000011), 0b10011101110000)
        self.assertEqual(p_5_4.get_next(0b11011001111100), 0b11011010001111)

    def test_problem_5_6(self):
        self.assertEqual(p_5_6.conversion(0b11001100, 0b11110000), 4)
        self.assertEqual(p_5_6.conversion(29, 15), 2)

    def test_problem_5_7(self):
        self.assertEqual(p_5_7.pairwise_swap(0b10101010), 0b01010101)
        self.assertEqual(p_5_7.pairwise_swap(0b11110000), 0b11110000)
        self.assertEqual(p_5_7.pairwise_swap(0b110), 0b1001)

    def test_problem_5_8(self):
        # Screen #1: Line spans less than 8 bits.
        screen_1 = [0] * 8
        width_1 = 8
        x1_1 = 3
        x2_1 = 7
        y_1 = 5
        # processed_screen_1 = [0] * 5 + [0b00011111] + [0] * 2
        expected_initial_screen_1 = '00000000\n'\
                                    '00000000\n'\
                                    '00000000\n'\
                                    '00000000\n'\
                                    '00000000\n'\
                                    '00000000\n'\
                                    '00000000\n'\
                                    '00000000\n'
        expected_final_screen_1 = '00000000\n'\
                                  '00000000\n'\
                                  '00000000\n'\
                                  '00000000\n'\
                                  '00000000\n'\
                                  '00011111\n'\
                                  '00000000\n'\
                                  '00000000\n'
        self.assertEqual(expected_initial_screen_1, p_5_8.stringify_screen(screen_1, width_1))
        p_5_8.draw_line(screen_1, width_1, x1_1, x2_1, y_1)
        self.assertEqual(expected_final_screen_1, p_5_8.stringify_screen(screen_1, width_1))

        # Screen #2: Line spans more than 8 bits.
        screen_2 = [0] * 8
        width_2 = 32
        x1_2 = 0
        x2_2 = 13
        y_2 = 1
        # processed_screen_2 = [0] * 4 + [255] + [0b11111100] + [0] * 2
        expected_initial_screen_2 = '00000000000000000000000000000000\n'\
                                    '00000000000000000000000000000000\n'
        expected_final_screen_2 = '00000000000000000000000000000000\n'\
                                  '11111111111111000000000000000000\n'

        self.assertEqual(expected_initial_screen_2, p_5_8.stringify_screen(screen_2, width_2))
        p_5_8.draw_line(screen_2, width_2, x1_2, x2_2, y_2)
        self.assertEqual(expected_final_screen_2, p_5_8.stringify_screen(screen_2, width_2))

        # Screen #3: Line spans more than 8 bits.
        screen_3 = [0] * 32
        width_3 = 64
        x1_3 = 5
        x2_3 = 24
        y_3 = 1
        # processed_screen_3 = [0] * 8 + [0b00000111] + [255] + [255] + [0b10000000] + [0] * 20
        expected_initial_screen_3 = '0000000000000000000000000000000000000000000000000000000000000000\n'\
                                    '0000000000000000000000000000000000000000000000000000000000000000\n'\
                                    '0000000000000000000000000000000000000000000000000000000000000000\n'\
                                    '0000000000000000000000000000000000000000000000000000000000000000\n'
        expected_final_screen_3 = '0000000000000000000000000000000000000000000000000000000000000000\n'\
                                  '0000011111111111111111111000000000000000000000000000000000000000\n'\
                                  '0000000000000000000000000000000000000000000000000000000000000000\n'\
                                  '0000000000000000000000000000000000000000000000000000000000000000\n'

        self.assertEqual(expected_initial_screen_3, p_5_8.stringify_screen(screen_3, width_3))
        p_5_8.draw_line(screen_3, width_3, x1_3, x2_3, y_3)
        self.assertEqual(expected_final_screen_3, p_5_8.stringify_screen(screen_3, width_3))

        # Screen #4: Line spans a single bit.
        screen_4 = [0]
        width_4 = 8
        x1_4 = 3
        x2_4 = 3
        y_4 = 0
        expected_initial_screen_4 = '00000000\n'
        expected_final_screen_4 = '00010000\n'
        self.assertEqual(expected_initial_screen_4, p_5_8.stringify_screen(screen_4, width_4))
        p_5_8.draw_line(screen_4, width_4, x1_4, x2_4, y_4)
        self.assertEqual(expected_final_screen_4, p_5_8.stringify_screen(screen_4, width_4))

    def test_problem_8_1(self):
        self.assertEqual(p_8_1.triple_step(3), 4)
        self.assertEqual(p_8_1.triple_step(4), 7)
        self.assertEqual(p_8_1.triple_step(5), 13)

    def test_problem_8_2(self):
        maze = [[1, 1, 1, 0, 1],
                [0, 0, 1, 1, 1],
                [0, 1, 1, 0, 0],
                [0, 1, 1, 0, 1],
                [1, 1, 1, 1, 1]]
        expected_path = [(0, 0), (0, 1), (0, 2), (1, 2), (2, 2), (3, 2), (4, 2), (4, 3), (4, 4)]
        self.assertEqual(p_8_2.robot_grid(maze, (0, 0), (4, 4)), expected_path)

    def test_problem_8_3(self):
        self.assertEqual(p_8_3.magic_index([-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), None)
        self.assertEqual(p_8_3.magic_index([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 5)
        self.assertEqual(p_8_3.magic_index([-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13]), 7)

    def test_problem_8_4(self):
        self.assertEqual(p_8_4.power_set([1, 2, 3]), [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]])
        self.assertEqual(p_8_4.power_set([1, 2]), [[], [1], [2], [1, 2]])
        self.assertEqual(p_8_4.power_set([1]), [[], [1]])

    def test_problem_8_5(self):
        self.assertEqual(p_8_5.recursive_multiply(1, 1), 1)
        self.assertEqual(p_8_5.recursive_multiply(1, 2), 2)
        self.assertEqual(p_8_5.recursive_multiply(0, 1), 0)
        self.assertEqual(p_8_5.recursive_multiply(9, 10), 90)
        self.assertEqual(p_8_5.recursive_multiply(9, 11), 99)
        self.assertEqual(p_8_5.recursive_multiply(12, 12), 144)

    def test_problem_8_6(self):
        tower0 = p_8_6.Tower([5, 4, 3, 2, 1])
        tower1 = p_8_6.Tower()
        tower2 = p_8_6.Tower()
        tower0.move_disks(5, tower2, tower1)
        self.assertEqual(tower0.disks, [])
        self.assertEqual(tower1.disks, [])
        self.assertEqual(tower2.disks, [5, 4, 3, 2, 1])

    def test_problem_8_7(self):
        self.assertEqual(set(p_8_7.permutations_no_dups('a')), {'a'})
        self.assertEqual(set(p_8_7.permutations_no_dups('al')), {'al', 'la'})
        self.assertEqual(set(p_8_7.permutations_no_dups('ale')), {'ela', 'lea', 'lae', 'eal', 'ael', 'ale'})
        self.assertEqual(set(p_8_7.permutations_no_dups('alex')), {'xela', 'exla', 'elxa', 'elax',
                                                                   'xlea', 'lxea', 'lexa', 'leax',
                                                                   'xlae', 'lxae', 'laxe', 'laex',
                                                                   'xeal', 'exal', 'eaxl', 'ealx',
                                                                   'xael', 'axel', 'aexl', 'aelx',
                                                                   'xale', 'axle', 'alxe', 'alex'})

    def test_problem_8_8(self):
        self.assertEqual(set(p_8_8.permutations_with_dups('ala')), {'ala', 'laa', 'aal'})
        self.assertEqual(set(p_8_8.permutations_with_dups('alaa')), {'aala', 'alaa', 'alaa', 'laaa',  'aala', 'aaal'})
        self.assertEqual(set(p_8_8.permutations_with_dups('alex')), {'xela', 'exla', 'elxa', 'elax',
                                                                   'xlea', 'lxea', 'lexa', 'leax',
                                                                   'xlae', 'lxae', 'laxe', 'laex',
                                                                   'xeal', 'exal', 'eaxl', 'ealx',
                                                                   'xael', 'axel', 'aexl', 'aelx',
                                                                   'xale', 'axle', 'alxe', 'alex'})

    def test_problem_8_9(self):
        self.assertEqual(set(p_8_9.parens(3)), {'()(())', '(())()', '((()))', '()()()', '(()())'})
        self.assertEqual(set(p_8_9.parens(2)), {'()()', '(())'})
        self.assertEqual(set(p_8_9.parens(1)), {'()'})
        self.assertEqual(set(p_8_9.parens(0)), {''})

    def test_problem_8_10(self):
        image = np.array([[0, 1, 1, 0, 0, 3],
                          [1, 1, 1, 1, 0, 0],
                          [0, 1, 1, 0, 0, 2],
                          [0, 0, 0, 0, 2, 2],
                          [0, 2, 2, 2, 2, 2],
                          [0, 0, 0, 2, 2, 2]])

        zeros_filled = np.array([[0, 1, 1, 5, 5, 3],
                                 [1, 1, 1, 1, 5, 5],
                                 [5, 1, 1, 5, 5, 2],
                                 [5, 5, 5, 5, 2, 2],
                                 [5, 2, 2, 2, 2, 2],
                                 [5, 5, 5, 2, 2, 2]])

        ones_filled = np.array([[0, 5, 5, 0, 0, 3],
                                [5, 5, 5, 5, 0, 0],
                                [0, 5, 5, 0, 0, 2],
                                [0, 0, 0, 0, 2, 2],
                                [0, 2, 2, 2, 2, 2],
                                [0, 0, 0, 2, 2, 2]])

        twos_filled = np.array([[0, 1, 1, 0, 0, 3],
                                [1, 1, 1, 1, 0, 0],
                                [0, 1, 1, 0, 0, 5],
                                [0, 0, 0, 0, 5, 5],
                                [0, 5, 5, 5, 5, 5],
                                [0, 0, 0, 5, 5, 5]])

        three_filled = np.array([[0, 1, 1, 0, 0, 5],
                                 [1, 1, 1, 1, 0, 0],
                                 [0, 1, 1, 0, 0, 2],
                                 [0, 0, 0, 0, 2, 2],
                                 [0, 2, 2, 2, 2, 2],
                                 [0, 0, 0, 2, 2, 2]])
        expected_zeros_filled = image.copy()
        p_8_10.paint_fill(expected_zeros_filled, 5, (2, 0))
        self.assertTrue((zeros_filled == expected_zeros_filled).all())

        expected_ones_filled = image.copy()
        p_8_10.paint_fill(expected_ones_filled, 5, (1, 2))
        self.assertTrue((ones_filled == expected_ones_filled).all())

        expected_twos_filled = image.copy()
        p_8_10.paint_fill(expected_twos_filled, 5, (4, 3))
        self.assertTrue((twos_filled == expected_twos_filled).all())

        expected_three_filled = image.copy()
        p_8_10.paint_fill(expected_three_filled, 5, (0, 5))
        self.assertTrue((three_filled == expected_three_filled).all())

    def test_problem_8_11(self):
        self.assertEqual(p_8_11.coin_representations(12), 4)
        self.assertEqual(p_8_11.coin_representations(7), 2)

    def test_problem_8_12(self):
        pass

    def test_problem_8_13(self):
        pass

    def test_problem_8_14(self):
        pass

    def test_merge_sort(self):
        input1 = [1000, 10, 7, 3, -1000, 5, 100, 9, 1, 10000, -10000, 6, 2, -10, 4, 8, -100, 0]
        expected_output_1 = [-10000, -1000, -100, -10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000]
        input2 = []
        expected_output_2 = []
        input3 = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7]
        expected_output_3 = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7]
        input4 = [1.1]
        expected_output_4 = [1.1]
        input5 = [1.4, 1.6, 1.1, 1.3, 1.5, 1.7, 1.2]
        expected_output_5 = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7]
        merge_sort.merge_sort(input1)
        merge_sort.merge_sort(input2)
        merge_sort.merge_sort(input3)
        merge_sort.merge_sort(input4)
        merge_sort.merge_sort(input5)
        self.assertEqual(expected_output_1, input1)
        self.assertEqual(expected_output_2, input2)
        self.assertEqual(expected_output_3, input3)
        self.assertEqual(expected_output_4, input4)
        self.assertEqual(expected_output_5, input5)

    def test_quick_sort(self):
        input1 = [1000, 10, 7, 3, -1000, 5, 100, 9, 1, 10000, -10000, 6, 2, -10, 4, 8, -100, 0]
        expected_output_1 = [-10000, -1000, -100, -10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000]
        input2 = []
        expected_output_2 = []
        input3 = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7]
        expected_output_3 = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7]
        input4 = [1.1]
        expected_output_4 = [1.1]
        input5 = [1.4, 1.6, 1.1, 1.3, 1.5, 1.7, 1.2]
        expected_output_5 = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7]
        quick_sort.quick_sort(input1)
        quick_sort.quick_sort(input2)
        quick_sort.quick_sort(input3)
        quick_sort.quick_sort(input4)
        quick_sort.quick_sort(input5)
        self.assertEqual(expected_output_1, input1)
        self.assertEqual(expected_output_2, input2)
        self.assertEqual(expected_output_3, input3)
        self.assertEqual(expected_output_4, input4)
        self.assertEqual(expected_output_5, input5)

    def test_problem_10_01(self):
        A = [5, 5, 10, 10, 15, 0, 0, 0, 0, 0]
        B = [3, 6,  9, 12, 15]
        lastA = 4
        lastB = 4
        C = [3, 5, 5, 6, 9, 10, 10, 12, 15, 15]
        p_10_1.sorted_merge(A, lastA, B, lastB)
        self.assertEqual(A, C)

        D = [5, 5, 10, 10, 0, 0, 0, 0, 0, 0]
        E = [3, 6,  9, 12, 15, 15]
        lastD = 3
        lastE = 5
        p_10_1.sorted_merge(D, lastD, E, lastE)
        self.assertEqual(D, C)

    def test_problem_16_01(self):
        pair_ab = [5, 9]
        p_16_01.swap_numbers(pair_ab)
        self.assertEqual(pair_ab, [9, 5])
        pair_cd = [5.1, -9.6]
        p_16_01.swap_numbers(pair_cd)
        self.assertEqual(pair_cd, [-9.6, 5.1])
        pair_ef = [-50435, -89048]
        p_16_01.swap_numbers(pair_ef)
        self.assertEqual(pair_ef, [-89048, -50435])

    def test_problem_16_03(self):
        segment1 = p_16_03.LineSegment(p_16_03.Point2(5, 5), p_16_03.Point2(0, 0))
        segment2 = p_16_03.LineSegment(p_16_03.Point2(0, 3), p_16_03.Point2(3, 0))
        segment3 = p_16_03.LineSegment(p_16_03.Point2(3, 0), p_16_03.Point2(6, 0))
        segment4 = p_16_03.LineSegment(p_16_03.Point2(4, 0), p_16_03.Point2(7, 0))
        segment5 = p_16_03.LineSegment(p_16_03.Point2(7, 7), p_16_03.Point2(5, 5))
        self.assertEqual(p_16_03.Point2(1.5, 1.5), p_16_03.intersection(segment1, segment2))
        self.assertEqual(None, p_16_03.intersection(segment1, segment3))
        self.assertEqual(None, p_16_03.intersection(segment4, segment3))
        self.assertEqual(p_16_03.Point2(5, 5), p_16_03.intersection(segment1, segment5))

    def test_problem_17_10(self):
        maj_0_array = [1, 1, 0, 0, 0]
        maj_1_array = [1, 1, 1, 0, 0]
        maj_5_array = [1, 2, 5, 9, 5, 9, 5, 5, 5]
        no_maj_array_1 = [3, 1, 7, 1, 3, 7, 3, 7, 1, 7, 7]
        no_maj_array_2 = [1, 2, 0, 0]
        maj_7_array = [7, 3, 1, 7, 1, 7, 3, 7, 3, 7, 1, 7, 7]
        self.assertEqual(p_17_10.majority_element(maj_0_array), 0)
        self.assertEqual(p_17_10.majority_element(maj_1_array), 1)
        self.assertEqual(p_17_10.majority_element(maj_5_array), 5)
        self.assertEqual(p_17_10.majority_element(no_maj_array_1), None)
        self.assertEqual(p_17_10.majority_element(no_maj_array_2), None)
        self.assertEqual(p_17_10.majority_element(None), None)
        self.assertEqual(p_17_10.majority_element(maj_7_array), 7)

    def test_problem_17_15(self):
        list1 = ['cat', 'banana', 'dog', 'nana', 'walk', 'walker', 'dogwalker']
        list2 = ['cat', 'dog', 'tree', 'catdog', 'catdogtree', 'catdogxxxxx']
        list3 = ['lol']
        list4 = ['cat', 'cats', 'catsz']
        self.assertEqual(p_17_15.find_longest_combination(list1), 'dogwalker')
        self.assertEqual(p_17_15.find_longest_combination(list2), 'catdogtree')
        self.assertEqual(p_17_15.find_longest_combination(list3), None)
        self.assertEqual(p_17_15.find_longest_combination(list4), None)

    def test_problem_17_21(self):
        histogram1 = [0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 8, 0, 2, 0, 5, 2, 0, 3, 0, 0]
        histogram2 = [5, 0, 0, 0, 1]
        histogram3 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]  # test case from leetcode problem https://leetcode.com/problems/trapping-rain-water/
        self.assertEqual(p_17_21.histogram_volume(histogram1), 46)
        self.assertEqual(p_17_21.histogram_volume(histogram2), 3)
        self.assertEqual(p_17_21.histogram_volume(histogram3), 6)

    def tearDown(self):
        pass


if __name__ == '__main__':
    unittest.main()
