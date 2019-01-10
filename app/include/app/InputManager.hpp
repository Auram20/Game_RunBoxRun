// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.HPP_____ 
//================================

#ifndef __INPUTMANAGER__HPP
#define __INPUTMANAGER__HPP

#include <iostream>
#include <utils/EventManager.hpp>
#include <vector>
#include <SDL/SDL.h>
#include <utils/glm.hpp>

namespace RUNBOXRUN
{

	enum class EventCode {
		MOUSEEVENT,
		KEYDOWNEVENT,
		KEYUPEVENT,
		QUITEVENT
	};

	class InputManager;

	class Input {

		public:
		// CONSTRUCTORS & DESTRUCTOR
		Input(const bool isContinuous = false)
		: _isActive(false), _isContinuous(isContinuous), _observables()
		{

		} /*!< Input's constructor with parameters*/
		Input(const Input &input)
		: _isActive(input._isActive), _isContinuous(input._isContinuous), _observables(input._observables)
		{

		}
		~Input() = default; /*!< default destructor*/

		inline void attach(utils::Observable<InputManager>** target, const unsigned int &id) {
			auto it = _observables.find(target);
			if(it != _observables.end()) {
				(it->second).emplace(id);
			} else {
				_observables.emplace(target, std::set<unsigned int>({id}));
			}
		}

		inline const std::map<utils::Observable<InputManager>**, std::set<unsigned int>>::iterator begin() {
			return _observables.begin();
		}

		inline const std::map<utils::Observable<InputManager>**, std::set<unsigned int>>::iterator end() {
			return _observables.end();
		}

		inline void turnOn() {
			_isActive = true;
		}

		inline void turnOff() {
			_isActive = false;
		}

		inline bool hasToContinue() const {
			return _isActive && _isContinuous;
		}

		inline const bool isActive() const {
			return _isActive;
		}

		private:
		bool _isActive;
		bool _isContinuous;
		std::map<utils::Observable<InputManager>**, std::set<unsigned int>> _observables;
	};

	/// \class Bonus
	/// \brief class defining the input manager.
	class InputManager : public utils::EventManager<InputManager>
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
		static InputManager *getInstance();
		void execute(const SDL_Event &e);
		static const glm::ivec2 getMousePosition() {
			glm::ivec2 mousePos;
			SDL_GetMouseState(&mousePos.x, &mousePos.y);
			return mousePos;
		}
		
		inline void setMousePosition() {
			SDL_GetMouseState(&_cursor.x, &_cursor.y);
		}

		inline bool pollEvent(SDL_Event& e) {
			return SDL_PollEvent(&e);
		}

		inline bool isKeyPressed(SDLKey key) const {
			return SDL_GetKeyState(nullptr)[key];
		}

		// button can SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT and SDL_BUTTON_MIDDLE
		inline bool isMouseButtonPressed(uint32_t button) const {
			return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(button);
		}

		inline const glm::ivec2 mousePosition() const {
			return _cursor;
		}


		inline int attachKey(utils::Observable<InputManager> &target, const SDLKey &key, const std::function<void(InputManager&)> &action) {
			int id = utils::EventManager<InputManager>::attach(target, action);
			if(id == -1) return -1;
			auto it = _inputs.find(key);
			if(it != _inputs.end()) {
				(it->second).attach(target.ptr(), id);
			} else {
				Input newInput;
				newInput.attach(target.ptr(), id);
				_inputs.emplace(key, newInput);
			}
			return id;
		}

		inline int attachMouse(utils::Observable<InputManager> &target, const std::function<void(InputManager&)> &action) {
			int id = utils::EventManager<InputManager>::attach(target, action);
			if(id == -1) return -1;
			auto it = _observablesMouse.find(target.ptr());
			if(it != _observablesMouse.end()) {
				(it->second).emplace(id);
			} else {
				_observablesMouse.emplace(target.ptr(), std::set<unsigned int>({uint(id)}));
			}
			return id;
		}

		inline void update(const SDLKey &key) {
			std::map<SDLKey, Input>::iterator input = _inputs.find(key);
			if(input == _inputs.end()) return;

			if(!(input->second).isActive()) {
				(input->second).turnOn();
			}
			else {
				return;
			}

			for(auto it = (input->second).begin(); it != (input->second).end(); ++it) {
				utils::EventManager<InputManager>::update(it->first, it->second, *this);
			}


			if(!(input->second).hasToContinue()) (input->second).turnOff();
		}

		inline void updateMouse() {
			for(auto it = _observablesMouse.begin(); it != _observablesMouse.end(); ++it) {
				utils::EventManager<InputManager>::update(it->first, it->second, *this);
			}
		}

		inline void turnOff(const SDLKey &key) {
			std::map<SDLKey, Input>::iterator it = _inputs.find(key);
			if(it == _inputs.end()) return;
			(it->second).turnOff();
		}

		inline void updateAll() {
			utils::EventManager<InputManager>::updateAll(*this);
		}

		inline void clearAll() override {
			_inputs.clear();
			_observablesMouse.clear();
			EventManager::clearAll();
		}

		inline static void clearInstance() {
			if(_instance != nullptr) {
				_instance->clearAll();
			}
		}

		private:
			static InputManager *_instance;
			InputManager(); /*!< default constructor */
			std::map<SDLKey, Input> _inputs;
			std::map<utils::Observable<InputManager>**, std::set<unsigned int>> _observablesMouse;
			~InputManager(); /*!< default destructor*/
			glm::ivec2 _cursor;
	};
}

#endif