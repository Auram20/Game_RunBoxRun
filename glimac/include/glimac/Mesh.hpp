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
#include <memory>

namespace glimac {

    /// \class Mesh
    /// \brief class defining a new Mesh.
class Mesh 
{


public:
  
    // CONSTRUCTORS & DESTRUCTOR
    Mesh();
    Mesh(std::vector<Vertex> vert, std::vector<unsigned int> ind, std::vector<Texture> tex); /*!< object's constructor with arguments*/
    Mesh(const Mesh &mesh);
    ~Mesh() = default;
        
    // GETTERS
    
    const Vertex* getDataPointer() const 
    {
        return _VertexList.data();
    } /*!< Returns pointor on datas */
    
    GLsizei getVertexCount() const 
    {
        return _VertexList.size();
    } /*!< Returns Vertex numbers */
  
    virtual void displayInfos() const;/*!< displays info of a mesh - used for testing */
  
    void initVBO(); /*!< initialize the vbo */

    void initVAO(); /*!< initialize the vao*/

    virtual void initEBO(); /*!< initialise the ebo */

    void draw() const; /*!< Render a mesh */

    //Opérateur =

    static const GLuint VERTEX_ATTR_POSITION = 0;
    static const GLuint VERTEX_ATTR_NORMAL = 1;
    static const GLuint VERTEX_ATTR_TEXCOORDS = 2;

protected:
  
    std::vector<Vertex> _VertexList;
    std::vector<uint32_t> _index;
    std::vector<Texture> _textures;
    
    std::shared_ptr<GLuint> _vao;
    std::shared_ptr<GLuint> _vbo;
    std::shared_ptr<GLuint> _ebo;
    void setupMesh();
    void initPtr();
    static void deleteBuffers(GLuint* i) {
        if(i == nullptr) return;
        glDeleteBuffers(1, i);
		delete i;
    }
    static void deleteVertexArrays(GLuint* i) {
        if(i == nullptr) return;
        glDeleteVertexArrays(1, i);
		delete i;
    }

};
    
}

#endif 