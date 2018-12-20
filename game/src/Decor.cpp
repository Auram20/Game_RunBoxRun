// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ DECOR.CPP ___________ 
//================================


#include <game/Decor.hpp>
#include <iostream>
#include <glimac/Model.hpp>

using namespace glimac;

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------

Decor::Decor()
: Object()
{}

Decor::Decor(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const Model &model)
: Object(speed, position, size, color, model)
{}

Decor::Decor(const Decor &decor)
: Decor(decor._speed, decor._position, decor._size, decor._color, decor._model)
{}

Decor::~Decor()
{}


// --------------- DECOR'S FUNCTIONS --------------


void  Decor::displayInfos() 
{
	std::cout << "\n------------ DECOR'S INFORMATIONS ------------" << std::endl;
	Object::displayInfos();

}