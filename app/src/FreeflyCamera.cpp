#include "app/FreeflyCamera.hpp"

using namespace glimac;

FreeflyCamera::FreeflyCamera()
: m_Position(0, 0, 0), m_fPhi(glm::pi<float>()), m_fTheta(0)
{
    computeDirectionVectors();
}

void FreeflyCamera::computeDirectionVectors() {
    m_FrontVector = glm::vec3(glm::cos(m_fTheta) * glm::sin(m_fPhi), glm::sin(m_fTheta), glm::cos(m_fTheta) * glm::cos(m_fPhi));
    m_LeftVector = glm::vec3(glm::sin(m_fPhi + glm::half_pi<float>()), 0, glm::cos(m_fPhi + glm::half_pi<float>()));
    m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}


void FreeflyCamera::translateZ(float t) {
    moveFront(t);
}

void FreeflyCamera::translateX(float t) {
    moveLeft(t);
}

void FreeflyCamera::translateY(float t) {
    moveUp(t);
}

void FreeflyCamera::moveLeft(float t) {
    m_Position += t * m_LeftVector;
}

void FreeflyCamera::moveFront(float t) {
    m_Position += t * m_FrontVector;
}

void FreeflyCamera::moveUp(float t) {
    m_Position += t * m_UpVector;
}

void FreeflyCamera::rotateLeft(float degrees) {
    m_fPhi += glm::radians(degrees);
    computeDirectionVectors();
}

void FreeflyCamera::rotateUp(float degrees) {
    m_fTheta += glm::radians(degrees);
    computeDirectionVectors();
}

const glm::mat4 FreeflyCamera::getViewMatrix() const {
    return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
}