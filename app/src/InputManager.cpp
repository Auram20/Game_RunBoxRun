// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.CPP ___________ 
//================================


#include <app/InputManager.hpp>

namespace RUNBOXRUN {


	// --------------- CONSTRUCTORS && DESTRUCTORS --------------
	InputManager::InputManager()
	: _inputs()
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

	InputManager::~InputManager() {
		delete _instance;
	}

	InputManager *InputManager::getInstance() {
		if(_instance == nullptr) {
			_instance = new InputManager();	
		}
		return _instance;
	}

	InputManager* InputManager::_instance = nullptr;

}