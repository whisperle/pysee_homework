#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include "sort.h"

void sortingtimes(void (*f)(int a[], int SIZE), char *sortname, int a[], int SIZE);

void sortingtimes(void (*f)(int a[], int SIZE), char *sortname, int a[], int SIZE)
{
  clock_t start = clock();

  f(a, SIZE);

  double sec = (double)(clock() - start) / CLOCKS_PER_SEC;
  printf("\n");
  //print(a, 0, 20);
  printf("\n\tThe %s take %.6f s on %d size\n", sortname, sec, SIZE);
}

int main()
{
  const int SIZE = 100000;
  int *v;
  v = (int *)malloc(sizeof(int) * SIZE);

  srand((unsigned)time(NULL));
  for (int i = 0; i < SIZE; i++)
  {
    v[i] = (int)rand() % (SIZE * 10) + 1;
  };
  //print(v, 0, 20);

  int *a1,*a2,*a3,*a4;
  a1 = (int *)malloc(sizeof(int) * SIZE);
  a2 = (int *)malloc(sizeof(int) * SIZE);
  a3 = (int *)malloc(sizeof(int) * SIZE);
  a4 = (int *)malloc(sizeof(int) * SIZE);
  memcpy(a1,v, sizeof(int) * SIZE);
  sortingtimes(bubble_sort, "bubble sort", a1, SIZE);
  memcpy(a2,v, sizeof(int) * SIZE);
  sortingtimes(merge_sort, "merge sort", a2, SIZE);
  memcpy(a3,v, sizeof(int) * SIZE);
  sortingtimes(insertion_sort, "insertion sort", a3, SIZE);
  memcpy(a4,v, sizeof(int) * SIZE);
  sortingtimes(quick_sort, "quick sort", a4, SIZE);

  //memcpy(a,v sizeof(int) * SIZE);
  //sortingtimes(mergeSort, "merge sort", a, SIZE);

  free(v);
  free(a1);
  free(a2);
  free(a3);
  free(a4);
  return EXIT_SUCCESS;
}
