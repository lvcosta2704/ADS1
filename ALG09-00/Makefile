# Makefile para compilar main.c e LSD.c
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS :=
LDLIBS :=
TARGET := main
OBJS := main.o LSD.o
.PHONY: all clean run
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)
# Regras de compilação (main.c e LSD.c dependem de LSD.h)
%.o: %.c LSD.h
	$(CC) $(CFLAGS) -c $<
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
