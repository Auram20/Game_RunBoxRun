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
    // Upper Face
    _VertexList[8].position = glm::vec3(-w, h, t);     // Bottom Left
    _VertexList[9].position = glm::vec3(w, h, t);      // Bottom Right
    _VertexList[10].position = glm::vec3(w, h, -t);       // Up Right
    _VertexList[11].position = glm::vec3(-w, h, -t);      // Up Left
    // Bottom Face
    _VertexList[12].position = glm::vec3(-w, -h, t);     // Bottom Left
    _VertexList[13].position = glm::vec3(w, -h, t);      // Bottom Right
    _VertexList[14].position = glm::vec3(w, -h, -t);       // Up Right
    _VertexList[15].position = glm::vec3(-w, h, -t);      // Up Left
    // Left Face
    _VertexList[16].position = glm::vec3(-w, -h, -t);     // Bottom Left
    _VertexList[17].position = glm::vec3(-w, -h, t);      // Bottom Right
    _VertexList[18].position = glm::vec3(-w, h, t);       // Up Right
    _VertexList[19].position = glm::vec3(-w, h, -t);      // Up Left
    // Right Face
    _VertexList[20].position = glm::vec3(w, h, t);     // Bottom Left
    _VertexList[21].position = glm::vec3(w, -h, t);      // Bottom Right
    _VertexList[22].position = glm::vec3(w, -h, -t);       // Up Right
    _VertexList[23].position = glm::vec3(w, h, -t);      // Up Left

    // Calculate normals
    // for (unsigned int i = 0; i < getVertexCount(); i++)
    // {
    //     _VertexList[i].normal = normalize(_VertexList[i].position);
    // }

    // Front Face
    _VertexList[0].normal = glm::vec3(0, 0, 1);     // Bottom Left
    _VertexList[1].normal = glm::vec3(0, 0, 1);      // Bottom Right
    _VertexList[2].normal = glm::vec3(0, 0, 1);       // Up Right
    _VertexList[3].normal = glm::vec3(0, 0, 1);      // Up Left
    // Back Face
    _VertexList[4].normal = glm::vec3(0, 0, -1);     // Bottom Left
    _VertexList[5].normal = glm::vec3(0, 0, -1);      // Bottom Right
    _VertexList[6].normal = glm::vec3(0, 0, -1);       // Up Right
    _VertexList[7].normal = glm::vec3(0, 0, -1);      // Up Left
    // Upper Face
    _VertexList[8].normal = glm::vec3(0, 1, 0);     // Bottom Left
    _VertexList[9].normal = glm::vec3(0, 1, 0);      // Bottom Right
    _VertexList[10].normal = glm::vec3(0, 1, 0);       // Up Right
    _VertexList[11].normal = glm::vec3(0, 1, 0);      // Up Left
    // Bottom Face
    _VertexList[12].normal = glm::vec3(0, -1, 0);     // Bottom Left
    _VertexList[13].normal = glm::vec3(0, -1, 0);      // Bottom Right
    _VertexList[14].normal = glm::vec3(0, -1, 0);       // Up Right
    _VertexList[15].normal = glm::vec3(0, -1, 0);      // Up Left
    // Left Face
    _VertexList[16].normal = glm::vec3(-1, 0, 0);     // Bottom Left
    _VertexList[17].normal = glm::vec3(-1, 0, 0);      // Bottom Right
    _VertexList[18].normal = glm::vec3(-1, 0, 0);       // Up Right
    _VertexList[19].normal = glm::vec3(-1, 0, 0);      // Up Left
    // Right Face
    _VertexList[20].normal = glm::vec3(1, 0, 0);     // Bottom Left
    _VertexList[21].normal = glm::vec3(1, 0, 0);      // Bottom Right
    _VertexList[22].normal = glm::vec3(1, 0, 0);       // Up Right
    _VertexList[23].normal = glm::vec3(1, 0, 0);      // Up Left


    // Texture Coordinates
    for (int i = 0; i < (int)this->getVertexCount(); i = i + 4)
    {
        _VertexList[i].texCoords = glm::vec2(0,1);
        _VertexList[i+1].texCoords = glm::vec2(1,1);
        _VertexList[i+2].texCoords = glm::vec2(1,0);
        _VertexList[i+3].texCoords = glm::vec2(0,0);
    }

}

void Box::initIBO(const unsigned int &nTriangles) {
    //Création du IBO
    glGenBuffers(1, &_ibo);

    //Bin sur GL_ELEMENT_ARRAY_BUFFER, cible réservée pour les IBOs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);

    _nTriangles = nTriangles;

    //Tableau d'indices des sommets à dessiner
    std::vector<uint32_t> index;

    for(unsigned int i = 0; i < (nTriangles * 3) / 6; ++i) {
        index.push_back(i * 4);
        index.push_back(i * 4 + 1);
        index.push_back(i * 4 + 2);
        index.push_back(index[i * 6]);
        index.push_back(index[i * 6 + 2]);
        index.push_back(i * 4 + 3);
    }


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