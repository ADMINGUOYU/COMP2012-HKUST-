SRCS	= parking_spot.cpp vehicle.cpp parking_lot.cpp main.cpp
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(OBJS:.o=.d)

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

ifeq ($(OS),Windows_NT)
	EXEC = lab3.exe
	RM = del
else
	EXEC = lab3
	RM = rm -f
endif

all: $(EXEC)
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

-include $(DEPS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -MMD -MP -c $<

clean:
	$(RM) $(EXEC) $(OBJS) $(DEPS)