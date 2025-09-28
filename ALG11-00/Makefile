# Makefile para compilar main.c e Queue.c
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS :=
LDLIBS :=
TARGET := main
OBJS := main.o Queue.o
.PHONY: all clean run
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)
# Regras de compilação (main.c e Queue.c dependem de Queue.h)
%.o: %.c Queue.h
	$(CC) $(CFLAGS) -c $<
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
