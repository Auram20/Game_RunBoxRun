// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BONUS.CPP ___________ 
//================================


#include "../include/Bonus.hpp"
#include <iostream>

using namespace RUNBOXRUN;

Bonus::Bonus()
: EventObject()
{}

Bonus::Bonus(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &value)
: EventObject(speed, position, size, color), _value(value)
{}

Bonus::Bonus(const Bonus &bonus)
: EventObject(bonus._speed, bonus._position, bonus._size, bonus._color) , _value(bonus._value)
{}

/*
void const Bonus::displayInfos() const 
{
	Object::displayInfos();
	std::cout << "value : " << _value << std::endl;
}
*/

Bonus::~Bonus()
{}
