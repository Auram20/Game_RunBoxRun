#ifndef TRACKBALLCAMERA_H__
#define TRACKBALLCAMERA_H__

#include <utils/glm.hpp>
#include <app/Camera.hpp>

namespace glimac {

    /// \class TrackBallCamera
    /// \brief class for TrackBallCamera.
    /*!< Cette classe est la caméra qui permet de voir au  niveau du joueur*/

class TrackballCamera : public Camera {
    private:
        glm::vec3 m_PosTarget;
        float m_fDistance;// distance from the scene
        float m_fAngleX;// angle added on the X axis
        float m_fAngleY; // angle added on the Y axis
    public:
        TrackballCamera(float distance = 5.f, float angleX = 0.f, float angleY = 0.f, glm::vec3 posTarget = glm::vec3(0, 0, 0));
        void moveFront(float delta); /*!< move camera on Z axis */
        void rotateLeft(float degrees); /*!< rotate camera on horizontal axis */
        void rotateUp(float degrees); /*!< rotate camera on vertical axis */
        void translateZ(float t) override;  /*!< translate camera on Z axis */
        void translateX(float t) override; /*!< translate camera on X axis */
        void translateY(float t) override;/*!< translate camera on Y axis */
        const glm::mat4 getViewMatrix() const override; /*!< implement getViewMatrix() of Camera's class */
        /*glm::vec3 getVectorDirection() const;*/
};

}


#endif