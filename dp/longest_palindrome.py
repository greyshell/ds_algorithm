#!/usr/bin/env python3

# author: greyshell

"""
description:
Given a string, find the longest substring which is palindrome.
For example, if the given string is "forgeeksskeegfor",
the output should be "geeksskeeg".

reference:
https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

"""


def calculate_palindrome(my_string: str, dp_matrix: list, i: int, j: int) -> int:
    """

    :param my_string:
    :param dp_matrix:
    :param i:
    :param j:
    :return:
    """
    # base case scenarios
    if i == j:  # check for 1 char
        dp_matrix[i][j] = 1  # consider 1 char is palindrome
        return 1
    if (i + 1) == j:  # check for 2 chars
        if my_string[i] == my_string[j]:
            dp_matrix[i][j] = 1  # palindrome when both chars are same
        else:
            dp_matrix[i][j] = 0  # not palindrome when both chars are not same
        return dp_matrix[i][j]

    # top down approach: already calculated cases
    if dp_matrix[i][j] != -1:
        return dp_matrix[i][j]

    # consider all cases where string length > = 3 and not evaluated
    is_palindrome = calculate_palindrome(my_string, dp_matrix, (i + 1),
                                         (j - 1))  # check if the sub_string is palindrome
    # check if the 1st and the last char is same and sub_string is also palindrome
    if (my_string[i] == my_string[j]) and is_palindrome:
        dp_matrix[i][j] = 1
    else:
        dp_matrix[i][j] = 0

    return dp_matrix[i][j]


def longest_palindrome(my_string: str) -> str:
    """
    time complexity:
        - O(n^2) -> for the nested loops
        - calculate_palindrome() -> will be n^2 times as it is inside the nested loops
        - but due to the memoization matrix after certain call it will give O(1) complexity

    space complexity:
    for dp_matrix => O(n^2)
    stack call => O(1) => constant
    """
    str_len = len(my_string)

    # initialize a 2d array with -1
    w, h = str_len, str_len
    dp_matrix = [[-1 for y in range(w)] for x in range(h)]
    # objective is to set 1 if the substring(i, j) is palindrome, else set 0

    max_str = ""
    max_len = -1
    for i in range(str_len):
        for j in range(i, str_len):
            is_palin = calculate_palindrome(my_string, dp_matrix, i, j)  # it returns 1 if
            # palindrome
            if is_palin and (j - i + 1) > max_len:  # not consider the case 'a'
                max_len = (j - i) + 1
                max_str = my_string[i:j + 1]  # returns a new string as python strings are immutable

    return max_str


def main():
    # sample test case
    my_string = "abcbde"
    my_string = "forgeeksskeegfor"
    result = longest_palindrome(my_string)
    print(f"[+] largest palindrome: {result}, length: {len(result)}")


if __name__ == '__main__':
    main()
