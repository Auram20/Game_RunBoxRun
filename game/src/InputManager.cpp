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
	Player* p = Player::getInstance();
	std::function<void(Player*)> move = [] (Player* p) {};


	_inputs.push_back(Input(SDLK_z, move));

	move = [] (Player* p) {
		p->jump(1.0); 
	};


	_inputs.push_back(Input(SDLK_q, move));

	move = [] (Player* p) {
		p->moveHorizontal(-1.0); // left
	};


	_inputs.push_back(Input(SDLK_s, move));

	move = [] (Player* p) {
		p->jump(-1.0);

	};

		std::cout << " Apres changement " << std::endl;
		p->displayInfos();
		
	_inputs.push_back(Input(SDLK_d, move));

	move = [] (Player* p) {
		p->moveHorizontal(1.0); // right
	};
}
