/*
 * author: greyshell
 * description: random experiment
 * */

#include <stdio.h>
#include <math.h>
#include <z3.h>

typedef struct {
    bool type;  // non zero -> max heap
    size_t size;
    size_t initial_capacity;
    size_t current_capacity;
    int *data_arr;
} heap;

int main(void) {
    size_t b = 5;
    heap h;

    printf("floor = %d\n", h.type);

    printf("floor = %zu\n", (size_t) floor((double) b / 2));


    return 0;
}
