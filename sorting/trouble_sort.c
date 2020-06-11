/*
 * author: greyshell
 * description: https://codeforces.com/contest/1365/problem/B
 * */

#include <stdio.h>
#include "stdbool.h"

bool is_sorted(int arr[], size_t length){
    bool is_swapped = false;
    for (int j = length - 1; j > 0; j--) {
        // if the right element is smaller than the left element then perform swap
        if (arr[j] < arr[j - 1]) {
            is_swapped = true;
        }
    }
    if (is_swapped == false) {
        // no swap occurs inside the loop which means now the array is sorted
        return true;
    }
    return false;
}

bool trouble_sort(int arr[], int arr_type[], size_t length){
    /*
     * time complexity: O(n)
     * space complexity: O(1)
     */
    bool return_type;
    bool type_0_is_present = false;
    bool type_1_is_present = false;

    // case 1: if entire array is already sorted then sort not required
    return_type = is_sorted(arr, length);
    if (return_type == true){
        // array is already sorted so further sorting is not possible
        return 0;
    }
    // case 2: check at least 1 '0' type is present
    for (int i = 0; i < length; i++){
        if (arr_type[i] == 0){
            type_0_is_present = true;
            break;
        }
    }

    // case 2: check at least 1 '1' type is present
    for (int i = 0; i < length; i++){
        if (arr_type[i] == 1){
            type_1_is_present = true;
            break;
        }
    }
    // sorting is possible if at least one both types of elements are present
    if (type_0_is_present == true && type_1_is_present == true){
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    int arr[] = {30, 15, 200, 70, 80};
    int arr_type[] = {0, 1, 1, 0, 0};
    size_t length = 5;
    if (trouble_sort(arr, arr_type, length)){
        printf("sorting possible \n");
    }
    else{
        printf("sorting not possible \n");
    }

    return 0;
}