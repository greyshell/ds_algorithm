/*
 * author: greyshell
 * description: random experiment
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch = '1';
    int i, j;
    j = ch - '0'; // ch - 48 ; char digit to integer digit conversion
    i = (int) ch;  // type casting to get the ascii char
    printf("number = %d \n", j);
    printf("ascii = %d \n", i);
    return 0;
}
