# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Directories
BIN_DIR = bin

# Target executable name
TARGET = $(BIN_DIR)/program.exe

# Source files
SOURCES = $(wildcard *.c)

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Default target - this will run when you just type 'make'
.DEFAULT_GOAL := build

# Build target
build: $(BIN_DIR) $(TARGET)

# Create bin directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Linking rule
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f *.o

# Run the program
run: build
	./$(TARGET)

# Clean everything, build, and run
rebuild: clean build run

# Build, run, then clean
runclean: build run clean

# Phony targets
.PHONY: build clean run rebuild runclean