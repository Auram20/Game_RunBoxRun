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
		std::function<void()> move = [] () {};


		_inputs.emplace(SDLK_z, Input(move));

		move = [] () {
			Player* p = Player::getInstance();
			p->jump(1.0);
			std::cout << " Apres changement " << std::endl;
			p->displayInfos();
		};

		_inputs.emplace(SDLK_q, Input(move));

		move = [] () {
			Player* p = Player::getInstance();
			p->moveHorizontal(-1.0); // left
			std::cout << " Apres changement " << std::endl;
			p->displayInfos();
		};

		_inputs.emplace(SDLK_s, Input(move));

		move = [] () {
			Player* p = Player::getInstance();
			p->jump(-1.0);
			std::cout << " Apres changement " << std::endl;
			p->displayInfos();
		};


		_inputs.emplace(SDLK_d, Input(move));

		move = [] () {
			Player* p = Player::getInstance();
			p->moveHorizontal(1.0); // right
			std::cout << " Apres changement " << std::endl;
			p->displayInfos();
		};

		_inputs.emplace(SDLK_a, Input(move));

		move = [] () {
			Player* p = Player::getInstance();
			p->moveHorizontal(1.0); // right
			std::cout << " Apres changement " << std::endl;
			p->displayInfos();
		};

		_inputs.emplace(SDLK_ESCAPE, Input(move));
	}

	void InputManager::call(const SDLKey &key) {
		if(_inputs.find(key) != _inputs.end())
			_inputs.at(key).call();
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