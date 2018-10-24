#include <gtk/gtk.h>
#include <time.h>

/* function declarations */
void my_wait(unsigned int);

int main(int argc, char *argv[])
{
    GtkWidget *window; /* holds the main window (widget) */

    /* initialize gtk+ */
    gtk_init(&argc, &argv);

    /* create a new window with a title and display it */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Application 02");
    gtk_widget_show(window);
    my_wait(5);
    gtk_widget_hide(window);

    /* start the main loop */
    gtk_main();
    return 0;
}

/* wait: wait for a certain number of seconds */
void my_wait (unsigned int s) {
    unsigned int waitTime = time(0) + s; 
    while (time(0) < waitTime);
}
