/*
 * author: greyshell
 * description: implementation of sorting algorithms
 * */

#include <stdio.h>

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
    
    printf("%zu", sizeof(a));
    return 0;
}

