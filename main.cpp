
#include "stl_reader.hpp"
#include "graphics.hpp"


mesh simpleMesh() {

    vector3 a(0,0,0);
    vector3 b(1,0,0);
    vector3 c(0,1,0);
    vector3 d(0,0,-1);
    triangle t(a,b,c,d);
    std::vector<triangle> meshTris;
    meshTris.push_back(t);
    mesh retVal(meshTris);
    return retVal;
}



int main() {
    std::cout << "Hello World!\n";
    stl_reader cat("cat.stl");
    //mesh catMesh = cat.read_stl();
    mesh catMesh = simpleMesh();
    std::vector<mesh> meshes = {catMesh};
    canvas screen;
    scene computation(screen, meshes);
    computation.rasterization();
    return 0;
}
