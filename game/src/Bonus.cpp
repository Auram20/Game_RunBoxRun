// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BONUS.CPP ___________ 
//================================


#include "../include/Bonus.hpp"
#include <iostream>

using namespace RUNBOXRUN;

Bonus::Bonus()
{}

Bonus::Bonus(const unsigned int &value)
: EventObject(), _value(value)
{}

Bonus::Bonus(const Bonus &bonus)
: Bonus(bonus._value)
{}

void Bonus::displayInfos()
{
	std::cout << "value : " << _value << std::endl;
}

Bonus::~Bonus()
{}
