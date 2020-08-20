/*
 * author: greyshell
 * description: quick sort
 */

#include <stdio.h>

void display(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

void swap(int arr[], int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int left_index, int right_index) {
    /*
     * what is pivot: an item that we want to find its home / final position in the sorted array.
     * it can be any item but the we consider best pivot is the median of the array.
     *
     * partition() function splits the array in two halves:
     * items_less_than_pivot | pivot | items_greater_than_pivot
     * partition() return the index (final position) of the pivot element.
     * so whenever the partition() is called, it sorts 1 element i.e the pivot element
     * */
    printf("\ncall to partition() function");
    int pivot = arr[right_index];  // select the last element as pivot
    // i variable will keep track of the "tail" of the section of items less than the pivot so that
    // at the end we can "sandwich" the pivot between the section less than it and the section greater than it
    int i = left_index - 1;

    int j;  // scan from the left boundary to item before the right boundary or the pivot element

    for (j = left_index; j < right_index; j++) {
        // if this item is less than the pivot then it needs to be moved to the section of items less than the pivot
        if (arr[j] < pivot) {
            // move i forward so that we can swap the value at j into the tail of the items less than the pivot
            i++;
            printf("\nj=%d points the element=%d is less than pivot=%d", j, arr[j], pivot);
            printf("\ni=%d points the element=%d, so swap with the element=%d that j=%d points", i, arr[i], arr[j], j);
            swap(arr, i, j);
            printf("\n");
            display(arr, 8);

        }
    }
    // swap the pivot value right after the section of items less than
    // the pivot. i keeps the tail of this section
    swap(arr, i + 1, right_index);
    printf("\nplace the pivot into its home, i+1=%d index:", i + 1);
    printf("\n");
    display(arr, 8);
    printf("\n");
    return i + 1; // return the pivot's actual position in the sorted array
}

void quick_sort(int arr[], size_t left_index, size_t right_index) {
    /*
     * property:
     * =========
     * - recursive implementation
     * - divide rule: split the array in left and right halves based on the index of the pivot
     * element returned by the partition() function.
     * - conquer rule: sort the left and right half of the array through recursion.
     *
     * time complexity:
     * ================
     * best case scenario:
     *  - pivot element is chosen is such a way that splits the array into
     *  two equal halves every time.
     *  - O(n*log(n))
     *
     *  worst case scenario:
     *  - O(n**2), if every time the pivot is chosen is such a way that splits
     *  the array in 1:n-1 or n-1:1.
     *  - when the array is sorted / reversely sorted and if we select
     *  the last / first item as pivot every time.
     *
     *  average / expected case scenario:
     *  - O(n*log(n)) for randomized version, where the pivot element is selected randomly.
     *
     * space complexity:
     * =================
     * worst case scenario:
     * - O(1), in-memory sorting, no extra space is required.
     *
     * */
    printf("\n\nquick_sort() with left_index=%zu, right_index=%zu", left_index, right_index);

    // base case: when array is empty / has only 1 element
    if (left_index == right_index){
        printf("\nno further partition is required !!");
        return;
    }
    // case 1: when array has > 1 element
    // condition: left_index < right_index
    // partition the array into 2 halves
    size_t actual_position_of_pivot_element = partition(arr, left_index, right_index);

    // partition() function returns the actual home of the selected pivot in the sorted array

    // recursively call the same function to solve the left half
    quick_sort(arr, left_index, actual_position_of_pivot_element - 1);

    // recursively call the same function to solve the right half
    quick_sort(arr, actual_position_of_pivot_element + 1, right_index);
    return;
}

int main(void) {
    int arr[] = {4, 6};
    int length = 2;

    printf("\ninput array: ");
    display(arr, length);
    quick_sort(arr, 0, length - 1);  // left_index = 0, right_index = (arr_length - 1)
    printf("\n\nsorted array: ");
    display(arr, length);

    return 0;
}
