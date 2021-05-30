#include"sort.h"
 
void quick_sort(int a[], int size);
void quickSort(int a[], int left, int right);
void choosePivot(int a[], int left, int right);
 int partition(int a[], int left, int right);
 
// Sort the given array of size
void quick_sort(int a[], int size) {
   quickSort(a, 0, size - 1);
}
 
// Sort the given array in [left, right]
void quickSort(int a[], int left, int right) {
   if ((right - left) >= 1) {   // more than 1 elements, need to sort
      choosePivot(a, left, right);
      int pivotIndex = partition(a, left, right);
      quickSort(a, left, pivotIndex -  1);
      quickSort(a, pivotIndex + 1, right);
   }
}
 
// Choose a pivot element and swap with the right
void choosePivot(int a[], int left, int right) {
   int pivotIndex = (right + left) / 2;
   int temp;
   temp = a[pivotIndex];
   a[pivotIndex] = a[right];
   a[right] = temp;
}

 int partition(int a[], int left, int right) {
   int pivot = a[right];
   int temp;  // for swapping
   int storeIndex = left;
      // Start the storeIndex from left, swap elements smaller than
      //  pivot into storeIndex and increase the storeIndex.
      // At the end of the pass, all elements up to storeIndex are
      //  smaller than pivot.
   for (int i = left; i < right; ++i) {  // exclude pivot
      if (a[i] < pivot) {
         // for tracing
         //print(a, left, right);
 
         if (i != storeIndex) {
            temp = a[i];
            a[i] = a[storeIndex];
            a[storeIndex] = temp;
         }
         ++storeIndex;

      }
   }
   // Swap pivot and storeIndex
   a[right] = a[storeIndex];
   a[storeIndex] = pivot;
   return storeIndex;
}