// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TRANSFORM.HPP_____ 
//================================

#ifndef __TRANSFORM__HPP
#define __TRANSFORM__HPP

#include <GL/glew.h>
#include <utils/Error.hpp>
#include <utils/glm.hpp>

namespace RUNBOXRUN
{
    
    struct Transform {
        glm::vec3 _scale;
        glm::vec3 _translate;
        glm::vec3 _rotateLocal;
        glm::vec3 _rotateGlobal;

        const glm::mat4 rotate(const glm::mat4 &matrix, const glm::vec3 &angles) const {
            glm::mat4 rotate = matrix;
            rotate = glm::rotate(rotate, angles[2], glm::vec3(0.f, 0.f, 1.f));
            rotate = glm::rotate(rotate, angles[1], glm::vec3(0.f, 1.f, 1.f));
            rotate = glm::rotate(rotate, angles[0], glm::vec3(1.f, 0.f, 1.f));
            return rotate;
        }

        Transform(
            const glm::vec3 &pos = glm::vec3(0.f, 0.f, 0.f),
            const glm::vec3 &scale = glm::vec3(0.5f, 0.5f, 0.5f),
            const glm::vec3 &rotateLocal = glm::vec3(0.f, 0.f, 0.f),
            const glm::vec3 &rotateGlobal = glm::vec3(0.f, 0.f, 0.f)
        )
        : _scale(scale), _translate(pos), _rotateLocal(rotateLocal), _rotateGlobal(rotateGlobal)
        {
        }

        Transform(const Transform &transform)
        : _scale(transform._scale), _translate(transform._translate), _rotateLocal(transform._rotateLocal), _rotateGlobal(transform._rotateGlobal)
        {
        }



        ~Transform() = default;

        inline const glm::mat4 matrix() const {
            glm::mat4 translate = glm::translate(glm::mat4(1.f), _translate);
            glm::mat4 scale = glm::scale(glm::mat4(1.f), _scale);
            glm::mat4 rotateLocal = rotate(glm::mat4(1.f), _rotateLocal);
            glm::mat4 rotateGlobal = rotate(glm::mat4(1.f), _rotateGlobal);

            return rotateGlobal * translate * rotateLocal * scale;
        }

         inline void setRotation(glm::vec3 &angles){
           _rotateLocal = angles;
        } 
        
        
    };
	
}

#endif
