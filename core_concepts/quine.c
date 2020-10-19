/*
 * author: greyshell
 * description: quine programming: a program that display its own source code
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char c;
    // __FILE__ contains the location of this C programming file in a string
    fp = fopen(__FILE__, "r");
    if (fp == NULL) {
        printf("cannot open file \n");
        exit(0);
    }

    // read contents from file
    c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);
    return 0;
}

