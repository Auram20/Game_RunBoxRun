// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BONUS.HPP ___________ 
//================================

#ifndef __BONUS__HPP
#define __BONUS__HPP

// Includes 
#include "EventObject.hpp"

namespace RUNBOXRUN
{
	/// \class Bonus
	/// \brief class defining a new bonus.
	class Bonus: public EventObject
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		Bonus(); /*!< default constructor */
		Bonus(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &value); /*!< bonus's constructor with parameters*/
		Bonus(const Bonus &bonus); /*!< bonus's constructor by copy*/
		~Bonus(); /*!< default destructor*/

		// GETTERS
		inline const unsigned int getValue() const { return _value; }/*!< get bonus value*/

		// BONUS FUNCTIONS
		virtual void displayInfos()  ; /*!< display bonus's informations */






		private:
		unsigned int _value; /*!< bonus's value */
	};
}

#endif
