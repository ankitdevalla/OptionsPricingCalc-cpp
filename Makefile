# Compiler
CXX = g++

# Compiler flags -- Iinclude tells the compiler where to look for header files
# and -Wall -Wextra -std=c++11 are compiler flags for warnings, C++11 standard
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++11

# Target executable
TARGET = OptionsPricingCalculator

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Source files -- wildcard function is used to get all .cpp files in the source directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files -- converts each .cpp file name to the corresponding .o file name.
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Rule to build the target executable -- builds target from object files
# automatic vars: $@ is the target, $^ is the dependencies (object files)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files -- builds object files from source files
# automatic vars: $@ is the target, $< is the first dependency (source file)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: clean