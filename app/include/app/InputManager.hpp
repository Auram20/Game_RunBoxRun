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
	class InputManager : public utils::EventManager<EventCode>
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		static InputManager *getInstance();
		void execute(const SDL_Event &e);

		private:
			static InputManager *_instance;
			InputManager(); /*!< default constructor */
			std::map<SDLKey, Input> _inputs;
			~InputManager(); /*!< default destructor*/
	};
}

#endif