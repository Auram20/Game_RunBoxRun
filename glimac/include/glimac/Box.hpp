// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BOX.HPP ___________ 
//================================

#ifndef __BOX__HPP
#define __BOX__HPP

#include <vector>
#include "common.hpp"

namespace glimac {

    /// \class Box
    /// \brief class defining a new box.
class Box {


public:
  
    // CONSTRUCTORS & DESTRUCTOR
    Box(GLfloat width, GLfloat height, GLfloat depth):
    m_nVertexCount(24) {

        build(width, height, depth); 
    } /*!< init constructor*/

    // GETTERS
    const ShapeVertex* getDataPointer() const 
    {
        return &m_Vertices[0];
    } /*!< Returns pointor on datas */
    
    GLsizei getVertexCount() const 
    {
        return m_nVertexCount;
    } /*!< Returns Vertex numbers */

    // FONCTION pour allouer et renseigner les données dans le cpp.
    void build(GLfloat width, GLfloat height, GLfloat depth);



private:
    ShapeVertex m_Vertices[24];
    GLsizei m_nVertexCount; // Nombre de sommets

    };
    
}

#endif 