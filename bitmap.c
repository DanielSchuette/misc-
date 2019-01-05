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
void set_bit(unsigned char *, unsigned char, long);
unsigned char get_bit(unsigned char *, long);
void print_bits(unsigned char *, long);

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
        set_bit(bitmap, 0, i);
    }
    print_bits(bitmap, MAX_FIELD_NUM);

    /* set all entries to one */
    for (int i = 0; i < MAX_BITMAP_SIZE; i++) {
        set_bit(bitmap, 1, i);
    }
    print_bits(bitmap, MAX_FIELD_NUM);

    /* 
     * TODO: turning off bits doesn't
     * work yet (see below).
     */
    set_bit(bitmap, 0, 43);
    print_bits(bitmap, MAX_FIELD_NUM);

    return 0;
}

void set_bit(unsigned char *bitmap, 
             unsigned char val, long index)
{
    if ((val != 1) && (val != 0))
        return;     /* protect against unreasonable input */

    int idx;                    /* index into the bitmap */
    int pos;                    /* position in bitmap elem */
    int mask;                   /* holds mask for bit shifting */
    int bits_per_field = 8;     /* change if necessary! */
    /*
     * TODO: determine mask with respect to
     * user input, otherwise bits cannot be
     * turned off.
     */
    if (val == 1)
        mask = val;         /* user turns bit on */
    else if (val == 0)
        // TODO                 /* user turns bit off */

    idx = index / bits_per_field; 
    pos = index % bits_per_field;
    mask <<= pos;
    printf("mask=%d, index=%d, pos=%d\n", mask, idx, pos);
    bitmap[idx] |= mask;
}

unsigned char get_bit(unsigned char *bitmap, long index)
{
    int idx;                /* index into the bitmap */
    int pos;                /* position in bitmap elem */
    int mask = 1;           /* probably doesn't change */
    int bits_per_field = 8; /* change if necessary! */

    idx = index / bits_per_field;
    pos = index % bits_per_field;
    mask <<= pos;
    return (unsigned char)(bitmap[idx] & mask);
}

void print_bits(unsigned char *bitmap, long size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", bitmap[i]);
    }
    printf("\n");
}
