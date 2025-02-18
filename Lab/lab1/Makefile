# Simple Makefile for lab1
# A simple Makefile for compiling on a Unix-like environment (Linux/Mac/WSL). If you’re on Windows with MinGW, this will work provided make and g++ are installed.

CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
# depending on the OS, the executable name may be different
ifeq ($(OS), Windows_NT)
	EXEC = lab1.exe
else
	EXEC = lab1
endif

all: $(EXEC)

$(EXEC): main.o employee.o company.o
	$(CXX) $(CXXFLAGS) main.o employee.o company.o -o $(EXEC)

main.o: main.cpp employee.h company.h
	$(CXX) $(CXXFLAGS) -c main.cpp

employee.o: employee.cpp employee.h
	$(CXX) $(CXXFLAGS) -c employee.cpp

company.o: company.cpp company.h employee.h
	$(CXX) $(CXXFLAGS) -c company.cpp

clean:
	rm -f *.o $(EXEC)