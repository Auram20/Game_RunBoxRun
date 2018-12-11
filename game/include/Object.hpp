// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ OBJECT.HPP ___________ 
//================================

#ifndef __OBJECT__HPP
#define __OBJECT__HPP

// Includes 
#include <glm.hpp>

namespace RUNBOXRUN
{
	/// \class Object
	/// \brief class defining a new object.
	class Object
	{
			
		public:
		Object();
		//~Object(); 

		private:
		double _speed; /*!< object's speed */
		glm::vec3 _position ;  /*!< object's position */

	};
}



#endif
