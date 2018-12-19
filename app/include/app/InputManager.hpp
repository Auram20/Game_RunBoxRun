// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.HPP_____ 
//================================

#ifndef __INPUTMANAGER__HPP
#define __INPUTMANAGER__HPP

#include <app/Input.hpp>
#include <map>
#include <iostream>

namespace RUNBOXRUN
{
	/// \class Bonus
	/// \brief class defining the input manager.
	class InputManager
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		static InputManager *getInstance();
		void call(const SDLKey &key);


		private:
			static InputManager *_instance;
			InputManager(); /*!< default constructor */
			std::map<SDLKey, Input> _inputs;
			~InputManager(); /*!< default destructor*/
	};
}

#endif