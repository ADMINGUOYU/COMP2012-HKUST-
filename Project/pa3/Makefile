CC = g++
CPPFLAGS = -std=c++11 -g
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

ifneq ($(OS), Windows_NT)
RM = -rm
ifeq ($(shell uname), Linux)
# Enable AddressSanitizer and UndefinedBehaviorSanitizer on Linux
CPPFLAGS += -fsanitize=address,undefined,leak
endif
else
RM = -del
endif

pa3: $(OBJS)
	$(CC) -o $@ $^ $(CPPFLAGS)

-include $(DEPS)

%.o: %.cpp
	$(CC) -MMD -MP -c -o $@ $< $(CPPFLAGS)

clean:
	$(RM) -f *.o *.d pa3 pa3.exe