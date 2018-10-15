#include <stdio.h>
#include <string.h>

/* function declarations */
int stringlen(char *s);

int main(int argc, char **argv) {
    /* define two strings for demonstration purposes */
    char *s1 = "hello world";
    char *s2 = "string";

    /* print stdlibs results */
    printf("len s1 (strlen): %lu\n", strlen(s1));
    printf("len s2 (strlen): %lu\n", strlen(s2));

    /* print `stringlen' results */
    printf("len s1 (stringlen): %d\n", stringlen(s1));
    printf("len s2 (stringlen): %d\n", stringlen(s2));
    return 0;
}

/* stringlen returns the length of an input string */
int stringlen(char *s) {
    int res = 0;
    while(*(s+res) != '\0') /* increment until '\0' is reached */
        ++res; 
    return res;
}
