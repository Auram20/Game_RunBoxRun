// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYER.HPP ___________ 
//================================

#ifndef __PLAYER__HPP
#define __PLAYER__HPP

// Includes 
#include <glm.hpp>




/// \class Player
/// \brief class defining a new player.
class Player
{
		
	public:
	Player();
	~Player(); 



	private:
	unsigned int _health; /*!< health points of the player */
	unsigned int _jumpState;  /*!< check if player is jumping/crouching/standing */	
	glm::vec3 _position ;  /*!< player's position */


};

#endif
