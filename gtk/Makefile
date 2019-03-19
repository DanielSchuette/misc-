# Build gtk projects.
PROG := gtk_04
GTK_VERSION := 2.0

.PHONY: all test clean

all:
	gcc `pkg-config --cflags gtk+-$(GTK_VERSION)` $(PROG).c `pkg-config --libs gtk+-$(GTK_VERSION)` -o $(PROG)

test:
	./$(PROG)

clean:
	rm -f *.o $(PROG)
