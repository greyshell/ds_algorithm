/*
 * author: greyshell
 * description: test foo.c
 * */

#include <stdio.h>
#include "foo.h"

int global_var = 10;

void foo(void){
    extern int global_var;
    printf("Hello, I am foo lib ! \n");
    printf("global_var = %d", global_var);
}