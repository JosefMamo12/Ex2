CC=gcc 
FLAGS= -Wall -g
AR= ar


all:mains

mains: main.o myBanks
	$(CC) $(FLAGS) -o mains main.o libmyBank.a

myBanks: myBank.o 
	$(AR) -rcs -o libmyBank.a myBank.o

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY:clean all	

clean:
	-rm *o mains libmyBank.a