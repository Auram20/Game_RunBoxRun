// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ COIN.CPP ___________ 
//================================


#include "../include/Coin.hpp"
#include <iostream>

using namespace RUNBOXRUN;

Coin::Coin()
: _value(0)
{}

Coin::Coin(const unsigned int value)
: _value(value)
{}

Coin::Coin(const Coin &coin)
: Coin(coin._value)
{}

void const Coin::displayInfos() const
{
	std::cout << "value : " << _value << std::endl;
}

Coin::~Coin()
{}


