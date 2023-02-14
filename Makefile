CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
BUILD_DIR = build
SOURCE_DIR = src

CPPRUN_SRC = $(SOURCE_DIR)/cpprun.cpp
CPPRUN_OBJ = $(BUILD_DIR)/cpprun.o
CPPRUN_EXE = $(BUILD_DIR)/cpprun

OBJS = $(CPPRUN_OBJ)

.PHONY: all clean

all: $(CPPRUN_EXE)

$(CPPRUN_EXE): $(CPPRUN_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -o $@

$(CPPRUN_OBJ): $(CPPRUN_SRC)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(CPPRUN_EXE)

