#include "graphics.hpp"
#include "vectors.hpp"
#include "triangle.hpp"
#include "stl_reader.hpp"
#include <cstdint>

void scene::rasterization() {

    for (mesh actor : actors) {
        //uint32_t numTriangles = actor.numTriangles();
        //for (uint32_t i = 0; i < numTriangles; ++i) {
        for (triangle tri : actor.triangles) {
            
        }
    }
}
