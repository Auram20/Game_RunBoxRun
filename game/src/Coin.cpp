// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ COIN.CPP ___________ 
//================================


#include "game/Coin.hpp"
#include <iostream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------
Coin::Coin()
: EventObject()
{}
//: EventObject(1, glm::vec3(0), glm::vec3(10), glm::vec3(100), _value(0))
//{}

Coin::Coin(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int value)
:  EventObject(speed, position, size, color), _value(value)
{}

Coin::Coin(const Coin &coin)
: Coin(coin._speed, coin._position, coin._size, coin._color, coin._value)
{}

Coin::~Coin()
{}



// --------------- COIN'S FUNCTIONS --------------

void Coin::displayInfos() 
{
	std::cout << "\n------------ COIN INFORMATIONS ------------" << std::endl;
	Object::displayInfos();
	std::cout << "value : " << _value << std::endl;
}


