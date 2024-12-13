# Define compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./include

# Define the output executable
TARGET = build/my_program

# Define source files and object files
SRC = $(wildcard src/Cpp-Files/*.cpp)
OBJ = $(SRC:src/Cpp-Files/%.cpp=build/%.o)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile source files into object files
build/%.o: src/Cpp-Files/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f build/*.o $(TARGET)
