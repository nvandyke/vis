#ifndef STLREADER
#define STLREADER

#include "vectors.hpp"
#include "triangle.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdint>


class mesh {
public:

    std::vector<triangle> triangles;
    uint32_t numTriangles() { return triangles.size(); };
    matrix3 rotGlobalToCanvas;
    vector3 originGlobal;

    mesh(std::vector<triangle> inputTris) {
        triangles = inputTris;
    };
private:

};


class stl_reader {

public:
    std::string filename;

    stl_reader(std::string filePath = "") :
        filename(filePath) {} ;

    mesh read_stl() {

        //first 80 bytes are the header
        unsigned char headerBuffer[80];

        //next 4 bytes is the number of triangles
        unsigned char numTrianglesBuffer[4];

        //each triangle is 50 bytes
        unsigned char triangleBuffer[50];

        //return list of triangles
        std::vector<triangle> meshTriangles;

        //file handle
        FILE *filePtr;
        filePtr = fopen(filename.c_str(),"rb");

        //grab the header
        fread(headerBuffer, sizeof(headerBuffer),1,filePtr);
        //std::cout << headerBuffer << std::endl;

        //grab the number of triangles and process into integer
        fread(numTrianglesBuffer, sizeof(numTrianglesBuffer),1,filePtr);

        uint32_t numTriangles = (numTrianglesBuffer[3] << 24) + 
                    (numTrianglesBuffer[2] << 16) + 
                    (numTrianglesBuffer[1] << 8) + 
                    (numTrianglesBuffer[0]);
        //std::cout << numTriangles << std::endl;

        for (uint32_t i = 0; i < numTriangles; ++i) {
            //grab the next 50 bytes
            fread(triangleBuffer, sizeof(triangleBuffer), 1, filePtr);

            //process into triangle and add to list
            triangle tri = bufferToTriangle(triangleBuffer);
            meshTriangles.push_back(tri);
        }


        fclose(filePtr);

        mesh retVal(meshTriangles);
        return retVal;

    };



private:
    triangle bufferToTriangle(unsigned char buffer[]) {
        
        //first 12 bytes are the normal vector - ignore
        vector3 normal = bufferToVector3(buffer);
        
        //next 12 bytes are node 1
        vector3 node1 = bufferToVector3(buffer + 12);
        
        //next 12 bytes are node 2
        vector3 node2 = bufferToVector3(buffer + 24);
        
        //next 12 bytes are node 3
        vector3 node3 = bufferToVector3(buffer + 36);
        
        //last 2 bytes are the attribute byte count - ignore
        
        //form triangle
        triangle tri(node1,node2,node3,normal);
        return tri;
    };
    
    vector3 bufferToVector3(unsigned char buffer[]) {
        
        //convert buffer into 3 floats (4 bytes each)
        float x = bufferToFloat(buffer + 0);
        float y = bufferToFloat(buffer + 4);
        float z = bufferToFloat(buffer + 8);
        
        //form vector
        vector3 vec(x,y,z);
        return vec;
    }
    
    float bufferToFloat(unsigned char buffer[]){
        
        //things are flipped, also need to bitshift
        uint32_t hexVal = ((buffer[3] << 24) + (buffer[2] << 16) + (buffer[1] << 8) + (buffer[0] << 0));
        
        //convert data to float
        float floatVal = *((float*) &hexVal);
        
        //std::cout << floatVal << std::endl;
        return floatVal;
    }
    
};
#endif
