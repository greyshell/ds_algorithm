/*
 * author: greyshell
 * description: driver program to test the sorting algorithms
 * */

#include <stdio.h>
#include <stdlib.h>
#include "../private_libs/sort.h"


void array_copy(int *dest, int *src, size_t len) {
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
}

void test_counting_sort(int arr[], int *temp_array, size_t len) {
    array_copy(arr, temp_array, len);
    printf("\nbefore counting sort: ");
    display_arr(arr, len);
    int *result_array = (int *) calloc(len, sizeof(int));
    counting_sort(arr, result_array, len);
    printf("\nafter counting sort:  ");
    display_arr(result_array, len);
}

void test_bubble_sort(int *arr, int *temp_array, size_t len) {
    array_copy(arr, temp_array, len);
    printf("\nentered array: ");
    display_arr(arr, len);
    printf("\nafter bubble sort:  ");
    bubble_sort(arr, len);
    display_arr(arr, len);
}

void test_cocktail_sort(int *arr, int *temp_array, size_t len) {
    array_copy(arr, temp_array, len);
    printf("\nentered array: ");
    display_arr(arr, len);
    printf("\nafter cocktail sort:  ");
    cocktail_sort(arr, len);
    display_arr(arr, len);
}


int main(void) {
    int choice;
    size_t len = 0;
    int *arr = NULL, *temp_arr = NULL;

    while (1) {
        printf("\n\n===================");
        printf("\nmenu driven program:");
        printf("\n====================");
        printf("\n1. enter the array elements");
        printf("\n2. display the array elements");
        printf("\n3. bubble sort");
        printf("\n4. cocktail sort");
        printf("\n5. counting sort");
        printf("\n6. selection sort");
        printf("\n7. insertion sort");
        printf("\n8. shell sort");
        printf("\n9. quick sort");
        printf("\n10. merge sort");
        printf("\n11. heap sort");
        printf("\n12. radix sort");
        printf("\n13. bucket sort");
        printf("\n14. tim sort");


        printf("\n10. quit\n");

        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nenter the length of the array: ");
                scanf("%zu", &len);
                if ((int *) arr != NULL && (int *) temp_arr != NULL) {
                    free(arr);
                    free(temp_arr);
                }
                // dynamically creating the array
                arr = (int *) calloc(len, sizeof(int));
                temp_arr = (int *) calloc(len, sizeof(int));

                printf("\nenter the elements in the array: ");
                for (int i = 0; i < len; i++) {
                    scanf("%d", &arr[i]);
                }
                array_copy(temp_arr, arr, len);
                break;
            case 2:
                printf("\nentered array: ");
                display_arr(temp_arr, len);
                break;
            case 3:
                test_bubble_sort(arr, temp_arr, len);
                break;
            case 4:
                test_cocktail_sort(arr, temp_arr, len);
                break;
            case 5:
                test_counting_sort(arr, temp_arr, len);
                break;

            case 10:
                return 0;
            default:
                printf("\nwrong choice");
        }
    }
}
