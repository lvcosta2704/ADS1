# Makefile para compilar main.c e LSE.c
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS :=
LDLIBS :=
TARGET := main
OBJS := main.o LSE.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

# Regras de compilação (main.c e LSE.c dependem de LSE.h)
%.o: %.c LSE.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
