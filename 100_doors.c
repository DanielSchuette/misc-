#include <stdio.h>

#define NUM_DOORS 100
#define TRUE 1
#define FALSE 0

int main(void)
{
    int pass;
    int doors[100];

    for (int i = 0; i < NUM_DOORS; i++)
        doors[i] = TRUE; /* at pass 1, all doors are opened */

    for (pass = 2; pass <= NUM_DOORS; pass++) /* make (NUM_DOOR-1) more passes */
        for (int door = pass; door <= NUM_DOORS; door += pass)
            doors[door-1] = !doors[door-1]; /* open closed door and vice versa */

    for (int i = 0; i < NUM_DOORS; i++) /* print open doors */
        if (doors[i] == TRUE)
            printf("%d ", i+1);

    printf("\n");

    return 0;
}
