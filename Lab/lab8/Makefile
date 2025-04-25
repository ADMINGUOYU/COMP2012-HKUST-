# This Makefile is designed to compile an executable
# from multiple C++ source files.

# Change the following variables as necessary
ASGN_NAME = game.exe
SRCS = main.cpp WordGame.cpp

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

# Linux/macOS
clean:; rm -f $(EXE) $(OBJS) $(DEPS)
# Windows:
# clean:; del $(EXE) $(OBJS) $(DEPS)
