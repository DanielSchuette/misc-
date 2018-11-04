#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 80

int main(void)
{
    int day, month, year;
    char *line, *monthname;
    size_t bufsize = BUFSIZE;

    /* allocate memory for buffers */
    line = (char *)malloc(BUFSIZE * sizeof(char));
    monthname = (char *)malloc(BUFSIZE * sizeof(char));

    /* read and convert user input */
    while (getline(&line, &bufsize, stdin) > 0) {
        if (sscanf(line, "%d/%d/%d", &day, &month, &year) == 3)
            printf("valid: %s\n", line);
        else if (sscanf(line, "%d %79s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line);
        else
            printf("invalid: %s\n", line);
    }

    /* free memory */
    free(line);
    free(monthname);

    return 0;
}
