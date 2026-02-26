CC	= gcc
CFLAGS	= -Wall -Wextra -std=c11 -Iinclude
TARGET	= bin/car

SRC	= src/main.c \
	  src/car.c
OBJ	= obj/main.o obj/car.o

all: build_dirs $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build_dirs:
	mkdir -p bin obj

clean:
	rm -rf bin obj
