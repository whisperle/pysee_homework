#include "sort.h"

void merge_sort(int a[], int size);
void mergeSort(int a[], int iLeft, int iRight, int work[]);
void merge(int a[], int iLeftHalfLeft, int iLeftHalfRight,
           int iRightHalfLeft, int iRightHalfRight, int work[]);
void print(const int a[], int iLeft, int iRight);

 
// Sort the given array of size
void merge_sort(int a[], int size) {
   int work[size];  // work space
   mergeSort(a, 0, size - 1, work);
}
 
// Sort the given array in [iLeft, iRight]
void mergeSort(int a[], int iLeft,int iRight, int work[]) {
   if ((iRight - iLeft) >= 1) {   // more than 1 elements, divide and sort
      // Divide into left and right half
      int iLeftHalfLeft = iLeft;
      int iLeftHalfRight = (iRight + iLeft) / 2;   // truncate
      int iRightHalfLeft = iLeftHalfRight + 1;
      int iRightHalfRight = iRight;
 
      // Recursively sort each half
      mergeSort(a, iLeftHalfLeft, iLeftHalfRight, work);
      mergeSort(a, iRightHalfLeft, iRightHalfRight, work);
 
      // Merge two halves
      merge(a, iLeftHalfLeft, iLeftHalfRight, iRightHalfLeft, iRightHalfRight, work);
   }
}
 
// Merge two halves in [iLeftHalfLeft, iLeftHalfRight] and [iRightHalfLeft, iRightHalfRight]
// Assume that iLeftHalfRight + 1 = iRightHalfLeft
void merge(int a[], int iLeftHalfLeft, int iLeftHalfRight,
           int iRightHalfLeft, int iRightHalfRight, int work[]) {
   int size = iRightHalfRight - iLeftHalfLeft + 1;
   int iResult = 0;
   int iLeft = iLeftHalfLeft;
   int iRight = iRightHalfLeft;
   while (iLeft <= iLeftHalfRight && iRight <= iRightHalfRight) {
      if (a[iLeft] <= a[iRight]) {
         work[iResult++] = a[iLeft++];
      } else {
         work[iResult++] = a[iRight++];
      }
   }
   // Copy the remaining left or right into work
   while (iLeft <= iLeftHalfRight) work[iResult++] = a[iLeft++];
   while (iRight <= iRightHalfRight) work[iResult++] = a[iRight++];   
    // Copy the work back to the original array
   for (iResult = 0, iLeft = iLeftHalfLeft; iResult < size; ++iResult, ++iLeft) {
      a[iLeft] = work[iResult];
   }
}