// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.CPP ___________ 
//================================


#include <app/InputManager.hpp>

namespace RUNBOXRUN {


	// --------------- CONSTRUCTORS && DESTRUCTORS --------------
	InputManager::InputManager()
	: _inputs(), _observablesMouse(), _cursor(0, 0)
	{

	}

	void InputManager::execute(const SDL_Event &e) {

            if(e.type == SDL_QUIT) {
                //update(EventCode::QUITEVENT);
            }

            if(e.type == SDL_KEYDOWN) {
                update(e.key.keysym.sym);
            }

			if(e.type == SDL_MOUSEMOTION) {
				updateMouse();
			}
        
	}

	InputManager::~InputManager() {
		_instance = nullptr;
	}

	InputManager *InputManager::getInstance() {
		if(_instance == nullptr) {
			_instance = new InputManager();	
		}
		return _instance;
	}

	InputManager* InputManager::_instance = nullptr;

}