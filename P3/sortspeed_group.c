
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#include "sort.h"

int sortingtimes(void (*f)(int *a, int SIZE), int *a, int SIZE);

int sortingtimes(void (*f)(int *a, int SIZE), int *a, int SIZE)
{
    clock_t start = clock();
    f(a, SIZE);
    double clicks = (double)(clock() - start);
    return (int)clicks;
}

int main()
{
    int SIZE = 0;       //the begin size of array
    int STEP = 5000;    //the step size of array
    const int NUM = 10; // the numbers of test sample

    // Arrays to store time duration of sorting algorithms
    int time_bubble[NUM], time_merge[NUM], time_insertion[NUM], time_quick[NUM];

    //printf("A_size,Bubble\n");

    printf("A_size,Bubble,Merge,Insertion,Quick\n");

    // Performs number iterations
    for (int it = 0; it < NUM; it++)
    {
        // increases the size of array by 10000
        SIZE += STEP;

        int a1[SIZE],a2[SIZE],a3[SIZE],a4[SIZE], v[SIZE];
        srand((unsigned)time(NULL));
        for (int i = 0; i < SIZE; i++)
        {
            v[i] = (int)rand() % (SIZE * 5) + 1;
        };
        
        // 4kinds of sorting
        memcpy(a1, v, sizeof(int) * SIZE);
        time_bubble[it] = sortingtimes(bubble_sort, a1, SIZE);
        memcpy(a2, v, sizeof(int) * SIZE);
        time_merge[it] = sortingtimes(merge_sort, a2, SIZE);
        memcpy(a3, v, sizeof(int) * SIZE);
        time_insertion[it] = sortingtimes(insertion_sort, a3, SIZE);
        memcpy(a4, v, sizeof(int) * SIZE);
        time_quick[it] = sortingtimes(quick_sort, a4, SIZE);
        /*printf("%i, %i\n",
               SIZE,
               //time_bubble[it]);
               time_merge[it]);
        */
        printf("%i, %i, %i, %i, %i\n",
               SIZE,
               time_bubble[it],
               time_merge[it],
               time_insertion[it],
               time_quick[it]      
               );
    }

    return 0;
}