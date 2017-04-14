import unittest
import importlib

class Tests(unittest.TestCase):

    def setUp(self):
        pass

    def test_problem_2_4(self):
        problem_2_4 = importlib.import_module("02_linked_lists/2.4_partition.py")
        n1 = problem_2_4.Node(1, None)
        n2 = problem_2_4.Node(2, n1)
        n10 = problem_2_4.Node(10, n2)
        n5_1 = problem_2_4.Node(5, n10)
        n8 = problem_2_4.Node(8, n5_1)
        n5_0 = problem_2_4.Node(5, n8)
        n3 = problem_2_4.Node(3, n5_0)
        new_head = problem_2_4.partition(n3)
        string_representation = ''
        while new_head is not None:
            string_representation += str(new_head.value)
        self.assertEqual(string_representation, '12358510')

    def tearDown(self):
        pass

if __name__ == '__main__':
    unittest.main()