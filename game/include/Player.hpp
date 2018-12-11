// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYER.HPP ___________ 
//================================

#ifndef __PLAYER__HPP
#define __PLAYER__HPP

// Includes 
#define GLM_ENABLE_EXPERIMENTAL
#include <glm.hpp>
#include "Object.hpp"

namespace RUNBOXRUN
{
	/// \class Player
	/// \brief class defining a new player.
	class Player : public Object
	{
			
		public:
		Player();
		~Player(); 

		private:
		unsigned int _health; /*!< health points of the player */
		unsigned int _jumpState;  /*!< check if player is jumping/crouching/standing */	

	};
}


#endif
