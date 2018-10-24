/*
 * GTK+ example
 * compile with:
 * gcc `pkg-config --cflags gtk+-2.0` -o example mygtk.c `pkg-config --libs gtk+-2.0`
 */
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkWidget *window;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}
