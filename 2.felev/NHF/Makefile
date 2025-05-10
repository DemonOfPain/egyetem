# Makefile for Filmtár project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++11

# Source files
SOURCES = main.cpp application.cpp filmManager.cpp film.cpp familyFilm.cpp documentaryFilm.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = filmManager.o film.o familyFilm.o documentaryFilm.o

# Executable names
EXECUTABLE = filmtar

# Default target
all: $(EXECUTABLE) $(TEST_EXECUTABLE)

# Main program
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE) $(TEST_EXECUTABLE)

# Dependencies
main.o: main.cpp application.h
application.o: application.cpp application.h filmManager.h
filmManager.o: filmManager.cpp filmManager.h film.h familyFilm.h documentaryFilm.h
film.o: film.cpp film.h
familyFilm.o: familyFilm.cpp familyFilm.h film.h
documentaryFilm.o: documentaryFilm.cpp documentaryFilm.h film.h

# Phony targets
.PHONY: all clean