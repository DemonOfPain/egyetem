# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Directories
BIN_DIR = bin

# Target executable name (in bin directory)
TARGET = $(BIN_DIR)/program.exe

# Automatically find all .c files in directory
SOURCES = $(wildcard *.c)

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir $(BIN_DIR) 2>nul

# Default target
all: $(BIN_DIR) $(TARGET)

# Linking rule
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule (Windows compatible)
clean:
	del /Q /F *.o 2>nul

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean, build and run
rebuild: clean all run

# Build, run, then clean everything
cleanrun: all clean run

# Phony targets
.PHONY: all clean run rebuild runclean rebuildclean
