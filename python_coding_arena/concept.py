#!/usr/bin/env python3

# author: greyshell
# description: proof of concept code


def main():
    for i in range(0, 10, 1):
        print(f"{i}")
        if i == 2:
            break
    else:
        print(f"hello")
    print(f"asinha")
    # end of main


if __name__ == '__main__':
    main()
