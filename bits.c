#include <stdio.h>
#define TEST_NUMBER 17

/* function declarations */
unsigned int bit_count(int);

int main(void)
{
    unsigned int res; /* holds the result */
    res = bit_count(TEST_NUMBER);
    printf("on-bits in %d: %u\n", TEST_NUMBER, res);
    return 0;
}

/* bit_count: returns the number of on-bits in `x' */
unsigned int bit_count(int x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}
