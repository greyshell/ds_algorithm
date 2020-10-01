/*
 * author: greyshell
 * description: driver program to tests different sorting algorithms
 * */

#include <stdio.h>
#include <stdlib.h>
#include <z3.h>
#include "../../liquid_oxygen/sorting/sort.h"


void array_copy(int *dest, int *src, size_t n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void test_heap_sort(int arr[], int *temp_array, size_t n) {
    bool sort_type = true;
    array_copy(arr, temp_array, n);
    printf("original array: \n");
    display_array(arr, n);
    printf("\n");
    heap_sort(arr, n, sort_type); // sort_type = false -> desc | true -> asc
    printf("after heap sort: \n");
    display_array(arr, n);
}

void test_counting_sort(int arr[], int *temp_array, size_t n) {
    array_copy(arr, temp_array, n);
    printf("original array: \n");
    display_array(arr, n);
    printf("\n");
    // create the auxiliary array to store the result
    int *out_array = (int *) calloc(n, sizeof(int));
    counting_sort(arr, out_array, n);
    printf("after counting sort: \n");
    display_array(out_array, n);
}

void test_bubble_sort(int *arr, int *temp_array, size_t n) {
    array_copy(arr, temp_array, n);
    printf("original array: \n");
    display_array(arr, n);
    printf("\n");
    printf("after bubble sort: \n");
    bubble_sort(arr, n);
    display_array(arr, n);
}

void test_cocktail_sort(int *arr, int *temp_array, size_t n) {
    array_copy(arr, temp_array, n);
    printf("original array: \n");
    display_array(arr, n);
    printf("\n");
    printf("after cocktail sort: \n");
    cocktail_sort(arr, n);
    display_array(arr, n);
}


int main(void) {
    size_t choice;
    size_t n = 0;
    int *arr = NULL, *temp_arr = NULL;

    while (1) {
        printf("\n\n");
        printf("=================== \n");
        printf("menu driven program: \n");
        printf("==================== \n");
        printf("0. enter the array elements \n");
        printf("1. display the array elements \n");
        printf("2. bubble sort \n");
        printf("3. cocktail sort \n");
        printf("4. counting sort \n");
        printf("5. selection sort \n");
        printf("6. insertion sort \n");
        printf("7. heap sort \n");
        printf("100. quit \n");


        printf("\n\n");
        printf("enter your choice: \n");
        printf("================== \n");
        scanf("%zu", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("enter the array length: \n");
                scanf("%zu", &n);
                if ((int *) arr != NULL && (int *) temp_arr != NULL) {
                    free(arr);
                    free(temp_arr);
                }
                // dynamically creating the array
                arr = (int *) calloc(n, sizeof(int));
                temp_arr = (int *) calloc(n, sizeof(int));

                printf("enter the elements in the array: \n");
                for (size_t i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                array_copy(temp_arr, arr, n);
                break;
            case 1:
                printf("entered array: \n");
                display_array(temp_arr, n);
                break;
            case 2:
                test_bubble_sort(arr, temp_arr, n);
                break;
            case 3:
                test_cocktail_sort(arr, temp_arr, n);
                break;
            case 4:
                test_counting_sort(arr, temp_arr, n);
                break;
            case 7:
                test_heap_sort(arr, temp_arr, n);
                break;
            case 100:
                return 0;
            default:
                printf("wrong choice \n");
        }
    }
}
