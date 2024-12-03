
CXX = g++
CXXFLAGS = -g
CPPFLAGS = ''
LDFLAGS = ''

targets := main.cpp rasterization.cpp
headers := vector3.hpp triangle.hpp stl_reader.hpp

all:
	$(CXX) $(targets)  $(CXXFLAGS) -o test.exe
