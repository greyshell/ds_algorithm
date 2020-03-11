#!/usr/bin/env python3

# author: greyshell
# description: learning queue


def main():
    # creating the queue using list
    queue = list()
    # insert items into queue
    queue.append(9)
    queue.append(8)
    queue.append(7)
    queue.append(6)
    # FIFO | deleting from queue
    queue.pop(0)
    print(queue)


if __name__ == '__main__':
    main()
