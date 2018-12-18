#ifndef TRACKBALLCAMERA_H__
#define TRACKBALLCAMERA_H__

#include <glimac/glm.hpp>
#include <glimac/Camera.hpp>

namespace glimac {

class TrackballCamera : public Camera {
    private:
        float m_fDistance;
        float m_fAngleX;
        float m_fAngleY;
    public:
        TrackballCamera(float distance = 5.f, float angleX = 0.f, float angleY = 0.f);
        void moveFront(float delta);
        void rotateLeft(float degrees);
        void rotateUp(float degrees);
        glm::mat4 getViewMatrix() const override;
        /*glm::vec3 getVectorDirection() const;*/
};

}


#endif