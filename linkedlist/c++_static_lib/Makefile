CC = g++ -Wall -ggdb 
# CC = g++

all : linkedlist linkedlist_dynamic

## -lm means "math lib"
linkedlist : libysun
	${CC} -o $@ app_main.cpp  -lm -L/home/msun/MyCode/linkedlist/c++_static_lib -lysun

## -Wl,-R/path-to-dll  tells the linked where is the dll library to find at run time
linkedlist_dynamic: libysundll
	${CC} -o $@ app_main.cpp  -lm -L/home/msun/MyCode/linkedlist/c++_static_lib -lysundll -Wl,-R/home/msun/MyCode/linkedlist/c++_static_lib

## generating static libary
libysun: linkedlist.o 
	ar rsv libysun.a linkedlist.o

## generating dynamic library
libysundll: linkedlist.o
	${CC} -shared linkedlist.o -o libysundll.so

	## -fPIC --- Position Independent Code (PIC)
linkedlist.o: 
	${CC} -c -fPIC -o $@ linkedlist.cpp

clean:
	rm -f *.o *.a *.BAK *.so linkedlist linkedlist_dynamic
