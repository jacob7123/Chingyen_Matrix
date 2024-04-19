# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Build targets
TARGET = main
SRC = Chingyen_Huang_main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# To generate object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJ)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Prevent Make from doing something with a file named 'clean' or 'run'
.PHONY: clean run
