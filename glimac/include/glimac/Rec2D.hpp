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
class Rec2D : public Box
{

public:
      // CONSTRUCTORS & DESTRUCTOR
    Rec2D(GLfloat width, GLfloat height)
    : Box()
    {
        build(width, height, 0);
        initIndex();
        setupMesh();
    } /*!< init constructor*/

    void draw() const override {
        glDisable(GL_DEPTH_TEST);
        Mesh::draw();
    }; /*!< Render a Rec2D */

};  

}

#endif 