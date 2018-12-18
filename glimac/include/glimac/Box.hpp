// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BOX.HPP ___________ 
//================================

#ifndef __BOX__HPP
#define __BOX__HPP

#include <vector>
#include "Mesh.hpp"
#include "common.hpp"

namespace glimac {

    /// \class Box
    /// \brief class defining a new box.
class Box : public Mesh
{


public:
  
    // CONSTRUCTORS & DESTRUCTOR
    Box(GLfloat width, GLfloat height, GLfloat depth)
    : Mesh(24) 
    {
        build(width, height, depth); 
    } /*!< init constructor*/

 

    // FONCTION pour allouer et renseigner les données dans le cpp.
    void build(GLfloat width, GLfloat height, GLfloat depth);



     virtual void displayInfos();


private:
  
  
  };
    
}

#endif 