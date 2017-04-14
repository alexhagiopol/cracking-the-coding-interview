import unittest
from chapter_02_linked_lists import problem_2_4_partition as p_2_4


class Tests(unittest.TestCase):

    def setUp(self):
        pass

    def test_problem_2_4(self):
        n1 = p_2_4.Node(1, None)
        n2 = p_2_4.Node(2, n1)
        n10 = p_2_4.Node(10, n2)
        n5_1 = p_2_4.Node(5, n10)
        n8 = p_2_4.Node(8, n5_1)
        n5_0 = p_2_4.Node(5, n8)
        n3 = p_2_4.Node(3, n5_0)
        new_head = p_2_4.partition(n3, 5)
        string_representation = ''
        while new_head is not None:
            string_representation += str(new_head.value)
            new_head = new_head.next_node
        self.assertEqual(string_representation, '12358510')

    def tearDown(self):
        pass

if __name__ == '__main__':
    unittest.main()