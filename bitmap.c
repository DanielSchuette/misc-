/*
 * bitmap.c implements a bitmap of unsigned chars that 
 * can be used to store binary-type information efficiently.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITMAP_SIZE     80   /* change if necessary */
#define MAX_FIELD_NUM       ((MAX_BITMAP_SIZE)/8)

/* in an actual implementation, move these to header */
static void set_bit(unsigned char *, unsigned char, long);
static unsigned char get_bit(const unsigned char *, long);
static void print_bits(const unsigned char *, long);

/* global bitmap */
unsigned char *bitmap;

/* 
 * to work with individual bits, one has to make a 
 * large enough char array where every packet of 8 
 * bits (per char) can be indexed and shifted to get 
 * the respective value of the wanted bit.
 * E.g., for bit 67 in array `a':
 * idx = (67 / 32)               // =2 for indexing
 * shft = (67 % 32)              // =3 for shifting
 * return (a[idx] >> shft) & 1   // index, shift & mask
 */

int main(int argc, char **argv)
{
    /* make a bitmap */
    bitmap = (unsigned char *)malloc(MAX_FIELD_NUM);

    /* set all entries to one */
    for (int i = 0; i < MAX_BITMAP_SIZE; i++) {
        set_bit(bitmap, 1, i);
    }
    printf("expect all bit fields to be on:\n");
    print_bits(bitmap, MAX_FIELD_NUM);

    /* set all entries to zero */
    for (int i = 0; i < MAX_BITMAP_SIZE; i++) {
        set_bit(bitmap, 0, i);
    }
    printf("expect all bit fields to be off:\n");
    print_bits(bitmap, MAX_FIELD_NUM);

    /* set single entries to one (zero-indexed) */
    set_bit(bitmap, 1, 0);
    set_bit(bitmap, 1, 8);
    set_bit(bitmap, 1, 37);
    set_bit(bitmap, 1, MAX_BITMAP_SIZE-1);
    print_bits(bitmap, MAX_FIELD_NUM);

    /* check if bits 1, 9, 80 are on */
    printf("expect bits 1, 9, 38, 80 to be on:\n");
    for (int i = 0; i < MAX_BITMAP_SIZE; i++) {
        unsigned char bit;
        if ((bit = get_bit(bitmap, i)) != 0)
            printf("%d: %d\n", i, bit);
    }

    return 0;
}

void set_bit(unsigned char *bitmap, 
             unsigned char val, long index)
{
    if ((val != 1) && (val != 0))
        return;     /* protect against unreasonable input */

    int idx;                    /* index into the bitmap */
    int pos;                    /* position in bitmap elem */
    unsigned char mask = 1;     /* holds mask for bit shifting */
    int bits_per_field = 8;     /* change if necessary! */

    idx = index / bits_per_field; 
    pos = index % bits_per_field;

    if (val == 1) {             /* user turns bit on */
        mask <<= pos;
        bitmap[idx] |= mask;
    } else {                    /* user turns bit off */
        mask <<= pos;
        bitmap[idx] &= (~mask);
    }
}

unsigned char get_bit(const unsigned char *bitmap, long index)
{
    int idx;                /* index into the bitmap */
    int pos;                /* position in bitmap elem */
    int mask = 1;           /* probably doesn't change */
    int bits_per_field = 8; /* change if necessary! */

    idx = index / bits_per_field;
    pos = index % bits_per_field;
    mask <<= pos;
    /*
     * Since the values of the bitmap itself are
     * not shifted to not change the bitmap while
     * getting values, one must be careful not to
     * return values (0, 256].
     */
    return (unsigned char)(bitmap[idx] & mask) > 0 ? 1 : 0;
}

void print_bits(const unsigned char *bitmap, long size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", bitmap[i]);
    }
    printf("\n");
}
