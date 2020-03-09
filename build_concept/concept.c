/*
 * author: greyshell
 * description: implementation of sorting algorithms
 * */

#include <stdio.h>
#include <limits.h>

struct student {
    int i;
    char ch;
    float f;
};

int main(void){
    struct student a;
    a.i = 4;
    a.ch = 'a';
    a.f = 2.4;
    int i = INT_MIN;
    int j = INT_MAX;
    
    printf("%d %d", i, j);
    return 0;
}

