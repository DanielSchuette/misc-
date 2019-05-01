# Build gtk projects.
PROG := gtk_04
GTK_VERSION := 2.0
PKG_CONFIG_CFLAGS := `pkg-config --cflags gtk+-$(GTK_VERSION)`
PKG_CONFIG_LIBS := `pkg-config --libs gtk+-$(GTK_VERSION)`

.PHONY: all test clean

all:
	gcc $(PKG_CONFIG_CFLAGS) $(PROG).c $(PKG_CONFIG_LIBS) -o $(PROG)

test:
	./$(PROG)

clean:
	rm -f *.o $(PROG)
