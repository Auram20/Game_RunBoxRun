// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BONUS.CPP ___________ 
//================================


#include <game/Bonus.hpp>
#include <iostream>

using namespace RUNBOXRUN;



// --------------- CONSTRUCTORS && DESTRUCTORS --------------
Bonus::Bonus()
: EventObject()
{}

Bonus::Bonus(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &value, const Model &model)
: EventObject(speed, position, size, color, model), _value(value)
{}

Bonus::Bonus(const Bonus &bonus)
: EventObject(bonus._speed, bonus._position, bonus._size, bonus._color, bonus._model) , _value(bonus._value)
{}





// --------------- BONUS'S FUNCTIONS --------------

void  Bonus::displayInfos()  
{

	std::cout << "\n------------ BONUS INFORMATIONS ------------" << std::endl;
	Object::displayInfos();
	std::cout << "value : " << _value << std::endl;
}


Bonus::~Bonus()
{}
