
CC = g++
BIN = main
BUILD = ./src/obj
OBJS = ${BUILD}/${BIN}.o
SRC = ./src
CFLAGS = -std=c++11
INC = -I/usr/include -I./include
LIB = -L/usr/lib -L/usr/local/lib
LIBS = -lGL -lglut -lGLEW -lglfw3 -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -ldl


${BIN}: ${OBJS}
	${CC} -o ${BIN} ${OBJS} ${INC} ${LIB} ${LIBS} -pthread

${BUILD}/%.o: ${SRC}/%.cpp
	${CC} -c -o $@ $< ${INC} ${CFLAGS} -pthread

clean: 
	rm ${BUILD}/*.o 
	rm ${BIN}