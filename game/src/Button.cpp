// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BUTTON.CPP ___________ 
//================================


#include "../include/Button.hpp"
#include <iostream>

using namespace RUNBOXRUN;

// --------------- CONSTRUCTORS && DESTRUCTORS --------------
Button::Button()
: _width(0), _height(0), _backgroundColor(glm::vec3(255)) , _frontColor(glm::vec3(0)), _description(" ")
{}

Button::Button(const unsigned int &width, const unsigned int &height, const std::string &description)
: _width(width), _height(height), _description(description)
{}

Button::Button(const unsigned int &width, const unsigned int &height, const glm::vec3 &backgroundColor, const glm::vec3 &frontColor, const std::string &description)
: _width(width), _height(height), _backgroundColor(backgroundColor), _frontColor(frontColor), _description(description)
{}

Button::Button(const Button &button)
: _width(button._width), _height(button._height), _backgroundColor(button._backgroundColor), _frontColor(button._frontColor), _description(button._description)
{}

Button::~Button()
{}


// --------------- BUTTON'S FUNCTIONS --------------
/*
void Button::displayInfos()
{
	std::cout << "width : " << _width << std::endl
	<< "height : " << _height << std::endl
	<< "color of front : " << _frontColor << std::endl
	<< " color of background : " << _backgroundColor << std::endl
	<< " description : " <<  _description << std::endl;
}
*/
