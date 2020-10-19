/*
 * author: greyshell
 * description: how to use and declare a variadic function
 * */

#include <stdarg.h>
#include <stdio.h>

int add_em_up(int count, ...) {
    va_list arg;
    int i, sum;

    va_start (arg, count);         /* Initialize the argument list. */

    sum = 0;
    for (i = 0; i < count; i++)
        sum += va_arg (arg, int);    /* Get the next argument value. */

    va_end (arg);                  /* Clean up. */
    return sum;
}

int main(void) {
    /* This call prints 16. */
    printf("%d\n", add_em_up(3, 5, 5, 6));

    /* This call prints 55. */
    printf("%d\n", add_em_up(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

    return 0;
}