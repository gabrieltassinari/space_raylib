CC = gcc

CFLAGS = -Wall -std=c99
INCLUDES = -I lib/
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

SRC = ${wildcard */*.c}
OBJ = ${SRC:.c=.o}

all: space

space: ${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJ} ${LDFLAGS}
run:
	./space

clean:
	rm -f ${OBJ} space

.PHONY: clean
