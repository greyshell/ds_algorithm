/*
 * author: greyshell
 * description: tests program
 * # create linux binary in cmake-build-debug directory
 * make -f create_binary_from_lib PROG=test_foo LIB=foo build-linux
 * */

#include <stdio.h>
#include "../liquid_oxygen/foo/foo.h"

int main(void)
{
    printf("this is a tests for custom libs \n");
    foo();
    return 0;
}