CC = g++

CFLAGS = -Wall -g

all: main

main: main.o
	$(CC) $(CFLAGS) main.o -o main

main.o: main.cpp f_lab2_sequence.h f_lab2_arraysequence.h f_lab2_dynamicarray.h f_lab2_linkedlist.h f_lab2_linkedlistsequence.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -rf *.o main
