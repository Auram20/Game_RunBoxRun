// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ REC2D.HPP ___________ 
//================================

#ifndef __REC2D__HPP
#define __REC2D__HPP

#include <vector>
#include <glimac/Box.hpp>

namespace glimac {

    /// \class Rec2D
    /// \brief class defining a new Rec2D.
    /*!< Classe pour réaliser un rectangle en 2D */
class Rec2D : public Box
{

public:
      // CONSTRUCTORS & DESTRUCTOR
    /*!< init constructor*/
    Rec2D(GLfloat width, GLfloat height)
    : Box()
    {
        build(width, height, 0);
        initIndex();
        setupMesh();
    } 

    /*!< Render a Rec2D */
    void draw() const override {
        glDisable(GL_DEPTH_TEST);
        Mesh::draw();
    };

};  

}

#endif 