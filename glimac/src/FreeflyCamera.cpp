#include "glimac/FreeflyCamera.hpp"

/*TrackballCamera::TrackballCamera(float distance, float angleX, float angleY)
: m_fDistance(distance), m_fAngleX(angleX), m_fAngleY(angleY)
{

}

void TrackballCamera::moveFront(float delta) {
    m_fDistance += delta;
}

void TrackballCamera::rotateLeft(float degrees) {
    m_fAngleY += degrees;
}

void TrackballCamera::rotateUp(float degrees) {
    m_fAngleX += degrees;
}

glm::mat4 TrackballCamera::getViewMatrix() const {
    glm::mat4 viewMatrix =  glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, -m_fDistance));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(0.f, 1.f, 0.f));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(1.f, 0.f, 0.f));
    return viewMatrix;
}*/