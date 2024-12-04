#ifndef GRAPHICS
#define GRAPHICS
#include <vector>
#include "triangle.hpp"
#include "vectors.hpp"
#include <cstdint>


class pixel {
public:
    uint8_t r, g, b;
    pixel(uint8_t rVal = 0, uint8_t gVal = 0, uint8_t bVal = 0) :
        r(rVal), g(gVal), b(bVal) {};
};

class canvas {
public:
    matrix3 rotGlobalToCanvas;
    vector3 originGlobal;
    uint32_t numPixelsX, numPixelsY;
    std::vector<std::vector<pixel>> image;
    canvas(uint32_t xSize, uint32_t ySize) {
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

void rasterization(std::vector<triangle> mesh);


#endif
