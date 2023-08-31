# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -Werror

# Source Files
SRC = main.cpp Bureaucrat.cpp

# Executable Name
EXEC = bureaucrat

# Compile and Link
all: $(EXEC)

$(EXEC):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

# Clean Object Files and Executable
clean:
	rm -f *.o $(EXEC)

# Run Executable
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run