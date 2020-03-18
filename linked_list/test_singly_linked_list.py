#!/usr/bin/env python3

# author: greyshell

import unittest
# added private_libs as "content" root / "Project Sources and Headers"
from singly_linked_list import SinglyLinkedList


class TestSolution(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        """
        optional:
        - run one time before staring the test
        - can be used to populate a database to set up testing
        """
        pass

    def setUp(self):
        """
        optional:
        - run this before every single test function
        - can be used to add files to a directory / set variables
        """
        self.single_linkedlist = SinglyLinkedList()

    # ------------------- test methods --------------------- #

    def test_append(self):
        self.single_linkedlist.append(3)
        self.single_linkedlist.append(4)

        # assertEqual(expect, actual)
        self.assertEqual("[3, 4]", str(self.single_linkedlist))  # self.single_linkedlist calls
        # __repr__ function

    def test_prepend(self):
        self.single_linkedlist.prepend(2)
        self.single_linkedlist.prepend(1)
        self.single_linkedlist.prepend(0)

        # assertEqual(expect, actual)
        self.assertEqual("[0, 1, 2]", str(self.single_linkedlist))

    def test_reverse(self):
        self.single_linkedlist.append(2)
        self.single_linkedlist.append(3)
        self.single_linkedlist.append(4)
        self.single_linkedlist.append(5)

        self.single_linkedlist.reverse()

        # assertEqual(expect, actual)
        self.assertEqual("[5, 4, 3, 2]", str(self.single_linkedlist))

    def test_recursive_reverse(self):
        self.single_linkedlist.append(2)
        self.single_linkedlist.append(3)
        self.single_linkedlist.append(4)
        self.single_linkedlist.append(5)

        self.single_linkedlist.recursive_reverse()

        # assertEqual(expect, actual)
        self.assertEqual("[5, 4, 3, 2]", str(self.single_linkedlist))

    def test_find(self):
        self.single_linkedlist.append(3)
        self.single_linkedlist.append(4)

        # assertEqual(expect, actual)
        self.assertEqual("3", str(self.single_linkedlist.find(3)))

    def test_remove(self):
        self.single_linkedlist.append(3)
        self.single_linkedlist.append(4)
        self.single_linkedlist.append(5)
        self.single_linkedlist.append(3)

        self.single_linkedlist.remove(3)

        # assertEqual(expect, actual)
        self.assertEqual("[4, 5, 3]", str(self.single_linkedlist))  # remove the first element

    def test_remove_all(self):
        self.single_linkedlist.append(3)
        self.single_linkedlist.append(4)
        self.single_linkedlist.append(5)
        self.single_linkedlist.append(3)

        self.single_linkedlist.remove_all()
        self.assertEqual("[]", str(self.single_linkedlist))

    # ------------------- test methods --------------------- #

    def tearDown(self):
        """
        optional
        - it runs automatically after every single test function is executed
        - can be used to delete files from directory those created during testing / unset variables
        """
        self.single_linkedlist.remove_all()

    @classmethod
    def tearDownClass(cls):
        """
        optional ->
        can be used to clean up the database to start other testing from clean state
        """
        pass


if __name__ == '__main__':
    unittest.main()
