/*
 * a simple program that demonstrates stdio's 
 * `scanf' and `printf' functions and `malloc' 
 * for memory allocation
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* prompt user for input, allocate memory for
     two integers and return sum of input values */
    int *in1, *in2;
    printf("please provide an integer input: ");
    in1 = malloc(sizeof(int));
    in2 = malloc(sizeof(int));
    scanf("%d", in1);
    printf("and a second integer, please: ");
    scanf("%d", in2);
    printf("first input: %d\nsecond input: %d\nsum: %d\n",
            *in1, *in2, (*in1)+(*in2));

    /* free the memory that was allocated for `in1' 
     and `in2' and return exit status success */
    free(in1);
    free(in2);
    return 0;
}
