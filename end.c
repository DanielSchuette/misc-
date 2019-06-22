/* end.c: demonstration of endianess and how to deal with it. */
#include <stdio.h>

typedef char byte;

typedef union {
    short w;        /* 16 bytes */
    struct {
        byte l;     /* lower 8 bytes */
        byte h;     /* higher 8 bytes */
    } low;
    struct {
        byte h;
        byte l;
    } high;
} word;

int main(void)
{
    word w;
    w.w = 12;
    printf("low-low: %d\n", w.low.l);
    printf("low-high: %d\n", w.low.h);
    printf("high-low: %d\n", w.high.l);
    printf("high-high: %d\n", w.high.h);
    return 0;
}
