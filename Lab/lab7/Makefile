# Source files
SRCS     = main.cpp \
           BinarySearchTree.cpp

# Object files (automatically derived from SRCS)
OBJS     = $(SRCS:.cpp=.o)

# Final executable name
TARGET   = lab7

# Default rule: build the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Generic rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Optional rule to run the program
run: $(TARGET)
	./$(TARGET)