CC = g++ -Wall -ggdb 
# CC = g++

all : linkedlist

## -lm means "math lib"
linkedlist : linkedlist.o app_main.o
	${CC} -o $@ linkedlist.cpp app_main.cpp  -lm

clean:
	rm -f *.o *.a *.BAK linkedlist
