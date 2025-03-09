# Definition of variables
SRCS	= bulb.cpp lamp.cpp lamp-test.cpp
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(OBJS:.o=.d)
EXE	= lamp-test
CXXFLAGS = -std=c++11

# Rules: 
# target: dependencies
#   command used to create the target
$(EXE): $(OBJS) 
	g++ $(CXXFLAGS) -o $@ $(OBJS)

# To include the .d dependency files
-include $(DEPS)

# -MMD -MP creates the .d dependency files
.cpp.o:; g++ $(CXXFLAGS) -MMD -MP -c $<

clean:;	/bin/rm $(EXE) $(OBJS) $(DEPS)
