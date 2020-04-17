/*
 * author: greyshell
 * description: quick proof of concept
 * */

#include <stdio.h>
#include <limits.h>
#include "stdbool.h"

struct student {
    int i;
    char ch;
    float f;
};

int main(void){
    bool my_bool;
    int i;
    size_t j;
    unsigned int k;
    long int l;
    long long int m;
    
    printf("\nbool size=%lu", sizeof(my_bool));  // 1 byte
    printf("\nsigned int size=%lu", sizeof(i));  // 4 byte

    printf("\nunsigned int size=%lu", sizeof(k));  // 4 byte
    printf("\nlong int size=%lu", sizeof(l));  // 8 byte
    printf("\nlong long size=%lu", sizeof(m));  // 8 byte
    return 0;
}

