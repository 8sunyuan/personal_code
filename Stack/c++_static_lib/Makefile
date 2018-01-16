CC = g++ -Wall -ggdb 
# CC = g++

all : myStack

## -lm means "math lib"
myStack : 
	${CC} -o $@ Stack.cpp app_main.cpp -I/home/msun/MyCode/linkedlist/c++_static_lib  -lm -L/home/msun/MyCode/linkedlist/c++_static_lib -lysun


clean:
	rm -f *.o *.a *.BAK myStack
