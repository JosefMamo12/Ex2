CC=gcc 
FLAGS= -Wall -g
AR= ar


all:mains

mains: myBank.o  mains.o
	$(AR) -rcs -o Ex2.a myBank.o  mains.o

main.o: main.c myBank.h 
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY:clean all	

clean:
	-rm *o  