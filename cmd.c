/* cmd: execute a shell command using C */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char cmd[BUFSIZ] = "cat "; /* prepare buffer */

    /* text for buffer overflow */
    if (strlen(argv[0]) > 
            (BUFSIZ - strlen(cmd) - 1))
        fprintf(stderr, "cmd: cannot execute %s\n",
                argv[0]);

    /* execute cmd */
    strcat(cmd, argv[0]);
    strcat(cmd, ".c");
    printf("cmd: executing %s\n", cmd);
    system(cmd);

    return 0;
}
