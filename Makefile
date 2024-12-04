
CXX = g++
CXXFLAGS = -g
CPPFLAGS = ''
LDFLAGS = ''

targets := main.cpp rasterization.cpp

all:
	$(CXX) $(targets)  $(CXXFLAGS) -o test.exe
