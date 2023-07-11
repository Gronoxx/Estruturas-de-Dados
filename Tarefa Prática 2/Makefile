CC=g++
CFLAGS=-std=c++11 -Wall -pg
TARGET=programa

BIN_DIR    = ./bin
SRC_DIR    = ./src
OBJ_DIR    = ./obj
INCLUDE_DIR  = ./include

all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${OBJ_DIR}/main.o ${OBJ_DIR}/fat.o ${OBJ_DIR}/fib.o
	${CC} ${CFLAGS} -o ${BIN_DIR}/${TARGET} ${OBJ_DIR}/*.o

${OBJ_DIR}/main.o: ${OBJ_DIR}/fat.o ${OBJ_DIR}/fib.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

${OBJ_DIR}/fat.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/fatorial.cpp -o ${OBJ_DIR}/fat.o

${OBJ_DIR}/fib.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/fibonacci.cpp -o ${OBJ_DIR}/fib.o

	

	
clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}
	rm -f gmon.out

run: all 
	${BIN_DIR}/${TARGET} -f 5
	${BIN_DIR}/${TARGET} -fr 5
	${BIN_DIR}/${TARGET} -b 5
	${BIN_DIR}/${TARGET} -br 5