// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.HPP_____ 
//================================

#ifndef __INPUTMANAGER__HPP
#define __INPUTMANAGER__HPP

#include <app/Input.hpp>
#include <vector>
#include <iostream>

namespace RUNBOXRUN
{
	/// \class Bonus
	/// \brief class defining a new bonus.
	class InputManager
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		static InputManager *getInstance();



		private:
			static InputManager *_instance;
			InputManager(); /*!< default constructor */
			std::vector<Input> _inputs;
			~InputManager(); /*!< default destructor*/
	};
}

#endif