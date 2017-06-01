import unittest
from chapter_01_arrays_strings import problem_1_1_is_unique as p_1_1
from chapter_01_arrays_strings import problem_1_2_are_permuations as p_1_2
from chapter_01_arrays_strings import problem_1_3_URLify as p_1_3
from chapter_01_arrays_strings import problem_1_4_palindrome_permutation as p_1_4
from chapter_01_arrays_strings import problem_1_5_one_away as p_1_5
from chapter_01_arrays_strings import problem_1_6_string_compression as p_1_6
from chapter_01_arrays_strings import problem_1_7_rotate_matrix as p_1_7
from chapter_01_arrays_strings import problem_1_8_set_zero as p_1_8
from chapter_01_arrays_strings import problem_1_9_string_rotation as p_1_9
from chapter_02_linked_lists import LinkedList as ll
from chapter_02_linked_lists import problem_2_1_remove_dups as p_2_1
from chapter_02_linked_lists import problem_2_3_delete_middle as p_2_3
from chapter_02_linked_lists import problem_2_4_partition as p_2_4
from chapter_02_linked_lists import problem_2_5_sum_lists as p_2_5
from chapter_02_linked_lists import problem_2_8_find_loop as p_2_8
from chapter_03_stacks_queues import Stack
from chapter_03_stacks_queues import Queue
from chapter_04_trees_and_graphs import tree_basics as tb
from chapter_04_trees_and_graphs import problem_4_1_path_exists as p_4_1
from chapter_04_trees_and_graphs import problem_4_2_make_bst as p_4_2
from chapter_04_trees_and_graphs import problem_4_3_make_ll as p_4_3
from chapter_04_trees_and_graphs import problem_4_4_is_balanced as p_4_4
from chapter_04_trees_and_graphs import problem_4_5_validate_BST as p_4_5
from chapter_04_trees_and_graphs import problem_4_6_successor as p_4_6
from chapter_05_bit_manipulation import problem_5_0_convert_binary as p_5_0
from chapter_05_bit_manipulation import problem_5_1_insertion as p_5_1


