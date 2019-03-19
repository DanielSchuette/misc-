#include <stdio.h>
#include <time.h>
#include <gtk/gtk.h>

GtkWidget *entry;
int random_num;

void button_click(GtkWidget *, gpointer data);

int main(int argc, char **argv)
{
    GtkWidget *window, *box;
    GtkWidget *button;
    GtkWidget *label;
    PangoFontDescription *font;

    // generate a random number
    srand(time(0) * 1000);
    random_num = rand() % 1000 + 1;

    // initialize gtk and set up widgets
    gtk_init(&argc, &argv);
    window = gtk_window_new(0);
    box = gtk_vbox_new(TRUE, 20);
    button = gtk_button_new_with_label("ok");
    label = gtk_label_new("Guess a number between 1 and 1000!");
    entry = gtk_entry_new();

    // modify font and widget sizes
    font = pango_font_description_from_string("Arial 24");
    gtk_widget_modify_font(entry, font);
    gtk_widget_set_size_request(label, 100, 40);
    gtk_widget_set_size_request(entry, 100, 40);
    gtk_widget_set_size_request(button, 100, 60);

    // set up main window
    gtk_window_set_position(GTK_WINDOW(window), 1);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    gtk_window_set_title(GTK_WINDOW(window), "Guess a Number");

    // put widgets into box and box into main window
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    gtk_container_set_border_width(GTK_CONTAINER(window), 25);
    gtk_container_add(GTK_CONTAINER(window), box);

    // associate widgets with callback functions
    g_signal_connect_swapped(GTK_OBJECT(button), "clicked",
            G_CALLBACK(button_click), GTK_OBJECT(label));
    g_signal_connect(GTK_OBJECT(window), "destroy",
            G_CALLBACK(gtk_main_quit), NULL);

    // display all widgets and enter event loop
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

void button_click(GtkWidget *widget, gpointer data)
{
    int guessed = atoi(gtk_entry_get_text(GTK_ENTRY(entry)));

    if (guessed < random_num)
        gtk_label_set_text(GTK_LABEL(widget), "Too small.");
    if (guessed > random_num)
        gtk_label_set_text(GTK_LABEL(widget), "Too large.");
    if (guessed == random_num)
        gtk_label_set_text(GTK_LABEL(widget), "Correct!");
}
