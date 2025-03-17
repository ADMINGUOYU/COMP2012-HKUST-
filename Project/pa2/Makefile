CC = g++
CPPFLAGS = -std=c++11 -Wall -g -MMD -MP
BUILD_DIR = build

SRCS = main.cpp Market.cpp TrendFollowingStrategy.cpp WeightedTrendFollowingStrategy.cpp \
       MeanReversionStrategy.cpp TradingBot.cpp Strategy.cpp Utils.cpp
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Uncomment the following line to enable sanitizers
# CXXFLAGS += -fsanitize=address,leak,undefined

ifeq ($(OS),Windows_NT)
	RM = del
	EXEC = pa2.exe
else
	RM = rm -f
	EXEC = pa2
endif

all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(CPPFLAGS)

# Create directory for object files
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

# include dependency files
-include $(DEPS)

.PHONY: clean

clean:
	$(RM) -rf $(BUILD_DIR)
	$(RM) -f *.o *.d pa2 pa2.exe