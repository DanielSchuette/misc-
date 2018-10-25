#include <stdio.h>
#include "misc.h"

int main(void)
{
    int x, y;
    x = 5, y = 1;
    printf("swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("swap: x = %d, y = %d\n", x, y);
}

/* swap: swap values of `a' and `b' */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
