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
            vector2 v0, v1, v2;
            v0 = projectOntoCanvas();
            v1 = projectOntoCanvas();
            v2 = projectOntoCanvas();
            for (uint32_t i = 0; i < screen.numPixelsX; ++i) {
                for (uint32_t j = 0; j < screen.numPixelsY; ++j) {
                    if (pixelInTriangle(i,j,v0,v1,v2)) {
                        screen.image[i][j] = tri.color;
                    }
                }
            }
        }
    }
}


vector2 scene::projectOntoCanvas() {
    vector2 retVal;
    return retVal;
}


bool scene::pixelInTriangle(uint32_t i, uint32_t j,
                            vector2 n1, vector2 n2, vector2 n3) {
    vector2 pt(i,j);
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, n1, n2);
    d2 = sign(pt, n2, n3);
    d3 = sign(pt, n3, n1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

float sign (vector2 p1, vector2 p2, vector2 p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

