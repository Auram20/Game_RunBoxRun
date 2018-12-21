// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ OBSTACLE.CPP ___________ 
//================================


#include "game/Obstacle.hpp"
#include <iostream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------

Obstacle::Obstacle()
: EventObject()
{}

Obstacle::Obstacle(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const std::string &type, const std::string &pathObj)
: EventObject(speed, position, size, color, pathObj), _type(type)
{}


Obstacle::Obstacle(const Obstacle &obstacle)
: EventObject(obstacle._speed, obstacle._position, obstacle._size, obstacle._color, obstacle._pathObj), _type(obstacle._type)
{}

Obstacle::~Obstacle()
{}


// --------------- OBSTACLE'S FUNCTIONS --------------

void Obstacle::displayInfos()
{
	std::cout << "\n------------ OBSTACLE INFORMATIONS ------------" << std::endl;
	Object::displayInfos();
	std::cout << "type : " << _type << std::endl;
}
