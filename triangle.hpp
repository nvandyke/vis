#ifndef TRIANGLE
#define TRIANGLE

#include "vector3.hpp"
#include <vector>

class triangle {
public:
    std::vector<vector3> nodes;
    vector3 normal;

    triangle(vector3 node1, vector3 node2, vector3 node3, vector3 normal_vec) {
        nodes.push_back(node1);
        nodes.push_back(node2);
        nodes.push_back(node3);
        normal = normal_vec;
        
    };


private:
    
    
    
};
#endif