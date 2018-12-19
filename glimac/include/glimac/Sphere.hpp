#pragma once

#include <vector>

#include "glimac/common.hpp"
#include "glimac/Mesh.hpp"

namespace glimac {

// Représente une sphère discrétisée centrée en (0, 0, 0) (dans son repère local)
// Son axe vertical est (0, 1, 0) et ses axes transversaux sont (1, 0, 0) et (0, 0, 1)
class Sphere : public Mesh {
    // Alloue et construit les données (implantation dans le .cpp)
    void build(GLfloat radius, GLsizei discLat, GLsizei discLong);

public:
    // Constructeur: alloue le tableau de données et construit les attributs des vertex
    Sphere(GLfloat radius, GLsizei discLat, GLsizei discLong):
        Mesh(0) {
        build(radius, discLat, discLong); // Construction (voir le .cpp)
        initVBO();
        initVAO();
    }
};
    
}