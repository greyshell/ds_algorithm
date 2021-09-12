#!/usr/bin/env python3
# author: greyshell


def balance_bracket(arr):
    # create a stack
    s = list()

    for i in range(0, len(arr)):
        if arr[i] == '(':
            s.append(')')

        elif arr[i] == ')':
            if len(s) != 0:
                out = s[-1]
                if out == ')':
                    s.pop()
            else:
                s.append('(')

    if len(s) == 0:
        return True

    return False


def main():
    # sample test case
    arr = ['(', ')']
    result = balance_bracket(arr)
    print(f"{result}")


if __name__ == '__main__':
    main()
