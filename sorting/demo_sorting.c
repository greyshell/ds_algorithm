/*
 * author: greyshell
 * description: quick sort
 */

#include <stdio.h>
#include "../libO2/include/sort_int.h"

int main(void) {
    int arr[] = {4, 3, 2, 1, 0};
    int length = 5;

    printf("input array: \n");
    display_array(arr, length);
    quick_sort(arr, length);
    printf("after sorting: \n");
    display_array(arr, length);

    return 0;
}
