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
<<<<<<< HEAD
	/// \class Player
	/// \brief class defining a new player.
	class Player : public Object
	{
			
		public:
		Player();
		~Player(); 
=======
		
	public:
	/// \brief constructor default
	Player();
	/// \brief destructor
	//~Player(); 

>>>>>>> 5b890efd46a76dcf4278e34f632b2eebde2a0e02



<<<<<<< HEAD
		private:
		unsigned int _health; /*!< health points of the player */
		unsigned int _jumpState;  /*!< check if player is jumping/crouching/standing */	

	};
}
=======
};
>>>>>>> 5b890efd46a76dcf4278e34f632b2eebde2a0e02

#endif
