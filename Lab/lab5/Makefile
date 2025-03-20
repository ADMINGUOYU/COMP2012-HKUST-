# This Makefile is designed to compile an executable
# from multiple C++ source files.

# Change the following variables as necessary
ASGN_NAME = vehicle_factory
SRCS = main.cpp Factory.cpp Vehicle.cpp

# Definition of variables
CPPFLAGS = -std=c++11 -Wall
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
EXE = $(ASGN_NAME)

# Rules: 
# target: dependencies
#   command used to create the target
$(EXE): $(OBJS) 
	g++ $(CPPFLAGS) -o $@ $(OBJS)

# To include the .d dependency files
-include $(DEPS)

# -MMD -MP creates the .d dependency files
.cpp.o:; g++ $(CPPFLAGS) -MMD -MP -c $<

clean:; rm -f $(EXE) $(OBJS) $(DEPS)

