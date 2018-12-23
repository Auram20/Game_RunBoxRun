// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.HPP_____ 
//================================

#ifndef __INPUTMANAGER__HPP
#define __INPUTMANAGER__HPP

#include <map>
#include <iostream>
#include <utils/Observer.hpp>
#include <vector>
#include <SDL/SDL.h>

namespace RUNBOXRUN
{

	enum class EventCode {
		MOUSEEVENT,
		KEYDOWNEVENT,
		KEYUPEVENT,
		QUITEVENT
	};

	struct Input {
		// CONSTRUCTORS & DESTRUCTOR
		Input(const bool isContinuous = false)
		: _isActive(false), _isContinuous(isContinuous)
		{}; /*!< Input's constructor with parameters*/
		~Input() = default; /*!< default destructor*/


		bool _isActive;
		bool _isContinuous;
	};


	/// \class Bonus
	/// \brief class defining the input manager.
	class InputManager
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		static InputManager *getInstance();
		void execute(const SDL_Event &e);
		inline void attach(const EventCode &eCode, utils::AbstractObserver *o) {
			_observers.at(eCode).push_back(o);
			std::cout << "push" << std::endl;
		}

		inline void update(const EventCode &eCode) const {
			std::vector<utils::AbstractObserver*> temp = _observers.at(eCode);
			std::cout << temp.size() << std::endl;
			for(auto it = temp.begin(); it != temp.end(); ++it) {
				std::cout << "zup" << std::endl;
				(*it)->update();
			}
		}

		private:
			static InputManager *_instance;
			InputManager(); /*!< default constructor */
			std::map<EventCode, std::vector<utils::AbstractObserver*>> _observers;
			std::map<SDLKey, Input> _inputs;
			~InputManager(); /*!< default destructor*/
	};
}

#endif