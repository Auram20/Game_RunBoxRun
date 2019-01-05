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
        glm::mat4 _scale;
        glm::mat4 _translate;
        glm::mat4 _rotateLocal;
        glm::mat4 _rotateGlobal;

        const glm::mat4 rotate(const glm::mat4 &matrix, const glm::vec3 &angles) {
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
        : _scale(glm::mat4(1.f)), _translate(glm::mat4(1.f)), _rotateLocal(glm::mat4(1.f)), _rotateGlobal(glm::mat4(1.f))
        {
            _translate = glm::translate(_translate, pos);
            _scale = glm::scale(_scale, scale);
            _rotateLocal = rotate(_rotateLocal, rotateLocal);
            _rotateGlobal = rotate(_rotateGlobal, rotateGlobal);
        }

        Transform(const Transform &transform)
        : _scale(transform._scale), _translate(transform._translate), _rotateLocal(transform._rotateLocal), _rotateGlobal(transform._rotateGlobal)
        {
        }



        ~Transform() = default;

        inline const glm::mat4 matrix() const {
            return _rotateGlobal * _translate * _rotateLocal * _scale;
        }

         inline void setRotation(glm::vec3 &angles){
            glm::mat4 rotate = _rotateGlobal;
            rotate = glm::rotate(rotate, angles[2], glm::vec3(0.f, 0.f, 1.f));
            rotate = glm::rotate(rotate, angles[1], glm::vec3(0.f, 1.f, 1.f));
            rotate = glm::rotate(rotate, angles[0], glm::vec3(1.f, 0.f, 1.f));
            _rotateGlobal = rotate;
        } 
        
        
    };
	
}

#endif