class Tests(unittest.TestCase):
    def setUp(self):
        pass

    def test_problem_1_1(self):
        s1 = "alex"
        s2 = "aalex"
        self.assertTrue(p_1_1.is_unique(s1))
        self.assertFalse(p_1_1.is_unique(s2))

    def test_problem_1_2(self):
        s1 = "alex"
        s2 = "aalex"
        s3 = "xela"
        self.assertFalse(p_1_2.are_permuations(s1, s2))
        self.assertTrue(p_1_2.are_permuations(s1, s3))

    def test_problem_1_3(self):
        # python strings are immutable, so we use a list of chars to do this "in place"
        # Expect 'Mr. John Smith' -> 'Mr.%20John%20Smith'
        self.assertEqual(['M', 'r', '.', '%', '2', '0', 'J', 'o', 'h', 'n', '%', '2', '0', 'S', 'm', 'i', 't', 'h'],
                         p_1_3.URLify(['M', 'r', '.', ' ', 'J', 'o', 'h', 'n', ' ', 'S', 'm', 'i', 't', 'h']))

    def test_problem_1_4(self):
        # spaces don't matter
        self.assertEqual(True, p_1_4.palindrome_permuation('tact coa'))  # calitalization matters
        self.assertFalse(p_1_4.palindrome_permuation('Tact Coa'))  # capitalization matters
        self.assertFalse(p_1_4.palindrome_permuation('xyz'))

    def test_problem_1_5(self):
        self.assertTrue(p_1_5.one_away('pale', 'ple'))
        self.assertTrue(p_1_5.one_away('pale', 'pale'))
        self.assertTrue(p_1_5.one_away('pale', 'bale'))
        self.assertFalse(p_1_5.one_away('pale', 'bae'))
        self.assertFalse(p_1_5.one_away('alex', 'al'))

    def test_problem_1_6(self):
        self.assertEqual('a2b1c5a3', p_1_6.string_compression('aabcccccaaa'))
        self.assertEqual('alex', p_1_6.string_compression(
            'alex'))  # strings that don't benefit from compression don't get compressed

    def test_problem_1_7(self):
        import numpy as np
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
        import numpy as np
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

    def test_problem_2_1(self):
        n0 = ll.Node(9, None)
        n1 = ll.Node(7, n0)
        n2 = ll.Node(2, n1)
        n3 = ll.Node(5, n2)
        n4 = ll.Node(3, n3)
        n5 = ll.Node(3, n4)
        n6 = ll.Node(7, n5)
        self.assertEqual('7,3,3,5,2,7,9,', ll.stringify_linked_list(n6))
        p_2_1.remove_dups(n6)
        self.assertEqual('7,3,5,2,9,', ll.stringify_linked_list(n6))

    def test_problem_2_1_alternative(self):
        n0 = ll.Node(9, None)
        n1 = ll.Node(7, n0)
        n2 = ll.Node(2, n1)
        n3 = ll.Node(5, n2)
        n4 = ll.Node(3, n3)
        n5 = ll.Node(3, n4)
        n6 = ll.Node(7, n5)
        self.assertEqual('7,3,3,5,2,7,9,', ll.stringify_linked_list(n6))
        p_2_1.remove_dups_alternative(n6)
        self.assertEqual('7,3,5,2,9,', ll.stringify_linked_list(n6))

    def test_problem_2_3(self):
        n1 = ll.Node(1, None)
        n2 = ll.Node(2, n1)
        n10 = ll.Node(10, n2)
        n5 = ll.Node(5, n10)
        string_representation = ''
        head = n5
        p_2_3.delete_middle(n10)
        while head is not None:
            string_representation += str(head.value)
            head = head.next_node
        self.assertEqual(string_representation, '521')

    def test_problem_2_4(self):
        n1 = ll.Node(1, None)
        n2 = ll.Node(2, n1)
        n10 = ll.Node(10, n2)
        n5_1 = ll.Node(5, n10)
        n8 = ll.Node(8, n5_1)
        n5_0 = ll.Node(5, n8)
        n3 = ll.Node(3, n5_0)
        new_head = p_2_4.partition(n3, 5)
        string_representation = ''
        while new_head is not None:
            string_representation += str(new_head.value)
            new_head = new_head.next_node
        self.assertEqual(string_representation, '12358510')

    def test_problem_2_5(self):
        """
        List1: 3 -> 2 -> 4 -> 9 -> NONE
        List2: 1 -> 5 -> 9 -> NONE

         9423
        + 951
        -----
        10374
        """
        # first list
        n14 = ll.Node(9, None)
        n13 = ll.Node(4, n14)
        n12 = ll.Node(2, n13)
        n11 = ll.Node(3, n12)
        # second list
        n23 = ll.Node(9, None)
        n22 = ll.Node(5, n23)
        n21 = ll.Node(1, n22)
        sum_head = p_2_5.sum_lists(n11, n21)
        list_num = ""
        while sum_head is not None:
            list_num = str(sum_head.value) + list_num  # careful to reverse order!
            sum_head = sum_head.next_node
        self.assertEqual(list_num, '10374')

    def test_problem_2_8(self):
        # see problem_2_8_explanation.pdf
        # example #1
        node1_7 = ll.Node(7, None)
        node1_6 = ll.Node(6, node1_7)
        node1_5 = ll.Node(5, node1_6)
        node1_4 = ll.Node(4, node1_5)
        node1_3 = ll.Node(3, node1_4)
        node1_2 = ll.Node(2, node1_3)
        node1_1 = ll.Node(1, node1_2)
        node1_0 = ll.Node(0, node1_1)
        node1_7.next_node = node1_5
        self.assertEqual(p_2_8.find_loop(node1_0), node1_5)

        # example #2
        node2_10 = ll.Node(7, None)
        node2_9 = ll.Node(7, node2_10)
        node2_8 = ll.Node(7, node2_9)
        node2_7 = ll.Node(7, node2_8)
        node2_6 = ll.Node(6, node2_7)
        node2_5 = ll.Node(5, node2_6)
        node2_4 = ll.Node(4, node2_5)
        node2_3 = ll.Node(3, node2_4)
        node2_2 = ll.Node(2, node2_3)
        node2_1 = ll.Node(1, node2_2)
        node2_0 = ll.Node(0, node2_1)
        node2_10.next_node = node2_3
        self.assertEqual(p_2_8.find_loop(node2_0), node2_3)

    def test_stack(self):
        my_stack = Stack.Stack()
        my_stack.push(1)
        my_stack.push(2)
        my_stack.push(3)
        my_stack.push(4)
        test_array = []
        for i in range(4):
            test_array += [my_stack.pop()]
        self.assertEqual(test_array, [4, 3, 2, 1])
        self.assertEqual(my_stack.is_empty(), True)

    def test_queue(self):
        my_q = Queue.Queue()
        my_q.add(1)
        my_q.add(2)
        my_q.add(3)
        my_q.add(4)
        test_array = []
        for i in range(4):
            test_array += [my_q.remove().value]
        self.assertEqual(test_array, [1, 2, 3, 4])
        self.assertTrue(my_q.is_empty())

    def test_problem_4_1(self):
        my_graph = p_4_1.Graph()
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists(my_graph, my_graph.get_node(7), my_graph.get_node(5)), True)
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists(my_graph, my_graph.get_node(3), my_graph.get_node(8)), False)
        p_4_1.reset(my_graph)
        self.assertEqual(p_4_1.path_exists(my_graph, my_graph.get_node(1), my_graph.get_node(8)), True)

    def test_problem_4_2(self):
        my_list = [8, 9, 10, 11, 12, 13, 14]
        root = p_4_2.make_bst(my_list)
        self.assertEqual('11,\n9,13,\n8,10,12,14,\n_,_,_,_,_,_,_,_,\n', tb.stringify_bin_tree(root))

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
        """
        For the purposes of this question, a balanced tree is defined to be a tree
        such that the heights of the two subtrees of any node never differ by more than one.
        """
        '''
        balanced tree:
        root,
        node,leaf,
        leaf,leaf,_,_,
        _,_,_,_,
        '''
        node131 = tb.BinaryNode("leaf", None, None)
        node132 = tb.BinaryNode("leaf", None, None)
        node121 = tb.BinaryNode("node", node131, node132)
        node122 = tb.BinaryNode("leaf", None, None)
        root1 = tb.BinaryNode("root", node121, node122)
        self.assertTrue(p_4_4.is_balanced(root1))
        '''
        unbalanced tree:
        root,
        node,leaf,
        node,leaf,_,_,
        leaf,_,_,_,
        _,_,
        '''
        node241 = tb.BinaryNode("leaf", None, None)
        node231 = tb.BinaryNode("node", node241, None)
        node232 = tb.BinaryNode("leaf", None, None)
        node221 = tb.BinaryNode("node", node231, node232)
        node222 = tb.BinaryNode("leaf", None, None)
        root2 = tb.BinaryNode("root", node221, node222)
        self.assertFalse(p_4_4.is_balanced(root2))

    def test_problem_4_5(self):
        # contstruct a binary tree
        node1 = tb.BinaryNode(1)
        node2 = tb.BinaryNode(2)
        node3 = tb.BinaryNode(3)
        node4 = tb.BinaryNode(4)
        node5 = tb.BinaryNode(5)
        node6 = tb.BinaryNode(6)
        node8 = tb.BinaryNode(8)
        node10 = tb.BinaryNode(10)

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
        node1 = tb.BinaryNodeLP(1)
        node2 = tb.BinaryNodeLP(2)
        node3 = tb.BinaryNodeLP(3)
        node4 = tb.BinaryNodeLP(4)
        node5 = tb.BinaryNodeLP(5)
        node6 = tb.BinaryNodeLP(6)
        node8 = tb.BinaryNodeLP(8)
        node10 = tb.BinaryNodeLP(10)

        node1.parent = node2
        node3.parent = node2
        node2.parent = node4
        node5.parent = node6
        node6.parent = node4
        node4.parent = node8
        node10.parent = node8

        node8.left = node4
        node8.right = node10
        node4.left = node2
        node4.right = node6
        node2.left = node1
        node2.right = node3
        node6.left = node5

        self.assertEqual(node8, p_4_6.successor(node6))
        self.assertEqual(node5, p_4_6.successor(node4))
        self.assertEqual(node3, p_4_6.successor(node2))
        self.assertEqual(None, p_4_6.successor(node10))

    def test_problem_5_0(self):
        self.assertEqual(p_5_0.convert_to_base2(122), '1111010')
        self.assertEqual(p_5_0.convert_to_base(255, 10, 16), 'ff')
        self.assertEqual(p_5_0.convert_to_base('11110100', 2, 16), 'f4')

    def test_problem_5_1(self):
        self.assertEqual(p_5_1.insertion('10000000000', '10011', 2, 6), '10001001100')

    def tearDown(self):
        pass


if __name__ == '__main__':
    unittest.main()
