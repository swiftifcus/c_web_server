CC=gcc
CFLAGS=-I. -Wall -Wextra -O0 -g3

test: test.o server.o httprequest.o
	$(CC) -o test test.o server.o httprequest.o