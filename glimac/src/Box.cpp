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

    for(int i = 0; i < getVertexCount(); i++) {
        _VertexList.push_back(ShapeVertex());
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

void Box::initIBO(const unsigned int &nTriangles) {
    //Création du IBO
    glGenBuffers(1, &_ibo);

    //Bin sur GL_ELEMENT_ARRAY_BUFFER, cible réservée pour les IBOs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);

    _nTriangles = nTriangles;

    //Tableau d'indices des sommets à dessiner
    std::vector<uint32_t> index = {
        0, 4, 3, //Right Face
        0, 3, 7,
        0, 1, 2, //Front Face
        0, 2, 3,
        1, 5, 6, //Left Face
        1, 6, 2,
        4, 5, 6, //Back Face
        4, 6, 7,
        2, 6, 7, //Top Face
        2, 3, 7,
        0, 1, 3, //Bottom Face
        0, 5, 4
    };

    //On remplit l'IBO avec les indices
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        (nTriangles) * 3 * sizeof(std::vector<uint32_t>),
        index.data(),
        GL_STATIC_DRAW
    );

    //Debin de l'IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Box::displayInfos()
{

    std::cout << " -------------------- INFOS BOX -------------------- " << std::endl;
    for (size_t i=0;i<_VertexCount;i++)
    {
        std::cout << _VertexList[i].position << std :: endl;
        std::cout << _VertexList[i].normal << std :: endl;
        std::cout << _VertexList[i].texCoords << std :: endl;

    }

}