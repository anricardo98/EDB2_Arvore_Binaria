#Makefile for "arvore_B" C++ application
#Created by Andre 19/10/2018

PROG = arvore_B
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o: 
	 $(CC) $(CPPFLAGS) -c main.cpp

clean:
	rm -f *.o arvore_B
