/*
 * author: greyshell
 * description: quick sort
 *
 *  reference:
 *  https://leetcode.com/problems/kth-largest-element-in-an-array/
 *
 *  description:
 *  Find the kth largest element in an unsorted array.
 *
 *  time complexity:
 *      - worst case: O(n**2)
 *      - average / expected case: O(n) for randomized version
 *  space complexity:
 *      - O(1)
 *      - in-memory sorting
 *      - no extra space is required.
 */

#include <stdio.h>
#include <stdlib.h>


int findKthLargest(int *nums, int numsSize, int k) {
    /*
     * approach:
     * =========
     *
     * time complexity:
     * ================
     *
     * space complexity:
     * =================
     */
    printf("\n");
    return 0;
}

int arr_length;

void display(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

void swap(int arr[], int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int left_index, const int right_index) {
    // randomised version:
    // choose random index as pivot element
    // NOT completed
    int random_index = rand() % arr_length;
    int pivot = arr[random_index];
    int i = left_index - 1;
    int j;

    for (j = left_index; j < right_index; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, right_index);
    return i + 1;
}

int find_kth_smallest(int arr[], int left_index, int right_index, int k_smallest) {
    int expected_position_of_pivot;

    // case 1: invalid range of k
    if (k_smallest < 1 || k_smallest > right_index + 1) {
        return 0;
    }

    expected_position_of_pivot = partition(arr, left_index, right_index);

    if (expected_position_of_pivot == k_smallest - 1) {
        return arr[expected_position_of_pivot];
    } else if (expected_position_of_pivot < k_smallest - 1) {
        return find_kth_smallest(arr, expected_position_of_pivot + 1, right_index, k_smallest);
    } else {
        // case: final_position_of_pivot > k_smallest - 1
        return find_kth_smallest(arr, left_index, expected_position_of_pivot - 1, k_smallest);
    }
}


int main() {
    int arr[] = {12, 3, 10, 7, 4, 11, 2};
    arr_length = 7;
    display(arr, arr_length);

    int k = 7;
    printf("\nwhen n=%d, then %dth smallest element means %dth largest element.", arr_length, k, arr_length - k + 1);
    printf("\nans = %d", find_kth_smallest(arr, 0, arr_length - 1, k));
    return 0;
}