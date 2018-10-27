/* 
 * American currency exchange problem 
 */
#include <stdio.h>
#include <stdlib.h>

#define DOLLAR  100
#define QUARTER 25
#define DIME    10
#define NICKEL  5
#define PENNY   1

int main(int argc, char *argv[])
{
    /* declare/initialize variables */
    int amount;
    int remainder;
    int dollar = 0;
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;

    /* check input validity and get amount */
    if (argc < 2) {
        puts("change: provide an amount as an argument");
        return 1;
    }
    amount = atoi(argv[1]);
    if (amount < 1) {
        puts("change: provide a valid amount in pennies as an argument");
        return 1;
    }

    /* calculate change */
    dollar = amount / DOLLAR;
    remainder = amount % DOLLAR;
    quarter = remainder / QUARTER;
    remainder = remainder % QUARTER;
    dime = remainder / DIME;
    penny = remainder % DIME;
    printf("you get %d dollars, %d quarters, %d dimes, %d nickel, and %d pennies\n",
            dollar, quarter, dime, nickel, penny);
    return 0;
}
