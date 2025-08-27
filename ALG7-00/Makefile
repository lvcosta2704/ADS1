# Makefile para compilar main.c e Ponto.c
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
LDLIBS = -lm
TARGET = main
OBJS = main.o Ponto.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDLIBS)

main.o: main.c Ponto.h
	$(CC) $(CFLAGS) -c main.c

Ponto.o: Ponto.c Ponto.h
	$(CC) $(CFLAGS) -c Ponto.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
