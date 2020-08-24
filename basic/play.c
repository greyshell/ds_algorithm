/*
 * author: greyshell
 * description: random experiment
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <z3.h>

int main(void) {
    size_t b = 5;
    printf("floor = %zu\n", b / 2);

    printf("floor = %zu\n", (size_t) floor((double) b / 2));


    return 0;
}
