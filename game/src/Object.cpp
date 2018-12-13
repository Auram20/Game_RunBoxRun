// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ OBJECT.CPP ___________ 
//================================


#include "../include/Object.hpp"
#include <iostream>

using namespace RUNBOXRUN;

Object::Object()
{}

Object::Object(const double &speed, const glm::vec3 &position)
: _speed(speed), _position(position)
{}
