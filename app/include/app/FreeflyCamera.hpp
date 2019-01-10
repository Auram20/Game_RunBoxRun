// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ FREEFLYCAMERA.HPP ___________ 
//================================


#ifndef FREEFLYCAMERA_H__
#define FREEFLYCAMERA_H__

#include <app/Camera.hpp>

namespace glimac {
    
    class FreeflyCamera : public Camera {
        private:
            glm::vec3 m_Position; // Position x,y and z
            float m_fPhi; // angle of rotation
            float m_fTheta; 
            glm::vec3 m_FrontVector;
            glm::vec3 m_LeftVector;
            glm::vec3 m_UpVector;

            void computeDirectionVectors();
        public:
            FreeflyCamera(); /*!< cosntructor */
            void moveFront(float t); /*!< move camera on Z axis */
            void moveLeft(float t); /*!< move camera on X axis */ 
            void moveUp(float t); /*!< move camera on Y axis */
            void rotateLeft(float degrees); /*!< rotate camera on horizontal axis */
            void rotateUp(float degrees); /*!< rotate camera on vertical axis */
            void translateZ(float t) override; /*!< translate camera on Z axis */
            void translateX(float t) override; /*!< translate camera on X axis */
            void translateY(float t) override; /*!< translate camera on Y axis */
            const glm::mat4 getViewMatrix() const override; /*!< implement getViewMatrix() of Camera's class */
    };
}

#endif