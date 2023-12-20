CC=gcc
CFLAGS=-I.

test: test.o server.o
	$(CC) -o test test.o server.o