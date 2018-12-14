// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ DECOR.HPP ___________ 
//================================

#ifndef __DECOR__HPP
#define __DECOR__HPP

// Includes 
#include "Object.hpp"

namespace RUNBOXRUN
{
	/// \class Decor
	/// \brief class defining a new decor.
	class Decor : public Object
	{
			
		public:
		// Constructors && Destructor
		Decor();/*!<default constructor*/
		Decor(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color); /*!< constructor width parameters */
		Decor(const Decor &decor); /*!< constructor by copy */
		~Decor(); /*!< default destructor*/

		// Setters
		inline void setColor( const unsigned int r, const unsigned int v , const unsigned int b ) {_color.x = r; _color.y = v; _color.z = b; }/*!< set decor's object's color */

		// Decor's Functions
		virtual void displayInfos(); /*!< display of decor's informations */
	

		private:
	};
}

#endif
