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

		Object(); /*!< default constructor */
		Object(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color);/*!< object's constructor with arguments*/
		Object(const Object &object);/*!< constructor with arguments*/
		~Object(); /*!< default destructor */

		//void const displayInfos() const ;

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
		glm::vec3 _size; /*!< object's size */
		glm::vec3 _color; /*!< object's color */

	};
}



#endif
