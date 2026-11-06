CXX      = g++
CXXFLAGS = -std=c++11 -O2 -Wall -Wextra -Iinclude
TARGET   = estruturas
SRCS     = main.cpp demo.cpp comparacao.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
