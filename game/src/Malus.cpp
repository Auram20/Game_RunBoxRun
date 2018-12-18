// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MALUS.CPP ___________ 
//================================


#include <game/Malus.hpp>
#include <iostream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------
Malus::Malus()
: EventObject()
{}

Malus::Malus(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const std::string &type)
: EventObject(speed, position, size, color), _type(type)
{}

Malus::Malus(const Malus &malus)
: EventObject(malus._speed, malus._position, malus._size, malus._color), _type(malus._type)
{}

Malus::~Malus()
{}


// --------------- MALUS'S FUNCTIONS --------------

void Malus::displayInfos()
{
	std::cout << "\n------------ MALUS INFORMATIONS ------------" << std::endl;
	Object::displayInfos();
	std::cout << "type : " << _type << std::endl;
}
