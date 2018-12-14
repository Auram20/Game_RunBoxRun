// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ OBJECT.CPP ___________ 
//================================


#include "../include/Object.hpp"
#include <iostream>

using namespace RUNBOXRUN;

Object::Object()
: _speed(1), _position(glm::vec3(0)), _size(glm::vec3(10)), _color(glm::vec3(100))
{}

Object::Object(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color)
: _speed(speed), _position(position), _size(size), _color(color)
{}

Object::Object(const Object &object)
: _speed(object._speed) , _position(object._position), _size(object._size), _color(object._color)
{}

/*
void const displayInfos() const
{
	std::cout << "size : " << _size << std::endl
	<< "position : " << _position << std::endl
	<< "speed: " << _speed << std::endl
	<< "color : " << _color << std::endl;
}
*/

Object::~Object()
{}
