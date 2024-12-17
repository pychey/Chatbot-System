# Define compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./include

# Define the output executable
TARGET = build/bot

# Define source files and object files (recursive)
SRC = $(wildcard src/Cpp-Files/*.cpp src/Cpp-Files/*/*.cpp)
OBJ = $(patsubst src/Cpp-Files/%.cpp, build/%.o, $(SRC))

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile source files into object files
build/%.o: src/Cpp-Files/%.cpp
	@mkdir -p $(dir $@)   
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf build $(TARGET)
