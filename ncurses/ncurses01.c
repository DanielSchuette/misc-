/*
 * ncurses hello world example. Compile with:
 * $gcc -lncurses ncurses01.c -o prog
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

int main(int argc, char **argv) {
    WINDOW * mainwin;

    /*  initialize ncurses  */
    if ((mainwin = initscr()) == NULL) {
	    fprintf(stderr, "%s: error initialising ncurses.\n", argv[0]);
	    exit(1);
    }

    /*
     * Display text in the centre of the screen, call refresh() 
     * to show changes, and sleep to get the full screen effect.
     */
    mvaddstr(13, 33, "Hello, ncurses");
    refresh();
    sleep(3);

    /*  clean up */
    delwin(mainwin);
    endwin();
    refresh();

    return 0;
}
