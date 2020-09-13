/*
 * author: greyshell
 */

#include <stdio.h>
#include <z3.h>


bool solution(int arr[], size_t n) {
    /*
     * assuming the array is sorted
     * time complexity: O(n)
     * space complexity: O(1)
     */
    size_t i, j;
    for (i = 0, j = (n / 2); i <= n / 2; i++, j++) {
        if (arr[i] == arr[j]) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int arr[] = {1, 2, 3, 4};
    size_t n = 4;

    printf("output: %d \n", solution(arr, n));

    int arr2[] = {2, 2, 9, 9, 9};
    size_t n2 = 5;
    printf("output: %d  \n", solution(arr2, n2));

    return 0;
}
