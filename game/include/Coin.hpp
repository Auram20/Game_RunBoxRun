// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ COIN.HPP ___________ 
//================================

#ifndef __COIN__HPP
#define __COIN__HPP

// Includes 
#include "EventObject.hpp"

namespace RUNBOXRUN
{
	/// \class Coin
	/// \brief class defining a new coin.
	class Coin : public EventObject
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		Coin(); /*!< default constructor */
		Coin(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int value);  /*!<constructor with arguments */
		Coin(const Coin &coin); /*!< coin's constructor by copy */
		~Coin(); /*!< default destructor */


		// COIN FUNCTIONS
		virtual void displayInfos() ; /*!< display of coin's informations */





		private:
		unsigned int _value; /*!< coin's value */
    };
}

#endif
