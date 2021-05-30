#include "sort.h"

void insertion_sort(int a[], int size);
void print(const int a[], int iMin, int iMax);

// Sort the given array of size using insertion sort
void insertion_sort(int a[], int size)
{
   int temp; // for shifting elements
   for (int i = 1; i < size; ++i)
   {
      /*// for tracing
      print(a, 0, i - 1);    // already sorted
      print(a, i, size - 1); // to be sorted
      printf('\n');
        */
      // For element at i, insert into proper position in [0, i-1]
      //  which is already sorted.
      // Shift down the other elements
      for (int prev = 0; prev < i; ++prev)
      {
         if (a[i] < a[prev])
         {
            // insert a[i] at prev, shift the elements down
            temp = a[i];
            for (int shift = i; shift > prev; --shift)
            {
               a[shift] = a[shift - 1];
            }
            a[prev] = temp;
            break;
         }
      }
   }
}