# Makefile for Arithmetic Operations

# Compiler
CC = gcc

# Source files
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SOURCES:.c=.o)

# Subdirectory for library
LIBDIR = lib

# Compiler flags
CFLAGS = -I$(SRCDIR) -Wall

# Targets
LIBRARY = $(LIBDIR)/libarithmetic.a
EXECUTABLE = main

# Default target
all: $(LIBRARY) $(EXECUTABLE)

# Library target
$(LIBRARY): $(OBJS)
	mkdir -p $(LIBDIR)
	ar rcs $@ $(OBJS)

# Executable target
$(EXECUTABLE): main.c
	$(CC) -o $@ main.c -L$(LIBDIR) -larithmetic

# Clean
clean:
	rm -f $(OBJS) $(LIBRARY) $(EXECUTABLE)

