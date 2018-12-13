// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ OBJECT.HPP ___________ 
//================================

#ifndef __OBJECT__HPP
#define __OBJECT__HPP

// Includes 
#define GLM_ENABLE_EXPERIMENTAL
#include <glm.hpp>

namespace RUNBOXRUN
{
	/// \class Object
	/// \brief class defining a new object.
	class Object
	{
			
		public:

		Object(); 
		
		Object( const double &speed, const glm::vec3 &position);/*!< object's constructor with arguments*/

		//~Object(); 

		/*!< getter object's position */
		inline glm::vec3 getPos(){
			return _position;
		}

		/*!< setter object's position */
		inline void setPos(glm::vec3 &newPos){
			 _position = newPos;
		}


		protected:
		double _speed; /*!< object's speed */
		glm::vec3 _position ;  /*!< object's position */

	};
}



#endif
