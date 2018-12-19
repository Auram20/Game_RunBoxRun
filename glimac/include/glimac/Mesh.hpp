// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MESH.HPP ___________ 
//================================

#ifndef __MESH__HPP
#define __MESH__HPP

#include <vector>
#include <glimac/common.hpp>


namespace glimac {

    /// \class Mesh
    /// \brief class defining a new Mesh.
class Mesh 
{


public:
  
    // CONSTRUCTORS & DESTRUCTOR
    Mesh();
    Mesh(GLuint _VertexCount);/*!< object's constructor with arguments*/
    ~Mesh();
        
    // GETTERS
    
    const ShapeVertex* getDataPointer() const 
    {
        return &_VertexList[0];
    } /*!< Returns pointor on datas */
    
    GLsizei getVertexCount() const 
    {
        return _VertexCount;
    } /*!< Returns Vertex numbers */
  
    virtual void displayInfos();/*!< displays info of a mesh - used for testing */
  
    void initVBO(); /*!< initialize the vbo */

    void initVAO(); /*!< initialize the vao*/

    virtual void initIBO(const unsigned int &nTriangles) {}; /*!< initialise the ibo */

    inline void setMVMatrix(glm::mat4 MVMatrix) {
        _MVMatrix = MVMatrix; 
    } /*!< Set MVMatrix */

    void render() const; /*!< Render a mesh */


protected:
  
    std::vector<ShapeVertex> _VertexList;
    GLuint _VertexCount;
    
    GLuint _vao;
    GLuint _vbo;
    GLuint _ibo;
    unsigned int _nTriangles;

    glm::mat4 _MVMatrix;


};
    
}

#endif 