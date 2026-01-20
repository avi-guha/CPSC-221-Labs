CPP_FILES = $(wildcard *.cpp) lodepng/lodepng.cpp
OBJ_FILES = $(CPP_FILES:.cpp=.o)
CXX = g++

CXXFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -lpthread -lm


all: $(OBJ_FILES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	del /Q *.o 2>nul

.PHONY: all clean
