/* get_time.c: use the system locale to print date & time. */
#include <langinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STRLEN 128

int main(void)
{
    char outstr[STRLEN];
    char *fmt;
    time_t t;
    struct tm *tm;
    nl_item item;

    /* get time and date */
    t = time(NULL);
    tm = localtime(&t);

    /* get a date & time format string via locale */
    item = D_T_FMT;
    fmt = nl_langinfo(item);

    /* print date & time to a buffer and to the screen */
    strftime(outstr, sizeof(outstr), fmt, tm);
    fprintf(stderr, "%s\n", outstr);

    return 0;
}
