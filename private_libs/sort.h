/*
 * author: greyshell
 * */

#ifndef SORT_H__
#define SORT_H__

#include "singly_linkedlist.h"

void swap(int *, int *);

void display_arr(int [], size_t);

void bubble_sort(int [], size_t);

void cocktail_sort(int [], size_t);

void selection_sort(int [], size_t);

void insertion_sort(int [], size_t);

// singly_linkedlist *insertion_sort_singly_linkedlist(singly_linkedlist *, singly_linkedlist *);

void shell_sort(int [], int);

void quick_sort(int [], int);

void merge_sort(int [], int);

void counting_sort(int [], int [], size_t);

void bucket_sort(int [], int);

void radix_sort(int [], int);

void heap_sort(int [], int);

#endif // _SORT_H__
