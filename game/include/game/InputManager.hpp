// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.HPP_____ 
//================================

#ifndef __INPUTMANAGER__HPP
#define __INPUTMANAGER__HPP

#include <game/Input.hpp>
#include  <vector>
#include <game/Player.hpp>
#include <iostream>

namespace RUNBOXRUN
{
	/// \class Bonus
	/// \brief class defining a new bonus.
	class InputManager
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		InputManager(); /*!< default constructor */
		~InputManager() = default; /*!< default destructor*/


		private:
			std::vector<Input> _inputs;
	};
}

#endif