
#include "stl_reader.hpp"
#include <iostream>

int main() {
    std::cout << "Hello World!\n";
    stl_reader cat("cat.stl");
    cat.read_stl();
    return 0;
}
