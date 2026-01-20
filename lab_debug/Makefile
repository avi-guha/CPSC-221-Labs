EXENAME = sketchify
TESTNAME = test

MAIN_FILE = main.cpp
TEST_FILE = testsketchify.cpp

# Flags:
CXXFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -lpthread -lm
COVFLAGS = -fprofile-arcs -ftest-coverage
CXX = g++
LD = g++

# Discover files in dir...
CPP_FILES += $(filter-out $(TEST_FILE),$(wildcard *.cpp))
CPP_FILES += $(wildcard cs221util/*.cpp)
CPP_FILES += $(wildcard cs221util/lodepng/*.cpp)

OBJ_FILES += $(CPP_FILES:.cpp=.o)


# Discover files for testing...
TEST_CPP += $(filter-out $(MAIN_FILE),$(CPP_FILES))
TEST_CPP += $(TEST_FILE)

TEST_OBJ = $(TEST_CPP:.cpp=.o)


# Rules
all: $(EXENAME) $(TESTNAME)

$(EXENAME): $(OBJ_FILES)
	$(LD) $(OBJ_FILES) $(LDFLAGS) $(COVFLAGS) -o $(EXENAME)

test: $(TEST_OBJ)
	$(LD) $(TEST_OBJ) $(LDFLAGS) $(COVFLAGS) -o $(TESTNAME)

coverage:
	-gcov test
	-lcov --capture --directory . --output-file coverage.info
	-genhtml coverage.info --output-directory coverage_html

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(COVFLAGS) $< -o $@

clean:
	-del /Q *.o $(EXENAME) $(TESTNAME) cs221util\*.o cs221util\lodepng\*.o *.profdata *.profraw *.html 2>nul



