// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MAP.HPP ___________ 
//================================

#ifndef __MAP__HPP
#define __MAP__HPP

// Includes 
#include "EventObject.hpp"
#include <utils/FilePath.hpp>

namespace RUNBOXRUN
{
	/// \class Map
	/// \brief class defining a new coin.
	class Map
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
