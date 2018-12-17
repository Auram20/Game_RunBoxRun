// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUT.HPP_____ 
//================================

#ifndef __INPUT__HPP
#define __INPUT__HPP

#include <SDL/SDL.h>
#include <functional>
#include "../include/Player.hpp"

namespace RUNBOXRUN
{
	/// \class Bonus
	/// \brief class defining a new bonus.
	class Input
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		Input(const SDLKey &key, std::function<void(Player* p)> &action); /*!< bonus's constructor with parameters*/
		~Input() = default; /*!< default destructor*/

		inline void call() const {
			//_action();
		}


		private:
			bool _active;
			SDLKey _key;
			std::function<void(Player* p)> _action;

	};
}

#endif