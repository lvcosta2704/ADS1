# Makefile para compilar main.c e AED2.c
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS :=
LDLIBS :=
TARGET := main
OBJS := main.o AED2.o
.PHONY: all clean run
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)
# Regras de compilação (main.c e AED2.c dependem de AED2.h)
%.o: %.c AED2.h
	$(CC) $(CFLAGS) -c $<
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
