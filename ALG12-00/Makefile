# Makefile para compilar main.c e LinkedList.c
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS :=
LDLIBS :=
TARGET := main
OBJS := main.o LinkedList.o
.PHONY: all clean run
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)
# Regras de compilação (main.c e LinkedList.c dependem de LinkedList.h)
%.o: %.c LinkedList.h
	$(CC) $(CFLAGS) -c $<
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
