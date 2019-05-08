# make is a utility that automates compilation
# it is invoked with "make" at the os prompt

OBJS = main.o Graph.o LinkedList.o Queue.o
CC = gcc -g
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o main

main.o : main.c Graph.h
		$(CC) $(CFLAGS) main.c

Graph.o : Graph.c LinkedList.h Queue.h Node.h
		$(CC) $(CFLAGS) Graph.c

LinkedList.o : LinkedList.c Node.h
		$(CC) $(CFLAGS) LinkedList.c

Queue.o : Queue.c Node.h 
		$(CC) $(CFLAGS) Queue.c

clean:
		\rm *.o main