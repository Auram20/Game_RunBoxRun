// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BOX.CPP ___________ 
//================================

#include <cmath>
#include <vector>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/Box.hpp>

using namespace glimac; 

void Box::build(GLfloat width = 1.0, GLfloat height = 1.0, GLfloat depth = 1.0) {

    float w,h,t;
    w = width;        // 0.5
    h = height;       // 0.5
    t = depth;    // 0.5

    // Build all vertices
    // Front face

    for(int i = 0; i < 8; i++) {
        _VertexList.push_back(Vertex());
    }
    
    // Front Face
    _VertexList[0].position = glm::vec3(-w, -h, t);     // Bottom Left
    _VertexList[1].position = glm::vec3(w, -h, t);      // Bottom Right
    _VertexList[2].position = glm::vec3(w, h, t);       // Up Right
    _VertexList[3].position = glm::vec3(-w, h, t);      // Up Left
    // Back Face
    _VertexList[4].position = glm::vec3(-w, -h, -t);     // Bottom Left
    _VertexList[5].position = glm::vec3(w, -h, -t);      // Bottom Right
    _VertexList[6].position = glm::vec3(w, h, -t);       // Up Right
    _VertexList[7].position = glm::vec3(-w, h, -t);      // Up Left

    // Calculate normals
    // for (unsigned int i = 0; i < getVertexCount(); i++)
    // {
    //     _VertexList[i].normal = normalize(_VertexList[i].position);
    // }


    for(unsigned int i = 0; i < getVertexCount(); i++) {
        _VertexList[i].normal = _VertexList[i].position;
    }


    // Texture Coordinates
    _VertexList[0].texCoords = glm::vec2(0,1);
    _VertexList[1].texCoords = glm::vec2(1,1);
    _VertexList[2].texCoords = glm::vec2(1,0);
    _VertexList[3].texCoords = glm::vec2(0,0);

    _VertexList[4].texCoords = glm::vec2(0,0);
    _VertexList[5].texCoords = glm::vec2(1,0);
    _VertexList[6].texCoords = glm::vec2(1,1);
    _VertexList[7].texCoords = glm::vec2(0,1);

}

void Box::displayInfos()
{

    std::cout << " -------------------- INFOS BOX -------------------- " << std::endl;
    for (size_t i = 0; i < getVertexCount(); i++)
    {
        std::cout << _VertexList[i].position << std :: endl;
        std::cout << _VertexList[i].normal << std :: endl;
        std::cout << _VertexList[i].texCoords << std :: endl;

    }

}