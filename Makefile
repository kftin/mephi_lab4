CC = g++

CFLAGS = -Wall -g

all: main

tests.o: tests.cpp f_lab2_linkedlistsequence.h f_lab2_arraysequence.h
	$(CC) $(CFLAFS) -c tests.cpp

main.o: main.cpp f_lab2_sequence.h f_lab2_arraysequence.h f_lab2_dynamicarray.h f_lab2_linkedlist.h f_lab2_linkedlistsequence.h
	$(CC) $(CFLAGS) -c main.cpp

main: main.o tests.o
	$(CC) $(CFLAGS) -o main main.o tests.o -lgtest

clean:
	rm -rf *.o main


#-0fast 
