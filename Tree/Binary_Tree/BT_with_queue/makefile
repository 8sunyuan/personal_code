CC = g++  
# CFLAGS = -Wall -ggdb
CFLAGS = -ggdb
#INCLUDE_PATH = /home/msun/MyCode/linkedlist/c++_static_lib 
#LIB_PATH = /home/msun/MyCode/linkedlist/c++_static_lib
#STATIC_LIB = ysun
#DYNAMIC_LIB = ysundll
SRC = binaryTree.cpp \
	linkedlist.cpp \
	Stack.cpp \
	Queue.cpp \
	app_main.cpp

all: binaryTree

## -lm means "math lib"
binaryTree :
	${CC} ${CFLAGS} -o $@ ${SRC}
#${CC} ${CFLAGS} -o $@ ${SRC} -I${INCLUDE_PATH} -lm -L${LIB_PATH} -l${STATIC_LIB}

clean:
	rm -f *.o *.a *.BAK *.so binaryTree
