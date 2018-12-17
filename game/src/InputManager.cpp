// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.CPP ___________ 
//================================


#include "../include/InputManager.hpp"
#include <iostream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------
InputManager::InputManager()
{

	std::function<void()> move = [] () {};

	_inputs.push_back(Input(SDLK_z, move));
	move = [] () {

	};

	_inputs.push_back(Input(SDLK_q, move));
	move = [] () {};

	_inputs.push_back(Input(SDLK_s, move));
	move = [] () {};

	_inputs.push_back(Input(SDLK_d, move));
	move = [] () {};
}

//constructeur player seulement appelé par la méthode static 
// le constructeur est privé
// méthode static dans la classe player qui instancie le player en singleton
// attribut 'one'
