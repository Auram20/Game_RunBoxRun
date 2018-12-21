// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MALUS.HPP ___________ 
//================================

#ifndef __MALUS__HPP
#define __MALUS__HPP

// Includes 
#include "EventObject.hpp"
#include <string>

namespace RUNBOXRUN
{
	/// \class Malus
	/// \brief class defining a new malus.
	class Malus: public EventObject
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		Malus(); /*!< default constructor */
		Malus(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const std::string &type); /*!< malus's constructor with arguments*/
		Malus(const Malus &malus); /*!< constructor by copy */
		~Malus(); /*!< default destructor */

		
		// MALUS FUNCTIONS
		virtual void displayInfos(); /*!< display infos */

			
		
		private:
		std::string _type; /*!< type of malus */
	};
}

#endif
