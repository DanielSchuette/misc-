/*
 * Program exploring different debugging strategies
 */
#include <stdio.h>
#include <string.h>

// function declarations
int stringcomp(char *s1, char *s2);

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (stringcomp(argv[1], "--debug")) {
            int debug = 1;
            printf("debugging level %d\n", debug);
        } else {
        printf("don't know this argument: %s\n", argv[1]);
        }
    }
    if (argc > 2) {
        if (stringcomp(argv[2], "--print")) {
            for (int i = 0; i < 100; i++) {
                printf("counter: %d\n", i);
            }
        } else {
            printf("don't know this argument: %s\n", argv[1]);
        }
    }
#ifdef DEBUG
#if (DEBUG > 2)
    printf("debugging...");
#endif
#endif
    printf("done\n");
}

// compares two strings and returns true or false if they are identical or not
int stringcomp(char *s1, char *s2) {
    // compare string length
    if (strlen(s1) != strlen(s2)) {
        return 0;
    }
    for (int i = 0, n = strlen(s1); i < n; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}
