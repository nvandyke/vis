
#include "stl_reader.hpp"
#include "graphics.hpp"


std::vector<triangle> simpleMesh() {
    
    vector3 a(0,0,0);
    vector3 b(1,0,0);
    vector3 c(0,1,0);
    vector3 d(0,0,-1);
    triangle t(a,b,c,d);
    std::vector<triangle> mesh;
    mesh.push_back(t);
    return mesh;
}



int main() {
    std::cout << "Hello World!\n";
    stl_reader cat("cat.stl");
    //std::vector<triangle> mesh = cat.read_stl();
    std::vector<triangle> mesh = simpleMesh();
    rasterization(mesh);
    return 0;
}
