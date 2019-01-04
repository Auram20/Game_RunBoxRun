#ifndef TRACKBALLCAMERA_H__
#define TRACKBALLCAMERA_H__

#include <utils/glm.hpp>
#include <glimac/Camera.hpp>

namespace glimac {

class TrackballCamera : public Camera {
    private:
        glm::vec3 m_PosTarget;
        float m_fDistance;
        float m_fAngleX;
        float m_fAngleY;
    public:
        TrackballCamera(float distance = 5.f, float angleX = 0.f, float angleY = 0.f, glm::vec3 posTarget = glm::vec3(0, 0, 0));
        void moveFront(float delta);
        void rotateLeft(float degrees);
        void rotateUp(float degrees);
        void translateZ(float t) override;
        void translateX(float t) override;
        void translateY(float t) override;
        const glm::mat4 getViewMatrix() const override;
        /*glm::vec3 getVectorDirection() const;*/
};

}


#endif