#!/usr/bin/env python3

# author: greyshell
# description: proof of concept code


def main():
    for i in range(0, 10):
        print(f"{i}")
        if i == 4:
            break
    else:
        print(f"hello")
    # end of main


if __name__ == '__main__':
    main()
