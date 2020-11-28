/*
 * author: greyshell
 * description: find kth largest elements in an immutable heap
 * */

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "../libO2/include/binary_heap_dynamic_array_int.h"



int main(void) {
    int arr[] = {17, 7, 16, 2, 3, 15, 14};
    int n = 7;
    // build the immutable heap
    heap immutable_h;
    build_heap(&immutable_h, true, arr, 7);
    return 0;
}