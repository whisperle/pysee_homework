#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void bubble_sort(int a[], int size);
    void merge_sort(int a[],int size);
    void insertion_sort(int a[],int size);
    void quick_sort(int a[],int size);

    void print(const int a[], int iMin, int iMax);

#ifdef __cplusplus
}
#endif

#endif