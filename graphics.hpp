#ifndef GRAPHICS
#define GRAPHICS
#include <vector>
#include "triangle.hpp"
#include "vectors.hpp"
#include "stl_reader.hpp"
#include <cstdint>



class canvas {
public:
    matrix3 rotGlobalToCanvas;
    vector3 originGlobal;
    uint32_t numPixelsX, numPixelsY;
    std::vector<std::vector<pixel>> image;
    canvas(uint32_t xSize = 0, uint32_t ySize = 0) {
        numPixelsX = xSize;
        numPixelsY = ySize;
        resetImage();
    };

    void resetImage() {
        pixel dummy;
        for (uint32_t i = 0; i < numPixelsX; ++i) {
            for (uint32_t j = 0; j < numPixelsY; ++j) {
                image[i][j] = dummy;
            }
        }
    };

};


class scene {
public:
    canvas screen;
    std::vector<mesh> actors;

    scene() {};
    scene(canvas inputCanvas, std::vector<mesh> inputActors) {
        screen = inputCanvas;
        actors = inputActors;
    };
    void formImage();
    void rasterization();
    void rayTracing();
    vector2 projectOntoCanvas();
    bool pixelInTriangle(uint32_t i, uint32_t j,
                         vector2 n1, vector2 n2, vector2 n3);
};

float sign(vector2 n1, vector2 n2, vector2 n3);

#endif
