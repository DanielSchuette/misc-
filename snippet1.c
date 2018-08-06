/*
 * Program that prints its first four command line arguments and optionally
 * the name of the compiled program in all capital letters
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFSIZE 1
#define MAX_ARGS 5

// function declarations
void clear(void);

// global variables
char buffer[BUFSIZE];

int main(int argc, char *argv[]) {
    if (argc > MAX_ARGS) {
        printf("too many arguments\nusage: ./main [arg1 arg2 arg3 arg4]\n");
        return 1;
    }
    for (int i = 0; i < argc; i++) {
        printf("%s", argv[i]);    
        printf("\n");
    }
    do { 
        printf("print toupper program name (y/n)? ");
        scanf("%c", buffer);
        clear();
        buffer[0] = tolower(buffer[0]);
    } while ((buffer[0] != 'y') && (buffer[0] != 'n'));

    if (buffer[0] == 'y') {
        int nameLen = strlen(argv[0]);
        char upperName[nameLen+1];
        char *mainName = argv[0];
        for (int i = 0; i < nameLen; i++) {
            upperName[i] = toupper(mainName[i]); 
        }
        upperName[nameLen+1] = '\0';
        printf("%s\n", upperName);
    }
    return 0;
}

// clear() removes a user's typeahead from stdio input stream
void clear(void) {
    int ch;
    while (((ch = getchar()) != '\n') && (ch != EOF)) {
        /* discard*/ ;
    }
}
