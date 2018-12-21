// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ OBJECT.CPP ___________ 
//================================


#include "game/Object.hpp"
#include <iostream>

using namespace RUNBOXRUN;

// --------------- CONSTRUCTORS && DESTRUCTORS --------------

Object::Object()
: _speed(1), _position(glm::vec3(0)), _size(glm::vec3(10)), _color(glm::vec3(100)), _pathObj(" ")
{}

Object::Object(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const std::string &pathObj)
: _speed(speed), _position(position), _size(size), _color(color), _pathObj(pathObj)
{}

Object::Object(const Object &object)
: _speed(object._speed) , _position(object._position), _size(object._size), _color(object._color), _pathObj(object._pathObj)
{}


Object::~Object()
{}



// --------------- OBJECT'S FUNCTIONS --------------


void  Object::displayInfos() 
{
	std::cout << "speed: " << _speed << std::endl
	<< "position : " << _position << std::endl
	<< "size : " << _size << std::endl
	<< "color : " << _color << std::endl;
}


void Object::moveHorizontal(const double &t)
{
	_position.y += t;
}



