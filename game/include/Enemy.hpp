// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ENEMY.HPP ___________ 
//================================

#ifndef __ENEMY__HPP
#define __ENEMY__HPP

// Includes 
#include "EventObject.hpp"

namespace RUNBOXRUN
{
	/// \class Enemy
	/// \brief class defining a new Enemy .
	class Enemy : public EventObject
	{
			
		public:
		Enemy();/*!<default constructor*/
		Enemy(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color); /*!< constructor width parameters */
		Enemy(const Enemy &enemy); /*!< constructor by copy */
		~Enemy();/*!< default destructor*/

		//void displayInfos(); /*!< display of enemy's informations */

		private:

	};
}

#endif
