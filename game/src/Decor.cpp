// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ DECOR.CPP ___________ 
//================================


#include "game/Decor.hpp"
#include <iostream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------

Decor::Decor()
: Object()
{}

Decor::Decor(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color)
: Object(speed, position, size, color)
{}

Decor::Decor(const Decor &decor)
: Decor(decor._speed, decor._position, decor._size, decor._color)
{}

Decor::~Decor()
{}


// --------------- DECOR'S FUNCTIONS --------------


void  Decor::displayInfos() 
{
	std::cout << "\n------------ DECOR'S INFORMATIONS ------------" << std::endl;
	Object::displayInfos();

}