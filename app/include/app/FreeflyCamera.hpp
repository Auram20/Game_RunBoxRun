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
            glm::vec3 m_Position;
            float m_fPhi;
            float m_fTheta;
            glm::vec3 m_FrontVector;
            glm::vec3 m_LeftVector;
            glm::vec3 m_UpVector;

            void computeDirectionVectors();
        public:
            FreeflyCamera();
            void moveFront(float t);
            void moveLeft(float t);
            void moveUp(float t);
            void rotateLeft(float degrees);
            void rotateUp(float degrees);
            void translateZ(float t) override;
            void translateX(float t) override;
            void translateY(float t) override;
            const glm::mat4 getViewMatrix() const override;
    };
}

#endif