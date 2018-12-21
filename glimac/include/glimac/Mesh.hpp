// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MESH.HPP ___________ 
//================================

#ifndef __MESH__HPP
#define __MESH__HPP

#include <vector>
#include <glimac/common.hpp>
#include <glimac/Texture.hpp>


namespace glimac {

    /// \class Mesh
    /// \brief class defining a new Mesh.
class Mesh 
{


public:
  
    // CONSTRUCTORS & DESTRUCTOR
    Mesh();
    Mesh(std::vector<Vertex> vert, std::vector<unsigned int> ind, std::vector<Texture> tex); /*!< object's constructor with arguments*/
    ~Mesh();
        
    // GETTERS
    
    const Vertex* getDataPointer() const 
    {
        return &_VertexList[0];
    } /*!< Returns pointor on datas */
    
    GLsizei getVertexCount() const 
    {
        return _VertexList.size();
    } /*!< Returns Vertex numbers */
  
    virtual void displayInfos();/*!< displays info of a mesh - used for testing */
  
    void initVBO(); /*!< initialize the vbo */

    void initVAO(); /*!< initialize the vao*/

    virtual void initEBO(); /*!< initialise the ebo */

    void draw() const; /*!< Render a mesh */

    static const GLuint VERTEX_ATTR_POSITION = 0;
    static const GLuint VERTEX_ATTR_NORMAL = 1;
    static const GLuint VERTEX_ATTR_TEXCOORDS = 2;

protected:
  
    std::vector<Vertex> _VertexList;
    std::vector<uint32_t> _index;
    std::vector<Texture> _textures;
    
    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;
    void setupMesh();


};
    
}

#endif 