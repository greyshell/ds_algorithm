/*
 * author: greyshell
 * */

#ifndef SORT_H__
#define SORT_H__

void display_array(int *arr, size_t n);

void bubble_sort(int *, size_t);

void cocktail_sort(int *, size_t);

void counting_sort(int *, int *, size_t);

void heap_sort(int *, size_t, bool);

void selection_sort(int *, size_t);

void insertion_sort(int *, size_t);

void shell_sort(int *, int);

void quick_sort(int *, int);

void merge_sort(int *, int);

void bucket_sort(int *, int);

void radix_sort(int *, int);

#endif // _SORT_H__
