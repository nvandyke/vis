
CXX = g++
CXXFLAGS = -g
CPPFLAGS = ''
LDFLAGS = ''

targets := main.cpp
headers := vector3.hpp triangle.hpp stl_reader.hpp

all: 
	$(CXX) main.cpp $(CXXFLAGS) -o test.exe