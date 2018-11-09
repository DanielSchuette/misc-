#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int unsorted[ARRAY_SIZE] = {5, 1, 2, 9, 7, 4, 9, 7, 8, 3};
int sorted[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void isort(int *, int);
void swap(int *, int, int);

int main(void)
{   
    /* sort the arrays */
    isort(unsorted, ARRAY_SIZE);
    isort(sorted, ARRAY_SIZE);

    /* print the sorted arrays to stdout */
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", unsorted[i]);
    printf("\n");

    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", sorted[i]);
    printf("\n");

    return 0;
}
/* isort: sorts an array of a given size in-place */
void isort(int *arr, int size)
{
    int i, j;

    for (i = 1; i < size; i++) {/* iterate over input */
        int temp = i;
        for (j = i-1; j >= 0; j--) /* iterate over sorted part */
            if (arr[temp] < arr[j]) {
                swap(arr, temp, j); /* swap i'th and j'th elements */
                temp--;
            } else {
                break; /* left part of the array is now sorted */
            }
    }
}

void swap(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
