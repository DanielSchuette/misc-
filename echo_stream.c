/* echo_stream.c takes input from stdio
 * and after a new line character or EOF 
 * signal, that input is returned via stdout
 */
#include <stdio.h>
#define MAXLINE 1000

/* function declarations */
int get_line(char line[], int maxline); /* avoid re-declaring from stdlibc */

int main(int argc, char *argv[])
{
    int c;
    char line[MAXLINE];

    while ((c = get_line(line, MAXLINE)) > 0)
        printf("chars: %d :: %s", c, line);
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0'; /* string delimiter */
    return i;
}
