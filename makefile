CC := gcc
CFLAGS := -Werror -Wpedantic -Wextra -Werror -g3
CINCLUDE := src

app.exe: linked-list.o main.o
	$(CC) -o app.exe $^

main.o: test/main.c
	$(CC) -c $(CFLAGS) -I $(CINCLUDE) $^

linked-list.o: src/linked-list.c src/linked-list.h
	$(CC) -c $(CFLAGS) -I $(CINCLUDE) $<