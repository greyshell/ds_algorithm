/*
 * author: greyshell
 * description: quick proof of concept
 * */

#include <stdio.h>
#include "stdbool.h"

struct student {
    int i;
    char ch;
    float f;
};

int main(void){
    bool my_bool;
    int i;
    size_t j = 9;
    unsigned int k;
    long int l;
    long long int m;
    struct student s;
    char a;
    float f;
    
    printf("bool size = %lu \n", sizeof(my_bool));  // 1 byte
    printf("signed int size = %lu \n", sizeof(i));  // 4 bytes

    printf("unsigned int size = %lu \n", sizeof(k));  // 4 bytes
    printf("long int size = %lu \n", sizeof(l));  // 8 bytes
    printf("long long size = %lu \n", sizeof(m));  // 8 bytes
    printf("size_t size = %lu \n", sizeof(j));  // 8 bytes

    printf("singed char size = %lu \n", sizeof(a));  // 1 bytes
    printf("signed float size = %lu \n", sizeof(f));  // 4 bytes
    printf("student structure size = %lu \n", sizeof(s)); // 12 bytes
    return 0;
}

