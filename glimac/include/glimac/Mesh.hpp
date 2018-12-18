// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MESH.HPP ___________ 
//================================

#ifndef __MESH__HPP
#define __MESH__HPP

#include <vector>
#include "common.hpp"

namespace glimac {

    /// \class Mesh
    /// \brief class defining a new Mesh.
class Mesh 
{


public:
  
    // CONSTRUCTORS & DESTRUCTOR
    Mesh();
    Mesh(GLuint _VertexCount);/*!< object's constructor with arguments*/
    ~Mesh() = default;
        
    // GETTERS
    
    const ShapeVertex* getDataPointer() const 
    {
        return &_VertexList[0];
    } /*!< Returns pointor on datas */
    
    GLsizei getVertexCount() const 
    {
        return _VertexCount;
    } /*!< Returns Vertex numbers */
  
    virtual void displayInfos();

protected:
  
    std::vector<ShapeVertex> _VertexList;
    GLuint _VertexCount;



};
    
}

#endif 