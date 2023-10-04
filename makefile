# Makefile to compile all .cpp files in the current directory and its subdirectories
# into corresponding .o files and then link them into an executable

# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -pedantic

# Source directory (current directory and its subdirectories)
SRC_DIR := .

# Find all .cpp files in the source directory and its subdirectories
SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp")

# Generate corresponding .o file names for all .cpp files
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

# Define the executable name
EXECUTABLE := ScareCrow.app

# Makefile targets
.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)

rebuild:$(OBJECTS)
	$(RM) $(EXECUTABLE)
	$(CXX) $(CXXFLAGS) $^ -o $(EXECUTABLE)
