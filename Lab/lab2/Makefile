# Simple Makefile for lab2
# A simple Makefile for compiling on a Unix-like environment (Linux/Mac/WSL). 
# If you’re on Windows with MinGW, this will work provided make and g++ are installed.

CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2

# Detect OS and adjust settings
ifeq ($(OS), Windows_NT)
    EXEC = lab2.exe
    RM = del /Q
else
    EXEC = lab2
    RM = rm -f
endif

# if you want to use the main_interactive.cpp file, you can change all the "main.cpp" to "main_interactive.cpp"
all: $(EXEC)

$(EXEC): main.o class.o todo.o
	$(CXX) $(CXXFLAGS) main.o class.o todo.o -o $(EXEC)

main.o: main.cpp class.h
	$(CXX) $(CXXFLAGS) -c main.cpp

class.o: class.cpp class.h
	$(CXX) $(CXXFLAGS) -c class.cpp

todo.o: todo.cpp class.h
	$(CXX) $(CXXFLAGS) -c todo.cpp

clean:
	$(RM) *.o $(EXEC)

