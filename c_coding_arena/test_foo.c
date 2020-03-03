/*
 * author: greyshell
 * description: Quine Programming:
 * A C program that display its own source code
 *
 * # create linux binary in cmake-build-debug directory
 * make -f create_binary_from_custom_lib PROG=test_foo LIB=foo build-linux
 * */

#include <stdio.h>
#include "../private_libs/foo.h"

int main(void)
{
    printf("\nThis is a test for custom shared / static ...");
    foo();
    return 0;
}