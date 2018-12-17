// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BOX.CPP ___________ 
//================================

#include <cmath>
#include <vector>
#include <iostream>
#include "../include/glimac/common.hpp"
#include "../include/glimac/Box.hpp"

using namespace glimac; 

void Box::build(GLfloat width = 1.0, GLfloat height = 1.0, GLfloat depth = 1.0) {

    float w,h,t;
    w = width/2;        // 0.5
    h = height/2;       // 0.5
    t = depth/2;    // 0.5

    // Build all vertices
    // Front face
    m_Vertices[0].position = glm::vec3(-w, -h, t);     // Bottom Left
    m_Vertices[1].position = glm::vec3(w, -h, t);      // Bottom Right
    m_Vertices[2].position = glm::vec3(w, h, t);       // Up Right
    m_Vertices[3].position = glm::vec3(-w, h, t);      // Up Left
    // Back Face
    m_Vertices[4].position = glm::vec3(-w, -h, -t);     // Bottom Left
    m_Vertices[5].position = glm::vec3(w, -h, -t);      // Bottom Right
    m_Vertices[6].position = glm::vec3(w, h, -t);       // Up Right
    m_Vertices[7].position = glm::vec3(-w, h, -t);      // Up Left
    // Upper Face
    m_Vertices[8].position = glm::vec3(-w, h, t);     // Bottom Left
    m_Vertices[9].position = glm::vec3(w, h, t);      // Bottom Right
    m_Vertices[10].position = glm::vec3(w, h, -t);       // Up Right
    m_Vertices[11].position = glm::vec3(-w, h, -t);      // Up Left
    // Bottom Face
    m_Vertices[12].position = glm::vec3(-w, -h, t);     // Bottom Left
    m_Vertices[13].position = glm::vec3(w, -h, t);      // Bottom Right
    m_Vertices[14].position = glm::vec3(w, -h, -t);       // Up Right
    m_Vertices[15].position = glm::vec3(-w, h, -t);      // Up Left
    // Left Face
    m_Vertices[16].position = glm::vec3(-w, -h, t);     // Bottom Left
    m_Vertices[17].position = glm::vec3(-w, -h, -t);      // Bottom Right
    m_Vertices[18].position = glm::vec3(-w, h, -t);       // Up Right
    m_Vertices[19].position = glm::vec3(-w, h, t);      // Up Left
    // Right Face
    m_Vertices[20].position = glm::vec3(w, -h, t);     // Bottom Left
    m_Vertices[21].position = glm::vec3(w, -h, -t);      // Bottom Right
    m_Vertices[22].position = glm::vec3(w, h, -t);       // Up Right
    m_Vertices[23].position = glm::vec3(w, h, t);      // Up Left

    // Calculate normals
    // for (unsigned int i = 0; i < getVertexCount(); i++)
    // {
    //     m_Vertices[i].normal = normalize(m_Vertices[i].position);
    // }

    // Front Face
    m_Vertices[0].normal = glm::vec3(0, 0, 1);     // Bottom Left
    m_Vertices[1].normal = glm::vec3(0, 0, 1);      // Bottom Right
    m_Vertices[2].normal = glm::vec3(0, 0, 1);       // Up Right
    m_Vertices[3].normal = glm::vec3(0, 0, 1);      // Up Left
    // Back Face
    m_Vertices[4].normal = glm::vec3(0, 0, -1);     // Bottom Left
    m_Vertices[5].normal = glm::vec3(0, 0, -1);      // Bottom Right
    m_Vertices[6].normal = glm::vec3(0, 0, -1);       // Up Right
    m_Vertices[7].normal = glm::vec3(0, 0, -1);      // Up Left
    // Upper Face
    m_Vertices[8].normal = glm::vec3(0, 1, 0);     // Bottom Left
    m_Vertices[9].normal = glm::vec3(0, 1, 0);      // Bottom Right
    m_Vertices[10].normal = glm::vec3(0, 1, 0);       // Up Right
    m_Vertices[11].normal = glm::vec3(0, 1, 0);      // Up Left
    // Bottom Face
    m_Vertices[12].normal = glm::vec3(0, -1, 0);     // Bottom Left
    m_Vertices[13].normal = glm::vec3(0, -1, 0);      // Bottom Right
    m_Vertices[14].normal = glm::vec3(0, -1, 0);       // Up Right
    m_Vertices[15].normal = glm::vec3(0, -1, 0);      // Up Left
    // Left Face
    m_Vertices[16].normal = glm::vec3(-1, 0, 0);     // Bottom Left
    m_Vertices[17].normal = glm::vec3(-1, 0, 0);      // Bottom Right
    m_Vertices[18].normal = glm::vec3(-1, 0, 0);       // Up Right
    m_Vertices[19].normal = glm::vec3(-1, 0, 0);      // Up Left
        // Bottom Face
    m_Vertices[20].normal = glm::vec3(1, 0, 0);     // Bottom Left
    m_Vertices[21].normal = glm::vec3(1, 0, 0);      // Bottom Right
    m_Vertices[22].normal = glm::vec3(1, 0, 0);       // Up Right
    m_Vertices[23].normal = glm::vec3(1, 0, 0);      // Up Left


    // Texture Coordinates
    for (int i = 0; i < (int)this->getVertexCount(); i = i + 4)
    {
        m_Vertices[i].texCoords = glm::vec2(0,1);
        m_Vertices[i+1].texCoords = glm::vec2(1,1);
        m_Vertices[i+2].texCoords = glm::vec2(1,0);
        m_Vertices[i+3].texCoords = glm::vec2(0,0);
    }

 
}