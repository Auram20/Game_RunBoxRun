// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.HPP ___________ 
//================================

#ifndef __INPUTMANAGER__HPP
#define __INPUTMANAGER__HPP


namespace INPUTMANAGER
{
	/// \class Bonus
	/// \brief class defining a new bonus.
	class InputManager
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		InputManager(const SDL_Event e); 
		InputManager() = default ; /*!< default constructor */
		~InputManager() = default ; /*!< default destructor*/

	};
}

#endif
