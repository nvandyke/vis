#ifndef TRIANGLE
#define TRIANGLE

#include "vectors.hpp"
#include <vector>
#include <cstdint>

class pixel {
public:
    uint8_t r, g, b;
    pixel(uint8_t rVal = 0, uint8_t gVal = 0, uint8_t bVal = 0) :
        r(rVal), g(gVal), b(bVal) {};
};

class triangle {
public:
    std::vector<vector3> nodes;
    vector3 normal;
    pixel color;

    triangle(vector3 node1, vector3 node2, vector3 node3, vector3 normal_vec) {
        nodes.push_back(node1);
        nodes.push_back(node2);
        nodes.push_back(node3);
        normal = normal_vec;
        
    };


private:
    
    
    
};
#endif
