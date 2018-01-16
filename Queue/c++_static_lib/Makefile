CC = g++  
CFLAGS = -Wall -ggdb
INCLUDE_PATH = /home/msun/MyCode/linkedlist/c++_static_lib 
LIB_PATH = /home/msun/MyCode/linkedlist/c++_static_lib
STATIC_LIB = ysun
DYNAMIC_LIB = ysundll
SRC = Queue.cpp \
	app_main.cpp

all: myQueue queue_dynamic

## -lm means "math lib"
myQueue :
	${CC} ${CFLAGS} -o $@ ${SRC} -I${INCLUDE_PATH} -lm -L${LIB_PATH} -l${STATIC_LIB}

queue_dynamic :
	${CC} ${CFLAGS} -o $@ ${SRC} -I${INCLUDE_PATH} -lm -L${LIB_PATH} -l${DYNAMIC_LIB} -Wl,-R${LIB_PATH}

clean:
	rm -f *.o *.a *.BAK *.so myQueue queue_dynamic
