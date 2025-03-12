SRCS	= Exhibit.cpp IndoorExhibit.cpp OutdoorExhibit.cpp Animal.cpp Zoo.cpp main.cpp
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(OBJS:.o=.d)

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Uncomment the following line to enable sanitizers
# CXXFLAGS += -fsanitize=address,leak,undefined

ifeq ($(OS),Windows_NT)
	EXEC = lab4.exe
	RM = del
else
	EXEC = lab4
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