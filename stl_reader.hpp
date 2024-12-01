#ifndef STLREADER
#define STLREADER

#include "vector3.hpp"
#include "triangle.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstdlib>

class stl_reader {

public:
    std::string filename;
    
    stl_reader(std::string filePath = "") : 
        filename(filePath) {} ;
    
    std::vector<triangle> read_stl() {
        /* std::ifstream input(filename, std::ios::binary);
        std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
        std::cout << buffer.size() << std::endl;
        
        //first 80 bytes are the header
        unsigned int start_byte = 0;
        unsigned int end_byte = 79;
        std::string header(buffer.begin() + start_byte, buffer.begin() + end_byte);
        std::cout << header << "\n";
        
        input.close();
        //next 4 bytes is number of triangles
        start_byte = ++end_byte;
        end_byte += 3;
        //std::string numTriangles(buffer.begin() + start_byte, buffer.begin() + end_byte);
        //std::cout << numTriangles << "\n";
 */
        
        
        unsigned char triangleBuffer[50];
        unsigned char numTrianglesBuffer[4];
        unsigned char headerBuffer[80];
        
        FILE *ptr;
        ptr = fopen("cat.stl","rb");
        
        fread(headerBuffer, sizeof(headerBuffer),1,ptr);
        
        fread(numTrianglesBuffer, sizeof(numTrianglesBuffer),1,ptr);
        fclose(ptr);
        
        std::cout << headerBuffer << std::endl;
        std::cout << numTrianglesBuffer[0] << numTrianglesBuffer[1] << numTrianglesBuffer[2] << numTrianglesBuffer[3] << std::endl;
        int n = std::atoi( ( char * ) numTrianglesBuffer );
        
        std::cout << n << std::endl;
        /* std::ifstream infile;
        infile.open(filename, std::ios::binary | std::ios::in);
        std::cout << infile.fail() << std::endl;
        int32_t numTriangles;
        infile.seekp(80, std::ios::beg);
        std::cout << infile.fail() << std::endl;
        infile.read(&numTriangles, sizeof(numTriangles));
        std::cout << infile.fail() << std::endl;
        infile.close(); */
        
        //next 4 bytes are the
        vector3 a;
        triangle t1(a,a,a,a);
        std::vector<triangle> mesh;
        mesh.push_back(t1);
        return mesh;
        
    };



private:
    
    
};
#endif
