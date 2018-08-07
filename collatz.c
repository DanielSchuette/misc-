/*
 * Program that implements the Collatz Conjecture 
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFSIZE 1
#define NUM_ARGS 1

// function declarations
int collatz(int n, int counter);
void clear(void);

// global variables
int buffer[BUFSIZE] = { 0 };

int main(int argc, char *argv[]) {
    // check validity of inputs
    if (argc != NUM_ARGS) {
        printf("wrong number of arguments\nusage: ./collatz\n");
        return 1;
    }
    // ask user for input
    do { 
        printf("input a positive integer: ");
        scanf("%i", &buffer[0]);
        clear();
    } while (buffer[0] <= 0);
    printf("result: %i\n", collatz(buffer[0], 0));
    return 1;
}

// clear() removes a user's typeahead from stdio input stream
void clear(void) {
    int ch;
    while (((ch = getchar()) != '\n') && (ch != EOF)) {
        /* discard*/ ;
    }
}

// collatz() calculates the collatz conjecture for an integer input n
int collatz(int n, int counter) {
    // base case of n being 1
    if (n == 1) {
        return counter;
    }

    // increment counter
    counter++;

    // if base case is not true, return recursive call with incremented counter
    if ((n % 2) == 0) {
        return collatz((n/2), counter);
    } else {
        return collatz(((3*n)+1), counter);
    }
    // something went wrong
    return 0;
}
