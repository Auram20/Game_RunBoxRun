#include <glimac/TrackballCamera.hpp>
#include <math.h>
#include <iostream>

using namespace glimac;

TrackballCamera::TrackballCamera(float distance, float angleX, float angleY)
: m_fDistance(distance), m_fAngleX(angleX), m_fAngleY(angleY)
{

}

void TrackballCamera::moveFront(float delta) {
    m_fDistance += delta;
}

void TrackballCamera::rotateLeft(float degrees) {
    if(m_fAngleY <= -90)
    {
        if(degrees>0)
        {
            std::cout<< "angleY : " << m_fAngleY << std::endl;
            m_fAngleY += degrees;
        }
           
    }
    else if(m_fAngleY >= 90)
    {
        if(degrees<0)
        {
            std::cout<< "angleY : " << m_fAngleY << std::endl;
            m_fAngleY += degrees;
        }
    }
    if(m_fAngleY > -90 && m_fAngleY < 90)
    {
        std::cout<< "angleY : " << m_fAngleY << std::endl;
        m_fAngleY += degrees;
    }
            
}


void TrackballCamera::rotateUp(float degrees) {
    m_fAngleX += degrees;
}

glm::mat4 TrackballCamera::getViewMatrix() const {
    glm::mat4 viewMatrix =  glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, -m_fDistance));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(0.f, 1.f, 0.f));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(1.f, 0.f, 0.f));
    return viewMatrix;
}

/*glm::vec3 TrackballCamera::getVectorDirection() const {
    glm::vec4 vector =  glm::vec4(0.f, 0.f, m_fDistance, 0.f);
    vector = glm::rotate(glm::mat4(1.f), glm::radians(m_fAngleY), glm::vec3(0.f, 1.f, 0.f)) * vector;
    vector = glm::rotate(glm::mat4(1.f), glm::radians(m_fAngleX), glm::vec3(1.f, 0.f, 0.f)) * vector;
    return glm::vec3(vector);
}*/