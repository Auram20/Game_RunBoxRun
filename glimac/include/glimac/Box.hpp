// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BOX.HPP ___________ 
//================================

#ifndef __BOX__HPP
#define __BOX__HPP

#include <vector>
#include <glimac/Mesh.hpp>
#include <glimac/common.hpp>

namespace glimac {

    /// \class Box
    /// \brief class defining a new box.
class Box : public Mesh
{


public:
  
    // CONSTRUCTORS & DESTRUCTOR
    Box(GLfloat width, GLfloat height, GLfloat depth)
    : Mesh()
    {
        build(width, height, depth);
        initIndex();
        setupMesh();
    } /*!< init constructor*/

 

    // FONCTION pour allouer et renseigner les données dans le cpp.
    void build(GLfloat width, GLfloat height, GLfloat depth);

    inline void initIndex() {
        _index = {
            0, 4, 7, //Left Face
            0, 3, 4,
            0, 1, 2, //Front Face
            0, 2, 3,
            1, 5, 6, //Right Face
            1, 6, 2,
            4, 5, 6, //Back Face
            4, 6, 7,
            2, 6, 7, //Top Face
            2, 3, 7,
            0, 1, 5, //Bottom Face
            0, 5, 4
        };
    };

    virtual void displayInfos();
  
  };
    
}

#endif 