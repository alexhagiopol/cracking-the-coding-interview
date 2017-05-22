import unittest
from chapter_01_arrays_strings import problem_1_1_is_unique as p_1_1
from chapter_02_linked_lists import LinkedList as ll
from chapter_02_linked_lists import problem_2_4_partition as p_2_4
from chapter_02_linked_lists import problem_2_5_sum_lists as p_2_5
from chapter_03_stacks_queues import Stack
from chapter_03_stacks_queues import Queue
from chapter_05_bit_manipulation import problem_5_0_convert_binary as p_5_0


class Tests(unittest.TestCase):

    def setUp(self):
        pass

    def test_is_unique(self):
        s1 = "alex"
        s2 = "aalex"
        self.assertEqual(p_1_1.is_unique(s1), True)
        self.assertEqual(p_1_1.is_unique(s2), False)

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
        self.assertEqual(my_q.is_empty(), True)

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

    def test_problem_5_0(self):
        self.assertEqual(p_5_0.convert_to_base2(122), '1111010')

    def tearDown(self):
        pass

if __name__ == '__main__':
    unittest.main()