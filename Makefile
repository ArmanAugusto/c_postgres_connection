# Variables to control Makefile Operation

CC	 = gcc
CFLAGS	 = -Wall -g
OBJFILES = main.o pg_items.o

# ******************************************
# Targets needed to bring the executable up to date

PostgresConnection: main.o pg_items.o
	$(CC) $(CFLAGS) -o PostgresConnection main.o pg_items.o -I/usr/include/postgresql -lpq

main.o: main.c pg_items.h
	$(CC) $(CLFLAGS) -c main.c -I/usr/include/postgresql -lpq

pg_items.o: pg_items.h

clean:
	rm -f $(OBJFILES) *~
